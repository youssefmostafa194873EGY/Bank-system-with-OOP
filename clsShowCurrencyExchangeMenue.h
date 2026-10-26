#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrencies.h"
#include "clsFindCurrency.h"
#include "clsUpdateRate.h"
#include "CurrencyCalcultor.h"
using namespace std;
class clsShowCurrencyExchangeMenue : protected clsScreen {
private:
    enum enCurrencyOptions {
        eListCurrencies = 1, eFindCurrency = 2 ,eUpdateRate = 3, eCurrencyCalcultor = 4, eMainMenue = 5
    };
    
    static short _ReadCurrencyMenueOption(){
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _ListCurrencies() {
        //cout << "\nList Currencies is here\n";
        clsListCurrencies::showListCurrencies();
    }
    static void _FindCurrency() {
        //cout << "\nFind Currency is here\n";
        clsFindCurrency::ShowFindCurrency();
    }
    static void _UpdateRate() {
       //cout << "\Update Rate is here\n";
        clsUpdateRate::ShowUpdateRate();
    }
    static void _CurrencyCalcultor() {
      // cout << "\nCurrency Calcultor is here\n";
        CurrencyCalcultor::ShowCurrencyCalcultor();
    }

    static void _GoBackToCurrencyMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowCurrencyExchangeMenue();

    }

    
    static void _PerformCurrencyMenueOption(enCurrencyOptions CurrencyMenueOption)
    {
        switch (CurrencyMenueOption)
        {
        case enCurrencyOptions::eListCurrencies:
        {
            system("cls");
            _ListCurrencies();
            _GoBackToCurrencyMenue();
            break;
        }


        case enCurrencyOptions::eFindCurrency:
        {
            system("cls");
            _FindCurrency();
            _GoBackToCurrencyMenue();
            break;
        }

        case enCurrencyOptions::eUpdateRate:
        {
            system("cls");
            _UpdateRate();
            _GoBackToCurrencyMenue();
            break;

        }
        case enCurrencyOptions::eCurrencyCalcultor:
        {
            system("cls");
            _CurrencyCalcultor();
            _GoBackToCurrencyMenue();
            break;

        }
        case enCurrencyOptions::eMainMenue:
        {

            //do nothing here the main screen will handle it;

        }
        }

    }
    

    
	static void _CurrencyExchangeMenue() {
        system("cls");
        _DrawScreenHeader("  Currency Exchange Menue Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calcultor.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformCurrencyMenueOption((enCurrencyOptions)_ReadCurrencyMenueOption());
	}

public:
	static void ShowCurrencyExchangeMenue() {
        _CurrencyExchangeMenue();
	}
};

