/*
Author: Mahaila Guzman
Date: 2/15/26
Purpose: using objects and classes, allows us to practice putting data into specific variables and using setters/getters
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // default constructor
    BankAccount() {
        accountNumber = "0000";
        accountHolderName = "None";
        balance = 0.0;
    }

    // constructor with specific parameters
    BankAccount(string accNum, string name, double initialBal) {
        accountNumber = accNum;
        accountHolderName = name;

        // makes sure there isn't a negative numbers inputted and value iputted is included in parameters
        if (initialBal < 0) {
            balance = 0;
        } else {
            balance = initialBal;
        }
    }

    // getters
    string getAccountNumber() { return accountNumber; }
    string getAccountHolderName() { return accountHolderName; }
    double getBalance() { return balance; }

    // setters
    void setAccountHolderName(string newName) {
        accountHolderName = newName;
    }

    // specific outputs that depend on what the user inputted
    void deposit(double amount) {
        if (amount > 0) {
            balance = balance + amount;
            cout << "Deposit successful! New balance: $" << balance << endl;
        } else {
            cout << "Error: Deposit amount must be positive." << endl;
        }
    }

    // makes sure what the user inputted is included in the parameters
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Error: Insufficient funds!" << endl;
        } else if (amount <= 0) {
            cout << "Error: Withdrawal must be more than 0." << endl;
        } else {
            balance = balance - amount;
            cout << "Withdrawal successful! Remaining balance: $" << balance << endl;
        }
    }
};

int main() {
    vector<BankAccount> allAccounts;
    int userChoice = 0;

    while (userChoice != 5) {
        cout << "\n--- My Bank Menu ---" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Show All Accounts" << endl;
        cout << "5. Exit" << endl;
        cout << "Selection: ";
        cin >> userChoice;

        if (userChoice == 1) {
            string num, name;
            double startMoney;

            cout << "Enter Account Number: ";
            cin >> num;
            cout << "Enter Owner Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Starting Balance: ";
            cin >> startMoney;

            BankAccount tempAccount(num, name, startMoney);
            allAccounts.push_back(tempAccount);

            cout << "Account added to the system." << endl;

        } else if (userChoice == 2) {
            string searchNum;
            double amt;
            cout << "Enter Account Number for Deposit: ";
            cin >> searchNum;

            bool found = false;
            for (int i = 0; i < allAccounts.size(); i++) {
                if (allAccounts[i].getAccountNumber() == searchNum) {
                    cout << "Enter amount to deposit: ";
                    cin >> amt;
                    allAccounts[i].deposit(amt);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Account not found." << endl;

        } else if (userChoice == 3) {
            string searchNum;
            double amt;
            cout << "Enter Account Number for Withdrawal: ";
            cin >> searchNum;

            bool found = false;
            for (int i = 0; i < allAccounts.size(); i++) {
                if (allAccounts[i].getAccountNumber() == searchNum) {
                    cout << "Enter amount to withdraw: ";
                    cin >> amt;
                    allAccounts[i].withdraw(amt);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Account not found." << endl;

        } else if (userChoice == 4) {
            cout << "\n--- Current Accounts ---" << endl;
            for (int i = 0; i < allAccounts.size(); i++) {
                cout << "ID: " << allAccounts[i].getAccountNumber()
                     << " | Name: " << allAccounts[i].getAccountHolderName()
                     << " | Balance: $" << allAccounts[i].getBalance() << endl;
            }
        }
    }

    cout << "Goodbye, have a good day!" << endl;
    return 0;
}