#include <iostream>
#include <Windows.h>
#include <vector>
#include "Animals.h"
using namespace std;

int main()
{
	int selection;
	HomeZoo zoo;
	do
	{
		system("cls");
		zoo.Show();
		cout << "Zoo menu:\n";
		cout << "1 - Add animal.\n";
		cout << "2 - Add few \"random\" animals.\n";
		cout << "3 - Edit animal.\n";
		cout << "4 - Sell animal.\n";
		cout << "5 - Sell all animals.\n";
		cout << "6 - Save zoo to the file.\n";
		cout << "7 - Load zoo from the file.\n";
		cout << "0 - Exit.\n";
		cout << "Make your selection: ";
		cin >> selection;
		switch (selection)
		{
		case 1:
			zoo.AddAnimal();
			break;
		case 2:
			zoo.AddRandom();
			break;
		case 3:
			zoo.Edit();
			break;
		case 4:
			zoo.Sell();
			break;
		case 5:
			zoo.SellAll();
			break;
		case 6:
			zoo.SaveZoo();
			break;
		case 7:
			zoo.LoadZoo();
			break;
		case 0:
			cout << "Have a nice day.\n";
			break;
		default:
			cout << "Invalid input. Try again.\n";
			system("pause");
			break;
		}
	} while (selection != 0);

	system("pause");
	return 0;
}