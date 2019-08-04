#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool GetArgs(string& f1, string& f2, int argNumber);
void EatLine();

int main(int argc, char* argv[])
{
	string command, filename1, filename2;
	char symbol;
	cout << "Microsoft Windows [Version 10.0.18362.267]" << endl;
	cout << "(c)Microsoft Corporation, 2019. All rights reserved." << endl;
	while (true)
	{
		command = filename1 = filename2 = "";
		cout << endl << argv[0] << ">";
		cin >> command;
		if (command == "create")
		{
			if (GetArgs(filename1, filename2, 1))
			{
				cout << "Enter file data:" << endl;
				EatLine();
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
		}
		else if (command == "print")
		{
			if (GetArgs(filename1, filename2, 1))
			{
				ifstream fin(filename1);
				if (fin)
				{
					cout << filename1 << " content:" << endl;
					cout << fin.rdbuf();
					cout.clear();
				}
				else
					cerr << "Error opening file." << endl;
			}
		}
		else if (command == "append")
		{
			if (GetArgs(filename1, filename2, 1))
			{
				EatLine();
				ifstream fin(filename1);
				if (fin.is_open())
				{
					ofstream fout(filename1, ios::app);
					cout << filename1 << " content:" << endl;
					cout << fin.rdbuf();
					cout.clear();
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
		}
		else if (command == "copy")
		{
			if (GetArgs(filename1, filename2, 2))
			{
				ifstream fin(filename1);
				ofstream fout(filename2);
				if (fin.is_open() && fout.is_open())
					fout << fin.rdbuf();
				fin.close();
				fout.close();
			}
		}
		else if (command == "filterDigits")
		{
			if (GetArgs(filename1, filename2, 2))
			{
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
		}
		else if (command == "exit" || command == "quit")
		{
			cout << "Have a nice day." << endl;
			break;
		}
		else
		{
			cin.ignore(255, '\n');
			cerr << "Unknown command \"" << command << "\"." << endl;
		}
	}
	system("pause");
	return 0;
}

bool GetArgs(string& f1, string& f2, int argNumber)
{
	string* tmp[2] = { &f1, &f2 };
	for (int i = 0; i < argNumber; i++)
	{
		while (cin.peek() == ' ' || cin.peek() == '\t')
			cin.get();
		if (cin.peek() == '\n')
		{
			cerr << "Error. Not enough arguments." << endl;
			return false;
		}
		cin >> *tmp[i];
	}
	while (cin.peek() == ' ' || cin.peek() == '\t')
		cin.get();
	if (cin.peek() != '\n')
	{
		cerr << "Error. Too many arguments." << endl;
		EatLine();
		return false;
	}
	return true;
}

void EatLine()
{
	while (cin.get() != '\n')
		continue;
}
