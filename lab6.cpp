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

void outputArrayData(double *array, int size) {
    cout << "Outputting " << size << " array elements: ";
    for (int i = 0; i < size - 1; i++) {
        cout << array[i] << " ";
    }
    cout << array[size - 1] << endl;
}

double sumArray(double *array, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum = sum + array[i];
    }

    return sum;
}

int main() {
    double *array = new double[SIZE];

    enterArrayData(array, SIZE);
    outputArrayData(array, SIZE);

    double array_sum = sumArray(array, SIZE);
    cout << "Sum of values: " << array_sum << endl;

    return 0;
}