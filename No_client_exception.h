#pragma once
#include <iostream>
#include <exception>

class No_client_exception : public std::exception{
public:
	const char* error() const throw(){
    	return "CARD HAS NO CLIENT ASSIGNED.";
    }
};
