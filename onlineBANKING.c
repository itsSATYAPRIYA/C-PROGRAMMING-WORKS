#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for bank account
typedef struct {
    char name[50];
    int accNo;
    float balance;
    int pin;
} Account;

// Function to create a new account
void createAccount(Account *acc) {
    printf("Enter account holder's name: ");
    scanf("%s", acc->name);
    printf("Enter account number: ");
    scanf("%d", &acc->accNo);
    printf("Enter PIN for the account: ");
    scanf("%d", &acc->pin);
    acc->balance = 0;
    printf("Account created successfully!\n");
}

// Function to deposit money
void deposit(Account *acc, float amount) {
    acc->balance += amount;
    printf("Deposit successful. Current balance: %.2f\n", acc->balance);
}

// Function to withdraw money
void withdraw(Account *acc, float amount) {
    if (amount > acc->balance) {
        printf("Insufficient funds!\n");
    } else {
        acc->balance -= amount;
        printf("Withdrawal successful. Current balance: %.2f\n", acc->balance);
    }
}

// Function to check balance
void checkBalance(Account *acc) {
    printf("Account Holder: %s\n", acc->name);
    printf("Account Number: %d\n", acc->accNo);
    printf("Current Balance: %.2f\n", acc->balance);
}

// Function to change PIN
void changePin(Account *acc) {
    int newPin;
    printf("Enter current PIN: ");
    int currentPin;
    scanf("%d", &currentPin);
    if (currentPin == acc->pin) {
        printf("Enter new PIN: ");
        scanf("%d", &newPin);
        acc->pin = newPin;
        printf("PIN changed successfully!\n");
    } else {
        printf("Incorrect PIN!\n");
    }
}

int main() {
    Account myAccount;
    int choice;
    float amount;

    while (1) {
        printf("=============== WELCOME TO THE BANKING SYSTEM ===============\n");
        printf("\n1. Create Account*\n2. Deposit*\n3. Withdraw*\n4. Check Balance*\n5. Change PIN*\n6. Exit*\n");
        printf("Enter your choice: ---->\n ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&myAccount);
                break;
            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&myAccount, amount);
                break;
            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&myAccount, amount);
                break;
            case 4:
                checkBalance(&myAccount);
                break;
            case 5:
                changePin(&myAccount);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}