#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLoggedIn()
{
    string username, password, un, pw;

    cout << "Enter your username: "; cin >> username;
    cout << "Enter your password: "; cin >> password;

    ifstream read("data\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password){
        return true;
    } else {
        return false;
    }

};


int main ()
{
    int choice;
    cout << "1: Register\n2: Login\nYour Choice: "; cin >> choice;

    if(choice == 1){
        string username, password;
        
        cout << "Select a username: "; cin >> username;
        cout << "Select a password: "; cin >> password;

        ofstream file;
        file.open("data\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        main();
        
    } else if (choice == 2){
        bool status = isLoggedIn();

        if(!status){
            cout << "False Login!" << endl;
            system("PAUSE");
            return 0;
        } else {
            cout << "Successfully Logged In!" << endl;
            system("PAUSE");
            return 1;
        };
        
    } else {
        cout << "Enter a valid number" << endl;
        main();
    }

};