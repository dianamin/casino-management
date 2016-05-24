//
//  Drinks.hpp
//  casino-management
//
//  Created by Florin Chirica on 25/05/16.
//  Copyright © 2016 Florin Chirica. All rights reserved.
//

#ifndef Drinks_h
#define Drinks_h

#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

/* apa, sucuri, berika, vodka, stroh etc. */

class Drink_Type {
    protected:
        string type;
    public:
        Drink_Type(string _type) {
            this->type = _type;
        }
    inline bool operator == (const Drink_Type &other) {
        return this->type == other.type;
    }
    friend class Drinks_Manager;
    virtual void show() {
        cout << "Tipul de bautura: " << this->type << "\n";
    }
};

/* Coca-Cola, Stalinskaya, Noroc etc. */

class Brand_Name : public Drink_Type {
    protected:
        string brand_name;
    public:
        Brand_Name(string _type, string _brand_name) : Drink_Type(_type) {
            this->brand_name = _brand_name;
        }
    inline bool operator == (const Brand_Name &other) {
        return this->type == other.type && this->brand_name == other.brand_name;
    }
    friend class Drinks_Manager;
    void show() {
        cout << "   Bauturi ale brandului " << this->brand_name << "\n";
    }
};

/* Coca-Cola 330 ml, Noroc 3L, Stalinskaya 0.7L */

class Drink_Product : public Brand_Name {
    protected:
        int price;
        string quantity;
    public:
        Drink_Product(string _type, string _brand_name, int _price, string _quantity) : Brand_Name(_type, _brand_name) {
            this->price = _price;
            this->quantity = _quantity;
        }
    inline bool operator == (const Drink_Product &other) {
        return this->type == other.type && this->brand_name == other.brand_name && this->price == other.price && this->quantity == other.quantity;
    }
    friend class Drinks_Manager;
    void show() {
        cout << "       Produsul " << this->brand_name << " este disponibil la cantitatea " << this->quantity << " si costa " << this->price << " lei \n";
    }
};

class Drinks_Manager {
private:
    static Drinks_Manager *s_instance;
    vector <Drink_Type> types;
    vector <Brand_Name> brands;
    vector <Drink_Product> products;
    int cntType, cntBrand, cntProduct;
    int kMaximumProducts;
    vector <int> G[50000];
    Drinks_Manager() {
        kMaximumProducts = 10000;
        cntType = 1;
        cntBrand = 1 + kMaximumProducts;
        cntProduct = 1 + 2 * kMaximumProducts;
    }
    template <class T>
    int getId(T foo, vector <T> &vect, bool &fount) {
        fount = 0;
        for (int i = 0; i < vect.size(); ++i)
            if (vect[i] == foo) {
                fount = 1;
                return i;
            }
        vect.push_back(foo);
        return vect.size() - 1;
    }
    void add_product_private(string _type, string _brand_name, int _price, string _quantity) {
        Drink_Type m_type(_type);
        Brand_Name m_brand(_type, _brand_name);
        Drink_Product m_product(_type, _brand_name, _price, _quantity);
        bool fount_type;
        bool fount_brand;
        bool fount_product;
        int id_type = getId(m_type, types, fount_type);
        int id_brand = getId(m_brand, brands, fount_brand);
        int id_product = getId(m_product, products, fount_product);
        if (fount_type == 0) {
            G[0].push_back(id_type + cntType);
        }
        if (fount_brand == 0) {
            G[id_type + cntType].push_back(id_brand + cntBrand);
        }
        if (fount_product == 0) {
            G[id_brand + cntBrand].push_back(id_product + cntProduct);
        }
    }
    void do_polimorfism(Drink_Type *foo) {
        foo -> show();
    }
    void dfs(int nod) {
        if (nod > 0) {
            if (nod >= cntProduct) {
                do_polimorfism(&products[nod - cntProduct]);
                cout << "       Pentru a cumpara, comandati produsul cu id-ul egal cu " << nod - cntProduct << "\n";
            }
            else if (nod >= cntBrand)
                do_polimorfism(&brands[nod - cntBrand]);
            else do_polimorfism(&types[nod - cntType]);
        }
        vector <int> :: iterator it;
        for (it = G[nod].begin(); it != G[nod].end(); ++it)
            dfs(*it);
    }
public:
    static Drinks_Manager *instance() {
        if (!s_instance)
            s_instance = new Drinks_Manager;
        return s_instance;
    }
    Drink_Product get_product(int id) {
        return products[id];
    }
    void add_product(string _type, string _brand_name, int _price, string _quantity) {
        add_product_private(_type, _brand_name, _price, _quantity);
    }
    void show_menu() {
        dfs(0);
    }
    bool valid_id(int id) {
        if (id < 0)
            return 0;
        return id >= products.size() ? 0 : 1;
    }
};




#endif /* Drinks_h */
