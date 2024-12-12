#pragma once
#include <iostream>
#include <string>
#include <vector>

enum class SUIT
{
    SPADE, CLUB, HEART, DIAMOND, UNSPECIFIED
};

enum class RANK {
    TWO = 0, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING, ACE, UNSPECIFIED 
};


//bool operator <(const RANK& a, const RANK& b){ return static_cast<int>(a) < static_cast<int>(b);}
class Card {

    public: 

        Card() : m_suit(SUIT::CLUB), m_rank(RANK::TEN){;};
        Card::Card(SUIT suit, RANK rank) :
        m_suit(suit), m_rank(rank)
        {;};

        inline bool operator == (const Card& other) {
            return ((m_rank == other.get_rank()) && (m_suit == other.get_suit()));
        }

        void print_card_info() const;
        std::wstring suit_to_string(SUIT suit) const;
        std::wstring rank_to_string(RANK rank) const;

        int get_underlying_rank()const { return static_cast<int>(m_rank);} 
        int get_underlying_suit()const {return static_cast<int>(m_suit);} 
        size_t get_rank_score() const;
        
        const RANK& get_rank() const {return m_rank;} 
        const SUIT& get_suit() const {return m_suit;}

        static void print_cards(std::vector<Card>& cards){
            for ( const auto& card : cards )
            {
                card.print_card_info();
            }
            std::cout << std::endl;
        }

    private: 

        SUIT m_suit;
        RANK m_rank;

};

