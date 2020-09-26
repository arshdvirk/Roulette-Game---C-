//Arsh Virk
//Roulette Game

int showInstructions();
int getBetAmount();
int spinWheel();
int makeBet(int* , int* , int* );
int figureWinnings(int, int, int, int, int, int);
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int number, amount, betnumber, eo, dozenbet, bettype, balance, again;
	

	while (1)
	{
		showInstructions();
		amount = getBetAmount();
		bettype = makeBet(&betnumber, &eo, &dozenbet);
		number = spinWheel();
		balance = figureWinnings(amount, number, bettype, betnumber, eo, dozenbet);
		
		
		while (1)
		{
			printf("\n1 for again	2 for quit!\n");
			scanf("%d", & again);
			if (again == 1)
			{
				break;
			}
			else if (again == 2)
			{
				printf("\nThank You For Playing Roulette!");
				exit(0);
			}
			else 
			{
			printf("Invalid Entry\n");
			}
		}
	}
	
	return 0;
}

int showInstructions()
{
	printf("The roulette wheel has the number 0-36 on it\n\nYou can place your bet in one of three ways:\n\n	i. bet on a number (payout is 36 times the bet amount)\n	ii. bet on an odd or even (payout is 2 times the bet)\n	iii. bet on a dozen ~ first 1-12, second 13.24, third 25-36 (payout is 3 times the bet)\n\nThe number zero does not count for odd or even or dozen, but can count as a number bet.");
	
}

int getBetAmount()
{
	int amount;
	printf("\n\nHow much would you like to bet? ");
	scanf("%d", & amount);
	
	return amount;
}

int makeBet(int *betnumber, int *eo, int *dozenbet)
{
	int bettype;
	while(1)
	{
		printf("What type of a bet would you like to place:\n(1 = number, 2 = even/odd, 3 = dozen)\n");
		scanf("%d", & bettype);
		if (bettype >=1 && bettype <=3)
		break;
		printf("\nInvalid Entry\n");
	}
	switch(bettype)
	{
		case 1:
			while(1)
			{
				printf("Which number would you like to bet on? \n");
				scanf("%d",  betnumber);
				if(*betnumber >= 0 && *betnumber <= 36)
				break;
				printf("\nInvalid Number\n");
			}
			break;
		case 2:
			while(1)
			{
				printf("\n1 for Even or 2 for odd: ");
				scanf("%d",  eo);
				if (*eo >=1 && *eo <=2)
				break;
				printf("\nInvalid Entry");
			}
			break;
		case 3:
			while(1)
			{
				printf("\nWhich dozen would you like to bet on?\n1- First 1-12\n2- Second 13-24\n3- Third 25-36\n");
				scanf("%d", dozenbet);
				if (*dozenbet >=1 && *dozenbet <= 3)
				break;
				printf("\nInvalid Entry");
			}	
			break;
		default:
			printf("\nInvalid Bet!");
	}
	
	return bettype;
}

int spinWheel()
{
	int number;
	srand(time(NULL));
	number=1+(rand()%36);
	printf("The number is %d\n", number);
	return number;
}

int figureWinnings(int amount, int number, int bettype, int betnumber, int eo, int dozenbet)
{
	int  winamount=0, x;
	
	if (bettype == 1)
	{
		if (number == betnumber)
		{
			winamount = amount * 36;
			printf("\nYou Won %d", winamount);
		}
		else if (number != betnumber)
		{
			printf("\nYou Lost %d", amount);
		}
	}
	if(bettype == 2)
	{
		
		if (eo == 1)
		{
			if ((number & 1) == 0)
			{
				winamount = amount * 2;
				printf("\nYou Won %d", winamount);
			} 
			else 
			{
				printf("\nYou Lost %d", amount);
			}
		}
		else if (eo == 2)
		{
			if (number % 2)
			{
				winamount = amount * 2;
				printf("\nYou Won %d", winamount);
			}
			else 
			{
				printf("\nYou Lost %d", amount);
			}
		}
	}
	if (bettype == 3)
	{
		
		if (dozenbet == 1)
		{
			if (number >= 1 && number <= 12)
			{
				winamount = amount * 3;
				printf("\nYou Won %d", winamount);
			}
			else 
			{
				printf("\nYou Lost %d", amount);
			}
		}
		else if (dozenbet == 2)
		{
			if (number >= 13 && number <= 24)
			{
				winamount = amount * 3;
				printf("\nYou Won %d", winamount);
			}
			else 
			{
				printf("\nYou Lost %d", amount);
			}
		}
		else if (dozenbet == 3)
		{
			if (number >=25 && number <= 36)
			{
				winamount = amount * 3;
				printf("You Won %d", winamount);
			}
			else 
			{
				printf("You Lost %d", amount);
			}
		}
	} 
	
	return winamount;
}
