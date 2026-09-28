#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Movie {
private:
    string screen_writer;
    int year;
    string title;

public:
    void set_screen_writer(string writer) { screen_writer = writer; }
    void set_year(int y) { year = y; }
    void set_title(string t) { title = t; }
  
    string get_screen_writer() { return screen_writer; }
    int get_year() { return year; }
    string get_title() { return title; }

    void print() {
        cout << "Movie: " << get_title() << endl;
        cout << "    Year released: " << get_year() << endl;
        cout << "    Screenwriter: " << get_screen_writer() << endl;
    }
};

int main() {
    ifstream file("lab15-input.txt");
    if (!file.is_open()) {
        cout << "Failed to open input file" << endl;
        return 0;
    }

    string screen_writer;
    string year_str;
    string title;

    vector<Movie> movies;
    while (getline(file, screen_writer)) {
        getline(file, year_str);
        int year = stoi(year_str);
        getline(file, title);

        Movie m;
        m.set_screen_writer(screen_writer);
        m.set_year(year);
        m.set_title(title);
        movies.push_back(m);
    }

    for (int i = 0; i < movies.size(); i++) {
        movies[i].print();
    }
}