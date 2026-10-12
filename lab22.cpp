#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    void delete_val(int value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    // Delete the node at a zero-based position.
    void delete_pos(int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not deleted.\n";
            return;
        }

        if (temp == head) {
            pop_front();
            return;
        }

        if (temp == tail) {
            pop_back();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void pop_front() {
        if (!head) return; // Empty list

        Node* temp = head;
        head = head->next;

        if (head)
            head->prev = nullptr;
        else
            tail = nullptr; // The list is now empty

        delete temp;
    }

    void pop_back() {
        if (!tail) return; // Empty list

        Node* temp = tail;
        tail = tail->prev;

        if (tail)
            tail->next = nullptr;
        else
            head = nullptr; // The list is now empty

        delete temp;
    }

    void print() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    DoublyLinkedList list;

    cout << "STEP 3 - adds pop_back() and completes the class\n";
    for (int value = 10; value <= 60; value += 10)
        list.push_back(value);
    cout << "Original list:                  ";
    list.print();

    cout << "Delete position 2 (middle):      ";
    list.delete_pos(2);
    list.print();

    cout << "Delete position 0 (head):        ";
    list.delete_pos(0);
    list.print();

    cout << "Delete position 3 (tail):        ";
    list.delete_pos(3);
    list.print();

    cout << "Reverse after position deletes:  ";
    list.print_reverse();

    cout << "After pop_front():               ";
    list.pop_front();
    list.print();

    cout << "After pop_back():                ";
    list.pop_back();
    list.print();

    cout << "Invalid delete_pos(99):          ";
    list.delete_pos(99);

    cout << "Invalid delete_pos(-1):          ";
    list.delete_pos(-1);

    list.push_front(30);
    list.push_front(20);
    list.push_front(10);
    cout << "Rebuilt list:                    ";
    list.print();

    cout << "delete_val(10), the head:        ";
    list.delete_val(10);
    list.print();

    cout << "delete_val(30), middle node:     ";
    list.delete_val(30);
    list.print();

    cout << "delete_val(40), the tail:        ";
    list.delete_val(40);
    list.print();

    cout << "pop_back() on the last node:     ";
    list.pop_back();
    list.print();

    list.pop_front(); // Safe on an empty list
    list.pop_back();  // Safe on an empty list
    cout << "After pops on an empty list:     ";
    list.print();

    return 0;
}
