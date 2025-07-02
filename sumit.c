#include <stdio.h>
#include <stdlib.h>

struct BankAccount {
    int accountNumber;
    char holderName[50];
    float balance;
};

void showMenu();
void checkBalance(struct BankAccount acc);
void deposit(struct BankAccount *acc);
void withdraw(struct BankAccount *acc);

int main() {
    struct BankAccount account = {9840254735, "AA8", 1000000.0};
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(account);
                break;
            case 2:
                deposit(&account);
                break;
            case 3:
                withdraw(&account);
                break;
            case 4:
                printf("Thank you for using the ATM Simulator. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }

        printf("\n");
    }

    return 0;
}

void showMenu() {
    printf("===== ATM Simulator =====\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
}

void checkBalance(struct BankAccount acc) {
    printf("Account Holder: %s\n", acc.holderName);
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Current Balance: Rs. %.2f\n", acc.balance);
}

void deposit(struct BankAccount *acc) {
    float amount;
    printf("Enter amount to deposit: Rs. ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }

    acc->balance += amount;
    printf("Deposit successful! New balance: Rs. %.2f\n", acc->balance);
}

void withdraw(struct BankAccount *acc) {
    float amount;
    printf("Enter amount to withdraw: Rs. ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid withdrawal amount.\n");
        return;
    }

    if (amount > acc->balance) {
        printf("Insufficient balance!\n");
        return;
    }

    acc->balance -= amount;
    printf("Withdrawal successful! New balance: Rs. %.2f\n", acc->balance);
}
