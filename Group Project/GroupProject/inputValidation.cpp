/*********************************************************************
 ** Author: Hao Liu
 ** Date: 4/14/2017
 ** Description: This is the implementation file of the 
 input_validation functions.
 *********************************************************************/

#include <iostream>
#include <limits>
#include "inputValidation.hpp"
using namespace std;

/*********************************************************************
 ** Author: Hao Liu
 ** Date: 4/14/2017
 ** Description: This function gets and validate input as int.
 The function checks to make sure that the input is an integer.
 It prevents the user from entering a character, string, float, or an
 integer followed by some other characters (such as '12a').
 
 I described my implementation in this Stack Overflow question:
 http://stackoverflow.com/questions/40119366/how-to-check-if-the-input-number-integer-not-float/43306071#43306071
 (See answer by Anthony L.)
 *********************************************************************/
void get_int_input_and_validate(int &int_variable) {
    while (!(cin >> int_variable)
           || cin.get() != '\n') {
        cout << "Please enter an integer:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

/*********************************************************************
 ** Author: Hao Liu
 ** Date: 4/14/2017
 ** Description: This function gets and validate input as int.
 It further ensures the int input is larger than or equal to a minimum
 value, which is specified by the user with an int parameter.
 *********************************************************************/
void get_int_input_and_validate_min(int &int_variable, int min) {
    while (!(cin >> int_variable)
           || int_variable < min
           || cin.get() != '\n') {
        cout << "Please enter an integer larger than or equal to "
             << min << ":" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

/*********************************************************************
 ** Author: Hao Liu
 ** Date: 4/14/2017
 ** Description: This function gets and validate input as int.
 It further ensures the int input is smaller than or equal to a maximum
 value, which is specified by the user with an int parameter.
 *********************************************************************/
void get_int_input_and_validate_max(int &int_variable, int max) {
    while (!(cin >> int_variable)
           || int_variable > max
           || cin.get() != '\n') {
        cout << "Please enter an integer smaller than or equal to "
        << max << ":" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

/*********************************************************************
 ** Author: Hao Liu
 ** Date: 4/14/2017
 ** Description: This function gets and validate input as int. 
 It further ensures the int input is within a range (inclusive),
 which is specified by the user with two int parameters.
 *********************************************************************/
void get_int_input_and_validate_range(int &int_variable,
                                      int min,
                                      int max) {
    // If the cin cannot be stored in an int
    while (!(cin >> int_variable)
           
           // if out of bound
           || (int_variable > max || int_variable < min)
           
           // If, for example, a float is entered
           || cin.get() != '\n'
           ) {
        cout << "Please enter an integer between "
        << min << " and " << max << ":" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

/*********************************************************************
 ** Author: Hao Liu
 ** Date: 4/14/2017
 ** Description: This function gets and validate input as char.
 *********************************************************************/
void get_char_input_and_validate(char &char_variable) {
    while (!(cin >> char_variable) || cin.get() != '\n') {
        cout << "Please enter a character:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

/*********************************************************************
 ** Author: Hao Liu
 ** Date: 4/28/2017
 ** Description: This function gets and validate input as float.
 *********************************************************************/
void get_float_input_and_validate(float &float_input) {
    while (!(cin >> float_input)
           || cin.get() != '\n') {
        cout << "Please enter a floating point number:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


/*********************************************************************
 ** Author: Hao Liu
 ** Date: 4/28/2017
 ** Description: This function gets and validate input as either the
 character Y or N.
 *********************************************************************/
void get_y_n_input_and_validate(char &char_input) {
    while (!(cin >> char_input)
           || cin.get() != '\n'
           || (char_input != 'y'
               && char_input != 'Y'
               && char_input != 'n'
               && char_input != 'N')
           ) {
        cout << "Please enter y or n:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // Convert it to upper case
    char_input = toupper(char_input);
}

/*********************************************************************
 ** Author: Hao Liu
 ** Date: 5/20/2017
 ** Description: This function gets and validates input as char.
 It further requires that the char must be one of R, r, P, p, S, s,
 E, or e. (r-rock, p-paper, s-scissor, e-exit).
 
 It takes a char variable as its parameter by reference, and stores
 the user provided character in that char variable.
 *********************************************************************/
void get_tool_type_and_validate(char &char_variable) {
    while (!(cin >> char_variable) // If input is not char
           ||                      // OR
           
           // If input is not an accepted character
           (char_variable != 'R'
            && char_variable != 'r'
            && char_variable != 'P'
            && char_variable != 'p'
            && char_variable != 'S'
            && char_variable != 's'
            && char_variable != 'E'
            && char_variable != 'e')
           ||                       // OR
           // If the following character isn't new line
           (cin.get() != '\n')
           ) {
        // Print error on screen
        cout << "Invalid input." << endl;
        cout << "Choose your tool "
             << "(r-rock, p-paper, s-scissor, e-exit): ";
        
        // Clear the input stream
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // Convert the input to an lower case char
    // (In case the user type in 'R' instead of 'r' for example)
    char_variable = tolower(char_variable);
}
