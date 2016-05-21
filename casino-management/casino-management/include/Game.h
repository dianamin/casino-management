//
//  Game.h
//  casino-management
//
//  Created by Diana Ghinea on 20/05/16.
//  Copyright © 2016 Diana Ghinea. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>

#include "Expenditure.h"

class Game {
protected:
    
    
public:
    virtual void play() {
        Expenditure e("Random Game", 100, "testing");
    }
};

#endif /* Game_h */
