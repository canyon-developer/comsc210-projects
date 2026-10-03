#include <iostream>
#include <vector>

using namespace std;

class Color {
private:
    int red;
    int green;
    int blue;

  public:
    Color() {}
    Color(int r) {
      red = r;
      green = 0;
      blue = 0;
    }
    Color(int r, int g, int b) {
      red = r;
      green = g;
      blue = b;
    }

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
    int size = 10;
    vector<Color> colors;

    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        int red = rand() % 256;
        int green = rand() % 256;
        int blue = rand() % 256;

        Color color;
        color.set_color(red, green, blue);
        colors.push_back(color);
    }

    cout << "---- " << colors.size() << " colors ----" << endl;
    for (int i = 0; i < size; i++) {
        colors[i].print();
    }

}