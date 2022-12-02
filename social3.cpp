#include <iostream>
#include "social3.h"

Social3::Social3() {
    numUsers = 0;
    for(int i = 0; i < 20; i++) {
        for(int q = 0; q < 20; q++) {
            following[i][q] = false;
        }
    }
}

int Social3::findID(std::string usrn) {
    for(int i = 0; i < 20; i++) {
        if(profiles[i].getUsername() == usrn) {
            return i;
        }
    }
    return -1;
}

bool Social3::addUser(std::string usrn, std::string dspn) {
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

bool Social3::follow(std::string usrn1, std::string usrn2) {
    bool u1 = false;
    int id1;
    bool u2 = false;
    int id2;
    for(int i = 0; i < numUsers; i++) {
        if(profiles[i].getUsername() == usrn1) {
            u1 = true;
            id1 = i;
        }
    }
    for(int q = 0; q < numUsers; q++) {
        if(profiles[q].getUsername() == usrn2) {
            u2 = true;
            id2 = q;
        }
    }
    if(u1 && u2) {
        following[id1][id2] = true;
        return true;
    }
    return false;
}

void Social3::printDot() {
    for(int i = 0; i < numUsers; i++) {
        for(int q = 0; q <numUsers; q++) {
            if(following[i][q]) {
                std::cout << profiles[i].getUsername() << " " << profiles[q].getUsername() << " true \n";
            } else {
                std::cout << profiles[i].getUsername() << " " << profiles[q].getUsername() << " false \n";
            }
        }
    }
    std::cout << "digraph { \n";
    for(int i = 0; i < numUsers; i++) {
        std::cout << " \"@" << profiles[i].getUsername() << "\" \n";
    }
    for(int q = 0; q < numUsers; q++) {
        for(int w = 0; w < numUsers; w++) {
            if(following[q][w]) {
                if(profiles[q].getUsername() == profiles[w].getUsername()) {
                } else {
                    std::cout << "\"@" << profiles[q].getUsername() << "\" -> " << "\"@" << profiles[w].getUsername() << "\" \n";
                }
            }
        }
    }
}