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

#include "Expenditure.h"

class Bill {
public:
    std :: vector <Expenditure> Expenditures;
};

#endif /* Bill_h */
