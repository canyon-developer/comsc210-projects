#include <iostream>

using namespace std;

struct Color {
    int red;
    int green;
    int blue;
};

int main() {
    Color c = {100, 150, 200};
    cout << "Color#    " << "R value    " << "G value    " << "B value" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "         " << c.red << "         " << c.green << "         " << c.blue << endl;
}