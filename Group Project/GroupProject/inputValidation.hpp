/*********************************************************************
 ** Author: Hao Liu
 ** Date: 4/14/2017
 ** Description: This is the header file of the input_validation 
 functions.
 *********************************************************************/

#ifndef input_validation_hpp
#define input_validation_hpp

#include <stdio.h>

// This function gets and validate input as int
void get_int_input_and_validate(int &int_variable);

// This is a function that ensures the int input is within a range
// The range is inclusive
void get_int_input_and_validate_range(int &int_variable,
                                      int min,
                                      int max);

// This is a function that ensures the int input is >= a min value
void get_int_input_and_validate_min(int &int_variable, int min);

// This is a function that ensures the int input is <= a max value
void get_int_input_and_validate_max(int &int_variable, int max);

// This is a function gets and validates input as a char
void get_char_input_and_validate(char &char_variable);

// This function gets and validates input as float.
void get_float_input_and_validate(float &float_input);

// This function gets and validates input as y or n
void get_y_n_input_and_validate(char &char_input);

// This function gets and validates input as r, p, s, e
void get_tool_type_and_validate(char &userChoice);

#endif /* input_validation_hpp */
