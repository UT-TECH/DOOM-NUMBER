#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include "Main.h"
#include"FDoomNumber.h"

using FString = std::string;


int GameEngine();
void PlayAgain();
void PlayGame();
void intro();
void StartGame();
void help();


FDoomNumber DoomNumber;
int NumberOfPlayers;
int MaxValue;
int input;







int main()
{
	StartGame();
}

int GetMaxValue()
{
	srand(time(NULL));
	MaxValue = (rand() % 150) ;
	if (MaxValue<55)
	{
		MaxValue = MaxValue + 60;
		std::cout << "\nMax Value is = " << MaxValue;
		return MaxValue;

	}
	else
	{
		std::cout << "\nMax Value is = " << MaxValue;

	}

	return MaxValue;

}



int GetNumberOfPlayers()
{

	

	ENumberOfPlayerStatus status = ENumberOfPlayerStatus::NOT_VALID;
	do
	{
		std::cout << "\nSelect Number Of Players (2-4)= ";
		std::cin >> NumberOfPlayers;
		
		ENumberOfPlayerStatus status = DoomNumber.IfNumberOfPlayersInvalid(NumberOfPlayers);
		switch (status)
		{
		case ENumberOfPlayerStatus::NOT_VALID:
			std::cout << "INVALID INPUT" << "\n" << "Please Select a Number Between(2-4)";
			break;
			return NumberOfPlayers;

			default:
			return NumberOfPlayers;
			break;
		}

	} while (status != ENumberOfPlayerStatus::FINE);

}


int GetInput()
{

	EInputStatus status = EInputStatus::INVALID;
	do
	{
	
		std::cin >> input;

		EInputStatus status = DoomNumber.IfInputIsInvalid(input);
		switch (status)
		{
		case EInputStatus::INVALID:
			std::cout << "INVALID INPUT"<<"\n"<<"Please Enter a Number Between(1-9) = ";
			break;
			return input;

	

		default:
			return input;
			break;
		}

	} while (status != EInputStatus::OK);


} 






int GameEngine()
{
	
	GetNumberOfPlayers();

	int players = NumberOfPlayers;
	int MaxNumber = GetMaxValue();
	int round = 0;



	while (MaxNumber <200)
	{
		int turn = 1;
		if (turn==1)
		{
			round = round + 1;
			std::cout << "\n______________________________________________________";
			std::cout << "\n                 ROUND "<<round<<"                      ";
			std::cout << "\n______________________________________________________";


			std::cout << "\n\nPLAYER " << turn << "\nEnter a Number (1-9) = ";
			GetInput();
			MaxNumber = MaxNumber - input;
			std::cout << MaxNumber;
			if (MaxNumber==0)
			{
				std::cout << "\n\nPLAYER " << turn << "is the WINNER! ";
				PlayAgain();
			}if (MaxNumber < 0)
			{
				std::cout << "\n\nGAME OVER! PLAYER " << turn << " IS LOOSER.";
				PlayAgain();

			}


			turn = turn + 1;
		} if (turn == 2)
		{
			std::cout << "\n\nPLAYER " << turn << "\nEnter a Number (1-9) = ";
			GetInput();
			MaxNumber = MaxNumber - input;
			std::cout << MaxNumber;
			if (MaxNumber == 0)
			{
				std::cout << "\n\nPLAYER " << turn << "is the WINNER! ";
				PlayAgain();

			}if (MaxNumber < 0)
			{
				std::cout << "\n\nGAME OVER! PLAYER " << turn << " IS LOOSER.";
				PlayAgain();

			}


			turn = turn + 1;

		} if (turn == 3 && players > 2)
		{
			std::cout << "\n\nPLAYER " << turn << "\nEnter a Number (1-9) = ";
			GetInput();
			MaxNumber = MaxNumber - input;
			std::cout << MaxNumber;
			if (MaxNumber == 0)
			{
				std::cout << "\n\nPLAYER " << turn << "is the WINNER! ";
				PlayAgain();

			}if (MaxNumber < 0)
			{
				std::cout << "\n\nGAME OVER! PLAYER "<<turn<<" IS LOOSER.";
				PlayAgain();

			}


			turn = turn + 1;

		}if (turn == 4 && players > 3)
		{
			std::cout << "\n\nPLAYER "<< turn <<"\nEnter a Number (1-9) = ";
			GetInput();
			MaxNumber = MaxNumber - input;
			std::cout << MaxNumber;
			if (MaxNumber == 0)
			{
				std::cout << "\n\nPLAYER " << turn << "is the WINNER! ";
				PlayAgain();

			}if (MaxNumber < 0)
			{
				std::cout << "\n\nGAME OVER! PLAYER " << turn << " IS LOOSER.";
				PlayAgain();

			}




	

		}
	}
	return 0;
}

void PlayAgain()
{

	std::cout << "\n\nPLAY AGAIN?? y/n";
	FString response = "";
	std::cin >> response;



	if ((response[0] == 'y') || (response[0] == 'Y'))
	{
		main();
	}
	else
	{
		std::cout << "Exiting Game................";
	}


}


void mainmenu()
{
	int selectmenu;
	std::cout << "\n________________________________________________________________________\n";
	std::cout << "\n\t\t     MAIN MENU\n\n";
	std::cout << " ________________________________________________________________________\n";
	std::cout << "\n1-PLAY GAME\n";
	std::cout << "\n2-HELP\n";

	EMainMenuStatus status = EMainMenuStatus::NOT_VALID1;
	do
	{
		std::cout << "\n\nEnter Choice= ";
		std::cin >> selectmenu;

		if (selectmenu == 1)
		{
			PlayGame();

		}if (selectmenu == 2)
		{
			help();
		}

		EMainMenuStatus status = DoomNumber.IfMenuSelectIsValid(selectmenu);
		switch (status)
		{
		case EMainMenuStatus::NOT_VALID1:
			std::cout << "\nINVALID INPUT" << "\n" << "Please Select a Menu Between(1 or 2) ";
			break;
			return ;

		default:
			return;
			break;
		}

	} while (status != EMainMenuStatus::FINE2);


	
}

void help()
{
	std::cout << "\n________________________________________________________________________\n";
	std::cout << "\n\t\t     HELP\n\n";
	std::cout << "\n________________________________________________________________________\n";
	std::cout << "\n1- Select Number of Players.\n";
	std::cout << "\n2- Enter Numbers between(1-9) one by one.\n";
	std::cout << "\n3- One who reach 0 first is the Winner\n";
	PlayAgain();
	
}


void intro()
{
	system("cls");
	std::cout << "\n________________________________________________________________________\n";
	std::cout << "\n\n\t\t     WELCOME TO DOOM NUMBER\n";
	std::cout << " ________________________________________________________________________\n";
	std::cout << std::endl;
	


}

void StartGame()
{
	intro();
	mainmenu();
}

void PlayGame()
{
	
	GameEngine();
}

