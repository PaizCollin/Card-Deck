#include "deck.h"
#include <cstdio>

void deal_hand(Deck & deck, int ncards) {
    while(ncards--) {
        Card card = deck.deal_card();
        printf("%s ", card_str(card));
    }
    printf("\n");
}

int main() {
    Deck deck;
    printf("There are %d cards remaining\n", deck.remaining());

    deal_hand(deck, 9);
    deal_hand(deck, 5);
    deal_hand(deck, 13);
    deal_hand(deck, 10);

    printf("There are %d cards remaining\n", deck.remaining());
    return 0;

}