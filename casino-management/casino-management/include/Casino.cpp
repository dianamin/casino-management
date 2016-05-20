//
//  Casino.cpp
//  casino-management
//
//  Created by Diana Ghinea on 20/05/16.
//  Copyright © 2016 Diana Ghinea. All rights reserved.
//

#include "Casino.h"

void Casino :: set_value(int new_value) {
    Casino :: value = new_value;
}

int Casino :: get_value() const {
    return Casino :: value;
}