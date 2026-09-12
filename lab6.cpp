#include <iostream>

using namespace std;

const int SIZE = 5;

void enterArrayData(double *array, int size) {
    cout << "Data entry for the array with size " << size << " :" << endl;

    for (int i = 0; i < size; i++) {
        cout << "    > Element #" << i << ": ";
        cin >> array[i];
    }
    cout << "Data entry complete." << endl;
}

int main() {
    double *array = new double[SIZE];

    enterArrayData(array, SIZE);

    return 0;
}