#include "Card.hpp"

void Card::print_card_info() const
{
    std::cout << rank_to_string(m_rank) + " of " + suit_to_string(m_suit) + "s" << std::endl ;
}
    
std::string Card::suit_to_string(SUIT suit) const {
    switch (suit) {
        case SUIT::SPADE: return "Spade";
        case SUIT::CLUB: return "Club";
        case SUIT::HEART: return "Heart";
        case SUIT::DIAMOND: return "Diamond";
        default: return "Unknown Suit";
    }
}

// Utility function to convert RANK to string
std::string Card::rank_to_string(RANK rank) const {
    switch (rank) {
        case RANK::TWO: return "Two";
        case RANK::THREE: return "Three";
        case RANK::FOUR: return "Four";
        case RANK::FIVE: return "Five";
        case RANK::SIX: return "Six";
        case RANK::SEVEN: return "Seven";
        case RANK::EIGHT: return "Eight";
        case RANK::NINE: return "Nine";
        case RANK::TEN: return "Ten";
        case RANK::JACK: return "Jack";
        case RANK::QUEEN: return "Queen";
        case RANK::KING: return "King";
        case RANK::ACE: return "Ace";
        default: return "Unknown Rank";
    }
}
