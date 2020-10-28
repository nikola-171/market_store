#pragma once
#include <exception>

class Negative_turnover : public std::exception{
public:
    const char* error() const throw(){
        return "NEGATIVE TURNOVER IS NOT ALLOWED.";
    }
};
