#include "sort.h"
#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * compare_cards - Compare two card values
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 *
 * Return: Integer less than, equal to, or greater than zero if the first
 * card is found to be less than, equal to, or greater than the second card
 */
int compare_cards(const void *a, const void *b)
{
    const card_t *card1 = (*(const deck_node_t **)a)->card;
    const card_t *card2 = (*(const deck_node_t **)b)->card;

    if (card1->kind != card2->kind)
        return card1->kind - card2->kind;

    return strcmp(card1->value, card2->value);
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 *
 * Description: This function sorts a deck of cards in ascending order
 * based on their values and kinds using the qsort function from the
 * C standard library.
 */
void sort_deck(deck_node_t **deck)
{
    size_t deck_size = 52;
    deck_node_t *current = *deck;
    deck_node_t **deck_array = malloc(deck_size * sizeof(deck_node_t *));
    size_t i = 0;

    while (current != NULL)
    {
        deck_array[i++] = current;
        current = current->next;
    }

    qsort(deck_array, deck_size, sizeof(deck_node_t *), compare_cards);

    for (i = 0; i < deck_size - 1; ++i)
    {
        deck_array[i]->next = deck_array[i + 1];
        deck_array[i + 1]->prev = deck_array[i];
    }

    *deck = deck_array[0];

    deck_array[0]->prev = NULL;

    deck_array[deck_size - 1]->next = NULL;

    free(deck_array);
}
