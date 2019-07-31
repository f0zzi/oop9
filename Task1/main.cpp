#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
	ifstream fin("Task1.txt");
	char symbol;
	bool space = true;
	int lines = 0, letters = 0, digits = 0, words = 0;
	if (fin.is_open())
	{
		if (fin.get() != EOF)
			lines = 1;
		fin.seekg(0);
		while (fin.get(symbol))
		{
			if (isspace(symbol))
			{
				if (symbol == '\n')
					lines++;
				space = true;
				continue;
			}
			else if (isalpha(symbol))
				letters++;
			else if (isdigit(symbol))
				digits++;
			if (space)
				words++;
			space = false;
		}
		fin.close();
		cout << "Task1.txt summary:" << endl;
		cout << "Lines: " << lines << "\tWords: " << words << endl;
		cout << "Letters: " << letters << "\tDigits: " << digits << endl;
	}
	else
		cout << "Error opening file." << endl;
	system("pause");
	return 0;
}