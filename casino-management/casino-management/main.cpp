#include <iostream>
#include <cstring>
#include <algorithm>


#include "Expenditure.h"
#include "Bill.h"
#include "Budget.h"
#include "Casino.h"
#include "Game.h"

using namespace std;

int Client :: current_client_id = 0;
Casino *Casino :: s_instance = 0;
Budget *Budget :: s_instance = 0;


int main(int argc, const char * argv[]) {

    Casino :: instance() -> set_value(1);
   // cout << Casino :: instance() -> get_value() << '\n';

    Game *g = new blackjack;

    Casino :: instance() -> add_client("Diana");
    Casino :: instance() -> add_client("Elf");
    
    Casino :: instance() -> show_clients();
    
    
    cout << '\n';
    (* Casino :: instance() -> get_client(0)).play_game(g);
    (* Casino :: instance() -> get_client(0)).play_game(g);
    (* Casino :: instance() -> get_client(0)).play_game(g);

    (* Casino :: instance() -> get_client(0)).get_drink("Apa");


    Casino :: instance() -> remove_client(0);


    Budget :: instance() -> show_history();

    return 0;
}
