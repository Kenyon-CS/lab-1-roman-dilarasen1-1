#include "Roman.h"
#include <iostream>
#include <map>

/**
 * Default constructor.
 * Purpose: Initializes an empty Roman numeral object with default values.
 * Preconditions: None.
 * Postconditions: The object has empty Roman numeral and integer values set to 0.
 */
Roman::Roman() : romanNumeral(""), integerValue(0) {}

/**
 * Constructor to initialize with a Roman numeral string.
 * Purpose: Converts a given Roman numeral string to its corresponding integer value.
 * Preconditions: The input string should be a valid Roman numeral.
 * Postconditions: Initializes the Roman numeral object with the provided string and its corresponding integer value.
 * @param numeral The Roman numeral string.
 */
Roman::Roman(const std::string& numeral) : romanNumeral(numeral) {
    integerValue = romanToInt(numeral); // Convert the Roman numeral to an integer
}

/**
 * Constructor to initialize with an integer.
 * Purpose: Converts a given integer to its corresponding Roman numeral representation.
 * Preconditions: The input integer should be between 1 and 3999 (inclusive).
 * Postconditions: Initializes the Roman numeral object with the provided integer and its corresponding Roman numeral representation.
 * @param value The integer value to be converted to a Roman numeral.
 */
Roman::Roman(int value) : integerValue(value) {
    romanNumeral = intToRoman(value);
}

/**
 * Function to print the integer value.
 * Purpose: Outputs the integer value of the Roman numeral object.
 * Preconditions: The object must have a valid Roman numeral.
 * Postconditions: Prints the integer value to the standard output.
 */
void Roman::printDec() const {
    std::cout << "Integer Value: " << integerValue << std::endl;
}

/**
 * Function to print the Roman numeral.
 * Purpose: Outputs the Roman numeral string of the object.
 * Preconditions: The object must have a valid Roman numeral string.
 * Postconditions: Prints the Roman numeral string to the standard output.
 */
void Roman::printRoman() const {
    std::cout << "Roman Numeral: " << romanNumeral << std::endl;
}

/**
 * Getter for the integer value.
 * Purpose: Returns the integer value of the Roman numeral object.
 * Preconditions: The object must have a valid Roman numeral.
 * Postconditions: Returns the integer value corresponding to the Roman numeral.
 * @return The integer value of the Roman numeral object.
 */
int Roman::getInt() const {  // Ensure that 'const' qualifier is present
    return integerValue;
}

/**
 * Getter for the Roman numeral string.
 * Purpose: Returns the Roman numeral string of the object.
 * Preconditions: The object must have a valid Roman numeral string.
 * Postconditions: Returns the Roman numeral string.
 * @return The Roman numeral string of the object.
 */
std::string Roman::getRoman() const {
    return romanNumeral;
}

/**
 * Private utility function to convert a Roman numeral to an integer.
 * Purpose: Converts a given Roman numeral string to its integer representation.
 * Preconditions: The input string should be a valid Roman numeral.
 * Postconditions: Returns the integer value corresponding to the Roman numeral.
 * @param numeral The Roman numeral string to convert.
 * @return The integer value corresponding to the Roman numeral.
 */
int Roman::romanToInt(const std::string& numeral) const {
    // Mapping of Roman numerals to integers
    std::map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int prevValue = 0;
    
    // Traverse the numeral from right to left
    for (int i = numeral.length() - 1; i >= 0; --i) {
        int value = romanMap[numeral[i]];
        
        if (value >= prevValue) {
            result += value;  // Add if greater or equal
        } else {
            result -= value;  // Subtract if smaller
        }

        prevValue = value;
    }

    return result;
}

/**
 * Private utility function to convert an integer to a Roman numeral.
 * Purpose: Converts a given integer to its Roman numeral representation.
 * Preconditions: The input integer should be between 1 and 3999 (inclusive).
 * Postconditions: Returns a string representing the Roman numeral of the input integer.
 * @param value The integer to convert.
 * @return The Roman numeral representation of the integer.
 */
std::string Roman::intToRoman(int value) const {
    // Array of Roman numerals and their corresponding values
    const std::pair<int, std::string> romanValues[] = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

    std::string result;
    
    // Iterate over the Roman numeral values
    for (const auto& [num, roman] : romanValues) {
        while (value >= num) {
            result += roman;
            value -= num;
        }
    }

    return result;
}
