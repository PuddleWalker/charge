#include <iostream>
#include "directory.h"
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	directory dgfff("Supercell", "Ilkka Paananen", "+35 840 022 8080", "Helsinki", "Gamedev");
	directory::find(directory::SearchType::CName, "yson");
	cout << "--------------------------------\n";
	directory::show();
	cout << "dsv";
	return 0;
}
