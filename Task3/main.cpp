#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string command, filename1, filename2;
	char symbol;
	//enum commands { create, print, append, copy, filterDigits };
	while (true)
	{
		//system("cls");
		command = filename1 = filename2 = "";
		cout << "Command promt. Waiting for command." << endl << ">";
		cin >> command;
		if (command == "create")
		{
			cout << "Enter file data:" << endl;
			cin >> command;
			cin.ignore();

			ofstream fout(command);
			if (fout.is_open())
			{
				while (cin.get(symbol))
					fout.put(symbol);
				cin.clear();
				fout.close();
				//cin.ignore('\n');
			}
			else
				cout << "Error opening file." << endl;
		}
		else if (command == "print")
		{
			cin >> command;
			ifstream fin(command);
			if (fin.is_open())
				cout << fin.rdbuf();
		}
		else if (command == "append")
		{
			cin >> command;
			ofstream fout(command, ios::app);
			if (fout.is_open())
			{
				char symbol;
				while (cin.get(symbol))
					//fout.put(symbol);
					fout << symbol;
				cin.clear();
				fout.close();
			}
			else
				cout << "Error opening file." << endl;
		}
		else if (command == "copy")
		{
			cin >> filename1;
			cin >> filename2;
			ifstream fin(filename1);
			ofstream fout(filename2);
			if (fin.is_open() && fout.is_open())
				fout << fin.rdbuf();
			fin.close();
			fout.close();
		}
		else if (command == "filterDigits")
		{
			cin >> filename1;
			cin >> filename2;
			ifstream fin(filename1);
			ofstream fout(filename2);
			while (fin.get(symbol))
				if (!isdigit(symbol))
					fout << symbol;
			fin.close();
			fout.close();
		}
		else if (command == "exit" || command == "quit")
		{
			cout << "Have a nice day." << endl;
			break;
		}
		else
		{
			cin.ignore(255, '\n');
			cout << "Unknown command \"" << command << "\". Try again." << endl;
		}
	}
	system("pause");
	return 0;
}