//Name:-Harsh Shaileshkumar Patel
// Project: Milestone-4

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#pragma once
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds
{
    extern bool debug; 

    int getTime(); 
    int getInt(const char* prompt = nullptr);
    int getInt(
        int min,   
        int max,  
        const char* prompt = nullptr,  
        const char* errorMessage = nullptr, 
        bool showRangeAtError = true    
    );
    char* getcstr(
        const char* prompt = nullptr,   
        std::istream& istr = std::cin,  
        char delimiter = '\n'   
    );
}
#endif 

