#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "BANKACCOUNT.h"
#include "COLOR.h"
using namespace std;

// Constructor: initialize default values
BankAccount::BankAccount() {
    bankCode = 1001;
    bankName = "BANK";
    balance = 0;
}

// Function to create a new account
void BankAccount::createAccount() {
    cout << GREEN << "     Create account\n" << RESET;
    cout << "================================================" << endl;

    // Collect user details
    cout << BLUE << "Enter name: " << RESET;
    getline(cin, accountHolderName);
    cout << BLUE << "Enter Email: " << RESET;
    getline(cin, email);
    cout << BLUE << "Enter phone number: " << RESET;
    getline(cin, phoneNumber);
    cout << BLUE << "Enter password: " << RESET;
    getline(cin, accountPassword);
    cout << "================================================" << endl;

    balance = 500.0; // Initial balance

    // Read last used bank code
    ifstream file("Bank.txt");
    if (file.is_open()) {
        file >> bankCode;
        file.close();
    }

    // Update bank code for next account
    ofstream outfile("Bank.txt");
    if (outfile.is_open()) {
        outfile << bankCode + 1;
        outfile.close();
    }

    // Generate account number
    accountNumber = bankName + to_string(bankCode);
    transactionHistory.push_back("Deposit: " + to_string(balance));

    cout << GREEN << "Account created successfully\n" << RESET;
    cout << YELLOW << "Account Number: " << accountNumber << endl;
    cout << YELLOW << "Balance: " << balance << RESET << endl;

    saveToFile(); // Save account to file
}

// Function to login an existing account
void BankAccount::loginAccount() {
    cout << BLUE << "Enter Account Number: " << RESET;
    getline(cin, accountNumber);
    cout << BLUE << "Enter Password: " << RESET;
    getline(cin, accountPassword);

    // Open account file
    ifstream file(accountNumber + ".txt");
    if (!file.is_open()) {
        cout << RED << "Account not found!" << RESET << endl;
        return;
    }

    // Load user data
    string storedName, storedNumber, storedPassword;
    getline(file, storedName);
    getline(file, storedNumber);
    getline(file, storedPassword);
    getline(file, email);
    getline(file, phoneNumber);
    file >> balance;
    file.ignore();

    transactionHistory.clear();
    string transaction;
    while (getline(file, transaction)) {
        transactionHistory.push_back(transaction);
    }
    file.close();

    // Validate password
    if (storedPassword == accountPassword) {
        accountHolderName = storedName;
        cout << GREEN << "Login successful!" << RESET << endl;
        mainMenu(); // Enter banking menu
    }
    else {
        cout << RED << "Invalid password!" << RESET << endl;
    }
}

// Deposit function
void BankAccount::depositMoney() {
    double amount;
    cout << BLUE << "Enter amount to deposit: " << RESET;
    cin >> amount;
    cin.ignore();

    if (amount <= 0) {
        cout << RED << "Invalid amount!" << RESET << endl;
        return;
    }

    balance += amount;
    transactionHistory.push_back("Deposit: " + to_string(amount));
    cout << GREEN << "Deposited successfully. New Balance: " << YELLOW << balance << RESET << endl;
    saveToFile();
}

// Withdraw function
void BankAccount::withdrawMoney() {
    double amount;
    cout << BLUE << "Enter amount to withdraw: " << RESET;
    cin >> amount;
    cin.ignore();

    if (amount <= 0 || amount > balance) {
        cout << RED << "Invalid or insufficient balance!" << RESET << endl;
        return;
    }

    balance -= amount;
    transactionHistory.push_back("Withdraw: " + to_string(amount));
    cout << GREEN << "Withdrawn successfully. New Balance: " << YELLOW << balance << RESET << endl;
    saveToFile();
}

// Check balance
void BankAccount::checkBalance() {
    cout << YELLOW << "Your current balance is: " << balance << RESET << endl;
}

// Display full account details
void BankAccount::accountDetails() {
    cout << GREEN << "----- Account Details -----" << RESET << endl;
    cout << "Account Holder: " << PINK << accountHolderName << RESET << endl;
    cout << "Account Number: " << PINK << accountNumber << RESET << endl;
    cout << "Email: " << PINK << email << RESET << endl;
    cout << "Phone Number: " << PINK << phoneNumber << RESET << endl;
    cout << "Balance: " << YELLOW << balance << RESET << endl;
}

// Print all past transactions
void BankAccount::getTransactionHistory() {
    cout << GREEN << "----- Transaction History -----" << RESET << endl;
    for (const auto& transaction : transactionHistory) {
        cout << transaction << endl;
    }
}

// Menu after logging in
void BankAccount::mainMenu() {
    bool logoutStatus = false;
    int choice;

    try {
        while (!logoutStatus) {
            cout << "\n" << GREEN << "============ FASTBANK MENU ============\n" << RESET;
            cout << "1. Deposit Money" << endl;
            cout << "2. Withdraw Money" << endl;
            cout << "3. Check Balance" << endl;
            cout << "4. Account Details" << endl;
            cout << "5. Transaction History" << endl;
            cout << "6. Logout" << endl;
            cout << BLUE << "Enter choice: " << RESET;
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid input! Please enter a number.");
            }
            cin.ignore();
            system("cls"); // Clear screen

            switch (choice) {
            case 1: depositMoney(); break;
            case 2: withdrawMoney(); break;
            case 3: checkBalance(); break;
            case 4: accountDetails(); break;
            case 5: getTransactionHistory(); break;
            case 6:
                cout << GREEN << "Logged out successfully!" << RESET << endl;
                logoutStatus = true;
                break;
            default:
                cout << RED << "Invalid choice! Try again." << RESET << endl;
            }
        }
    }
    catch (exception& e) {
        cout << RED << e.what() << RESET << endl;
    }
    catch (...) {
        cout << RED << "An unexpected error occurred." << RESET << endl;
    }
}

// Save account details to file
void BankAccount::saveToFile() {
    ofstream file(accountNumber + ".txt");
    if (file.is_open()) {
        file << accountHolderName << endl;
        file << accountNumber << endl;
        file << accountPassword << endl;
        file << email << endl;
        file << phoneNumber << endl;
        file << balance << endl;
        for (const auto& transaction : transactionHistory) {
            file << transaction << endl;
        }
        file.close();
    }
    else {
        cout << RED << "Error saving account!" << RESET << endl;
    }
}

// Load account details from file (if needed)
void BankAccount::loadFromFile() {
    ifstream file(accountNumber + ".txt");
    if (file.is_open()) {
        getline(file, accountHolderName);
        getline(file, accountNumber);
        getline(file, accountPassword);
        getline(file, email);
        getline(file, phoneNumber);
        file >> balance;
        file.ignore();

        string transaction;
        while (getline(file, transaction)) {
            transactionHistory.push_back(transaction);
        }
        file.close();
    }
    else {
        cout << RED << "Error loading file!" << RESET << endl;
    }
}
