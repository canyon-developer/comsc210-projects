#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double *prices;

public:
    Chair() {
        const int MIN = 10000, MAX = 99999;

        prices = new double[SIZE];
        legs = rand() % 2 + 3;
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / (double) 100;
    }

    Chair(int l, const double p[]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }

    ~Chair() { delete [] prices; }

    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1;
        prices[1] = p2;
        prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    srand(time(0));
    cout << fixed << setprecision(2);

    cout << "STEP 1 - RANDOM DEFAULT CONSTRUCTOR\n";
    Chair *chairPtr = new Chair;
    chairPtr->print();

    cout << "THE SAME CHAIR AFTER CALLING ITS SETTERS\n";
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();
    delete chairPtr;
    chairPtr = nullptr;

    cout << "STEP 2 - TWO-PARAMETER CONSTRUCTOR\n";
    double livingChairPrices[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, livingChairPrices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    cout << "STEP 3 - DEFAULT-CONSTRUCTED CHAIR ARRAY\n";
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++) {
        cout << "Chair " << i + 1 << ":\n";
        collection[i].print();
    }
    delete [] collection;
    collection = nullptr;

    return 0;
}
