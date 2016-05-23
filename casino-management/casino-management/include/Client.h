//
//  Client.h
//  casino-management
//
//  Created by Diana Ghinea on 22/05/16.
//  Copyright © 2016 Diana Ghinea. All rights reserved.
//

#ifndef Client_h
#define Client_h

#include <iostream>
#include <sstream>
#include <cstring>

#include "Budget.h"
#include "Bill.h"
#include "Game.h"

class Client {
private:
    static int current_client_id;
    int id;
    std :: string name;
    
    Bill bill;
public:
    Client(std :: string given_name) {
        id = Client :: current_client_id++;
        name = given_name;
        bill.set_name(name);
        std :: cout << "Clientul " << name << " (" << id << ") a fost adaugat!";
    }
    
    std :: string get_name() const;
    void set_name(std :: string given_name);
    
    void play_game(Game g);
    
    int get_id() const;
    
    void pay_bill();
    
    friend std :: ostream& operator<<(std :: ostream& os, const Client& client);
};


#endif /* Client_h */
