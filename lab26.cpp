// Lab 26: Compare common operations on vector, list, and set containers.
// Each race is run 15 times, and the average time is reported in microseconds.

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

using Microseconds = long long;

const string DATA_FILE = "names.txt";
const size_t EXPECTED_NAME_COUNT = 20000;
const int NUMBER_OF_RUNS = 15;
const int RACE_COUNT = 4;
const int CONTAINER_COUNT = 3;
const string TEST_NAME = "TESTNAME";

// The first cube slice stores one run. The second stores the running totals.
enum DataSlice {
    CURRENT_RUN,
    ACCUMULATED_TOTALS,
    DATA_SLICE_COUNT
};

// Each column in a race row belongs to one container type.
enum ContainerColumn {
    VECTOR_COLUMN,
    LIST_COLUMN,
    SET_COLUMN
};

// Run any callable operation and return its elapsed time in microseconds.
template <typename Operation>
Microseconds timeOperation(Operation operation) {
    const auto start = chrono::steady_clock::now();
    operation();
    const auto stop = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::microseconds>(stop - start).count();
}

// Read and validate the input file, passing each name to the supplied function.
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

// A race contains the same operation implemented by each container type.
struct Race {
    function<Microseconds()> runVector;
    function<Microseconds()> runList;
    function<Microseconds()> runSet;
};

// Run the read, sort, insert, and delete races once in dependency order.
void runExperiment(Microseconds results[RACE_COUNT][CONTAINER_COUNT]) {
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
                // A set maintains sort order automatically, so no sort is needed.
                return 0;
            }
        },
        {
            [&]() {
                return timeOperation([&]() {
                    vectorContestant.insert(
                        vectorContestant.begin() + vectorContestant.size() / 2,
                        TEST_NAME);
                });
            },
            [&]() {
                return timeOperation([&]() {
                    auto middle = listContestant.begin();
                    advance(middle, listContestant.size() / 2);
                    listContestant.insert(middle, TEST_NAME);
                });
            },
            [&]() {
                return timeOperation([&]() {
                    setContestant.insert(TEST_NAME);
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
        results[race][VECTOR_COLUMN] = races[race].runVector();
        results[race][LIST_COLUMN] = races[race].runList();
        results[race][SET_COLUMN] = races[race].runSet();
    }
}

// Display the average time for every operation/container combination.
void printAverages(
    const Microseconds raceData[DATA_SLICE_COUNT][RACE_COUNT][CONTAINER_COUNT]) {
    const string operationNames[RACE_COUNT] = {
        "Read", "Sort", "Insert", "Delete"
    };
    constexpr int OPERATION_WIDTH = 18;
    constexpr int RESULT_WIDTH = 12;

    cout << setw(OPERATION_WIDTH + RESULT_WIDTH) << "Number of simulations:"
         << setw(3) << NUMBER_OF_RUNS << '\n';
    cout << setw(OPERATION_WIDTH) << "Operation"
         << setw(RESULT_WIDTH) << "Vector"
         << setw(RESULT_WIDTH) << "List"
         << setw(RESULT_WIDTH) << "Set" << '\n';

    for (int race = 0; race < RACE_COUNT; ++race) {
        cout << setw(OPERATION_WIDTH) << operationNames[race];
        for (int container = 0; container < CONTAINER_COUNT; ++container) {
            cout << setw(RESULT_WIDTH)
                 << raceData[ACCUMULATED_TOTALS][race][container]
                        / NUMBER_OF_RUNS;
        }
        cout << '\n';
    }
}

int main() {
    // Each 4-by-3 slice is organized as [race][container].
    Microseconds raceData[DATA_SLICE_COUNT][RACE_COUNT][CONTAINER_COUNT] = {};

    try {
        for (int run = 0; run < NUMBER_OF_RUNS; ++run) {
            runExperiment(raceData[CURRENT_RUN]);

            for (int race = 0; race < RACE_COUNT; ++race) {
                for (int container = 0; container < CONTAINER_COUNT; ++container) {
                    raceData[ACCUMULATED_TOTALS][race][container]
                        += raceData[CURRENT_RUN][race][container];
                }
            }
        }

        printAverages(raceData);
    } catch (const exception& error) {
        cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
