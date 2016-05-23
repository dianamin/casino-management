//
//  Budget.cpp
//  casino-management
//
//  Created by Diana Ghinea on 20/05/16.
//  Copyright © 2016 Diana Ghinea. All rights reserved.
//

#include "Budget.h"

void Budget :: modify_value(int val) {
    Budget :: value += val;
}

int Budget :: get_value() const {
    return Budget :: value;
}

void Budget :: add_bill(Bill bill) {
    bills.push_back(bill);
}

void Budget :: show_history() {
    int l = (int)bills.size();
    
    std :: cout << "Buget: " << value;
    std :: cout << "\n---------------\n";
    
    for (int i = 0; i < l; i++) {
        std :: cout << bills[i] << "\n---------------\n";
    }
}

int Budget :: games_count(std :: string game_name) const{
    int count = 0;
    
    std :: vector <Bill> :: const_iterator it;
    
    for (it = bills.begin(); it != bills.end(); it++) {
        count += (*it).games_count(game_name);
    }
    
    return count;
}

int Budget :: game_wins_count(std :: string game_name) const{
    int count = 0;
    
    std :: vector <Bill> :: const_iterator it;
    
    for (it = bills.begin(); it != bills.end(); it++) {
        count += (*it).game_wins_count(game_name);
    }
    
    return count;
}