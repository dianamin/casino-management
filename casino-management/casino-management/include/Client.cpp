//
//  Client.cpp
//  casino-management
//
//  Created by Diana Ghinea on 22/05/16.
//  Copyright © 2016 Diana Ghinea. All rights reserved.
//

#include "Client.h"


std :: ostream& operator<<(std :: ostream& os, const Client& client)
{
    os << client.id << " " << client.name;
    
    return os;
}

void Client :: set_name(std :: string given_name) {
    name = given_name;
}

std :: string Client :: get_name() const {
    return name;
}

void Client :: play_game(Game game) {
    bill.add_expenditure(game.play());
    std :: cout << bill << '\n';
}

int Client :: get_id() const {
    return id;
}