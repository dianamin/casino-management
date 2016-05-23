//
//  Casino.h
//  casino-management
//
//  Created by Diana Ghinea on 20/05/16.
//  Copyright © 2016 Diana Ghinea. All rights reserved.
//

#ifndef Casino_h
#define Casino_h

#include <stdio.h>
#include <vector>
#include <sstream>
#include <cstring>

#include "Budget.h"
#include "Bill.h"
#include "Client.h"


class Casino {
private:
    int value;
    
    
    static Casino *s_instance;
    std :: vector <Bill> payed_bills;
    
    Casino(int val = 0) {
        value = val;
    }
    
    std :: vector <Client> clients;
    
public:
    static Casino *instance() {
        if (!s_instance)
            s_instance = new Casino;
        return s_instance;
    }
    
    void set_value(int new_value);
    int get_value() const;
    
    void add_client(std :: string name);
    std :: vector <Client> :: iterator get_client(int id);
    void remove_client(int id);
    void remove_client(std :: vector <Client> :: iterator it);

    
    void show_clients();
    
    double get_winning_rate(std :: string game_name) const;
};



#endif /* Casino_h */

