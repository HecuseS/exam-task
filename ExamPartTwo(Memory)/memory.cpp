#include "memory.h"
#include <Windows.h>


void Memory::FillMemoryField()
{
	int arrayNumber = 1;

	for (int ii = 0; ii < this->_memorySizeField; ii += 2, arrayNumber++)
	{
		this->_memoryField[ii] = arrayNumber;

		this->_memoryField[ii + 1] = arrayNumber;

		this->_hideMemoryField[ii] = false;
	}
}

void Memory::ShaffLMemoryField()
{
	for (int ii = 0; ii < this->_memorySizeField - 1; ii++)
	{
		ii = rand() % (_memorySizeField - 1);

		int temp = this->_memoryField[ii];

		this->_memoryField[ii] = this->_memoryField[ii + 1];

		this->_memoryField[ii + 1] = temp;
	}
}


Memory::Memory()
{
	this->_memorySizeField = GameMenu();

	this->_memoryField = new char[this->_memorySizeField]();

	this->_hideMemoryField = new bool[this->_memorySizeField]();

	this->FillMemoryField();

	this->ShaffLMemoryField();


}

void Memory::StarsSimbolMemoryField(int userChoise1, int userChoise2)
{
	if (userChoise1 >= 0 && userChoise1 < this->_memorySizeField && userChoise2 >= 0 &&
		userChoise2 < this->_memorySizeField && this->_memoryField[userChoise1] == this->_memoryField[userChoise2])
	{
		this->_hideMemoryField[userChoise1] = true;

		this->_hideMemoryField[userChoise2] = true;

		this->SoundWin();
	}
	else
	{
		Beep(196, 1000);
	}
}




void Memory::PrintMemoryField()
{
	std::cout << char(218) << char(196) << char(194) << char(196)
		<< char(194) << char(196) << char(194) << char(196) << char(191);

	std::cout << std::endl;

	for (int kk = 3, ii = 0; ii < this->_memorySizeField; ii++)
	{
		if (ii % 4 == 0 && ii != 0)
		{
			std::cout << std::endl << char(195) << char(196) << char(197) << char(196)
				<< char(197) << char(196) << char(197) << char(196) << char(180);

			std::cout << std::endl;

			std::cout << char(179) << this->_memoryField[ii];
		}

		else if (ii == kk)
		{
			std::cout << char(179) << this->_memoryField[ii] << char(179);
			kk += 4;
		}
		else
		{
			std::cout << char(179) << this->_memoryField[ii];
		}
	}

	std::cout << std::endl;

	std::cout << char(192) << char(196) << char(193) << char(196) << char(193) << char(196)
		<< char(193) << char(196) << char(217);
}

void Memory::Print()
{
	std::cout << char(218) << char(196) << char(194) << char(196)
		<< char(194) << char(196) << char(194) << char(196) << char(191);

	std::cout << std::endl;

	for (int kk = 3, ii = 0; ii < this->_memorySizeField; ii++)
	{
		if (this->_hideMemoryField[ii] && ii % 4 == 0 && ii != 0)
		{
			std::cout << std::endl << char(195) << char(196) << char(197) << char(196)
				<< char(197) << char(196) << char(197) << char(196) << char(180);

			std::cout << std::endl;

			std::cout << char(179) << this->_memoryField[ii];

		}

		else if (this->_hideMemoryField[ii] && ii == kk)
		{
			std::cout << char(179) << this->_memoryField[ii] << char(179);
			kk += 4;
		}

		else if (this->_hideMemoryField[ii])
		{
			std::cout << char(179) << this->_memoryField[ii];
		}

		else if (!this->_hideMemoryField[ii] && ii % 4 == 0 && ii != 0)
		{
			std::cout << std::endl << char(195) << char(196) << char(197) << char(196)
				<< char(197) << char(196) << char(197) << char(196) << char(180);

			std::cout << std::endl;

			std::cout << char(179) << '*';
		}

		else if (!this->_hideMemoryField[ii] && ii == kk)
		{
			std::cout << char(179) << '*' << char(179);

			kk += 4;
		}
		else
		{
			std::cout << char(179) << '*';
		}
	}

	std::cout << std::endl;
	std::cout << char(192) << char(196) << char(193) << char(196) << char(193) << char(196)
		<< char(193) << char(196) << char(217);
}

bool Memory::CheckEndGame()
{
	bool result = false;

	for (int ii = 0; ii < this->_memorySizeField; ii++)
	{
		if (this->_hideMemoryField[ii] == false)
		{
			break;
		}
		else if (ii == this->_memorySizeField - 1)
		{
			result = true;
		}
	}

	return result;
}

int Memory::GameMenu()
{
	std::cout << "\t\t\tИГРА ПАМЯТЬ\n"
		"\t\t     # правила игры: #\n"
		"\t=======================================================\n"
		"\t||     запомните расположение похожих символов       ||\n"
		"\t||                в начальной таблице                ||\n"
		"\t=======================================================\n"
		"\t|| после предложенного варианта введите номер ячейки ||\n"
		"\t||        согласно приведенному примеру              ||\n"
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

	std::cout << "Введите пукт меню:\n"
		"1. Игра с  размером поля 4 * 1\n"
		"2. Игра с  размером поля 4 * 2\n"
		"3. Игра с  размером поля 4 * 3\n"
		"4. Выход\n";

	std::cin >> this->_userMenu;

	while (this->_userMenu < 1 || this->_userMenu > 4)
	{
		std::cout << "Ошибка ввода пункта меню! Попробуйте еще раз\n";
		std::cin >> this->_userMenu;
	}



	switch (this->_userMenu)
	{
	case 1:
		this->_memorySizeField = 4;

		break;

	case 2:
		this->_memorySizeField = 8;

		break;

	case 3:
		this->_memorySizeField = 12;

		break;
	}

	return this->_memorySizeField;
}

void Memory::PlayGame()
{
	unsigned int start_time = clock();

	if (this->_userMenu != 4)
	{
		system("cls");

		int rows = this->_memorySizeField / 4;

		std::cout << " Игра с  размером поля 4  * " << rows << "\n";

		setlocale(0, "C");

		this->PrintMemoryField();

		std::cout << std::endl;

		system("pause");

		system("cls");

		setlocale(0, "");

		setlocale(0, "C");

		int counterSteps = 0;

		while (!this->CheckEndGame())
		{
			setlocale(0, "");

			std::cout << "Введите номера первой и второй ячейки\n";

			setlocale(0, "C");

			this->Print();

			int userChoiseIndex1;

			int userChoiseIndex2;

			setlocale(0, "");

			std::cout << "\nНомер 1й ячейки:  ";

			std::cin >> userChoiseIndex1;

			std::cout << "Номер 2й ячейки:  ";

			std::cin >> userChoiseIndex2;

			setlocale(0, "C");

			while (userChoiseIndex2 == userChoiseIndex1)
			{
				setlocale(0, "");
				std::cout << "Введенное число равно предыдущему!\n"
					"Введите второе число еще раз: ";

				std::cin >> userChoiseIndex2;
				setlocale(0, "C");
			}

			this->StarsSimbolMemoryField(userChoiseIndex1 - 1, userChoiseIndex2 - 1);

			system("cls");

			counterSteps++;
		}

		unsigned int end_time = clock();

		unsigned int search_time = end_time - start_time;

		setlocale(0, "");

		std::cout << "Вы победили за " << counterSteps << " ходов !!!!!!!";

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Времени затрачено " << search_time / 1000 << " секунды\n\n";

		setlocale(0, "C");
	}
	else
		std::cout << "Игра окончена";
}

void Memory::SoundWin()
{
	Beep(659.26, 200);
	Beep(659.26, 200);
	Sleep(200);
	Beep(659.26, 200);
	Sleep(100);
	Beep(523.26, 200);
	Beep(659.26, 200);
	Sleep(200);
	Beep(783.98, 200);
	Sleep(400);
	Beep(391.99, 200);
}

