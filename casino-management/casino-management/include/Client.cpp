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

void Client :: play_game(Game *game) {
    int nr;
    std :: cin >> nr;
    bill.add_expenditure(game->play(nr));
}

void Client :: play_game(std :: string game_name) {
    Game *game;
    
    if (game_name == "ruleta") game = new ruleta;
    if (game_name == "pacanea") game = new pacanea;
    else if (game_name == "blackjack") game = new blackjack;
    else {
        std :: cout << "\n Jocul " << game_name << "nu exista!\n\n";
        return;
    }
    
    play_game(game);
}

void Client :: pay_bill() {
    Budget :: instance() -> modify_value(bill.get_total());
    bill.quit_bill();
    Budget :: instance() -> add_bill(bill);
}

int Client :: get_id() const {
    return id;
}

void Client :: get_drink(std :: string drink) {
    int price = 30;
    bill.add_expenditure(Expenditure(drink, price));
}
