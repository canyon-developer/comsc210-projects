#include <iostream>
#include <vector>

using namespace std;

class Color {
private:
    int red;
    int green;
    int blue;

  public:
    Color() { red = 0; green = 0; blue = 0; }
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
    vector<Color> colors;

    Color c1;
    Color c2(100);
    Color c3(150, 150, 150);

    colors.push_back(c1);
    colors.push_back(c2);
    colors.push_back(c3);

    cout << "---- " << colors.size() << " colors ----" << endl;
    for (int i = 0; i < colors.size(); i++) {
        colors[i].print();
    }

}