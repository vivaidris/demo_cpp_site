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
                outFile << "Username: " << username << '\n';
                outFile << "Email: " << email << '\n';
                outFile << "Password: " << password << '\n';
                outFile << "PIN: " << pin << '\n';
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

int main(){
    
    UserAccount user;
    string answer;

    cout << "Welcome to my website!" << '\n';
    cout << "Since you are new, please enter your username: ";
    cin >> user.username;

    cout << "Please enter your email: ";
    cin >> user.email;

    cout << "Please enter your password: ";
    cin >> user.password;

    if(user.password == "password" || user.password == "1234"){
        cout << "Please enter a new password, your previous password was to weak: ";
        cin >> user.password;
    }

    cout << "Would you like to view your current password (Y/N): ";
    cin >> answer;

    if(answer == "Y" || answer == "yes" ){
        cout << user.password << '\n';
    }
    else{}

    cout << "Would you like to change your password before continuing? (Y/N): ";
    cin >> answer;

    if(answer == "Y" || answer == "yes"){
        cout << "Please enter a different password";
        cin >> user.password;

        if(user.password == "password" || user.password == "1234"){
            cout << "Please enter a new password, your previous password was to weak: ";
            cin >> user.password;
        }
    }
    else{}

    cout << "Please enter a two-step verification pin: ";
    cin >> user.pin;

    user.saveToFile();

    cout << "Thank you for signing up to ABC website";

    return 0;
}