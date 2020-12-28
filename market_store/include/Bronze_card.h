#ifndef BRONZE_CARD_H
#define BRONZE_CARD_H

#include <IDiscount_card.h>


class Bronze_card : public IDiscount_card
{
    public:
       Bronze_card(){}
    Bronze_card(Client* client) : client(client) {}
    float get_turnover();
    float get_discount_rate(float value_of_purchase);
    void set_turnover(float turnover);
    bool check_if_client_exists();
    ~Bronze_card();

    private:
        const unsigned int bottom_limit = 100, upper_limit = 300;
        const float initial_discount = 0, low_discount = 1, high_discount = 2.5;
        float turnover = 0;
        Client* client = NULL;
};

#endif // BRONZE_CARD_H
