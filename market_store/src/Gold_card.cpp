#include "Gold_card.h"

Gold_card::Gold_card(){}

Gold_card::Gold_card(Client* client) : client(client) {};

float Gold_card::get_discount_rate(float value_of_purchase){
    float discount = this->initial_discount;
    discount += static_cast<int>(value_of_purchase) / 100;
    discount = std::min(static_cast<float>(10), discount);
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
