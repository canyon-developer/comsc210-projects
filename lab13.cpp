#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    int id;
    float grade;
};

void selectionSort(vector<Student>& student_grades) {
    for (int i = 0; i < student_grades.size(); i++) {
        long smallest = student_grades[i].id;
        int idx = i;
        for (int j = i + 1; j < student_grades.size(); j++) {
            if (student_grades[j].id < smallest) {
                idx = j;
                smallest = student_grades[j].id;
            }
        }

        Student tmp = student_grades[i];
        student_grades[i] = student_grades[idx];
        student_grades[idx] = tmp;
    }
}
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

    selectionSort(student_grades);
    for (int i = 0; i < student_grades.size(); i++) {
        cout << student_grades[i].id << "  " << student_grades[i].grade << endl;
    }

    ofstream output("sorted_grades.txt");
    for (int i = 0; i < student_grades.size(); i++) {
        output << student_grades[i].id << " " << student_grades[i].grade << endl;
    }
}