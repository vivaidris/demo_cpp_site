#include "data_manager.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<UserAccount> loadUsersFromFile(const std::string& filename){
    std::ifstream inFile(filename);
    std::vector<UserAccount> users;
    std::string line;

    while(std::getline(inFile, line)){
        std::stringstream ss(line);
        UserAccount user;
        std::getline(ss, user.username, ',');
        std::getline(ss, user.email, ',');
        std::getline(ss, user.password, ',');
        std::getline(ss, user.pin, ',');
        users.push_back(user);
    }

    return users;

}

void saveUsersToFile(const std::vector<UserAccount>& users, const std::string& filename){
    std::ofstream outFile(filename, std::ios::trunc);

    for(const auto& user : users){
        outFile << user.username << ',' << user.email << ',' << user.password << ',' << user.pin << '\n';
    }
}

UserAccount* findUser(std::vector<UserAccount>& users, const std::string& username){
    for (auto& user : users) {
        if (user.username == username) {
            return &user;
        }
    }
    return nullptr;
}