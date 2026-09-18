#include <array>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ifstream data;
    data.open("lab9_external_data.txt");
    if (data.is_open()) {
        string line;
        while (getline(data, line)) {
            cout << line << endl;
        }
    }


}