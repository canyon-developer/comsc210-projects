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
    vector<Color> colors;
    colors.push_back({100, 150, 200});
    cout << left << setw(10) << "Color#" << setw(10) << "R value" << setw(10) << "G value" << setw(10) << "B value" << endl;
    cout << "--------------------------------------" << endl;
    
    for (int i = 0; i < 1; i++) {
      Color c = colors[i];
      cout << left << setw(10) << i + 1 << setw(10) << c.red << setw(10) << c.green << setw(10) << c.blue << endl;
    }
}