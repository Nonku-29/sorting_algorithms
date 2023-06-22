#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum suit_e - Enumeration of card suits.
 * @SPADES: Spades suit.
 * @HEARTS: Hearts suit.
 * @CLUBS: Clubs suit.
 * @DIAMONDS: Diamonds suit.
 */
typedef enum suit_e
{
    SPADES,
    HEARTS,
    CLUBS,
    DIAMONDS
} suit_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @suit: Suit of the card
 */
typedef struct card_s
{
    const char *value;
    const suit_t suit;
} card_t;

/**
 * struct deck_node_s - Node in a deck of cards
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node in the deck
 * @next: Pointer to the next node in the deck
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
