#ifndef MARKET_STORE_H
#define MARKET_STORE_H

#include "IDiscount_card.h"


class Market_store
{
    public:
Market_store(const Market_store& make_copy) = delete;
    Market_store(const Market_store&& make_copy) = delete;
    Market_store& operator=(const Market_store& make_copy) = delete;
    Market_store& operator=(const Market_store&& make_copy) = delete;

    static Market_store* get_instance(){
        if(!market){
            market = new Market_store();
        }
        return market;
    }

    void make_purchase(float value_of_purchase, IDiscount_card* card);
    ~Market_store();

    protected:

    private:
        static Market_store* market;
    Market_store(){}
};

#endif // MARKET_STORE_H
