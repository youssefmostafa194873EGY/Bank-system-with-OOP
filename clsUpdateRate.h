#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsstring.h"
#include <string>
#include <vector>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
class clsUpdateRate : protected clsScreen{
private:
	static void InfoCard(clsCurrency& Currency) {
		cout << "---------------------------------------------\n";
		cout << "Country  :"<< Currency.Country() << "\n";
		cout << "Code     :"<< Currency.CurrencyCode() << "\n";
		cout << "Name     :"<< Currency.CurrencyName() << "\n";
		cout << "Rate($1) :"<< Currency.Rate() << "\n";
		cout << "---------------------------------------------\n";
	}


	static void _search(string code) {
		clsCurrency Currency = clsCurrency::FindByCode(code);
		_Result(Currency);
	}

	static void _ChangeTheRate(clsCurrency& Currency){
		char choose;
		cout << "Are you Sure you want Update the Rate of this Currency (y/n): ";
		cin >> choose;
		if (choose == 'y' || choose == 'Y') {
			cout << "\nEnter New Rate: ";
			float newrate = clsInputValidate::ReadFloatNumber();
			Currency.UpdateRate(newrate);
			InfoCard(Currency);
		}

	}

	static void _Result(clsCurrency &Currency) {
		if (Currency.IsEmpty()) 
			cout << "\nSorry, The Code not Found.\n";
		else{
			InfoCard(Currency);
			_ChangeTheRate(Currency);

		}
	}


	static void _UpdateRateScreen(){
		_DrawScreenHeader("\tCurrency Calcultor");
		cout << "Please Enter the code: ";
		string code = clsInputValidate::ReadString();
		_search(code);
	}

public:
	static void ShowUpdateRate() {
		_UpdateRateScreen();
	}
};

