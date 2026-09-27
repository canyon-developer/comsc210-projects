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
};