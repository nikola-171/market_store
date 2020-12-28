#include "Bronze_card.h"

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
