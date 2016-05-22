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


std :: ostream& operator<<(std :: ostream& os, const Bill& bill)
{
    os << "Bill:\n";
    int expenditures_count = (int)bill.expenditures.size();
    
    for (int i = 0; i < expenditures_count; i++) {
        os << "#" << (i + 1) << " " << bill.expenditures[i] << '\n';
    }
    
    os << "\n\n";
    
    return os;
}
