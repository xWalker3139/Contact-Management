// Including header files
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// Global variables
string fname, lname, phone_num;

// Functions
void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);

int main(){
    short int choice;

    system("cls");
    cout << "\033[0;32m";

    cout << "\n\n\n\t\t\tContact Management.";
    cout << "\n\n\t 1. Add Contact\n\t 2. Search Contact \n\t 3. Help\n\t 4. Exit\n";
    cin >> choice;

    switch(choice){
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            help();
            break;
        case 4:
            self_exit();
            break;
        default:
            cout << "\n\n\tInvalid Input!";
            cout << "\n\tPress any key to Continue...";
            cin.ignore();
            cin.get();
    }
    return 0;
}

void self_exit(){
    system("cls");
    cout << "\n\n\n\t\tThank you for using!";
    exit(0);
}

void help(){
    cout << "\nHelp section...";
}

void addContact(){
    ofstream phone("number.txt", ios::app);

    system("cls");
    cout << "\n\n\tEnter first name: ";
    cin >> fname;
    cout << "\n\tEnter last name: ";
    cin >> lname;
    cout << "\n\tEnter 10-digit phone number: ";
    cin >> phone_num;

    if(check_digits(phone_num)){
        if(check_numbers(phone_num)){
            if(phone.is_open()){
                phone << fname << " " << lname << " " << phone_num << endl;
                cout << "\n\tContact saved successfully!";
            }
        } else {
            cout << "\n\tA phone number must contain only digits.";
        }
    } else {
        cout << "\n\tA phone number must contain 10 digits.";
    }
}

void searchContact(){
    bool found = false;

    ifstream myfile("number.txt");
    string keyword;

    cout << "\n\tEnter name to search";
    cin >> keyword;

    while(myfile >> fname >> lname >> phone_num){
        if(keyword == fname || keyword == lname){
            system("cls");
            cout << "\n\n\n\t\tContact Details...";
            cout << "\n\n\tFirst Name:" << fname;
            cout << "\n\tLast Name:" << lname;
            cout << "\n\tPhone Number:" << phone_num;
            found = true;
            break;
        }
    }
    if(found == false){
        cout << "No such contact was found!";
    }
}

bool check_digits(string x){
    return x.length() == 10;
}

bool check_numbers(string x){
    for(int i = 0; i < x.length(); i++){
        if(!(x[i] >= '0' && x[i] <= '9')){
            return false;
        }
    }
    return true;
}
