#include <ctime>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Color {
    int red;
    int green;
    int blue;
};

int main() {
    cout << left << setw(10) << "Color#" << setw(10) << "R value" << setw(10) << "G value" << setw(10) << "B value" << endl;
    cout << "--------------------------------------" << endl;
    
    vector<Color> colors;

    srand(time(NULL));
    int n = rand() % 26 + 25;

    for (int i = 0; i < n; i++) {
       int red = rand() % 256;
       int green = rand() % 256;
       int blue = rand() % 256;
       Color c = {red, green, blue};

       colors.push_back(c);
    }

    for (int i = 0; i < n; i++) {
      Color c = colors[i];
      cout << left << setw(10) << i + 1 << setw(10) << c.red << setw(10) << c.green << setw(10) << c.blue << endl;
    }
}