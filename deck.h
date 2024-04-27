#ifndef DECK_H
#define DECK_H

typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

#endif /* DECK_H */
