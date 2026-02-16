# Objects_Classes_Lab
# BankAccount Class

A C++ class for simulating basic banking operations within a management system.

## Data Dictionary

| Attribute           | Data Type     | Description                          |
|---------------------|---------------|--------------------------------------|
| `accountNumber`     | `std::string` | Unique identifier for the account.   |
| `accountHolderName` | `std::string` | Name of the person owning the account|
| `balance`           | `double`      | Current monetary balance.            |

## Methods List

| Method Signature                                     | Return Type   | Description                                   |
|------------------------------------------------------|---------------|-----------------------------------------------|
| `BankAccount()`                                      | (Constructor) | Initializes account with default values.      |
| `BankAccount(string, string, double)`                | (Constructor) | Initializes account with specific values.     |
| `getAccountNumber() const`                           | `std::string` | Returns the account number.                   |
| `getAccountHolderName() const`                       | `std::string` | Returns the account holder's name.            |
| `getBalance() const`                                 | `double`      | Returns the current balance.                  |
| `setAccountHolderName(string)`                       | `void`        | Updates the holder's name.                    |
| `deposit(double)`                                    | `void`        | Adds funds if the amount is positive.         |
| `withdraw(double)`                                   | `void`        | Subtracts funds if balance has enough funds.     |
