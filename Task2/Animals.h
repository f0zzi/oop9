#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string GetData(ifstream* f_in);

class Animal abstract
{
protected:
	string name;
	int age;
public:
	Animal() : Animal("Unknown", 0) {}
	Animal(string name, int age)
	{
		SetName(name);
		SetAge(age);
	}
	void SetAge(int age)
	{
		if (age >= 0)
			this->age = age;
	}
	void SetName(string name)
	{
		if (name.size() > 0)
			this->name = name;
	}
	virtual string Sound() const abstract;

	virtual string Type() const abstract;

	virtual string Breed() const abstract;

	int GetAge() const
	{
		return age;
	}
	string GetName() const
	{
		return name;
	}
	virtual void Print() const
	{
		cout << "Name: " << name << "\tAge: " << age << "\tType: " << Type() << "\tSays: " << Sound() << endl;
	}
};

class Dog : public Animal
{
private:
	string breed;
public:
	Dog(string name = "Noname dog", int age = 0, string breed = "Unknown") :
		Animal(name, age)
	{
		SetBreed(breed);
	}
	void SetBreed(string breed)
	{
		if (breed.size() >= 0)
			this->breed = breed;
	}
	void Print() const override
	{
		cout << "Name: " << name << "\tAge: " << age << "\tType: " << Type() << "\tBreed: " << breed << "\tSays: " << Sound() << endl;
	}
	string Type() const override
	{
		return "Dog";
	}
	string Sound() const override
	{
		return "Woof!";
	}
	string Breed() const override
	{
		return breed;
	}
};

enum Fur { Short, Medium, Long };

class Cat : public Animal
{
private:
	string breed;
	Fur fur;
public:
	Cat(string name = "Noname cat", int age = 0, string breed = "Unknown", Fur fur = Short) :
		Animal(name, age)
	{
		SetBreed(breed);
		SetFur(fur);
	}
	void SetFur(Fur fur)
	{
		this->fur = fur;
	}

	string GetFur() const
	{
		switch (fur)
		{
		case Short:
			return "short";
			break;
		case Medium:
			return "medium";
			break;
		case Long:
			return "long";
			break;
		}
		return "Unknown";
	};
	void SetBreed(string breed)
	{
		if (breed.size() >= 0)
			this->breed = breed;
	}
	void Print() const override
	{
		cout << "Name: " << name << "\tAge: " << age << "\tType: " << Type() << "\tBreed: " << breed << "\tSays: " << Sound() << "\tFur: " << GetFur() << endl;
	}
	string Type() const override
	{
		return "Cat";
	}
	string Sound() const override
	{
		return "Meow!";
	}
	string Breed() const override
	{
		return breed;
	}
};

class Parrot : public Animal
{
private:
	string breed;
public:
	Parrot(string name = "Noname cat", int age = 0, string breed = "Unknown") :
		Animal(name, age)
	{
		SetBreed(breed);
	}
	void SetBreed(string breed)
	{
		if (breed.size() >= 0)
			this->breed = breed;
	}
	void Print() const override
	{
		cout << "Name: " << name << "\tAge: " << age << "\tType: " << Type() << "\tBreed: " << breed << "\tSays: " << Sound() << endl;
	}
	string Type() const override
	{
		return "Parrot";
	}
	string Sound() const override
	{
		return "Polly wants some cracker!";
	}
	string Breed() const override
	{
		return breed;
	}
};
class Hamster : public Animal
{
private:
	string breed;
public:
	Hamster(string name = "Noname cat", int age = 0, string breed = "Unknown") :
		Animal(name, age)
	{
		SetBreed(breed);
	}
	void SetBreed(string breed)
	{
		if (breed.size() >= 0)
			this->breed = breed;
	}
	void Print() const override
	{
		cout << "Name: " << name << "\tAge: " << age << "\tType: " << Type() << "\tBreed: " << breed << "\tSays: " << Sound() << endl;
	}
	string Type() const override
	{
		return "Hamster";
	}
	string Sound() const override
	{
		return "Frr Frr";
	}
	string Breed() const override
	{
		return breed;
	}
};

class HomeZoo
{
private:
	vector <Animal*> zoo;
public:
	//конструктор(зоопарк  пустий)
	HomeZoo() {}
	//деструктор, вилучити всі тваринки з вектору
	//(спочатку слід вилучити динамічні об’єкти тваринок, потім можна  очищати елементи вектору zoo.clear())
	~HomeZoo()
	{
		for (int i = 0; i < zoo.size(); i++)
			delete zoo[i];
		zoo.clear();
	}
	//додавання певної тваринки у Зоопарк на замовлення користувача(запитати тип тваринки, кличку, вік, додаткові характеристики, створити динамічний екземпляр тваринки та додати до вектору
	void AddAnimal()
	{
		int animal, age;
		string name, breed;
		do
		{
			cout << "Choose animal to add:\n";
			cout << "1 - Dog.\n";
			cout << "2 - Cat.\n";
			cout << "3 - Parrot.\n";
			cout << "4 - Hamster.\n";
			cin >> animal;
			if (animal < 1 || animal > 4)
				cout << "Error. Invalid input.\n";
		} while (animal < 1 || animal > 4);
		do
		{
			cout << "Enter animal breed: ";
			cin >> breed;
			if (breed.size() == 0)
				cout << "Error. Invalid input.\n";
		} while (breed.size() == 0);
		do
		{
			cout << "Enter animal name: ";
			cin >> name;
			if (name.size() == 0)
				cout << "Error. Invalid input.\n";
		} while (name.size() == 0);
		do
		{
			cout << "Enter animal age: ";
			cin >> age;
			if (age < 0)
				cout << "Error. Invalid input.\n";
		} while (age < 0);
		switch (animal)
		{
		case 1:
			zoo.push_back(new Dog(name, age, breed));
			break;
		case 2:
			Fur fur;
			int selection;
			do
			{
				cout << "Enter fur length:\n";
				cout << "1 - Short.\n";
				cout << "2 - Medium.\n";
				cout << "3 - Long.\n";
				cout << "Fur length: ";
				cin >> selection;
				if (selection < 1 || selection > 3)
					cout << "Invalid input. Try again.\n";
			} while (selection < 1 || selection > 3);
			switch (selection)
			{
			case 1:
				fur = Short;
				break;
			case 2:
				fur = Medium;
				break;
			case 3:
				fur = Long;
				break;
			}
			zoo.push_back(new Cat(name, age, breed, fur));
			break;
		case 3:
			zoo.push_back(new Parrot(name, age, breed));
			break;
		case 4:
			zoo.push_back(new Hamster(name, age, breed));
			break;
		default:
			break;
		}
	}
	//метод автоматичного додавання кількох "випадкових" тваринок у зоопарк
	void AddRandom()
	{
		zoo.push_back(new Dog("Rex", 2, "Hound"));
		zoo.push_back(new Cat("Tom", 1, "British", Short));
		zoo.push_back(new Parrot("Poly", 3, "Cockatoo"));
		zoo.push_back(new Hamster("Fluffy", 0, "Chinese"));
	}
	//метод виведення усіх  тваринок зоопарку
	void Show() const
	{
		if (zoo.size() == 0)
		{
			cout << "Zoo is empty.\n";
			return;
		}
		cout << "HomeZoo:\n";
		for (int i = 0; i < zoo.size(); i++)
		{
			cout << "#" << i + 1 << " ";
			zoo[i]->Print();
		}
	}
	//метод редагування тваринки(редагується назва чи вік, не тип тваринки)
	void Edit()
	{
		if (zoo.size() == 0)
		{
			cout << "There's no one to edit.\n";
			system("pause");
			return;
		}
		int selection, age;
		string name;
		do
		{
			cout << "Enter number of animal to edit: ";
			cin >> selection;
			if (selection < 1 || selection > zoo.size())
				cout << "Error. Invalid input.\n";
		} while (selection < 1 || selection > zoo.size());
		do
		{
			cout << "Enter animal name: ";
			cin >> name;
			if (name.size() == 0)
				cout << "Error. Invalid input.";
		} while (name.size() == 0);
		zoo[selection - 1]->SetName(name);
		do
		{
			cout << "Enter animal age: ";
			cin >> age;
			if (age < 0)
				cout << "Error. Invalid input.\n";
		} while (age < 0);
		zoo[selection - 1]->SetAge(age);
	}
	//метод вилучення(продажу) тваринки з зоопарку
	void Sell()
	{
		if (zoo.size() == 0)
		{
			cout << "There's no one to sell.\n";
			system("pause");
			return;
		}
		int selection;
		do
		{
			cout << "Enter number of animal to sell: ";
			cin >> selection;
			if (selection < 1 || selection > zoo.size())
				cout << "Error. Invalid input.\n";
		} while (selection < 1 || selection > zoo.size());
		zoo.erase(zoo.begin() + selection - 1);
	}
	//метод вилучення(продажу) всіх тваринок
	void SellAll()
	{
		if (zoo.size() == 0)
		{
			cout << "There's no one to sell.\n";
			system("pause");
			return;
		}
		if (zoo.size() > 0)
		{
			for (int i = 0; i < zoo.size(); i++)
				delete zoo[i];
			zoo.clear();
		}
	}
	void SaveZoo()
	{
		if (zoo.size())
		{
			string filename;
			int age, size;
			cout << "Enter file name: ";
			cin >> filename;
			filename.append(".dat");
			ofstream f_out(filename, ios::out | ios::binary);
			if (f_out.is_open())
			{
				for (int i = 0; i < zoo.size(); i++)
				{
					size = zoo[i]->Type().size();
					f_out.write((char*)& size, sizeof(int));
					f_out.write((char*)zoo[i]->Type().c_str(), size * sizeof(char));
					size = zoo[i]->Breed().size();
					f_out.write((char*)& size, sizeof(int));
					f_out.write((char*)zoo[i]->Breed().c_str(), size * sizeof(char));
					size = zoo[i]->GetName().size();
					f_out.write((char*)& size, sizeof(int));
					f_out.write((char*)zoo[i]->GetName().c_str(), size * sizeof(char));
					age = zoo[i]->GetAge();
					f_out.write((char*)& age, sizeof(int));
					if (typeid(Cat) == typeid(*zoo[i]))
					{
						size = static_cast<Cat*>(zoo[i])->GetFur().size();
						f_out.write((char*)& size, sizeof(int));
						f_out.write((char*)static_cast<Cat*>(zoo[i])->GetFur().c_str(), size * sizeof(char));
					}
				}
				f_out.close();
				cout << "Success. Zoo saved to file \"" << filename << "\"." << endl;
			}
			else
				cout << "Error opening file." << endl;
			system("pause");
		}
		else
		{
			cout << "Nothing to save. Your zoo is empty." << endl;
			system("pause");
		}
	}
	void LoadZoo()
	{
		string filename, name, breed, type, furr;
		int age, size;
		Fur fur;
		char* tmp = nullptr;
		cout << "Enter file name: ";
		cin >> filename;
		filename.append(".dat");
		ifstream f_in(filename, ios::in | ios::binary);
		if (f_in.is_open())
		{
			while (!(f_in.peek() == EOF))
			{
				type = GetData(&f_in);
				breed = GetData(&f_in);
				name = GetData(&f_in);
				f_in.read((char*)& age, sizeof(int));

				if (type == "Cat")
				{
					f_in.read((char*)& size, sizeof(int));
					tmp = new char[size + 1];
					f_in.read((char*)tmp, size * sizeof(char));
					tmp[size] = '\0';
					furr = tmp;
					delete[] tmp;
					if (furr == "short")
						fur = Short;
					else if (furr == "medium")
						fur = Medium;
					else
						fur = Long;

					zoo.push_back(new Cat(name, age, breed, fur));
				}
				else if (type == "Dog")
					zoo.push_back(new Dog(name, age, breed));
				else if (type == "Parrot")
					zoo.push_back(new Parrot(name, age, breed));
				else if (type == "Hamster")
					zoo.push_back(new Hamster(name, age, breed));
			}
			f_in.close();
		}
		else
		{
			cout << "Error opening file." << endl;
			system("pause");
		}
	}
};
string GetData(ifstream* f_in)
{
	int size;
	char* tmp = nullptr;
	f_in->read((char*)& size, sizeof(int));
	tmp = new char[size + 1];
	f_in->read((char*)tmp, size * sizeof(char));
	tmp[size] = '\0';
	string s_tmp = tmp;
	delete[] tmp;
	return s_tmp;
}