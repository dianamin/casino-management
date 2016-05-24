
#ifndef Game_h
#define Game_h

#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>

#include "Expenditure.h"

class Game {
protected:
    int sum;
    
public:
    
    virtual Expenditure play(int nr) {
        return Expenditure("Random Game", 100, "testing");
    }
    
    virtual void newBet(int b) = 0;
};


class blackjack: public Game {
protected:
    int sum;
    
public:
    Expenditure play(int nr);
    //    return Expenditure("Random Game", 100, "testing");
    
    void newBet(int b);
    
    int getCard();
};

class pacanea: public Game {
protected:
    int sum;
    
public:
    Expenditure play(int nr);
    //   return Expenditure("Random Game", 100, "testing");
    void newBet(int b);
};


#endif /* Game_h */