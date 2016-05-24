//
//  Menu.hpp
//  casino-management
//
//  Created by Diana Ghinea on 24/05/16.
//  Copyright © 2016 Diana Ghinea. All rights reserved.
//

#ifndef Menu_h
#define Menu_h

#include <sstream>
#include <cstring>
#include <iostream>
#include <map>

#include "Casino.h"

class Menu {
private:
    static Menu *s_instance;
    
    
    
    Menu(const Menu &);
    void operator = (Menu const &);
    
    std :: string home_menu = "################################## \n\n\n Boss Casino \n\n\n################################## \n\n\n Scrie ajutor pentru a vedea comenzile!\n";
    
    
    std :: map <std :: string, std :: string> commands;
    
    void init() {
        commands["adauga client <name>"] = "Adauga clientul cu numele <name>\nExemplu: adauga client Boss";
        commands["sterge client <id>"] = "Sterge clientul cu numele <client>\nExemplu: sterge client 0";
        commands["client  <id> joaca <game_name>"] = "Clientul cu id-ul <id> va juca <game_name>\nJocuri disponibile: ruleta, blackjack, pacanea\nExemplu: client 0 joaca ruleta";
        commands["lista clienti"] = "Afiseaza lista clientilor\nPentru a vedea id-ul fiecarui client";
        commands["client <id> nota"] = "Afiseaza nota de plata a clientului cu id-ul <id>\nExemplu: client 0 nota";
        commands["istoric"] = "Afiseaza notele de plata deja achitate";
    }
    
    Menu() {
        init();
    }
    
    void show_help() {
        std :: map <std :: string, std :: string> :: iterator it;
        std :: cout << "\n Ajutor \n";
        for (it = commands.begin(); it != commands.end(); it++) {
            std :: cout << '\n';
            std :: cout << (*it).first << ": \n";
            std :: cout << (*it).second << "\n\n";
        }
    }
    
    void error() {
        std :: cout << "Comanda nu exista!!!\n";
    }

public:
    static Menu *instance() {
        if (!s_instance)
            s_instance = new Menu;
        return s_instance;
    }
    
    
    void get_command() {
        std :: string c;
        std :: cin >> c;
        
        
        if (c == "adauga") {
            std :: string a, name;
            std :: cin >> a;
            std :: cin >> name;
            Casino :: instance() -> add_client(name);
            return;
        }
        if (c == "sterge") {
            std :: string a;
            int id;
            std :: cin >> a;
            std :: cin >> id;
            Casino :: instance() -> remove_client(id);
        }
        if (c == "client") {
            int id;
            std :: string a;
            std :: cin >> id;
            std :: cin >> a;
            if (a == "joaca") {
                std :: string game_name;
                std :: cin >> game_name;
                
                if (game_name != "ruleta" && game_name != "blackjack" && game_name != "pacanea") {
                    std :: cout << "Nu exista jocul!!!\n";
                }
                
                (* Casino :: instance() -> get_client(id)).play_game(game_name);
                return;
            }
            else if (a == "nota") {
                std :: cout << (* Casino :: instance() -> get_client(id)).get_bill() << '\n';
                return;
            }
            error();
            return;
        }
        if (c == "lista") {
            std :: string a;
            std :: cin >> a;
            if (a == "clienti") {
                Casino :: instance() -> show_clients();
                std :: cout << '\n';
                return;
            }
            error();
            return;
        }
        
        if (c == "istoric") {
            Budget :: instance() -> show_history();
            std :: cout << '\n';
            return;
        }
        
        if (c == "ajutor") {
            show_help();
            return;
        }
        
        error();
        return;
    }
    
    void show_home() {
        std :: cout << home_menu;
    }

};

#endif /* Menu_hpp */


