//
//  Casino.cpp
//  casino-management
//
//  Created by Diana Ghinea on 20/05/16.
//  Copyright © 2016 Diana Ghinea. All rights reserved.
//

#include "Casino.h"

void Casino :: set_value(int new_value) {
    Casino :: value = new_value;
}

int Casino :: get_value() const {
    return Casino :: value;
}


void Casino :: add_client(std :: string name) {
    clients.push_back(Client(name));
}

std :: vector <Client> :: iterator Casino :: get_client(int id) {
    std :: vector <Client> :: iterator it;

    for (it = clients.begin(); it != clients.end(); it++) {
        if ((*it).get_id() != id) continue;
        return it;
    }
    return clients.end();
}

void Casino :: remove_client(int id) {
    std :: vector <Client> :: iterator it;
    
    for (it = clients.begin(); it != clients.end(); it++) {
        if ((*it).get_id() != id) continue;
        (*it).pay_bill();
        clients.erase(it);
        return;
    }
}

void Casino :: show_clients() {
    std :: vector <Client> :: iterator it;
    
    for (it = clients.begin(); it != clients.end(); it++) {
        std :: cout << (*it) << '\n';
    }
}