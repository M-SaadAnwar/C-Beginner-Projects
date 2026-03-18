#include <iostream>
#include <string>
#include <vector>

using namespace std;

// The "Database" - keeps track of the original names
const string original_books[10] = {
    "Sapiens", "1984", "The Hobbit", "Lord of the Rings", "Wuthering Heights", 
    "The Giver", "A Tale of Two Cities", "The Book Thief", "Harry Potter", "The Alchemist"
};

// The active list - this one gets modified
string books[10] = {
    "Sapiens", "1984", "The Hobbit", "Lord of the Rings", "Wuthering Heights", 
    "The Giver", "A Tale of Two Cities", "The Book Thief", "Harry Potter", "The Alchemist"
};

void display_books() {
    cout << "\n================================" << endl;
    cout << "     LIBRARY CURRENT STATUS     " << endl;
    cout << "================================" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << ". ";
        if (books[i] == "LENT") {
            cout << "[LENT OUT]";
        } else {
            cout << books[i];
        }
        cout << endl;
    }
    cout << "================================" << endl;
}

void lend_book() {
    int id;
    cout << "\nEnter Book ID to lend: ";
    cin >> id;

    int index = id - 1; // Convert 1-10 input to 0-9 index

    if (index >= 0 && index < 10) {
        if (books[index] != "LENT") {
            cout << "Success! You have borrowed: " << books[index] << endl;
            books[index] = "LENT";
        } else {
            cout << "Sorry, that book is already lent out." << endl;
        }
    } else {
        cout << "Invalid ID! Please enter a number between 1 and 10." << endl;
    }
}

void return_book() {
    int id;
    cout << "\nEnter Book ID to return: ";
    cin >> id;

    int index = id - 1;

    if (index >= 0 && index < 10) {
        if (books[index] == "LENT") {
            books[index] = original_books[index]; // Restore name from database
            cout << "Success! You returned: " << books[index] << endl;
        } else {
            cout << "This book is already in the library." << endl;
        }
    } else {
        cout << "Invalid ID! Please enter a number between 1 and 10." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n1. Display Books\n2. Lend Book\n3. Return Book\n4. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        if (choice == 1) {
            display_books();
        } else if (choice == 2) {
            lend_book();
        } else if (choice == 3) {
            return_book();
        } else if (choice == 4) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}