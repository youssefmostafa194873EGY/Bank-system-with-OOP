#pragma once
#include <iostream>
#include "clsCurrency.h"
#include <string>
#include <vector>
#include "clsScreen.h"
#include <iomanip>
class clsListCurrencies : protected clsScreen{
private:
	static void _PrintColumns(string line) {
		vector <clsCurrency> VData = clsCurrency::GetCurrenciesList();
		string space = "  ";
		for (clsCurrency Data : VData) {

			 cout << "|" << setw(36) << left << Data.Country() << "|";
			 cout << setw(12) << left << Data.CurrencyCode() << "|";
			 cout << setw(36) << left << Data.CurrencyName() << "|";
			 cout << setw(17) << left << Data.Rate() << "|\n";
			 cout << line;
		
		}
		

	}

	static void _ListCurrencies() { 
		string line = " --------------------------------------------------------------------------------------------------------\n";
		
		_DrawScreenHeader("\tList Currencies");
		
		cout << line;
		cout << "|  Country                           |  Code      |  Name                              |  Rate/(1$)      |\n";
		cout << line;
		_PrintColumns(line);
	
	}

public:
	static void showListCurrencies() {
		_ListCurrencies();
	}
};

