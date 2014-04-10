#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	int GameStarts(int Chips);
	void GameEnds();
	int DrawCard();
	int PlayerCardValue=0;
   	int DealerCardValue=0;
   	int TotalChips=100;
   	int ChipsPlay=0;

int main()
{	int TotalCards=52;
   	int cards[13]={2,3,4,5,6,7,8,9,10,10,10,10,11};
    int PlayerCardPointer=0;
    int DealerCardPointer=0;
   	int r=0;
   	time_t t;
   	char UserText[20];
   	char ch[10];
   	int PlayerStops=0;
   	int DealerStops=0;

  	
   /* Intializes random number generator */
   srand((unsigned) time(&t)); 
	printf( "You have %d chips. How many Chips do you want to play? ", TotalChips);
	if ( fgets(UserText, sizeof UserText, stdin) )
   {
      int number;
      if ( sscanf(UserText, "%d", &number) == 1 )
      {
			  	  if (number <=0 || TotalChips < number) { printf("You cannot play\n"); exit(0);}
				  TotalChips= TotalChips - number;
				  ChipsPlay=number;
	    printf("You now have %d chips left", TotalChips);			        
      }
   }


   while( TotalCards > 0 && ChipsPlay > 0)
   {
   	if (PlayerStops == 0 ) 
	   {
	   	PlayerCardPointer = DrawCard();
   		printf(" \n Your Card Drawn = %d", cards[PlayerCardPointer]);
   		PlayerCardValue = PlayerCardValue + cards[PlayerCardPointer];
   		if (PlayerCardValue == 21) {printf(" You Win!"); TotalChips = TotalChips + 2* ChipsPlay; printf (" You now have %d chips\n", TotalChips); exit(0);}
   		if (PlayerCardValue > 21) { if (cards[PlayerCardPointer] == 11) {PlayerCardValue = PlayerCardValue - 10;} else {printf(" Dealer Wins!"); exit(0);}}
   		printf(" Your Card Total is %d \n", PlayerCardValue);TotalCards = TotalCards -1; 
		}
   		
	if (DealerStops == 0) {
	DealerCardPointer = DrawCard();
	printf(" Dealer Card drawn = %d", cards[DealerCardPointer]);
	DealerCardValue = DealerCardValue + cards[DealerCardPointer];
	printf (" Dealer Card Total is %d \n", DealerCardValue);TotalCards = TotalCards -1;}
	if (DealerCardValue == 21) {printf(" Dealer Wins!"); exit(0);}
	if ((DealerCardValue >= 17) && (DealerCardValue <21))  {DealerStops=1; if (PlayerStops == 1) {GameEnds();}}
	if (DealerCardValue > 21) {
	if (cards[DealerCardPointer] == 11) {DealerCardValue = DealerCardValue - 10;} else {printf(" You Win!");}; TotalChips = TotalChips + 2* ChipsPlay; printf (" You now have %d chips\n", TotalChips); exit(0);}
	if (PlayerStops == 0) {
	printf ("Press Enter to continue, any other to stop\n");	
   	if ( getchar() == '\n') continue; else {
   	PlayerStops=1;if (DealerStops == 1) {GameEnds();}}}
   }
   if ((DealerStops == 1) && (PlayerStops == 1)) {GameEnds();}
   
}


  	int DrawCard ()
	{
	int r=0;
	r = rand() % 13;
	return r;
	}

	int GameStarts (int Chips)
	{
	Chips = Chips;
	}		

	void GameEnds ()
	{
	char ActualWinner;
	if (DealerCardValue > PlayerCardValue) { printf ("Dealer Wins!"); exit(0);} 
	else if (DealerCardValue < PlayerCardValue) {printf (" You Win!"); TotalChips = TotalChips + 2* ChipsPlay; printf( "You now have % d chips\n", TotalChips); exit(0);}
	else {printf("Its a Draw");exit (0);}
	}
	
	
