#ifndef SILVER_CARD_H
#define SILVER_CARD_H

#include <IDiscount_card.h>


class Silver_card : public IDiscount_card
{
    public:
        Silver_card();
    Silver_card(Client* client);
    float get_turnover();
    float get_discount_rate(float value_of_purchase);
    void set_turnover(float turnover);
    bool check_if_client_exists();
    ~Silver_card();

    protected:

    private:
           const unsigned int discount_limit = 300;
    const float initial_discount = 2, higher_discount = 3.5;
    float turnover = 0;
    Client* client = NULL;
};

#endif // SILVER_CARD_H
