#ifndef ROMAN_H
#define ROMAN_H

#include <string>

class Roman {
private:
    std::string romanNumeral; //Store Roman numeral as a string
    int integerValue; //Store the corresponding integer value

    //Utility function to convert Roman numeral to integer
    int romanToInt(const std::string& numeral) const;

    //Utility function to convert integer to Roman numeral
    std::string intToRoman(int num) const;

public:
    //Default constructor
    Roman();

    //Constructor to initialize with a Roman numeral string
    Roman(const std::string& numeral);

    //Constructor to initialize with an integer
    Roman(int value);

    // Function to print the integer value
    void printDec() const;

    // Function to print the Roman numeral
    void printRoman() const;

    // Getter for integer value
    int getInt() const;

    // Getter for Roman numeral string
    std::string getRoman() const;
};

#endif
