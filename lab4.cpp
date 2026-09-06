#include <iostream>
#include <iomanip>

using namespace std;

struct Color {
    int red;
    int green;
    int blue;
};

int main() {
    Color c = {100, 150, 200};
    cout << left << setw(10) << "Color#" << setw(10) << "R value" << setw(10) << "G value" << setw(10) << "B value" << endl;
    cout << "--------------------------------------" << endl;
    cout << left << setw(10) << 1 << setw(10) << c.red << setw(10) << c.green << setw(10) << c.blue << endl;
}