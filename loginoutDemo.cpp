#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//using these to avoid std:: prefix for common std types
using std::cout;
using std::cin;
using std::string;

//creates a class to hold user data
class UserAccount {
    public:
        string username;
        string email;
        string password;
        string pin;

        //saves user data to an external txt file
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

//allows user to login with their username and password, checks if they are correct
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
            return true;
        }

    }

    cout << "Login failed. Username or password incorrect.";
    return false;
};

//function to either let user register or login to their account
int main() {
    string action;
    string choice;

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
        while(success){
            cout << "Welcome to ABC Website." << '\n';
            cout << "1. View account information." << '\n';
            cout << "2. Rename or change account information." << '\n';
            cout << "3. Logout." << '\n';;
            cout << "Choose an option: ";
            cin >> choice;

            if(choice == "1"){
                //Implement show information 
            }
            else if(choice == "2"){
                //Implement feature to change account information
            }
            else if(choice == "3"){
                cout << "Goodbye!";
                break;
            }
            else{
                cout << "Invalid choice. Try again.";
            }

        }
    } 
    else {
        cout << "Invalid option. Please restart the program.\n";
    }

    return 0;
}
