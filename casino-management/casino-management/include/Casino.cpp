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

Client Casino :: get_client(int id) {
    int l = (int)clients.size();
    for (int i = 0; i < l; i++)
        if (clients[i].get_id() == id) return clients[i];
    return clients[l];
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