#pragma once
#include <string>
#include <fstream>
#include <exception>

using namespace std;

class directory
{
private:
	string CompanyName;
	string OwnerName;
	string PhoneNumber;
	string Address;
	string KindOfActivity;
	void compress() const
	{
		ofstream file("memory.txt", ofstream::app);
		if (file.is_open())
		{
			file << CompanyName.c_str() << ' ';
			file << OwnerName.c_str() << ' ';
			file << PhoneNumber.c_str() << ' ';
			file << Address.c_str() << ' ';
			file << KindOfActivity.c_str() << '\n';
			file.close();
		}
		else
		{
			throw runtime_error("Unable file");
		}
	}
	const void print()
	{
		cout << "Название фирмы: " << CompanyName << endl;
		cout << "Владелец: " << OwnerName << endl;
		cout << "Телефон: " << PhoneNumber << endl;
		cout << "Адрес: " << Address << endl;
		cout << "Род деятельности: " << KindOfActivity << endl << endl;
	}
	directory() {}
public:
	enum SearchType
	{
		CName = 1,
		OName,
		PNumber,
		Add,
		KindOfAct
	};
	directory(string CompanyName, string OwnerName, string PhoneNumber, string Address, string KindOfActivity) : CompanyName{ CompanyName }, OwnerName{ OwnerName }, PhoneNumber{ PhoneNumber }, Address{ Address }, KindOfActivity{ KindOfActivity }
	{
		compress();
	}
	static void clear()
	{
		ofstream file;
		file.open("memory.txt");
		file << "";
		file.close();
	}
	static void find(SearchType num, string info)
	{
		directory examp;
		ifstream file("memory.txt");
		if (file.is_open())
		{
			while (file >> examp.CompanyName >> examp.OwnerName >> examp.PhoneNumber >> examp.Address >> examp.KindOfActivity)
			{
				switch (num)
				{
				case 1:
					if (examp.CompanyName.find(info) != string::npos) examp.print();
					break;
				case 2:
					if (examp.OwnerName.find(info) != string::npos) examp.print();
					break;
				case 3:
					if (examp.PhoneNumber.find(info) != string::npos) examp.print();
					break;
				case 4:
					if (examp.Address.find(info) != string::npos) examp.print();
					break;
				case 5:
					if (examp.KindOfActivity.find(info) != string::npos) examp.print();
					break;
				default:
					cout << "Несуществующий параметр поиска!\n";
					break;
				}
			}
			file.close();
		}
		else
		{
			throw runtime_error("Unable file");
		}
	}
	static const void show()
	{
		directory examp;
		ifstream file("memory.txt");
		if (file.is_open())
		{
			while (file >> examp.CompanyName >> examp.OwnerName >> examp.PhoneNumber >> examp.Address >> examp.KindOfActivity)
			{
				examp.print();
			}
			file.close();
		}
		else
		{
			throw runtime_error("Unable file");
		}
	}
};
