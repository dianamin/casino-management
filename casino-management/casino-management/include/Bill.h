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

class Bill {
private:
    std :: vector <Expenditure> expenditures;
    
public:
    inline void add_expenditure(Expenditure expenditure) {
        expenditures.push_back(expenditure);
    }
    
    inline void add_expenditure(std :: string name, int price, std :: string details = "") {
        expenditures.push_back(Expenditure(name, price, details));
    }
    
    inline void remove_expenditure(std :: string name, int price, std :: string details = 0) {
        expenditures.push_back(Expenditure(name, (-1) * price, details));
    }
    
    inline void remove_expenditure(Expenditure expenditure) {
        expenditure.price = (-1) * expenditure.price;
        expenditures.push_back(expenditure);
    }
    
    int get_total() const {
        int total = 0;
        int expenditures_count = (int)expenditures.size();
        for (int i = 0; i < expenditures_count; i++)
            total += expenditures[i].price;
        return total;
    }
    
    
    friend std :: ostream& operator<<(std :: ostream& os, const Bill& bill)
    {
        os << "Bill:\n";
        int expenditures_count = (int)bill.expenditures.size();
        
        for (int i = 0; i < expenditures_count; i++) {
            os << "#" << (i + 1) << " " << bill.expenditures[i] << '\n';
        }
        
        os << "\n\n";
        
        return os;
    }

};


#endif /* Bill_h */
