#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "dependencies/view_account.h"
#include "dependencies/change_account.h"
#include "dependencies/UserAccount.h"
#include "dependencies/data_manager.h"

//using these to avoid std:: prefix for common std types
using std::cout;
using std::cin;
using std::string;

//function to either let user register or login to their account
int main() {
    string action;
    string choice;
    UserAccount user;

    cout << "Welcome to ABC website!\n";
    cout << "Would you like to (register) or (login)? ";
    cin >> action;

    if (action == "register") {

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
    
        std::vector<UserAccount> users = loadUsersFromFile("user_data.txt");
    
        auto it = std::find_if(users.begin(), users.end(), [&](const UserAccount& u) {
            return u.username == inputUser && u.password == inputPass;
        });
    
        if (it == users.end()) {
            cout << "Login failed. Username or password incorrect. Try again later.\n";
        } else {
            UserAccount& user = *it;
            bool loggedIn = true;
    
            while (loggedIn) {
                cout << "Welcome to ABC Website." << '\n';
                cout << "1. Continue." << '\n';
                cout << "2. Settings." << '\n';
                cout << "3. Logout." << '\n';
                cout << "Choose an option: ";
                cin >> choice;
    
                if(choice == "1"){
                    //Add in continue feature
                }
                else if (choice == "2") {
                    string settingsChoice;
                    bool inSettings = true;
                
                    while (inSettings) {
                        cout << "\n--- Settings ---\n";
                        cout << "1. View account information\n";
                        cout << "2. Change account information\n";
                        cout << "Danger Zone!" << '\n';
                        cout << "3. Delete account\n";
                        cout << "4. Back to main menu\n";
                        cout << "Select an option: ";
                        cin >> settingsChoice;
                
                        if (settingsChoice == "1") {
                            viewAccountInfo(&user);
                        }
                        else if (settingsChoice == "2") {
                            changeAccountInfo(&user);
                        }
                        else if (settingsChoice == "3") {
                            cout << "Are you sure you want to delete your account? (yes/no): ";
                            string confirm;
                            cin >> confirm;
                
                            if (confirm == "yes") {
                                users.erase(std::remove_if(users.begin(), users.end(), [&](const UserAccount& u) {
                                    return u.username == user.username && u.password == user.password;
                                }), users.end());
                
                                saveUsersToFile(users, "user_data.txt");
                                cout << "Account deleted successfully.\n";
                                break; // Exit main loop
                            } else {
                                cout << "Deletion cancelled.\n";
                            }
                        }
                        else if (settingsChoice == "4") {
                            inSettings = false;
                        }
                        else {
                            cout << "Invalid option. Try again.\n";
                        }
                    }
                }
                else if(choice == "3"){
                    cout << "Goodbye!\n";
                    saveUsersToFile(users, "user_data.txt");
                    loggedIn = false;
                }
                else{
                    cout << "Invalid choice. Try again.\n";
                }
            }
        }
    }
}
