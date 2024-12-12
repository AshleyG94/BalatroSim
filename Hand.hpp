#pragma once
#include "Card.hpp"
#include "Deck.hpp"
#include <vector>
#include <array>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <assert.h>

constexpr int HAND_SIZE = 8;
constexpr int NUM_SUITS = 4;
constexpr int NUM_CARDS_FOR_FLUSH = 5;
constexpr int MAX_DISCARD_NUM = 5;

struct test_result{
    bool success;
    std::vector<Card> result;
};

class HAND
{
 //boobies 
    public:

        HAND(DECK& deck){
            m_cards = deck.deal_n(HAND_SIZE);
        }
        

        void print_contents(){
            sort_by_suit_presence_then_rank();
            for ( const auto& card : m_cards )
            {
                card.print_card_info();
            }
        }

        void sort_ascending(){
            std::sort(m_cards.begin(), m_cards.end(), []( const Card& a,  const Card& b){
                return a.get_rank() < b.get_rank();});
        }

        void sort_by_suit_presence_then_rank()
        {
            std::array<int, NUM_SUITS> suit_count = {0};
            for ( int i = 0; i < m_cards.size(); i++ )
            {
                int suit_value = m_cards[i].get_underlying_suit();
                suit_count[suit_value]++;
            }

            std::sort(m_cards.begin(), m_cards.end(), [suit_count](const Card& a, const Card& b){
                if ( suit_count[a.get_underlying_suit()] > suit_count[b.get_underlying_suit()] )
                    return true;
                else if ( suit_count[a.get_underlying_suit()] < suit_count[b.get_underlying_suit()])
                    return false;
                else if ( a.get_underlying_suit() != b.get_underlying_suit() )
                    return a.get_underlying_suit() < b.get_underlying_suit(); 
                
                //To do this change this to be based on a deck instead
                if ( a.get_underlying_rank() > b.get_underlying_rank() )
                    return true;
                else
                    return false;
            });

        }

        test_result test_for_flush(){
            test_result flush_test;

            sort_by_suit_presence_then_rank();

            SUIT first_suit = m_cards[0].get_suit();
            int card_num = 1;
            int num_same = 1;

            while ( m_cards[card_num++].get_suit() == first_suit )
                num_same++;

            if ( num_same < NUM_CARDS_FOR_FLUSH )
            {
                flush_test.success = false;
                return flush_test;
            }

            std::vector<Card> result;
            for ( int i = 0; i < NUM_CARDS_FOR_FLUSH; i++ )
            {
                result.push_back(m_cards[i]);
            }
            flush_test.success = true;
            flush_test.result = result;
            return flush_test;
        }

        void discard_for_flush(DECK& deck)
        {
            sort_by_suit_presence_then_rank();
            Card& first_card = m_cards[0];
            discard_until_condition(RANK::UNSPECIFIED, first_card.get_suit(), MAX_DISCARD_NUM, deck);
        }

        void discard_until_condition(const RANK target_rank, const SUIT target_suit, size_t max_discards, DECK& deck)
        {
            size_t num_discarded = 0;
            std::vector<Card> cards_discarded;
            while ( num_discarded < max_discards && ( m_cards.back().get_suit() != target_suit && m_cards.back().get_rank() != target_rank ) )
            {
                cards_discarded.emplace_back(std::move(m_cards.back()));
                m_cards.pop_back();
                num_discarded++;
            }
            std::cout << "\ncards discarded: \n";
            Card::print_cards(cards_discarded);
            std::vector<Card> new_cards = deck.deal_n(num_discarded);
            m_cards.insert(m_cards.end(), new_cards.begin(), new_cards.end());
        }

        size_t score_hand_with_flush(std::vector<Card> flush) {
            return 4 * (35 + std::accumulate(flush.begin(), flush.end(), 0, [](size_t total, const Card& a) {
                return total + a.get_rank_score(); 
            }));
        }

        void play_hand(std::vector<Card>& cards, DECK& deck)
        {
            size_t num_played = 0;
            std::cout << "\nplaying hand :\n";
            Card::print_cards(cards);
            std::cout << "\n";
            for ( const auto& card : cards )
            {
                auto it = std::find(m_cards.begin(), m_cards.end(), card);

                if ( it != m_cards.end() )
                {
                    m_cards.erase(it);
                    num_played++;
                }
            }
            std::vector<Card> new_cards = deck.deal_n(num_played);
            m_cards.insert(m_cards.end(), new_cards.begin(), new_cards.end());  
        }


        const SUIT get_first_card_suit(){ return m_cards[0].get_suit();}
        const SUIT get_last_suit(){ return m_cards.back().get_suit();}

    private:
        std::vector<Card> m_cards;
};
