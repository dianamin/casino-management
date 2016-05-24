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
#include <iomanip>

#include "Casino.h"
#include "Drinks.h"

class Menu {
private:
    static Menu *s_instance;
    
    
    
    Menu(const Menu &);
    void operator = (Menu const &);
    
    std :: string home_menu = "################################## \n\n\n Boss Casino \n\n\n################################## \n\n\nScrie ajutor pentru a vedea comenzile!\n";
    
    
    std :: map <std :: string, std :: string> commands;
    
    void init() {
        commands["adauga client <name>"] = "Adauga clientul cu numele <name>\nExemplu: adauga client Boss";
        commands["adauga produs <type> <brand> <price> <quantity>"] = "Adauga produsul de tipul <type> de la firma <brand> ce poate fi cumparat cu pretul <price> lei la cantitatea <quantity>\nExemplu: adauga produs suc nestea 10 0.5L";
        commands["sterge client <id>"] = "Sterge clientul cu numele <client>\nExemplu: sterge client 0";
        commands["cauta <name>"] = "Cauta id-ul clientului cu numele <client>\nExemplu: cauta Boss";
        commands["client  <id> joaca <game_name>"] = "Clientul cu id-ul <id> va juca <game_name>\nJocuri disponibile: ruleta, blackjack, pacanea\nExemplu: client 0 joaca ruleta";
        commands["lista clienti"] = "Afiseaza lista clientilor\nPentru a vedea id-ul fiecarui client";
        commands["client <id> nota"] = "Afiseaza nota de plata a clientului cu id-ul <id>\nExemplu: client 0 nota";
        commands["istoric"] = "Afiseaza notele de plata deja achitate";
        commands["statistici <game_name>"] = "Afiseaza statisticile pentru jocul <gamen_name>\nExemplu: statistici ruleta";
        commands["meniu"] = "Afiseaza produsele";
    }
    
    Menu() {
        init();
    }
    
    void search_client(std :: string name) {
        std :: vector <int> ids = Casino :: instance() -> get_id(name);
        if (ids.size() == 0) {
            std :: cout << "Clientul nu exista!\n";
            return;
        }
        if (ids.size() == 1) {
            std :: cout << "Exista un client cu numele " << name << ": ";
        }
        else std :: cout << "Exista " << ids.size() << " clienti cu numele " << name << ": ";
        
        std :: vector <int> :: iterator it;
        for (it = ids.begin(); it != ids.end(); it++) std :: cout << *it << ' ';
        std :: cout << '\n';
    }
    
    void search_product(int id) {
        //Drinks_Manager :: instance() -> do_polimorfism(Drinks_Manager :: instance() -> get_product(id));
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
        std :: this_thread::sleep_for(std::chrono::milliseconds(1000));
        std :: cout << "Comanda nu exista!!!\n";
    }

    
    void show_stats(std :: string game_name) {
        std :: cout << "Probabilitatea de castig: " <<  std :: fixed << std :: setprecision(2) << Casino :: instance() -> get_winning_rate(game_name)<< "\n";
        std :: cout << "Probabilitatea de pierdere: " << std :: fixed << std :: setprecision(2) << Casino :: instance() -> get_losing_rate(game_name)<< "\n";
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
            std :: string a;
            std :: cin >> a;
            if (a == "client") {
                std :: string name;
                std :: cin >> name;
                Casino :: instance() -> add_client(name);
                return;
            }
            if (a == "produs") {
                std :: string type, quantity, brand;
                int price;
                std :: cin  >> type >> brand >> price >> quantity;
                
                Drinks_Manager :: instance() -> add_product(type, brand, price, quantity);
                return;
            }
            
            error();
            return;
        }
        if (c == "sterge") {
            std :: string a;
            int id;
            std :: cin >> a;
            std :: cin >> id;
            Casino :: instance() -> remove_client(id);
            return;
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
                    return;
                }
                
                if (Casino :: instance() -> find_client(id) == false) {
                    std :: cout << "Clientul nu exista!/n";
                    return;
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
        
        if (c == "statistici") {
            std :: string game_name;
            std :: cin >> game_name;
            show_stats(game_name);
            return;
        }
        
        if (c == "cauta") {
            std :: string name;
            std :: cin >> name;
            search_client(name);
            return;
        }
        
        if (c == "meniu") {
            Drinks_Manager :: instance() -> show_menu();
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


