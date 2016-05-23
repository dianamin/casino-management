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
}

void Client :: pay_bill() {
    Budget :: instance() -> modify_value(bill.get_total());
    Budget :: instance() -> add_bill(bill);
}

int Client :: get_id() const {
    return id;
}

void Client :: get_drink(std :: string drink) {
    int price = 30;
    bill.add_expenditure(Expenditure(drink, price));
}
