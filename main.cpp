#include "IDiscount_card.h"
#include "Market_store.h"
#include "Bronze_card.h"
#include "Silver_card.h"
#include "Gold_card.h"

/*
    IDiscount_card - inteface that all cards inherite;
    There can only be one instance of the Market_store;
    If a card has no client or the turnover is negative then no purchase can be made;
    Any purchase is made only from the market store (make_purchase function) using the card and value of the purchase;

*/

int main()
{
    Market_store* market = Market_store::get_instance();

    IDiscount_card* bronze_1 = new Bronze_card(new Client());

    IDiscount_card* silver_1 = new Silver_card(new Client());

    IDiscount_card* gold_1 = new Gold_card(new Client());

    try{
        bronze_1->set_turnover(0);
        silver_1->set_turnover(600);
        gold_1->set_turnover(1500);

        market->make_purchase(150, bronze_1);
        market->make_purchase(850, silver_1);
        market->make_purchase(1300, gold_1);
    }catch(Negative_turnover e){
        std::cout << e.error() << '\n';
    }catch(No_client_exception e2){
        std::cout << e2.error() << '\n';
    }

    delete market;
    delete bronze_1;
    delete silver_1;
    delete gold_1;

    return 0;
}
