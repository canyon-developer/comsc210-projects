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

// Display car information
void displayCar(const Car& car) {
    cout << "Car #" << car.id << ": " << car.model << '\n';
    cout << "  Price: $" << fixed << car.price << '\n';
    cout << "  Recorded mileages: ";

    if (car.mileageCount == 0) {
        cout << "none";
    } else {
        for (int i = 0; i < car.mileageCount; ++i) {
            cout << car.mileages[i] << " cm";
            if (i < car.mileageCount - 1) {
                cout << ", ";
            }
        }
    }

    cout << endl;
}

int main() {

  return 0;
}