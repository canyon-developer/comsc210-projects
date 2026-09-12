#include <iostream>

using namespace std;

const int SIZE = 5;

void enterArrayData(double *array, int size) {
    cout << "Please input " << size << " double value(s)." << endl;

    for (int i = 0; i < size; i++) {
      cin >> array[i];
    }
}

int main() {
    double *array = new double[SIZE];

    enterArrayData(array, SIZE);

    return 0;
}