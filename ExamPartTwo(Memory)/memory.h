#pragma once
#include <iostream>


class Memory
{
private:
	int _memorySizeField;  // ������ ����

	char* _memoryField;    // ������� ���������� �������

	bool* _hideMemoryField; // ������� ���������� �������� �������

	int _userMenu;

	/// <summary>
	/// ���������� ���� 
	/// </summary>
	void FillMemoryField();

	/// <summary>
	/// ���������� ���������� ������ ��������� ����
	/// </summary>
	void ShaffLMemoryField();

public:

	/// <summary>
	/// ����������� �� ��������� ��� ���������� �������� ���� ���� (��������� �� ���������)
	/// </summary>
	Memory();

	/// <summary>
	/// �������� �� ���������� �� ��������� �������
	/// </summary>
	/// <param name="userChoise1">���� ������������� ������ ������</param>
	/// <param name="userChoise2">���� ������������� ������ ������</param>
	void StarsSimbolMemoryField(int userChoise1, int userChoise2);

	/// <summary>
	/// ����� ���� � �� �������� ����������
	/// </summary>
	void PrintMemoryField();

	/// <summary>
	/// ����� ��������������� �������� ���� 
	/// </summary>
	void Print();

	/// <summary>
	/// �������� �� ��������� ����
	/// </summary>
	/// <returns> ���������� �������� ��� ������� ��� ������ �������</returns>
	bool CheckEndGame();

	/// <summary>
	/// ���� ����
	/// </summary>
	/// <returns>����� ������� ������ ����</returns>
	int GameMenu();

	/// <summary>
	/// �������� ����
	/// </summary>
	void PlayGame();

	/// <summary>
	/// ���� ��� ������� ��� ������� �������
	/// </summary>
	void SoundWin();
};



