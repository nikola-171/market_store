#ifndef NEGATIVE_TURNOVER_H
#define NEGATIVE_TURNOVER_H

#include <exception>


class Negative_turnover : std::exception
{
    public:
         const char* error() const throw(){
        return "NEGATIVE TURNOVER IS NOT ALLOWED.";
    }

    protected:

    private:
};

#endif // NEGATIVE_TURNOVER_H
