#include "memory_game.h"


MemoryGame::MemoryGame()
{
	 this->_userMenu;

	 this->_userField;

	this->GameMenu();
}

void MemoryGame::GameMenu()
{


	std::cout << "\t\t\t���� ������\n"
		"\t\t     # ������� ����: #\n"
		"\t=======================================================\n"
		"\t||     ��������� ������������ ������� ��������       ||\n"
		"\t||                � ��������� �������                ||\n"
		"\t=======================================================\n"
		"\t|| ����� ������������� �������� ������� ����� ������ ||\n"
		"\t||        �������� ������������ �������              ||\n"
		"\t=======================================================\n";

	setlocale(0, "C");
	std::cout << char(218) << char(196) << char(194) << char(196)
		<< char(194) << char(196) << char(194) << char(196) << char(191);

	std::cout << std::endl;

	for (int kk = 3, ii = 0; ii < 8; ii++)
	{
		if (ii % 4 == 0 && ii != 0)
		{
			std::cout << std::endl << char(195) << char(196) << char(197) << char(196)
				<< char(197) << char(196) << char(197) << char(196) << char(180);

			std::cout << std::endl;

			std::cout << char(179) << ii + 1;
		}

		else if (ii == kk)
		{
			std::cout << char(179) << ii + 1 << char(179);
			kk += 4;
		}
		else
		{
			std::cout << char(179) << ii + 1;
		}
	}

	std::cout << std::endl;

	std::cout << char(192) << char(196) << char(193) << char(196) << char(193) << char(196)
		<< char(193) << char(196) << char(217);

	setlocale(0, "");

	std::cout << std::endl;

	std::cout << "������� ���� ����:\n"
		"1. ���� �  �������� ���� 4 * 1\n"
		"2. ���� �  �������� ���� 4 * 2\n"
		"3. ���� �  �������� ���� 4 * 3\n"
		"4. �����\n";
	
}

int MemoryGame::EnteredGameMenu()
{
	std::cin >> this->_userMenu;

	while (this->_userMenu < 1 || this->_userMenu > 4)
	{
		std::cout << "������ ����� ������ ����! ���������� ��� ���\n";
		std::cin >> this->_userMenu;
	}

	return this->_userMenu;
}

int MemoryGame::ChoiseUserField()
{
	EnteredGameMenu();
	this->_userField = 0;

	switch (this->_userMenu)
	{
	case 1:
		this->_userField = 4;

		break;

	case 2:
		this->_userField = 8;

		break;

	case 3:
		this->_userField = 12;

		break;
	}

	return this->_userField;
}
