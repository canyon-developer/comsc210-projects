#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    int id;
    float grade;
};

int main() {
    vector<Student> student_grades;

    ifstream file("210-lab-13-grades.txt");
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
    }
    
    long id;
    float grade;
    while (file >> id >> grade) {
        Student record;
        record.id = id;
        record.grade = grade;
        student_grades.push_back(record);
    }
}