#pragma once
#include<string>
#include "FDoomNumber.h"


using FString = std::string;


struct FInputCount
{
	
	int Player1Input = 0;
	int Player2Input = 0;
	int player3Input = 0;
	int player4Input = 0;
};

enum EInputStatus
{
	INVALID,
	OK,

};

enum ENumberOfPlayerStatus
{
	NOT_VALID,
	FINE,

};
enum EMainMenuStatus
{
	NOT_VALID1,
	FINE2,

};

class FDoomNumber
{
public:
	
	EInputStatus IfInputIsInvalid(int);
	ENumberOfPlayerStatus IfNumberOfPlayersInvalid(int);
	EMainMenuStatus IfMenuSelectIsValid(int);


private:
	
};