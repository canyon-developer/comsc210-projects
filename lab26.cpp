#include <algorithm>
#include <chrono>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

using Nanoseconds = long long;

const string DATA_FILE = "names.txt";
const size_t EXPECTED_NAME_COUNT = 20000;
const int NUMBER_OF_RUNS = 15;
const int RACE_COUNT = 4;
const int CONTAINER_COUNT = 3;

template <typename Operation>
Nanoseconds timeOperation(Operation operation) {
    const auto start = chrono::steady_clock::now();
    operation();
    const auto stop = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
}

template <typename StoreName>
void readNames(StoreName storeName) {
    ifstream input(DATA_FILE);
    if (!input) {
        throw runtime_error("Could not open " + DATA_FILE);
    }

    string name;
    size_t count = 0;
    while (input >> name) {
        storeName(name);
        ++count;
    }

    if (count != EXPECTED_NAME_COUNT) {
        throw runtime_error(DATA_FILE + " must contain exactly "
                            + to_string(EXPECTED_NAME_COUNT) + " names");
    }
}

struct Race {
    function<Nanoseconds()> runVector;
    function<Nanoseconds()> runList;
    function<Nanoseconds()> runSet;
};

void runExperiment(Nanoseconds totals[RACE_COUNT][CONTAINER_COUNT]) {
    vector<string> vectorContestant;
    list<string> listContestant;
    set<string> setContestant;

    const Race races[RACE_COUNT] = {
        {
            [&]() {
                return timeOperation([&]() {
                    readNames([&](const string& name) {
                        vectorContestant.push_back(name);
                    });
                });
            },
            [&]() {
                return timeOperation([&]() {
                    readNames([&](const string& name) {
                        listContestant.push_back(name);
                    });
                });
            },
            [&]() {
                return timeOperation([&]() {
                    readNames([&](const string& name) {
                        setContestant.insert(name);
                    });
                });
            }
        },
        {
            [&]() {
                return timeOperation([&]() {
                    sort(vectorContestant.begin(), vectorContestant.end());
                });
            },
            [&]() {
                return timeOperation([&]() {
                    listContestant.sort();
                });
            },
            []() {
                return -1;
            }
        },
        {
            [&]() {
                return timeOperation([&]() {
                    vectorContestant.insert(
                        vectorContestant.begin() + vectorContestant.size() / 2,
                        "TESTNAME");
                });
            },
            [&]() {
                return timeOperation([&]() {
                    auto middle = listContestant.begin();
                    advance(middle, listContestant.size() / 2);
                    listContestant.insert(middle, "TESTNAME");
                });
            },
            [&]() {
                return timeOperation([&]() {
                    setContestant.insert("TESTNAME");
                });
            }
        },
        {
            [&]() {
                return timeOperation([&]() {
                    vectorContestant.erase(
                        vectorContestant.begin() + vectorContestant.size() / 2);
                });
            },
            [&]() {
                return timeOperation([&]() {
                    auto middle = listContestant.begin();
                    advance(middle, listContestant.size() / 2);
                    listContestant.erase(middle);
                });
            },
            [&]() {
                return timeOperation([&]() {
                    auto middle = setContestant.begin();
                    advance(middle, setContestant.size() / 2);
                    setContestant.erase(middle);
                });
            }
        }
    };

    for (int race = 0; race < RACE_COUNT; ++race) {
        totals[race][0] += races[race].runVector();
        totals[race][1] += races[race].runList();
        totals[race][2] += races[race].runSet();
    }
}

void printAverages(const Nanoseconds raceData[RACE_COUNT][CONTAINER_COUNT]) {
    const string operationNames[RACE_COUNT] = {
        "Read", "Sort", "Insert", "Delete"
    };
    constexpr int COLUMN_WIDTH = 16;

    cout << "Average times over " << NUMBER_OF_RUNS << " runs (nanoseconds)\n\n";
    cout << left << setw(COLUMN_WIDTH) << "Operation"
         << right << setw(COLUMN_WIDTH) << "Vector"
         << setw(COLUMN_WIDTH) << "List"
         << setw(COLUMN_WIDTH) << "Set" << '\n';

    for (int race = 0; race < RACE_COUNT; ++race) {
        cout << left << setw(COLUMN_WIDTH) << operationNames[race];
        for (int container = 0; container < CONTAINER_COUNT; ++container) {
            cout << right << setw(COLUMN_WIDTH)
                 << raceData[race][container] / NUMBER_OF_RUNS;
        }
        cout << '\n';
    }
}

int main() {
    Nanoseconds raceData[RACE_COUNT][CONTAINER_COUNT] = {};

    try {
        for (int run = 0; run < NUMBER_OF_RUNS; ++run) {
            runExperiment(raceData);
        }

        printAverages(raceData);
    } catch (const exception& error) {
        cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
