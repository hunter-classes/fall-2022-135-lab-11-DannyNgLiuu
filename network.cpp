#include "network.h"

Network::Network() {
    numUsers = 0;
}

int Network::findID(std::string usrn) {
    for(int i = 0; i < 20; i++) {
        if(profiles[i].getUsername() == usrn) {
            return i;
        }
    }
    return -1;
}

bool Network::addUser(std::string usrn, std::string dspn) {
    for(int i = 0; i < usrn.length(); i++) {
        if(!(isalnum(usrn[i]))) {
            return false;
        }
    }
    if(numUsers < 20) {
        for(int i = 0; i < 20; i++) {
            if(profiles[i].getUsername() == usrn) {
                return false;
            }
        }
        profiles[numUsers] = Profile(usrn, dspn);
        numUsers++;
        return true;
    }
    return false;
}