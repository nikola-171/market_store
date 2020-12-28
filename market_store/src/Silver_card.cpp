#include "Silver_card.h"

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
