#pragma once
#include "IDiscount_card.h"

class Bronze_card : public IDiscount_card{
private:
    const unsigned int bottom_limit = 100, upper_limit = 300;
    const float initial_discount = 0, low_discount = 1, high_discount = 2.5;
    float turnover = 0;
    Client* client = NULL;

public:
    Bronze_card(){}
    Bronze_card(Client* client) : client(client) {}
    float get_turnover();
    float get_discount_rate(float value_of_purchase);
    void set_turnover(float turnover);
    bool check_if_client_exists();
    ~Bronze_card();
};

float Bronze_card::get_discount_rate(float value_of_purchase){
    if(value_of_purchase < this->bottom_limit){
        return this->initial_discount;
    }else if(value_of_purchase >= this->bottom_limit && value_of_purchase <= this->upper_limit){
        return this->low_discount;
    }else{
        return this->high_discount;
    }
}

void Bronze_card::set_turnover(float turnover){
    if(turnover < 0){
        throw Negative_turnover();
    }
    this->turnover = turnover;
}

float Bronze_card::get_turnover(){
    return this->turnover;
}

bool Bronze_card::check_if_client_exists(){
    if(!this->client){
        return false;
    }
    return true;
}

Bronze_card::~Bronze_card(){
    if(this->client){
        delete this->client;
    }
}

