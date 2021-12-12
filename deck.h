#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <memory>

constexpr const char * suitstr = "cdhs";
constexpr const char * facecards = "ATJQK";
constexpr uint8_t default_deck = 52;
constexpr uint8_t max_decks = 10;
constexpr uint8_t suitcount = 4;
constexpr uint8_t rankcount = 13;

typedef struct {
    uint8_t suit : 4;
    uint8_t rank : 4;
} Card;

class Deck {
    public:
        Deck();                             // constructor
        Deck(uint8_t n);                    // constructor
        Deck(Deck &&) noexcept;                      // copy constructor
        ~Deck();                            // destructor

        void new_deck();                    // create a new deck
        void new_deck(uint8_t n);           // create a new deck of 52 or more cards
        void shuffle_deck();                // randomly shuffle deck
        const Card & deal_card();           // deals a card, reduces count of remaining cards by 1
        const Card & get_card(uint16_t index) const;        // 
        uint16_t remaining() const;                    // number of cards left in the deck
        uint16_t deck_size() const;                    // size of the deck
        const Card * deck() const;                // returns a pointer to the array of cards

    private:
        uint8_t cards = 0;
        uint8_t decks = 0;
        uint16_t remaining_cards = 0;
        Card * _deck = nullptr;

        void create_deck();
        void delete_deck();
        void init_deck();

};

const char * card_str(const Card &);