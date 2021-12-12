#include "deck.h"

Deck::~Deck() {
    delete_deck();
}

void Deck::delete_deck() {
    delete [] _deck;
    _deck = nullptr;
    remaining_cards = 0;
    return;
}

Deck::Deck() {
    cards = default_deck;
    decks = 1;
    srand((unsigned) time(nullptr));
    rand();
    create_deck();
    shuffle_deck();
    return;
}

Deck::Deck(Deck && old) noexcept {
    cards = old.cards;
    decks = old.decks;
    _deck = old._deck;
    remaining_cards = old.remaining_cards;
    old._deck = nullptr;
    old.delete_deck();
    return;
}

void Deck::init_deck() {
    delete_deck();
    if(decks > max_decks) {
        printf("There are too many decks");
    }
    remaining_cards = decks * cards;
    _deck = new Card[remaining_cards];
}

void Deck::create_deck() {
    init_deck();
    uint16_t n = 0;

    for(uint8_t ndeck = 0; ndeck < decks; ndeck++) {
        for(uint8_t nsuit = 0; nsuit < suitcount; nsuit++) {
            for(uint8_t nrank; nrank < rankcount; nrank++) {
                _deck[n].suit = nsuit;
                _deck[n].rank = nrank;
                n++;
            }
        }
    }
}

void Deck::new_deck() {
    create_deck();
    shuffle_deck();
}

void Deck::new_deck(uint8_t n) {
    decks = n;
    create_deck();
    shuffle_deck();
}

void Deck::shuffle_deck() {
    uint16_t n = remaining_cards;
    uint16_t i;

    for(i = 0; i < n; i++) {
        uint16_t j = i + (rand() % (n - i));
        std::swap(_deck[i], _deck[j]);
    }
}

const Card & Deck::deal_card() {
    if(remaining_cards <= 0) {
        printf("The deck is empty");
    }
    return _deck[--remaining_cards];
}

const Card & Deck::get_card(uint16_t index) const {
    if(index >= remaining_cards) {
        printf("Index out of range");
    }
    return _deck[index];
}

uint16_t Deck::deck_size() const {
    return decks * cards;
}

uint16_t Deck::remaining() const {
    return remaining_cards;
}

const Card * Deck::deck() const {
    return _deck;
}

const char * card_str(const Card & x) {
    static char outstr[3] = { 'x', 'x', 0 };
    char & outstr_rank = outstr[0];
    char & outstr_suit = outstr[1];
    
    if(x.rank == 0) outstr_rank = facecards[0];    // rank 0 is A
    else if(x.rank > 8) outstr_rank = facecards[x.rank - 8];   // T J Q K
    else outstr_rank = x.rank + '1';   // numeric cards

    outstr_suit = suitstr[x.suit];
    return (const char *) outstr;
}