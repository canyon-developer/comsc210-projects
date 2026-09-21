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
            cout << car.mileages[i] << " miles";
            if (i < car.mileageCount - 1) {
                cout << ", ";
            }
        }
    }

    cout << endl;
}

int main() {
    // The number of cars, here it is kept small and fixed
    // so the sample output is easy to follow.
    const int carCount = 3;

    // The carRecord itself is a dynamic array of Car structs.
    Car* carRecord = new Car[carCount];

    // These sample arrays let the demonstration cover zero, one, and several
    // mileage records.
    double singlemileages[] = {8000};
    double multiplemileages[] = {12000, 5000, 10500, 4000};

    setCar(carRecord[0], 101, "CR-V", 20000, nullptr, 0);
    setCar(carRecord[1], 102, "RAV4", 25000, singlemileages, 1);
    setCar(carRecord[2], 103, "Model Y", 35000, multiplemileages, 4);

    cout << "Car Record\n";
    cout << "=================" << endl << endl;

    // Walk through the outer dynamic array and print all three structs.
    for (int i = 0; i < carCount; ++i) {
        displayCar(carRecord[i]);
    }

    // Every call to new[] needs a matching delete[].
    for (int i = 0; i < carCount; ++i) {
        delete[] carRecord[i].mileages;
        carRecord[i].mileages = nullptr;
    }

    delete[] carRecord;
    carRecord = nullptr;
    return 0;
}