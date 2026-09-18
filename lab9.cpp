#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

const int SIZE = 30;

void array_demonstration(array<double, SIZE>& double_array) {
    cout << "1. Size: " << double_array.size() << endl;

    cout << "2. Max size: " << double_array.max_size() << endl;

    cout << "3. Values: ";
    for (double val : double_array) cout << val << " ";

    cout << "4. Element 5: " << double_array[5] << endl;
    cout << "5. Element 5: " << double_array.at(5) << endl;
    
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

    cout << "11. Memory address: " << double_array.data() << endl;

    cout << "12. Is empty: ";
    if (double_array.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;

    cout << "13. Max element: ";
    cout << *max_element(double_array.begin(), double_array.end()) << endl;

    cout << "14. Min element: ";
    cout << *min_element(double_array.begin(), double_array.end()) << endl;

    cout << "15. Array sum: ";
    cout << accumulate(double_array.begin(), double_array.end(), 0) << endl;   
}

void vector_demonstration(vector<double>& double_vector) {
    cout << "1. Size: " << double_vector.size() << endl;

    cout << "2. Max size: " << double_vector.max_size() << endl;

    cout << "3. Values: ";
    for (double val : double_vector) cout << val << " ";

    cout << "4. Element 5: " << double_vector[5] << endl;
    cout << "5. Element 5: " << double_vector.at(5) << endl;
    
    srand(time(nullptr));
    cout << "6. Random element: " << double_vector[rand()%SIZE] << endl;
  
    cout << "7. First element: " << double_vector.front() << endl;
    cout << "8. Last element: " << double_vector.back() << endl;


    sort(double_vector.begin(), double_vector.end());
    cout << "9. After sorting: ";
    for (double val : double_vector) cout << val << " "; cout << endl;

    cout << "10. Reverse sorted: ";
    reverse(double_vector.rbegin(), double_vector.rend());
    for (double val : double_vector) cout << val << " "; cout << endl;

    cout << "11. Memory address: " << double_vector.data() << endl;

    cout << "12. Is empty: ";
    if (double_vector.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;

    cout << "13. Max element: ";
    cout << *max_element(double_vector.begin(), double_vector.end()) << endl;

    cout << "14. Min element: ";
    cout << *min_element(double_vector.begin(), double_vector.end()) << endl;

    cout << "15. Array sum: ";
    cout << accumulate(double_vector.begin(), double_vector.end(), 0) << endl; 
}

int main() {
    array<double, SIZE> double_array;
    vector<double> double_vector;

    ifstream data;
    data.open("lab9_external_data.txt");
    if (data.is_open()) {
        for (int i = 0; i < SIZE; i++) {
            string line;
            if (getline(data, line)) {
                double_array[i] = stod(line);
                double_vector.push_back(stod(line));
            } else {
                break;
            }
        }
    } else {
        cout << "Failed reading external data." << endl;
        return 0;
    }

    array_demonstration(double_array);
    vector_demonstration(double_vector);
    
    return 0;
}