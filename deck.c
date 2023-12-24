#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "player.h"
//#include "player.h"

int deal_player_cards(struct player* front) {
   //front->card_list;

   struct hand *list = NULL;
   struct hand *list2 = NULL;

   /* Allocate space for new element */
   remdeck.top_card=0;
   int k=7;
    //fprintf(stdout, "add_to_list: allocate space for new item %d\n", new_item);

   user.card_list = (struct hand*)malloc(sizeof(struct hand));
   if (user.card_list == NULL) { return -1; }
   /* Initialize new element */
   user.card_list->payload = remdeck.mydeck[k-1];
   user.card_list->next = list;
   list = user.card_list;
   remdeck.top_card++;
   while (k-2>=0) {
      user.card_list = (struct hand*)malloc(sizeof(struct hand));
      user.card_list->payload = remdeck.mydeck[k-2];
      user.card_list->next = list;
      list = user.card_list;
      k--;
      remdeck.top_card++;
   }

      /* Allocate space for new element */
   int m=14;
    //fprintf(stdout, "add_to_list: allocate space for new item %d\n", new_item);
   computer.card_list = (struct hand*)malloc(sizeof(struct hand));
   if (computer.card_list == NULL) { return -1; }
   /* Initialize new element */
   
   computer.card_list->payload = remdeck.mydeck[m-1];
   computer.card_list->next = list2;
   list2 = computer.card_list;
   remdeck.top_card++;
   while (m-2>=7) {
      computer.card_list = (struct hand*)malloc(sizeof(struct hand));
      computer.card_list->payload = remdeck.mydeck[m-2];
      computer.card_list->next = list2;
      list2 = computer.card_list;
      m--;
      remdeck.top_card++;
   }
   //int suc=0;
   // ###Use this to remove cards from 1 to new_item.top_card
   //for (int i=0; i<new_item.top_card; i++) {
   //   *(new_item.mydeck[i]) = '\0';
      
   //}
   return 0;
}

void print_list( ) {
     //struct player* temp;
     //user.card_list = list;
     printf("Player 1's Hand: ");
     struct hand* tempi;
     tempi = user.card_list;
     while (tempi != NULL) {
       printf("%s ", tempi->payload);
       tempi = tempi->next;
     }
     printf("\nPlayer 2's Hand: ");
     struct hand* tempi2;
     tempi2 = computer.card_list;
     while (tempi2 != NULL) {
       printf("%s ", tempi2->payload);
       tempi2 = tempi2->next;
     }
     printf("\n");
}

void getbook1() {
   printf("Player 1's Book - ");
   printf("\n");
}

void getbook2() {
   printf("Player 2's Book - ");
   printf("\n");
}



size_t deck_size(struct deck p) {
   int figure = sizeof(p.mydeck)/sizeof(p.mydeck[0]);
   char* hunt = "X";
   for (int i=0; i<figure; i++) {
      if (*p.mydeck[i]==*hunt) {
         figure--;
      }
   }
   size_t answ = figure;
   return answ;
}

int shuffle() {
    srand(time(0));
    int choice;
    if (remdeck.stor<0) {
      return 1;
    }
    for (int flip=0; flip<remdeck.stor; flip++) {
         choice = rand() % remdeck.stor;
         //printf("%d\n",choice);
         // JC has s.mydeck[flip] and 10C as s.mydeck[choice]
         if (*remdeck.mydeck[choice]=='1' && *(remdeck.mydeck[choice]+1)=='0' && *(remdeck.mydeck[flip]+1)!='0') {
            char temp = *remdeck.mydeck[flip];
            char temp2 = *(remdeck.mydeck[flip]+1);
            char temp3 = *(remdeck.mydeck[choice]+2);
            *remdeck.mydeck[flip]=*remdeck.mydeck[choice];
            *remdeck.mydeck[choice]=temp;

            *(remdeck.mydeck[flip]+1)=*(remdeck.mydeck[choice]+1);
            *(remdeck.mydeck[flip]+2)=temp3;

            *(remdeck.mydeck[choice]+1)=temp2;
            *(remdeck.mydeck[choice]+2)='\0';
            
         }
         else if (*remdeck.mydeck[choice]=='1' && *(remdeck.mydeck[choice]+1)=='0' && *(remdeck.mydeck[flip]+1)=='0') {
            char temp = *remdeck.mydeck[flip];
            char temp2 = *(remdeck.mydeck[flip]+1);
            char temp3 = *(remdeck.mydeck[flip]+2);

            *remdeck.mydeck[flip]=*remdeck.mydeck[choice];
            *(remdeck.mydeck[flip]+1)=*(remdeck.mydeck[choice]+1);
            *(remdeck.mydeck[flip]+2)=*(remdeck.mydeck[choice]+2);

            *remdeck.mydeck[choice]=temp;
            *(remdeck.mydeck[choice]+1)=temp2;
            *(remdeck.mydeck[choice]+2)=temp3;
         }
         else if (*remdeck.mydeck[flip]=='1' && *(remdeck.mydeck[flip]+1)=='0' && *(remdeck.mydeck[choice]+1)!='0') {
            char temp = *remdeck.mydeck[flip];
            char temp2 = *(remdeck.mydeck[flip]+1);
            char temp3 = *(remdeck.mydeck[flip]+2);
            *remdeck.mydeck[flip]=*remdeck.mydeck[choice];
            *remdeck.mydeck[choice]=temp;

            *(remdeck.mydeck[flip]+1)=*(remdeck.mydeck[choice]+1);
            *(remdeck.mydeck[flip]+2)='\0';
            *(remdeck.mydeck[choice]+1)=temp2;
            *(remdeck.mydeck[choice]+2)=temp3;
            *(remdeck.mydeck[choice]+3)='\0';
         }
         else {
            char temp = *remdeck.mydeck[flip];
            char temp2 = *(remdeck.mydeck[flip]+1);
            *remdeck.mydeck[flip]=*remdeck.mydeck[choice];
            *remdeck.mydeck[choice]=temp;

            *(remdeck.mydeck[flip]+1)=*(remdeck.mydeck[choice]+1);
            *(remdeck.mydeck[choice]+1)=temp2; 
         }
    }
    return 0;
}


struct deck makedeck(struct deck x) {       
   int counting=0;   
   //printf("%ld",sizeof(deck_instance.ranks)/sizeof(deck_instance.ranks[0]));
   for (int a=0; a<sizeof(remdeck.ranks)/sizeof(remdeck.ranks[0]); a++) {
      for (int b=0; b<sizeof(remdeck.types)/sizeof(remdeck.types[0]); b++) {
          char * concat = (char *) malloc(1 + strlen(remdeck.ranks[a]) + strlen(remdeck.types[b]));
          strcpy(concat, remdeck.ranks[a]);
          strcat(concat, remdeck.types[b]);
          strcpy(remdeck.mydeck[counting],concat);
          counting++;
      }
   }
   remdeck.stor = sizeof(remdeck.mydeck)/sizeof(remdeck.mydeck[0]);
   return remdeck;
}

int next_card(int now) {
   /* Allocate space for new element */
   if (now==1) {
      struct hand* temp;
      temp = (struct hand*)malloc(sizeof(struct hand));
      if (temp == NULL) { return -1; }
      /* Initialize new element */
      //printf("%s!\n",new_item.mydeck[new_item.top_card]);

      temp->payload = remdeck.mydeck[remdeck.top_card];
      temp->next = user.card_list;
      user.card_list = temp;
      remdeck.top_card++;
   }
   if (now==2) {
      struct hand* temp2;
      temp2 = (struct hand*)malloc(sizeof(struct hand));
      if (temp2 == NULL) { return -1; }
      /* Initialize new element */
      
      temp2->payload = remdeck.mydeck[remdeck.top_card];
      temp2->next = computer.card_list;
      computer.card_list = temp2;
      remdeck.top_card++;
   }
   //int suc=0;
   // ###Use this to remove cards from 1 to new_item.top_card
   //for (int i=0; i<new_item.top_card; i++) {
   //   *(new_item.mydeck[i]) = '\0';
      
   //}
   return 0;
}