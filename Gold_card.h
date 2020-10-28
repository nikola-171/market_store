#pragma once
#include "IDiscount_card.h"

class Gold_card : public IDiscount_card{
private:
    const float initial_discount = 2;
    float turnover = 0;
    Client* client = NULL;

public:
    Gold_card();
    Gold_card(Client* client);
    float get_turnover();
    float get_discount_rate(float value_of_purchase);
    void set_turnover(float turnover);
    bool check_if_client_exists();
    ~Gold_card();
};

Gold_card::Gold_card(){}

Gold_card::Gold_card(Client* client) : client(client) {};

float Gold_card::get_discount_rate(float value_of_purchase){
    float discount = this->initial_discount;
    while(value_of_purchase >= 100){
        value_of_purchase -= 100;
        discount++;
        if(discount == 10){
            break;
        }
    }
    return discount;
}

bool Gold_card::check_if_client_exists(){
    if(!this->client){
        return false;
    }
    return true;
}

void Gold_card::set_turnover(float turnover){
    if(turnover < 0){
        throw Negative_turnover();
    }
    this->turnover = turnover;
}

float Gold_card::get_turnover(){
    return this->turnover;
}

Gold_card::~Gold_card(){
    if(this->client){
        delete this->client;
    }
}

