#include <iostream>

using namespace std;

class Movie {
private:
  string screen_writer;
  int year;
  string title;

public:
  void set_screen_writer(string writer) { screen_writer = writer; }
  void set_year(int y) { year = y; }
  void set_title(int t) { title = t; }
  
  string get_screen_writer() { return screen_writer; }
  int get_year() { return year; }
  string get_title() { return title; }

  void print() {
    cout << "Movie: " << get_title() << endl;
    cout << " Year released: " << get_year() << endl;
    cout << " Screenwriter: " << get_screen_writer() << endl;
  }
};

int main() {
    
}