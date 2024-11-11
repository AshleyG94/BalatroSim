#include "Deck.hpp"

std::vector<Card> DECK::deal_n(int n)
{
    std::vector<Card> dealt_cards;
    for ( int i = 0; i < n; i++ ){
        dealt_cards.emplace_back(m_cards.back());
        adjust_counts_for_dealt_card(m_cards.back());
        m_cards.pop_back();
    }

    return dealt_cards;
}

void DECK::adjust_counts_for_dealt_card(const Card& card)
{
    const int rank_ref = card.get_underlying_rank();
    const int suit_ref = card.get_underlying_suit();


}