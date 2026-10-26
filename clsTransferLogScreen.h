#pragma once
#include <iostream>
#include "clsBankClient.h"
#include <iomanip>
#include "clsScreen.h"
#include <vector>
#include <string>
using namespace std;

class clsTransferLogScreen : protected clsScreen{
private:

	static void Table(vector <clsBankClient::stinfoTransferLog> VinfoTransferLog) {
		cout << "\n ------------------------------------------------------------------------------------------------------------ ";
		cout << "\n| Date/time                   | S. acct   | D. acct   | Amount    | S. Balance    | D. Balance     | User    |";
		cout << "\n ------------------------------------------------------------------------------------------------------------ \n";
		for (clsBankClient::stinfoTransferLog infoTransferLog : VinfoTransferLog) {
			cout << "| " << left << setw(28) << infoTransferLog.Date;
			cout << "| " << left << setw(10) << infoTransferLog.Sacct;
			cout << "| " << left << setw(10) << infoTransferLog.Dacct;
			cout << "| " << left << setw(10) << infoTransferLog.Amount;
			cout << "| " << left << setw(14) << infoTransferLog.SBalance;
			cout << "| " << left << setw(15) << infoTransferLog.DBalance;
			cout << "| " << left << setw(8) << infoTransferLog.User << "|";
			cout << "\n ------------------------------------------------------------------------------------------------------------\n";
		}
		
	}
public:
	
	static void showTransferLog() {
	
	vector <clsBankClient::stinfoTransferLog> VinfoTransferLog;
	VinfoTransferLog = clsBankClient::TransferLoginFromfile();
	
	_DrawScreenHeader("Transfer Log");
	Table(VinfoTransferLog);

	}

};

