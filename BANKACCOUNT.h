#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>
using namespace std;

// Class representing a single bank account
class BankAccount {
private:
    int bankCode;                      // Unique code for generating account numbers
    string accountHolderName;         // Name of the account holder
    string accountNumber;             // Unique account number
    string accountPassword;           // Password for account access
    string email;                     // Email of account holder
    string phoneNumber;               // Phone number of account holder
    double balance;                   // Current balance in account
    string bankName;                  // Name prefix used in account number
    vector<string> transactionHistory;// Stores record of all transactions

public:
    BankAccount();
    void createAccount();            // Register a new account
    void loginAccount();             // Authenticate existing user
    void depositMoney();            // Deposit money to account
    void withdrawMoney();           // Withdraw money from account
    void checkBalance();            // Display current balance
    void accountDetails();          // Display all account info
    void getTransactionHistory();   // Print all past transactions
    void mainMenu();                // Post-login menu for banking options
    void saveToFile();              // Save account data to a file
    void loadFromFile();            // Load account data from a file
};

#endif
