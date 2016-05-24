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

void Casino :: remove_client(std :: vector <Client> :: iterator it) {
    clients.erase(it);
}

void Casino :: show_clients() {
    std :: vector <Client> :: iterator it;
    
    std :: cout << "\nClienti:\n";
    
    for (it = clients.begin(); it != clients.end(); it++) {
        std :: cout << (*it) << '\n';
    }
    std :: cout << '\n';
}


double Casino :: get_winning_rate(std :: string game_name) const{
    int games_count = Budget :: instance() -> games_count(game_name);
    int game_wins_count = Budget :: instance() -> game_wins_count(game_name);
    
    return 1.0 * game_wins_count / games_count;
}


double Casino :: get_losing_rate(std :: string game_name) const{
    return 1.0 - get_winning_rate(game_name);
}