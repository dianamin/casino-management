#include <iostream>

#include "Budget.h"
#include "Casino.h"


using namespace std;

Casino *Casino::s_instance = 0;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Casino :: instance()->set_value(1);
    cout << Casino :: instance() -> get_value() << '\n';
    
    std::cout << "Hello, World!\n";
    return 0;
}
