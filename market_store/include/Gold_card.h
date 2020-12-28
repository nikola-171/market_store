#ifndef GOLD_CARD_H
#define GOLD_CARD_H

#include <IDiscount_card.h>


class Gold_card : public IDiscount_card
{
    public:
        Gold_card();
        Gold_card(Client* client);
        float get_turnover();
        float get_discount_rate(float value_of_purchase);
        void set_turnover(float turnover);
        bool check_if_client_exists();
        ~Gold_card();

    private:
        const float initial_discount = 2;
        float turnover = 0;
        Client* client = NULL;
};

#endif // GOLD_CARD_H
