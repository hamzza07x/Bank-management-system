#include <iostream>
#include "BANKACCOUNT.h"
#include "COLOR.h"
using namespace std;

int main() {
    BankAccount account;
    int choice;

    try {
        do {
            // Main interface
            cout << GREEN << "=========== Welcome to FASTBANK ===========\n" << RESET;
            cout << "1. Create Account\n";
            cout << "2. Login to Existing Account\n";
            cout << "0. Exit\n";
            cout << BLUE << "Enter choice: " << RESET;
            cin >> choice;

            // Handle invalid non-integer input
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid input! Please enter a number.");
            }
            cin.ignore();

            // Menu options
            if (choice == 1) {
                account.createAccount();
                account.mainMenu();
            }
            else if (choice == 2) {
                account.loginAccount();
            }
            else if (choice == 0) {
                cout << GREEN << "Exiting..." << RESET << endl;
            }
            else {
                cout << RED << "Invalid choice!" << RESET << endl;
            }

        } while (choice != 0); 
    }
    catch (exception& e) {
        cout << RED << "Error: " << e.what() << RESET << endl;
    }
    catch (...) {
        cout << RED << "An unexpected error occurred." << RESET << endl;
    }

    cin.get();
    return 0;
}
