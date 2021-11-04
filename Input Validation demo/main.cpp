// This demonstrates how the input_validation functions work

#include <iostream>
#include "input_validation.hpp"
using namespace std;
int main() {
    
    int value;
    cout << "Enter an integer value: ";
    get_int_input_and_validate(value);
    cout << "Here is your value: " << value << endl;
    
    cout << "Enter an integer value larger than or equal to 0: ";
    get_int_input_and_validate_min(value, 0);
    cout << "Here is your value: " << value << endl;
    
    cout << "Enter an integer value smaller than or equal to 10: ";
    get_int_input_and_validate_max(value, 10);
    cout << "Here is your value: " << value << endl;
    
    cout << "Enter an integer value between 0 and 10: ";
    get_int_input_and_validate_range(value, 0, 10);
    cout << "Here is your value: " << value << endl;
    
    return 0;
}
