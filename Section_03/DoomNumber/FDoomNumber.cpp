#include "FDoomNumber.h"

using FString = std::string;


EInputStatus FDoomNumber::IfInputIsInvalid(int input)
{

	if (!(input<10 && input>=0))
	{
		return EInputStatus::INVALID;
	}
	else
	return EInputStatus::OK;


}

ENumberOfPlayerStatus FDoomNumber::IfNumberOfPlayersInvalid(int NumberOfPlayers)
{

	if (!(NumberOfPlayers < 5 && NumberOfPlayers > 1))
	{
		return ENumberOfPlayerStatus::NOT_VALID;
	}
	else
		return ENumberOfPlayerStatus::FINE;
}

EMainMenuStatus FDoomNumber::IfMenuSelectIsValid(int selectmenu)
{
	if (!(selectmenu < 3 && selectmenu > 0))
	{
		return EMainMenuStatus::NOT_VALID1;
	}
	else
		return EMainMenuStatus::FINE2;
}



