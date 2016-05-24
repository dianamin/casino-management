//
//  Bill.h
//  casino-management
//
//  Created by Diana Ghinea on 21/05/16.
//  Copyright © 2016 Diana Ghinea. All rights reserved.
//

#ifndef Bill_h
#define Bill_h

#include <stdio.h>
#include <vector>
#include <sstream>
#include <cstring>

#include "Expenditure.h"
#include "Time.h"

class Bill {
private:
    std :: vector <Expenditure> expenditures;
    std :: string client_name;
    
    std :: string start_time;
    std :: string end_time;
    
public:
    void add_expenditure(Expenditure expenditure);
    void add_expenditure(std :: string name, int price, std :: string details);
    void remove_expenditure(std :: string name, int price, std :: string details);
    void remove_expenditure(Expenditure expenditure);
    int get_total() const;
    
    std :: vector <Expenditure> get_expenditures();
    
    
    void set_name(std :: string given_name);
    std :: string get_client_name() const;
    
    int games_count(std :: string game_name) const;
    int game_wins_count(std :: string game_name) const;
    
    void quit_bill();
    
    
    friend std :: ostream& operator<<(std :: ostream& os, const Bill& bill);

    Bill() {
        start_time = Time :: instance() -> get_time();
        end_time = "";
    }
};


#endif /* Bill_h */
