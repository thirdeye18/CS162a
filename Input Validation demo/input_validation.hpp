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

// This is a function that ensures the int input is within a range (inclusive)
void get_int_input_and_validate_range(int &int_variable, int min, int max);

// This is a function that ensures the int input is >= a min value
void get_int_input_and_validate_min(int &int_variable, int min);

// This is a function that ensures the int input is <= a max value
void get_int_input_and_validate_max(int &int_variable, int max);

// This is a function gets and validates input as a char
void get_char_input_and_validate(char &char_variable);

// This function gets and validates input as direction (N, E, S, W)
void get_direction_input_and_validate(char &char_variable);

// This function gets and validates input as float.
void get_float_input_and_validate(float &float_input);

// This function gets and validates input as y or n
void get_y_n_input_and_validate(char &char_input);

#endif /* input_validation_hpp */
