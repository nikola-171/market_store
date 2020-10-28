#pragma once
#include "IDiscount_card.h"

class Silver_card : public IDiscount_card{
private:
    const unsigned int discount_limit = 300;
    const float initial_discount = 2, higher_discount = 3.5;
    float turnover = 0;
    Client* client = NULL;

public:
    Silver_card();
    Silver_card(Client* client);
    float get_turnover();
    float get_discount_rate(float value_of_purchase);
    void set_turnover(float turnover);
    bool check_if_client_exists();
    ~Silver_card();
};

Silver_card::Silver_card(){}

Silver_card::Silver_card(Client* client) : client(client) {}

float Silver_card::get_discount_rate(float value_of_purchase){
    if(value_of_purchase <= this->discount_limit){
        return this->initial_discount;
    }else{
        return this->higher_discount;
    }
}

void Silver_card::set_turnover(float turnover){
    if(turnover < 0){
        throw Negative_turnover();
    }
    this->turnover = turnover;
}

float Silver_card::get_turnover(){
    return this->turnover;
}

bool Silver_card::check_if_client_exists(){
    if(!this->client){
        return false;
    }
    return true;
}

Silver_card::~Silver_card(){
    if(this->client){
        delete this->client;
    }
}
