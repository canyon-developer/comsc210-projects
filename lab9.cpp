#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <random>

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
    
    srand(time(nullptr));
    cout << "6. Random element: " << double_array[rand()%SIZE] << endl;
  
    cout << "7. First element: " << double_array.front() << endl;
    cout << "8. Last element: " << double_array.back() << endl;


    sort(double_array.begin(), double_array.end());
    cout << "9. After sorting: ";
    for (double val : double_array) cout << val << " "; cout << endl;

    cout << "10. Reverse sorted: ";
    reverse(double_array.rbegin(), double_array.rend());
    for (double val : double_array) cout << val << " "; cout << endl;
}