#include <iostream>
#include <cstring>
#include <algorithm>


#include "Expenditure.h"
#include "Bill.h"
#include "Budget.h"
#include "Casino.h"


using namespace std;

Casino *Casino::s_instance = 0;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Casino :: instance()->set_value(1);
    cout << Casino :: instance() -> get_value() << '\n';
    
    Bill b;
    
    b.add_expenditure("produs 1", 10, "abc");
    b.add_expenditure("produs 2", 20, "bcd");
    b.add_expenditure("produs 3", 30, "cde");
    
    cout << b;
    
    std::cout << "Hello, World!\n";
    return 0;
}
