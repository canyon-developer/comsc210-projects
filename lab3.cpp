#include <iostream>

using namespace std;

struct Restaurant {
    string name;
    string address;
    string style;
    string petAllowed;
    string onlineOrderOffered;
};

Restaurant addRestaurant();
void restaurantInfo(Restaurant& restaurant);

int main() {
    const int NUMBER = 4;
    Restaurant restaurants[NUMBER]; // 4 restaurnants

    for (int i = 0; i < 2; i++) {
        cout << "Populate restaurant info for the " << i + 1 << " restaurant:" << endl;
        restaurants[i] = addRestaurant();
    }

    return 0;
}

Restaurant addRestaurant() {
    Restaurant restaurant;
    cout << "What is the name: ";
    getline(cin, restaurant.name);

    cout << "What is its address: ";
    getline(cin, restaurant.address);

    cout << "What is its style (Italian/French/Chinese/...): ";
    getline(cin, restaurant.style);

    cout << "Is pet allowed (y/n)?: ";
    getline(cin, restaurant.petAllowed);

    cout << "Does it provide online ordering (y/n)?: ";
    getline(cin, restaurant.onlineOrderOffered);

    return restaurant;
}

void restaurantInfo(Restaurant& restaurant) {
    cout << "---------- Restaurant Info ----------" << endl;
    cout << "Name:                 " << restaurant.name << endl;
    cout << "Address:              " << restaurant.address << endl;
    cout << "Style:                " << restaurant.address << endl;
    cout << "Pet Policy:           " << restaurant.petAllowed << endl;
    cout << "Online order offered: " << restaurant.onlineOrderOffered << endl;
}