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