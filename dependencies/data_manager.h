#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <iostream>
#include <vector>
#include <sstream>
#include "UserAccount.h"

std::vector<UserAccount> loadUsersFromFile(const std::string& filename);
void saveUsersToFile(const std::vector<UserAccount>& users, const std::string& filename);
UserAccount* findUser(std::vector<UserAccount>& users, const std::string& username);

#endif

