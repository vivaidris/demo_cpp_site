#include <iostream>
#include "view_account.h"

void viewAccountInfo(const UserAccount* user){
    std::cout << "Username: " << user->username << '\n';
    std::cout << "Email: " << user->email << '\n';
    std::cout << "Password: " << user->password << '\n';
    std::cout << "PIN: " << user->pin << '\n';
}
