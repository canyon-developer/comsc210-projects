#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
    float value;
    Node *next;
};

void output(Node *);

Node *createLinkedList(int size) {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < size; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else {
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }

    return head;
}

void deleteEntry(Node *& head) {
    cout << "Which node to delete? " << endl;
    output(head);
    cout << "Choice --> ";
    int entry;
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
}

void insertAfter(Node *& head) {
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    Node *current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    int entry;
    cin >> entry;

    current = head;
    Node *prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }
}

void deleteLinkedList(Node *&head) {
    Node *current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}




int main() {
    Node *head = createLinkedList(SIZE);
    output(head);

    do {
      cout << "Choose action:" << endl;
      cout << "    [1] Add a node to front" << endl;
      cout << "    [2] Add a node to end" << endl;
      cout << "    [3] Delete a node" << endl;
      cout << "    [4] Insert a node" << endl;
      cout << "    [5] Delete the list" << endl;
      cout << "    [6] Print the list" << endl;
      cout << "    [7] Exit" << endl;

      int action;
      cin >> action;
      if (action == 1) {
          insertAfter(head);
      } else if (action == 2) {
          insertAfter(head);
      } else if (action == 3) {
          deleteEntry(head);
      } else if (action == 4) {
          insertAfter(head);
      } else if (action == 5) {
          deleteEntry(head);
      } else if (action == 6) {
          output(head);
      } else if (action == 7) {
          break;
      } else {
          cout << "Wrong choice." << endl;
      }
    } while (true);

    return 0;
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}