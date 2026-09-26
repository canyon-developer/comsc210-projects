#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Student {
    int id;
    float grade;
};

int main() {
    vector<Student> student_grades;

    ifstream file("210-lab-13-grades.txt");
    string line;
    while (getline(file, line)) {
        
    }
}