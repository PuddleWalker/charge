#include <iostream>
#include "directory.h"
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	directory dgfff("s4e45d", "ff523nms", "eg53d", "gr14s", "3e00qd");
	directory dfbdf("1", "2", "3", "4", "5");
	directory drghf("5", "7", "8", "9", "10");
	directory::show();
	cout << "--------------------------------\n";
	directory::clear();
	directory::show();
	cout << "dsv";
	return 0;
}
