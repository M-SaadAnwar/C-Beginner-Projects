#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> account_name;
vector<int> balance;
vector<int> pin_codes;

void create_acc(){
    cout << "Create Account" << endl;
    string full_name;
    int pin, age;
    cout << "Enter your age: "; cin >> age;
    if (age >= 18){
        cout << "Enter your full name: "; cin >> full_name;
        cin.ignore();
        cout << "Enter pin code for your bank account: "; cin >> pin;
        account_name.push_back(full_name);
        pin_codes.push_back(pin);
    } else cout << "Age should be over 18!" << endl;      
}

int validate(){
    int pin_check, index;
    cout << "Enter you account pin code: "; cin >> pin_check;
    for (int i = 0; i < 5; i++){
        if(pin_codes[i] == pin_check){
            cout << "Account Verified!" << endl;
            index = i; return index;
            break;
        } 
    } 
    return -1;
}

void deposit(){
    cout << "Deposit Mode" << endl;
    int amount, index;
    index = validate();
    if (index >= 0 && index <= 4){
        cout << "Enter amount to deposit: "; cin >> amount;
        balance.insert(balance.begin() + index, amount);
    } else cout << "Account not found!" << endl;   
}

void withdraw(){
    cout << "Withdraw Mode" << endl;
    int amount, index;
    index = validate();
    cout << "Enter amount to withdraw: "; cin >> amount;
    balance[index] -= amount;
    cout << "Amount Withdrawn" << endl;
}

void check_balance(){
    cout << "Balance Check" << endl;
    int index, amount;
    index = validate();
    cout << "Balance: " << balance[index] << endl;
}


void start(){
    char choice;
    cout << "Select mode: "; cin >> choice;
    while (choice != 5){
        switch (choice){
        case '1':
            create_acc();
            break;
        case '2':
            deposit();
            break;
        case '3':
            withdraw();
            break;
        case '4':
            check_balance();
            break;
        default:
            break;
        }
    }
}

int main(){
    cout << "-------ATM Simulator-------" << endl;
    cout << "1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Check Balance\n5. Quit" << endl;
    start();

}
