#include <array>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int SIZE = 30;

int main() {
    array<double, SIZE> double_array;
    ifstream data;
    data.open("lab9_external_data.txt");
    if (data.is_open()) {
        for (int i = 0; i < SIZE; i++) {
            string line;
            if (getline(data, line)) {
                double_array[i] = stod(line);
                cout << double_array[i] << endl;
            } else {
                break;
            }
        }
    } else {
        cout << "Failed reading external data." << endl;
        return 0;
    }

    cout << "1. Size: " << double_array.size() << endl;

    cout << "2. Values: ";
    for (double val : double_array) cout << val << " " << endl;

    cout << "3. Element 5: " << double_array[5] << endl;
    cout << "3. Element 5: " << double_array.at(5) << endl;




}