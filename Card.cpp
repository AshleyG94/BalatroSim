#include "Card.hpp"

void Card::print_card_info() const
{
    std::wcout << rank_to_string(m_rank);
    
    std::wcout << suit_to_string(m_suit);
    std::wcout << ' ';
}
    
std::wstring Card::suit_to_string(SUIT suit) const {
    switch (suit) {
        case SUIT::SPADE: return L"\u2660";
        case SUIT::CLUB: return L"\u2663";
        case SUIT::HEART: return L"\u2665";
        case SUIT::DIAMOND: return L"\u2666";
        default: return L"Unknown Suit";
    }
}

// Utility function to convert RANK to string
std::wstring Card::rank_to_string(RANK rank) const {
    switch (rank) {
        case RANK::TWO: return L"2";
        case RANK::THREE: return L"3";
        case RANK::FOUR: return L"4";
        case RANK::FIVE: return L"5";
        case RANK::SIX: return L"6";
        case RANK::SEVEN: return L"7";
        case RANK::EIGHT: return L"8";
        case RANK::NINE: return L"9";
        case RANK::TEN: return L"10";
        case RANK::JACK: return L"J";
        case RANK::QUEEN: return L"Q";
        case RANK::KING: return L"K";
        case RANK::ACE: return L"A";
        default: return L"Unknown Rank";
    }
}

size_t Card::get_rank_score() const{
    switch (m_rank) {
        case RANK::TWO: return 2;
        case RANK::THREE: return 3;
        case RANK::FOUR: return 4;
        case RANK::FIVE: return 5;
        case RANK::SIX: return 6;
        case RANK::SEVEN: return 7;
        case RANK::EIGHT: return 8;
        case RANK::NINE: return 9;
        case RANK::TEN: return 10;
        case RANK::JACK: return 10;
        case RANK::QUEEN: return 10;
        case RANK::KING: return 10;
        case RANK::ACE: return 11;
        default: return 0;
    }
}
