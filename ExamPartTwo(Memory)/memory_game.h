#pragma once
#include <iostream>


class MemoryGame
{
private:

	int _userMenu;

	int _userField;
	
public:
	 
	MemoryGame();

	void GameMenu();

	int EnteredGameMenu();

	int ChoiseUserField();
};

