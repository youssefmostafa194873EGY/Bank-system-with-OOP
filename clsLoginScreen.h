#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  void _Login()
    {
        bool LoginFaild = false;
        short counter = 2;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!";
                cout << "\nyou have "<< counter <<" trials to login\n\n";
                counter--;
                
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();
            if (counter <= 0)
                break;
        } while (LoginFaild);
        if (LoginFaild == false) {
            CurrentUser.RegisterLogIn();
            clsMainScreen::ShowMainMenue();
                
        }
        else
            cout << "\n\nyou are locked after 3 faild trails.\n";
    }

public:


    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        _Login();

    }

};

