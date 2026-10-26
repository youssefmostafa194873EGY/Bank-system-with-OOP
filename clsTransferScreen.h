#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsTransferScreen:protected clsScreen {
private:
	static void clientcard(clsBankClient Client) {
		cout << "\n\n---------------------------------------------\n";
		cout << "Full name   : "<< Client.FullName() <<"\n";
		cout << "Acc. NUmber : "<< Client.AccountNumber() <<"\n";
		cout << "Balance     : "<< Client.AccountBalance <<"\n";
		cout << "---------------------------------------------\n";
	}

	static clsBankClient checkaccount() {

		string AccountNumber = "";
		cout << "\nEnter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

	 clsBankClient Client = clsBankClient::Find(AccountNumber);
	 return Client;

	}

	static void changebalance(clsBankClient &Client1, clsBankClient &Client2,float transfer) {
		Client1.AccountBalance -= transfer;
		Client2.AccountBalance += transfer;
	}

	static void checkopertions(clsBankClient& Client1, clsBankClient& Client2,float &Transfer) {
		clsBankClient::enSaveResults SaveResult1, SaveResult2;
		bool fullResult = false;
		SaveResult1 = Client1.Save();
		SaveResult2 = Client2.Save();
		if (SaveResult1 == 1 && SaveResult2 == 1) {
			fullResult = true;
		}


		switch (fullResult)
		{
		case  true :
		{
			cout << "\nTranfer Updated Successfully :-)\n";

			clientcard(Client1);
			clientcard(Client2);
			clsBankClient::TransferLogintofile(Client1, Client2, Transfer);
			break;
		}
		case false:
		{
			cout << "\nError Tranfer was not saved";
			break;

		}

		}
	}

public:
	static void showTransferScreen() {
		_DrawScreenHeader("\tTransfer Screen");
		clsBankClient Client1 = checkaccount();
		clientcard(Client1);
		clsBankClient Client2 = checkaccount();
		clientcard(Client2);
		
		
		cout << "\nEnter Transfer Amount: ";
		float transfer = clsInputValidate::ReadFloatNumber();
		
		
		while (Client1.AccountBalance < transfer) {
			cout << "Amount Exceeds the availble Balance, Enter anther Amount: ";
			transfer = clsInputValidate::ReadFloatNumber();
		}

		changebalance(Client1,Client2,transfer);
		checkopertions(Client1, Client2, transfer);

	}
};

