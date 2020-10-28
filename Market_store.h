#pragma once
#include "IDiscount_card.h"

class Market_store{
private:
    static Market_store* market;
    Market_store(){}

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
};
Market_store* Market_store::market = NULL;

void Market_store::make_purchase(float value_of_purchase, IDiscount_card* card){
    if(!card->check_if_client_exists()){
        throw No_client_exception();
    }

    float turnover = card->get_turnover();
    if(turnover < 0){
        throw Negative_turnover();
    }

    float discount_rate = card->get_discount_rate(turnover);
    float total = (value_of_purchase * discount_rate) / 100;

    std::cout << "VALUE OF PURCHASE:  $" << value_of_purchase << '\n';
    std::cout << "DISCOUNT RATE:  " << discount_rate << '%' << '\n';
    std::cout << "DISCOUNT:  $" << total << '\n';
    std::cout << "TOTAL:  $" << value_of_purchase - total << '\n';
}

Market_store::~Market_store(){}
