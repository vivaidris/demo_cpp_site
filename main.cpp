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
            std::ofstream outFile("C:\\Users\\Owner\\OneDrive - Mariam Al Batool School\\Desktop\\gameEngine\\user_data.txt", std::ios::app);

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
    std::string action;

    std::cout << "Welcome to ABC website!\n";
    std::cout << "Would you like to (register) or (login)? ";
    std::cin >> action;

    if (action == "register") {
        UserAccount user;

        std::cout << "Please enter your username: ";
        std::cin >> user.username;

        std::cout << "Please enter your email: ";
        std::cin >> user.email;

        std::cout << "Please enter your password: ";
        std::cin >> user.password;

        if (user.password == "password" || user.password == "1234") {
            std::cout << "Please enter a stronger password: ";
            std::cin >> user.password;
        }

        std::cout << "Enter a two-step verification PIN: ";
        std::cin >> user.pin;

        user.saveToFile();
        std::cout << "Registration complete!\n";
    } 
    else if (action == "login") {
        std::string inputUser, inputPass;
        std::cout << "Username: ";
        std::cin >> inputUser;
        std::cout << "Password: ";
        std::cin >> inputPass;

        bool success = login(inputUser, inputPass);
        if (!success) {
            std::cout << "Try again later.\n";
        }
    } 
    else {
        std::cout << "Invalid option. Please restart the program.\n";
    }

    return 0;
}
