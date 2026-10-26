#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsstring.h"
#include <string>
#include <vector>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
class clsFindCurrency:protected clsScreen {
private:
	enum enOptions {
		eCode = 1, eCountry = 2
		
	};

	static void _Search(enOptions Options) {
		string title = "";

		switch (Options){
		case enOptions::eCode :
		{
			cout << "\nEnter The Code: ";
			title = clsInputValidate::ReadString();
			
			clsCurrency Currency = clsCurrency::FindByCode(title);
			_printResult(Currency);
			break;
		}


		case enOptions::eCountry:
		{
			cout << "\nEnter The Country: ";
			title = clsInputValidate::ReadString();
			
			clsCurrency Currency = clsCurrency::FindByCountry(title);
			_printResult(Currency);
			break;
		}

		}
	}
	static void _printResult(clsCurrency &Currency) {
		if (Currency.IsEmpty()) {
			cout << "\nSorry, Is Not Found. ";
		}
		else {
			cout << "It is found.\n\n";
			cout << "----------------------------------\n";
			cout << "Country       :"<<Currency.Country()<<"\n";
			cout << "Currency Code :"<<Currency.CurrencyCode()<<"\n";
			cout << "Currency Name :"<<Currency.CurrencyName()<<"\n";
			cout << "Rate          :"<<Currency.Rate()<<"\n";
			cout << "----------------------------------\n";
		}

	}

	static short _ChooseMode() {
		cout << "Find By: [1] Code or [2] Country ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Find By: [1] Code or [2] Country ? ");
		return Choice;


	}

	static void _FindCurrencyScreen() {
		_DrawScreenHeader("\tFind Currency");
	_Search((enOptions)_ChooseMode());
	}


public:
	static void ShowFindCurrency() {
		_FindCurrencyScreen();
	}

};

