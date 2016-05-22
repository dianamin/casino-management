//
//  Expenditure.h
//  casino-management
//
//  Created by Diana Ghinea on 21/05/16.
//  Copyright © 2016 Diana Ghinea. All rights reserved.
//

#ifndef Expenditure_h
#define Expenditure_h

#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>

class Expenditure {
public:
    std :: string name;
    int price;
    int id;
    std :: string details;
    
    Expenditure(std :: string given_name, int given_price, std :: string given_details) {
        name = given_name;
        price = given_price;
        details = given_details;
    }
    
    friend std :: ostream& operator<<(std :: ostream& os, const Expenditure& expenditure)
    {
        os << expenditure.name << ' ' << expenditure.price << " lei\n";
        os << "Detalii: " << expenditure.details;
        return os;
    }

};


#endif /* Expenditure_h */
