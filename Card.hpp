#pragma once
#include <iostream>
#include <string>

enum class SUIT
{
    SPADE, CLUB, HEART, DIAMOND, END
};

enum class RANK {
    TWO = 0, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING, ACE 
};


//bool operator <(const RANK& a, const RANK& b){ return static_cast<int>(a) < static_cast<int>(b);}
class Card {

    public: 

        Card() : m_suit(SUIT::CLUB), m_rank(RANK::TEN){;};
        Card::Card(SUIT suit, RANK rank) :
        m_suit(suit), m_rank(rank)
        {;};

        void print_card_info() const;
        std::string suit_to_string(SUIT suit) const;
        std::string rank_to_string(RANK rank) const;

        int get_underlying_rank()const { return static_cast<int>(m_rank);} 
        int get_underlying_suit()const {return static_cast<int>(m_suit);} 
        const RANK& get_rank() const {return m_rank;} 
        const SUIT& get_suit() const {return m_suit;}

    private: 

        SUIT m_suit;
        RANK m_rank;

};