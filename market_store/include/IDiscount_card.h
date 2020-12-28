#ifndef IDISCOUNT_CARD_H
#define IDISCOUNT_CARD_H

#include "Negative_turnover.h"
#include "No_client_exception.h"
#include "Client.h"

class IDiscount_card
{
    public:
        virtual float get_turnover() = 0;
        virtual float get_discount_rate(float value_of_purchase) = 0;
        virtual void set_turnover(float turnover) = 0;
        virtual bool check_if_client_exists() = 0;
        virtual ~IDiscount_card();
};

#endif // IDISCOUNT_CARD_H
