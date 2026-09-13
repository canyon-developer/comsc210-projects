#include <iostream>
#include <string>

using namespace std;

string* reverseArray(string *array, int size) {
    int j = size - 1;
    for (int i = 0; i < j; i++) {
      string s = array[i];
      array[i] = array[j];
      array[j] = s;
     j--;
    }

    return array;
}

int main() {
  const int SIZE = 5;
  string *array = new string[SIZE];
  array[0] = "Leo";
  array[1] = "John";
  array[2] = "Kevin";
  array[3] = "Amy";
  array[4] = "Kytelyn";
}