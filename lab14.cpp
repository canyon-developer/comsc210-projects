#include <iostream>

using namespace std;

class Color {
private:
    int red;
    int green;
    int blue;

public:
    void set_red(int r) { red = r; }
    void set_green(int g) { green = g; }
    void set_blue(int b) { blue = b; }
    void set_color(int r, int g, int b) { red = r; green = g; blue = b;}

    int get_red() { return red; }
    int get_green() { return green; }
    int get_blue() { return blue; }

    void print() {
        cout << "(r, g, b) color: " << get_red() << " " << get_green() << " " << get_blue() << endl;
    }
};

int main() {

}