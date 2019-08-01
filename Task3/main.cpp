#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool GetArgs(string& f1, string& f2, int argNumber);

int main()
{
	string command, filename1, filename2;
	char symbol;
	//enum commands { create, print, append, copy, filterDigits };
	cout << "Command promt. Waiting for command." << endl;
	while (true)
	{
		command = filename1 = filename2 = "";
		cout << ">";
		cin >> command;
		if (command == "create")
		{
			cout << "Enter file data:" << endl;
			cin >> filename1;
			while (cin.get() != '\n')
				continue;

			ofstream fout(filename1);
			if (fout.is_open())
			{
				while (cin.get(symbol))
					fout.put(symbol);
				cin.clear();
				fout.close();
			}
			else
				cerr << "Error creating file." << endl;
		}
		else if (command == "print")
		{
			cin >> filename1;
			ifstream fin(filename1);
			if (fin.is_open())
				cout << fin.rdbuf();
			else
				cerr << "Error opening file." << endl;
		}
		else if (command == "append")
		{
			cin >> filename1;
			while (cin.get() != '\n')
				continue;
			ofstream fout(filename1, ios::app);
			if (fout.is_open())
			{
				ifstream fin(filename1);
				cout << fin.rdbuf();
				fin.close();
				char symbol;
				while (cin.get(symbol))
					fout << symbol;
				cin.clear();
				fout.close();
			}
			else
				cerr << "Error opening file." << endl;
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
			if (fin.is_open())
			{
				ofstream fout(filename2);
				while (fin.get(symbol))
					if (!isdigit(symbol))
						fout << symbol;
				fin.close();
				fout.close();
			}
			else
				cerr << "Error opening file." << endl;
		}
		else if (command == "exit" || command == "quit")
		{
			cout << "Have a nice day." << endl;
			break;
		}
		else
		{
			cin.ignore(255, '\n');
			cerr << "Unknown command \"" << command << "\". Try again." << endl;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

bool GetArgs(string& f1, string& f2, int argNumber)
{
	string* tmp[2] = { &f1, &f2 };
	for (int i = 0; i < argNumber; i++)
	{
		cin >> *tmp[i];
		if (tmp[i]->size() == 0)
			return false;
	}
	if (cin.get() != '\n')
	{
		cerr << "Wrong argument number." << endl;
		return false;
	}
	return true;
}