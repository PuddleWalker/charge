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
		ofstream file;
		file.open("memory.txt", ofstream::app);
		file.write((char*)this, sizeof(directory));
		file.close();
	}
	const void print()
	{
		cout << "�������� �����: " << CompanyName << endl;
		cout << "��������: " << OwnerName << endl;
		cout << "�������: " << PhoneNumber << endl;
		cout << "�����: " << Address << endl;
		cout << "��� ������������: " << KindOfActivity << endl;
	}
	directory() {}
public:
	directory(string CompanyName, string OwnerName, string PhoneNumber, string Address, string KindOfActivity) : CompanyName{ CompanyName }, OwnerName{ OwnerName }, PhoneNumber{ PhoneNumber }, Address{ Address }, KindOfActivity{ KindOfActivity }
	{
		compress();
	}
	static const void show()
	{
		directory examp;
		ifstream file;
		file.open("memory.txt", ifstream::in);
		while (file.read((char*)&examp, sizeof(directory)))
		{
			examp.print();
		}
		file.close();
	}
	static void clear()
	{
		ofstream file;
		file.open("memory.txt");
		file << "";
		file.close();
	}
	static void find(int num, string info)
	{
		directory examp;
		ifstream file;
		file.open("memory.txt", ifstream::in);
		while (file.read((char*)&examp, sizeof(directory)))
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
				cout << "�������������� �������� ������!\n";
				break;
			}
		}
		file.close();
	}
};
