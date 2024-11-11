#pragma once
#include "Card.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

class DECK {
    public:

        DECK(){
         
            m_cards.reserve(52);

            std::vector<RANK> ranks = { RANK::TWO, RANK::THREE, RANK::FOUR, RANK::FIVE, RANK::SIX, RANK::SEVEN, RANK::EIGHT, RANK::NINE, RANK::TEN, RANK::JACK, RANK::QUEEN, RANK::KING, RANK::ACE };
            std::vector<SUIT> suits = { SUIT::SPADE, SUIT::CLUB, SUIT::HEART, SUIT::DIAMOND };
            m_num_ranks = {4,4,4,4,4,4,4,4,4,4,4,4,4};
            m_num_suits = {13,13,13,13};
            for ( const auto& rank : ranks )
            {
                for ( const auto& suit: suits )
                {
                    m_cards.emplace_back(Card(suit, rank));
                }
            }  

            std::random_device rd; 
            std::mt19937 gen(rd()); 
            std::shuffle(m_cards.begin(), m_cards.end(), gen);
        }

        std::vector<Card> deal_n(int n);
        std::vector<int> m_num_ranks;
        std::vector<int> m_num_suits;
        


    private: 
        
        void adjust_counts_for_dealt_card(const Card& card);

        std::vector<Card> m_cards;
};