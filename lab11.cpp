#include <iostream>
#include <string>

using namespace std;

// A car has ordinary data, such as an ID, model, and price.
// It also has a pointer to a dynamic array of mileage measurements because
// a car has different mileages at different time.
struct Car {
    int id;
    string model;
    double price;
    double* mileages;
    int mileageCount;
};

void setCar(Car& car, int id, const string& model, double price,
              const double measurements[], int measurementCount) {
    car.id = id;
    car.model = model;
    car.price = price;
    car.mileageCount = measurementCount;

    // A car with no measurements does not need an array.
    if (measurementCount == 0) {
        car.mileages = nullptr;
        return;
    }

    // Allocate and copy only as many measurements as this car needs.
    car.mileages = new double[measurementCount];
    for (int i = 0; i < measurementCount; ++i) {
        car.mileages[i] = measurements[i];
    }
}

int main() {

  return 0;
}