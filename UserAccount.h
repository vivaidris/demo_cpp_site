#ifndef USER_ACCOUNT_H
#define USER_ACCOUNT_H

#include <string>
#include <fstream>
#include <iostream>

class UserAccount {
public:
    std::string username;
    std::string email;
    std::string password;
    std::string pin;

    void saveToFile() {
        std::ofstream outFile("user_data.txt", std::ios::app);
        if (outFile.is_open()) {
            outFile << username << ',' << email << ',' << password << ',' << pin << '\n';
            outFile.close();
            std::cout << "User info saved to file" << '\n';
        } else {
            std::cout << "Failed to open file\n";
        }
    }
};

#endif
