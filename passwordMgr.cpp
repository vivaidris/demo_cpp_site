#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::string;

class UserAccount {
    public:
        string username;
        string email;
        string password;
        string pin;

        void saveToFile(){
            std::ofstream outFile("user_data.txt", std::ios::app);

            if(outFile.is_open()){
                outFile << username << ',' << email << ',' << password << ',' << pin << '\n'; 
                outFile.close();
                cout << "User info saved to file" << '\n';
            }
            else{
                cout << "Failed to open file";
            }
        }
};

static bool login(const string& inputUser, const string& inputPass){
    std::ifstream inFile("user_data.txt");

    if(!inFile.is_open()){
        cout << "Failed to open file." << '\n';
        return false;
    }

    string line;
    while(std::getline(inFile, line)){
        std::stringstream ss(line);
        string user, mail, pass, pin;

        getline(ss, user, ',');
        getline(ss, mail, ',');
        getline(ss, pass, ',');
        getline(ss, pin, ',');

        if(inputUser == user && inputPass == pass){
            cout << "Welcome " << user;
            return true;
        }

    }

    cout << "Login failed. Username or password incorrect.";
    return false;
};

int main() {
    string action;

    cout << "Welcome to ABC website!\n";
    cout << "Would you like to (register) or (login)? ";
    cin >> action;

    if (action == "register") {
        UserAccount user;

        cout << "Please enter your username: ";
        cin >> user.username;

        cout << "Please enter your email: ";
        cin >> user.email;

        cout << "Please enter your password: ";
        cin >> user.password;

        if (user.password == "password" || user.password == "1234") {
            cout << "Please enter a stronger password: ";
            cin >> user.password;
        }

        cout << "Enter a two-step verification PIN: ";
        cin >> user.pin;

        user.saveToFile();
        cout << "Registration complete!\n";
    } 
    else if (action == "login") {
        string inputUser, inputPass;
        cout << "Username: ";
        cin >> inputUser;
        cout << "Password: ";
        cin >> inputPass;

        bool success = login(inputUser, inputPass);
        if (!success) {
            cout << "Try again later.\n";
        }
    } 
    else {
        cout << "Invalid option. Please restart the program.\n";
    }

    return 0;
}
