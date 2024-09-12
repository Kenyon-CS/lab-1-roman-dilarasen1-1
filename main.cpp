// Dilara Sen, Josh Temple, Luke Wilson
// This program takes an integer value or Roman numeral value and converts it into the other value.
// Each person contributed about equally to the development of the program and we followed the guidelines for Pair Programming.

#include <iostream>
#include <map>
#include <string>
#include "Roman.h"

/**
 * The main function of the program.
 * Purpose: To demonstrate the usage of the Roman class for converting between
 *          Roman numerals and integers, and to display the results.
 * Preconditions: The Roman class must be properly defined with working constructors,
 *                conversion functions, and print methods.
 * Postconditions: Outputs the integer and Roman numeral representations of the given values.
 * @return 0 upon successful execution.
 */
int main() {
    // Creating objects of Roman class
    Roman roman1("XII");  // Initializes with Roman numeral "XII"
    Roman roman2(1987);   // Initializes with integer value 1987

    // Printing values
    roman1.printDec();    // Outputs: Integer Value corresponding to Roman numeral "XII"
    roman1.printRoman();  // Outputs: Roman Numeral "XII"
    
    roman2.printDec();    // Outputs: Integer Value 1987
    roman2.printRoman();  // Outputs: Roman Numeral representation of 1987

    return 0;
}
