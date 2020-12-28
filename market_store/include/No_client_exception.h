#ifndef NO_CLIENT_EXCEPTION_H
#define NO_CLIENT_EXCEPTION_H
#include <exception>
#include <iostream>

class No_client_exception : std::exception
{
    public:
      const char* error() const throw(){
    	return "CARD HAS NO CLIENT ASSIGNED.";
    }

    protected:

    private:
};

#endif // NO_CLIENT_EXCEPTION_H
