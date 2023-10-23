/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Burak Yesil
 * Date        : 09-25-2021
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : "I pledge my honor that I have abided by the Stevens Honor                     System."
 ******************************************************************************/
#include <iostream>
#include <cctype>
#include <sstream>

using namespace std;

bool is_all_lowercase(const string &s) {
    // TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] < 97 || s[i] > 122) return false;
    }
    return true;
}


bool all_unique_letters(const string &s) {
    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.
    // You may use only a single int for storage and work with bitwise
    // and bitshifting operators.
    // No credit will be given for other solutions.
    unsigned int vector = 0;
    unsigned int setter;

    for (char const &C: s){
        setter = 1 << (C - 'a');
        if ((vector & setter) != 0) return false;
        else vector = vector | setter;
    }

    return true;
}


int main(int argc, char * const argv[]) {
    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.
    
    string s;
    istringstream iss;

    if(argc != 2){
        cerr << "Usage: " << argv[0] << " <string>" << endl;
        return 1;
    }

    iss.str(argv[1]);
    iss >> s;

    if(!(is_all_lowercase(s))){
        cerr << "Error: String must contain only lowercase letters." << endl;
        return 1;
    }

    //Passed all of the tests

    bool are_unique = all_unique_letters(s);

    if(are_unique){
        cerr << "All letters are unique." << endl; 
    }
    else{
        cerr << "Duplicate letters found." << endl;
    }

    return 0;
}