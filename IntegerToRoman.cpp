// IntegerToRoman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
#include "convert.h"
int main()
{
	convertToRoman obj;
	int number = 0;
	do
	{
		cout << "Number " << number << ": " << obj.get_number(number) << endl;
		cin >> number;
		system("cls");
	} while (number > 0 && number < 4000);
    return 0;
}

