//
//  Casino.h
//  casino-management
//
//  Created by Diana Ghinea on 20/05/16.
//  Copyright © 2016 Diana Ghinea. All rights reserved.
//

#ifndef Casino_h
#define Casino_h

#include <stdio.h>

#endif /* Casino_h */

class Casino {
private:
    int value;
    static Casino *s_instance;
    
    Casino(int val = 0) {
        value = val;
    }
    
public:
    static Casino *instance() {
        if (!s_instance)
            s_instance = new Casino;
        return s_instance;
    }
    
    void set_value(int new_value);
    int get_value() const;
};


