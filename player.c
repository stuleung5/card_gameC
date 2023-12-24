#include "player.h"
#include "card.h"
#include "deck.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char check_add_book(int who, char *hey) {
   if (who==1) {
      struct hand* tempis1 = user.card_list;
      while ( tempis1 != NULL) {
         //printf("%s^^\n",tempis1->payload);
         if (strcmp(hey,tempis1->payload)) {
            user.book[user.book1ct]=*hey;
            //printf("%c",user.book[user.book1ct]);
            user.book1ct++;
         }
         tempis1=tempis1->next;
      }
      //user.book[0]=user.nec[0][0];
   }
   if (who==2) {
      struct hand* tempis2 = computer.card_list;
      while ( tempis2 != NULL) {
         //printf("%s^^\n",tempis2->payload);
         if (strcmp(hey,tempis2->payload)) {
            computer.book[computer.book2ct]=*hey;
            computer.book2ct++;
         }
         tempis2=tempis2->next;
      }
      //computer.book[0]=computer.nec[0][0];
   }
   return 'a';
}
int add_card(int now, char *say) {
   /* Allocate space for new element */
   if (now==1) {
      struct hand* temp;
      temp = (struct hand*)malloc(sizeof(struct hand));
      if (temp == NULL) { return -1; }
      /* Initialize new element */
      temp->payload = say;
      temp->next = user.card_list;
      user.card_list = temp;
   }
   if (now==2) {
      struct hand* temp2;
      temp2 = (struct hand*)malloc(sizeof(struct hand));
      if (temp2 == NULL) { return -1; }
      /* Initialize new element */
      
      temp2->payload = say;
      temp2->next = computer.card_list;
      computer.card_list = temp2;
   }
   return 0;
}

int remove_card(int now2, char *say2, struct hand* nic) {
   //printf("\n%s!!!\n",say2);
   struct hand* iterator = nic;
   struct hand* previous = NULL;
   struct hand* list = NULL;
   if (iterator == NULL) { 
      return 0; 
   }
   while (strcmp(iterator->payload, say2)!=0) {
      //printf("\n%s ### %s \n",iterator->payload,say2); 
	   previous = iterator;               
      iterator = iterator->next;        
	   if (iterator == NULL) {            
         return 0;           
      }            
    }
    if (previous != NULL) {
       previous->next = iterator->next;
    }
    else {
      nic = iterator->next;
      list = nic;
    }
    free(iterator);
   return 1;
}
char user_play() {
    printf("Player 1's turn, enter a Rank: ");
    char Symb[5];
    //char nec[52][5];
    //char nec2[52][5];

    scanf("%[^\n]%*c", Symb);

    struct hand* tempid;
    struct hand* tempid2;
    struct hand* tempid3;

    tempid=user.card_list;
    tempid2=computer.card_list;
    

    int isthere = 0;
    int isthere2 = 0;

    while (tempid != NULL && tempid2 != NULL) {
      char *Test=tempid->payload;
      char *Test2=tempid2->payload;
      tempid3=computer.card_list;
      //printf("%c ((( %c\n",Test2[0],Symb[0]);
      if (Symb[1]!='0') {
         if (Symb[0]==Test[0]) {
            strcpy(user.nec[isthere],Test);
            isthere++;
         }
         tempid=tempid->next;
         if (Symb[0]==Test2[0]) {
            strcpy(computer.nec[isthere2],Test2);
            isthere2++;
         }
         tempid2=tempid2->next;
      }
      if (Symb[1]=='0') {
         if (Symb[0]==Test[0] && Symb[1]==Test[1]) {
            strcpy(user.nec[isthere],Test);
            isthere++;
         }
         tempid=tempid->next;
         if (Symb[0]==Test2[0] && Symb[1]==Test2[1]) {
            strcpy(computer.nec[isthere2],Test2);
            isthere2++;
         }
         tempid2=tempid2->next;
      }
    }
    while (tempid != NULL) {
      char *Test=tempid->payload;
      if (Symb[1]!='0') {
         if (Symb[0]==Test[0]) {
            strcpy(user.nec[isthere],Test);
            isthere++;
         }
      }
      tempid=tempid->next;
    }
    while (tempid2 != NULL) {
      if (Symb[1]!='0') {
         char *Test2=tempid2->payload;
         if (Symb[0]==Test2[0]) {
            strcpy(computer.nec[isthere2],Test2);
            isthere2++;
         }
         tempid2=tempid2->next;
      }
    }
    if (isthere==0) {
      printf("Error - must have at least one card from rank to play\n");
      return '1';
    }
    else if (isthere2==0) {
      printf("- Player 2 has no %s's\n",Symb);
      next_card(1);
      printf("- Go Fish, Player 1 draws %s\n",remdeck.mydeck[remdeck.top_card-1]);
      if (Symb[1]=='0') {
            check_add_book(1,Symb);
         }
         else {
            check_add_book(1,Symb);
         }
      printf("- Player 2's turn\n");
      return '2';
    }
    else {
      printf(" - Player 1 has ");
      for (int j=0; j<isthere; j++) {
         printf("%s ",user.nec[j]);
      }

      printf("\n - Player 2 has ");
      //struct hand* yts=comput;
      for (int j=0; j<isthere2; j++) {
         printf("%s ",computer.nec[j]);
         add_card(1,computer.nec[j]);
         remove_card(2,computer.nec[j],tempid3);
      }
      if (isthere+isthere2==4) {
         if (Symb[1]=='0') {
            check_add_book(1,Symb);
         }
         else {
            check_add_book(1,Symb);
         }
      }
      printf("\n - Player 1 gets another turn\n");
    }
   return '1';
}

char computer_play() {

    char Symb[5];
    char High[52][3];
   
    struct hand* tempid5;
    struct hand* tempid6;
    struct hand* tempid7;

    struct hand* tempid8;
    tempid8=computer.card_list;
    int r=0;

    while (tempid8 != NULL) {
      char *hold=tempid8->payload;
      if (hold[1]=='0') {
         char stri[3];
         stri[0]=hold[0];
         stri[1]=hold[1];
         strcpy(High[r],stri);
      }
      else {
         char stri[3];
         stri[0]=hold[0];
         strcpy(High[r],stri);
      }
      tempid8=tempid8->next;
      r++;
    }
    srand(time(0));
    int choice;
    choice = rand()%r;
    strcpy(Symb,High[choice]);
    printf("Player 2's turn, enter a Rank: %s\n",Symb);
    
    tempid5=user.card_list;
    tempid6=computer.card_list;
    tempid7=user.card_list;
    int isthere3 = 0;
    int isthere4 = 0;
    while (tempid5 != NULL && tempid6 != NULL) {
      char *Test=tempid5->payload;
      char *Test2=tempid6->payload;
      if (Symb[1]!='0') {
         if (Symb[0]==Test[0]) {
            strcpy(user.nec[isthere3],Test);
            isthere3++;
         }
         tempid5=tempid5->next;
         if (Symb[0]==Test2[0]) {
            strcpy(computer.nec[isthere4],Test2);
            isthere4++;
         }
         tempid6=tempid6->next;
      }
      if (Symb[1]=='0') {
         if (Symb[0]==Test[0] && Symb[1]==Test[1]) {

            strcpy(user.nec[isthere3],Test);
            isthere3++;
         }
         tempid5=tempid5->next;
         if (Symb[0]==Test2[0] && Symb[1]==Test2[1]) {
            strcpy(computer.nec[isthere4],Test2);
            isthere4++;
         }
         tempid6=tempid6->next;
      }
    }
   while (tempid5 != NULL) {
      char *Test=tempid5->payload;
      if (Symb[1]!='0') {
         if (Symb[0]==Test[0]) {
            strcpy(user.nec[isthere3],Test);
            isthere3++;
         }
      }
      tempid5=tempid5->next;
    }
    while (tempid6 != NULL) {
      if (Symb[1]!='0') {
         char *Test2=tempid6->payload;
         if (Symb[0]==Test2[0]) {
            strcpy(computer.nec[isthere4],Test2);
            isthere4++;
         }
      }
      tempid6=tempid6->next;
    }
    if (isthere4==0) {
      printf("Error - must have at least one card from rank to play\n");
      return '2';
    }
    else if (isthere3==0) {
      printf("- Player 1 has no %s's\n",Symb);
      next_card(2);
      printf("- Go Fish, Player 2 draws %s\n",remdeck.mydeck[remdeck.top_card-1]);
      if (Symb[1]=='0') {
            check_add_book(1,Symb);
         }
         else {
            check_add_book(1,Symb);
         }
      printf("- Player 1's turn\n");
      return '1';
    }
    else {
      printf("- Player 1 has ");
      for (int j=0; j<isthere3; j++) {
         printf("%s ",user.nec[j]);
         add_card(2,computer.nec[j]);
         remove_card(1,computer.nec[j],tempid7);
      }

      printf("\n - Player 2 has ");
      for (int j=0; j<isthere4; j++) {
         printf("%s ",computer.nec[j]);
      }
      if (isthere3+isthere4==4) {
         if (Symb[1]=='0') {
            check_add_book(2,Symb);
         }
         else {
            check_add_book(2,Symb);
         }
      }
    }
   printf("\n - Player 2 gets another turn\n");
   return '2';
}