#include <iostream>
#include <string>

using namespace std;

void reverseArray(string *array, int size) {
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

}