#pragma once
#include <iostream>


class Memory
{
private:
	int _memorySizeField;  // размер поля

	char* _memoryField;    // символы заполнения массива

	bool* _hideMemoryField; // символы заполнения скрытого массива

	int _userMenu;

	/// <summary>
	/// Заполнение поля 
	/// </summary>
	void FillMemoryField();

	/// <summary>
	/// Присвоение случайного прядка значениям поля
	/// </summary>
	void ShaffLMemoryField();

public:

	/// <summary>
	/// Конструктор по умолчанию для заполнения значений поля игры (параметры по умолчанию)
	/// </summary>
	Memory();

	/// <summary>
	/// Проверка на совпадение по введенным ячейкам
	/// </summary>
	/// <param name="userChoise1">ввод пользователем номера ячейки</param>
	/// <param name="userChoise2">ввод пользователем номера ячейки</param>
	void StarsSimbolMemoryField(int userChoise1, int userChoise2);

	/// <summary>
	/// Вывод поля с не скрытыми значениями
	/// </summary>
	void PrintMemoryField();

	/// <summary>
	/// Вывод результирующего игрового поля 
	/// </summary>
	void Print();

	/// <summary>
	/// Проверка на окончание игры
	/// </summary>
	/// <returns> Возвращает значение при котором все ячейки открыты</returns>
	bool CheckEndGame();

	/// <summary>
	/// Меню игры
	/// </summary>
	/// <returns>выбор игроком пункта меню</returns>
	int GameMenu();

	/// <summary>
	/// Основная игра
	/// </summary>
	void PlayGame();

	/// <summary>
	/// Звук при котором два символа совпали
	/// </summary>
	void SoundWin();
};



