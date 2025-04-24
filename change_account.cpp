#include <iostream>
#include "change_account.h"

void changeAccountInfo(UserAccount* user) {
    std::string field;

    std::cout << "What would you like to change?: ";
    std::cin >> field;

    if(field == "username"){
        std::cout << "Enter new username";
        std::cin >> user->username;
    }
    else if(field == "email"){
        std::cout << "Enter new email: ";
        std::cin >> user->email;
    }
    else if(field == "password"){
        std::cout << "Enter new password: ";
        std::cin >> user->password;
    }
    else if(field == "pin"){
        std::cout << "Enter new pin: ";
        std::cin >> user->pin;
    }
    else{
        std::cout << "Please restart.";
    }

    std::cout << "Account updated!" << std::endl;
}