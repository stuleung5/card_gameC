#include <stdio.h>
#include "gofish.h"
#include <string.h>

int main(int args, char *argv[]) {
  printf("Shuffling deck...\n\n");

  struct player* list = NULL;
  //struct deck init;  
  struct deck today; 
  //struct linked_list* listhey = NULL;

  strcpy(remdeck.ranks[0],"2");  strcpy(remdeck.ranks[1],"3");  strcpy(remdeck.ranks[2],"4");
  strcpy(remdeck.ranks[3],"5");  strcpy(remdeck.ranks[4],"6");  strcpy(remdeck.ranks[5],"7");
  strcpy(remdeck.ranks[6],"8");  strcpy(remdeck.ranks[7],"9");  strcpy(remdeck.ranks[8],"10");
  strcpy(remdeck.ranks[9],"J");  strcpy(remdeck.ranks[10],"Q"); strcpy(remdeck.ranks[11],"K");
  strcpy(remdeck.ranks[12],"A");

  strcpy(remdeck.types[0],"C");  strcpy(remdeck.types[1],"S"); strcpy(remdeck.types[2],"H");
  strcpy(remdeck.types[3],"D");

  today = makedeck(remdeck);
  shuffle();
  
  deal_player_cards(list);
  
  int de = 1;
  char swit='1';
  user.book1ct=0;
  computer.book2ct=0;
  while (de==1) {
  switch(swit) {
    case '1':
      print_list();
      getbook1();
      getbook2();
      swit=user_play();
      break;
    case '2':
      print_list();
      getbook1();
      getbook2();
      swit=computer_play();
      break;
    default:
      break;
  }
  }
  return 0;
}
