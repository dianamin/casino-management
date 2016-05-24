#include <iostream>
#include <cstring>
#include <algorithm>


#include "Expenditure.h"
#include "Bill.h"
#include "Budget.h"
#include "Casino.h"
#include "Game.h"
#include "Time.h"
#include "Menu.h"
#include "Drinks.h"

using namespace std;

int Client :: current_client_id = 0;
Casino *Casino :: s_instance = NULL;
Budget *Budget :: s_instance = NULL;
Time *Time :: s_instance = NULL;


Menu *Menu :: s_instance = NULL;
Drinks_Manager *Drinks_Manager :: s_instance = NULL;

int main(int argc, const char * argv[]) {
    
    Menu :: instance() -> show_home();
    
    while(true) {
        Menu :: instance() -> get_command();
    }
    
    return 0;
}
