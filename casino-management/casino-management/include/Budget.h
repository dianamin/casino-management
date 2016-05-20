//
//  Budget.h
//  casino-management
//
//  Created by Diana Ghinea on 20/05/16.
//  Copyright © 2016 Diana Ghinea. All rights reserved.
//

#ifndef Budget_h
#define Budget_h

#include <stdio.h>


class Budget {
private:
    int value;
    static Budget *s_instance;
    
    Budget(int val = 0) {
        value = val;
    }
    
public:
    static Budget *instance() {
        if (!s_instance)
            s_instance = new Budget;
        return s_instance;
    }
    
    void modify_value(int val);
    int get_value() const;
};



#endif /* Budget_h */