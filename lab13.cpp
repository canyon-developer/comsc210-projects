#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    int id;
    float grade;
};

void selectionSortID(vector<Student>& student_grades) {
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

void selectionSortGrade(vector<Student>& student_grades) {
    for (int i = 0; i < student_grades.size(); i++) {
        long smallest = student_grades[i].grade;
        int idx = i;
        for (int j = i + 1; j < student_grades.size(); j++) {
            if (student_grades[j].grade < smallest) {
                idx = j;
                smallest = student_grades[j].grade;
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
    cout << "Read " << student_grades.size() << " student records" << endl;

    selectionSortID(student_grades);
    for (int i = 0; i < student_grades.size(); i++) {
        cout << student_grades[i].id << "  " << student_grades[i].grade << endl;
    }

    ofstream output("210-lab-13-grades-sorted.txt");
    for (int i = 0; i < student_grades.size(); i++) {
        output << student_grades[i].id << " " << student_grades[i].grade << endl;
    }
    cout << "Sorted results written to 210-lab-13-grades-sorted.txt" << endl;

    selectionSortGrade(student_grades);

    float mean = 0.0;
    for (int i = 0; i < student_grades.size(); i++) {
        mean += student_grades[i].grade;
    }
    mean /= student_grades.size();

    float deviation = 0.0;
    for (int i = 0; i < student_grades.size(); i++) {
      float diff = student_grades[i].grade - mean;
        deviation += diff * diff;
    }
    deviation = sqrt(deviation / student_grades.size());

    cout << "--- Summary Statistics ---" << endl;
    cout << "Minimum Score: " << student_grades.front().grade << endl;
    cout << "Maximum Score: " << student_grades.back().grade << endl;
    cout << "Mean Score: " << mean << endl;
    cout << "Median Score: " << student_grades[student_grades.size() / 2].grade << endl;
    cout << "Standard Deviation: " << deviation;
    
}