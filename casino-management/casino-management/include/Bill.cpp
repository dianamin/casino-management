//
//  Bill.cpp
//  casino-management
//
//  Created by Diana Ghinea on 21/05/16.
//  Copyright © 2016 Diana Ghinea. All rights reserved.
//

#include "Bill.h"

void Bill :: add_expenditure(Expenditure expenditure) {
    expenditures.push_back(expenditure);
}

void Bill :: add_expenditure(std :: string name, int price, std :: string details) {
    expenditures.push_back(Expenditure(name, price, details));
}

void Bill :: remove_expenditure(std :: string name, int price, std :: string details = "") {
    expenditures.push_back(Expenditure(name, (-1) * price, details));
}

void Bill :: remove_expenditure(Expenditure expenditure) {
    expenditure.price = (-1) * expenditure.price;
    expenditures.push_back(expenditure);
}

int Bill :: get_total() const {
    int total = 0;
    int expenditures_count = (int)expenditures.size();
    for (int i = 0; i < expenditures_count; i++)
        total += expenditures[i].price;
    return total;
}


void Bill :: set_name(std :: string given_name) {
    client_name = given_name;
}

std :: string Bill :: get_client_name() const {
    return client_name;
}

void Bill :: quit_bill() {
    end_time = Time :: instance()->get_time();
}

std :: ostream& operator<<(std :: ostream& os, const Bill& bill)
{
    os << "Nota:\n";
    
    os << "\n" << bill.start_time << " \n";
    
    int expenditures_count = (int)bill.expenditures.size();
    
    for (int i = 0; i < expenditures_count; i++) {
        os << "#" << (i + 1) << " " << bill.expenditures[i] << '\n';
    }
    
    os << "--\nTOTAL: " << bill.get_total() << '\n';
    
    if (bill.end_time.length()) {
        os << "Achitata la: " << bill.end_time << "\n";
    }
    
    
    os << "\n\n";
    
    return os;
}

std :: vector <Expenditure> Bill :: get_expenditures() {
    return expenditures;
}

int Bill :: games_count(std :: string game_name) const {
    std :: vector <Expenditure> :: const_iterator it;
    int count = 0;
    
    for (it = expenditures.begin(); it != expenditures.end(); it++) {
        if ((*it).name == game_name) count++;
    }
    
    return count;
}

int Bill :: game_wins_count(std :: string game_name) const {
    std :: vector <Expenditure> :: const_iterator it;
    int count = 0;
    
    for (it = expenditures.begin(); it != expenditures.end(); it++) {
        if ((*it).name == game_name) count += ((*it).price < 0);
    }
    
    return count;
}
