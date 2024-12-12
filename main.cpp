#include "Card.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include "Game.hpp"

int main(){

    GAME game;
    game.play_using_fall_method();
    /*bool have_a_flush = false;
    HAND::test_result flush_result;

    while ( !have_a_flush )
    {
        
        DECK deck;
        HAND hand(deck);


        flush_result = hand.get_highest_flush();
        have_a_flush = flush_result.success;

        if ( have_a_flush )
        {
            std:: cout << "contents of original hand is :\n"  ;
            hand.print_contents();
            std::cout << "-------------------\n";
        }

    }
    
    std::cout << "contents of highest detected flush is" << std::endl;
    for ( const auto& card : flush_result.result )
        card.print_card_info();

    const std::array<int, 4> suit_counts = flush_result.suit_array;

    std::cout << "number of Spades : " << suit_counts[0] << std::endl;
    std::cout << "number of Clubs : " << suit_counts[1] << std::endl;
    std::cout << "number of Hearts : " << suit_counts[2] << std::endl;
    std::cout << "number of Diamonds : " << suit_counts[3] << std::endl;
    return 0;*/

}