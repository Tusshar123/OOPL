#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankUser {
private:
    int pin;

public:
    string name;
    int balance;
    int bank_number;

    void initializeAccount() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Bank Number: ";
        cin >> bank_number;
        cout << "Enter Initial Balance (More than ₹500): ";
        cin >> balance;
        cout << "Set a 4-digit PIN: ";
        cin >> pin;
    }

    bool validatePin(int enteredPin) {
        return pin == enteredPin;
    }

    void deposit(int deposit_amount) {
        balance += deposit_amount;
        cout << "Deposited Amount: ₹" << deposit_amount << endl;
        cout << "Current Balance: ₹" << balance << endl;
    }

    void withdraw(int withdraw_amount) {
        if (withdraw_amount <= balance && (balance - withdraw_amount) >= 500) {
            balance -= withdraw_amount;
            cout << "Withdrawn Amount: ₹" << withdraw_amount << endl;
            cout << "Current Balance: ₹" << balance << endl;
        } else {
            cout << "Insufficient balance. Minimum ₹500 must remain." << endl;
        }
    }

    void displayBalance() {
        cout << "Account Holder: " << name << endl;
        cout << "Account Number: " << bank_number << endl;
        cout << "Current Balance: ₹" << balance << endl;
    }
};

int findUserByBankNumber(vector<BankUser>& users, int bankNumber) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].bank_number == bankNumber) {
            return i;
        }
    }
    return -1;  
}

int main() {
    vector<BankUser> users;  

    int numberOfUsers;
    cout << "Enter the number of users: ";
    cin >> numberOfUsers;

    for (int i = 0; i < numberOfUsers; i++) {
        BankUser newUser;
        cout << "\nInitializing account for user " << i + 1 << ":\n";
        newUser.initializeAccount();
        users.push_back(newUser);
    }

    int choice;
    do {
        cout << "\nMenu:\n1. Deposit\n2. Withdraw\n3. Display Balance\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice != 4) {
            int bankNumber;
            cout << "Enter Bank Number: ";
            cin >> bankNumber;

            int userIndex = findUserByBankNumber(users, bankNumber);
            if (userIndex == -1) {
                cout << "User with Bank Number " << bankNumber << " not found." << endl;
            } else {
                int enteredPin;
                cout << "Enter PIN: ";
                cin >> enteredPin;

                if (users[userIndex].validatePin(enteredPin)) {
                    if (choice == 1) {
                        int deposit_amount;
                        cout << "Enter amount to deposit: ";
                        cin >> deposit_amount;
                        users[userIndex].deposit(deposit_amount);
                    } else if (choice == 2) {
                        int withdraw_amount;
                        cout << "Enter amount to withdraw: ";
                        cin >> withdraw_amount;
                        users[userIndex].withdraw(withdraw_amount);
                    } else if (choice == 3) {
                        users[userIndex].displayBalance();
                    } else {
                        cout << "Invalid choice." << endl;
                    }
                } else {
                    cout << "Incorrect PIN." << endl;
                }
            }
        }
    } while (choice != 4);

    cout << "Thank you!" << endl;

    return 0;
}
