#pragma once
#include "Card.hpp"
#include "Deck.hpp"
#include <vector>
#include <array>
#include <bitset>
#include <assert.h>

constexpr int HAND_SIZE = 8;
constexpr int NUM_SUITS = 4;
constexpr int NUM_CARDS_FOR_FLUSH = 5;

class HAND
{
 //boobies 
    public:

        struct test_result{
            bool success;
            std::vector<Card> result;
            std::array<int, NUM_SUITS> suit_array;
        };
        
        HAND(DECK& deck){
            m_cards = deck.deal_n(HAND_SIZE);
        }
        

        void print_contents(){
            for ( const auto& card : m_cards )
            {
                card.print_card_info();
            }
        }

        test_result get_highest_flush(){
            std::array<int, NUM_SUITS> suit_count = {0};
            std::array<std::bitset<8>, NUM_SUITS> position_bitsets;

            for ( int i = 0; i < m_cards.size(); i++ )
            {
                int suit_value = m_cards[i].get_underlying_suit();
                suit_count[suit_value]++;
                position_bitsets[suit_value].set(i);
            }

            int card_count(0);
            for ( int i = 0; i < NUM_SUITS && (HAND_SIZE - card_count) > NUM_CARDS_FOR_FLUSH; i++ )
            {
                if ( suit_count[i] > NUM_CARDS_FOR_FLUSH ){
                    return test_result{true, return_m_largest(NUM_CARDS_FOR_FLUSH, position_bitsets[i]), suit_count};
                    
                }
                    //todo-remove lowest from results
                else if ( suit_count[i] == NUM_CARDS_FOR_FLUSH )
                {
                    std::vector<Card> result;
                    for ( int j = 0; j < m_cards.size(); j++ )
                    {
                        if ( position_bitsets[i][j] ){
                            result.emplace_back(m_cards[j]);
                        }

                    }
                    return test_result{true, result, suit_count};
                } 
                else {
                    card_count += suit_count[i];
                }      
            }
            return test_result{ false, m_cards, suit_count};
        }

        std::vector<Card> return_m_largest(int m, std::bitset<8>& allowed)
        {
            assert(m <= allowed.count());
            std::vector<Card> result;
            for ( int i = 0; i < m_cards.size(); i++ )
            {
                if ( allowed[i] )
                {
                    result.emplace_back(m_cards[i]);
                }
            }
            std::sort(result.begin(), result.end(), []( const Card& a,  const Card& b){
                return a.get_rank() > b.get_rank();});
            
            result.resize(m);
            return result;
        }
    private:
        std::vector<Card> m_cards;
};
