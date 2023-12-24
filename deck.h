#ifndef DECK_H
#define DECK_H

#include <stdlib.h>
#include "player.h"
#include "card.h"

/*
 * Structure: deck
 * ---------------
 *  An array of 52 cards.
 */
struct deck {
  //struct card list[52];
  int top_card;

  char ranks[13][3];
  char types[4][2];
  char mydeck[52][4];

  char player1[7][4];
  char player2[7][4];
  
  size_t stor;

  char book1[9][4];
  char book2[9][4];
  //struct player yay;
};
struct deck makedeck(struct deck s);
int shuffle();
size_t deck_size(struct deck d);

void getbook1();
void getbook2();

struct deck input1(struct deck m);

struct deck input2(struct deck m);

void view(struct deck f);
/* 
 * Variable: deck_instance
 * -----------------------
 *
 * Go Fish uses a single deck
 */
//typedef struct deck deck_instance; 
struct deck remdeck;
/*
	 * Function: shuffle
 * --------------------
 *  Initializes deck_instance and shuffles it.
 *  Resets the deck if a prior game has been played.
 * 
 *  returns: 0 if no error, and non-zero on error
 */ 
/*
 * Function: deal_player_cards
 * ---------------------------
 *  Deal 7 random cards to the player specified in the function.
 *  Remove the dealt cards from the deck. 
 *
 *  target: pointer to the player to be dealt cards
 *
 *  returns: 0 if no error, and non-zero on error
 */

int deal_player_cards(struct player *target);

void print_list();
/*
 * Function: next_card
 * -------------------
 *  Return a pointer to the top card on the deck.
 *  Removes that card from the deck. 
 *
 *  returns: pointer to the top card on the deck.
 */
int next_card(int yay);

/*
 * Function: size
 * --------------
 *  Return the number of cards left in the current deck.
 *
 *  returns: number of cards left in the deck.
 */
//extern void makedeck();
#endif
