#include "Menu.h"
using namespace std;

void menu() {

	User *user = NULL;
	getUserInformation(user, "VEN001"); // Please fix this by providing the choice of being admin and adding the whole login structure

	// Load and prepare data such as equipments list, loan records 
	// and the allowed number of item that the user can borrow
	Tent *tents = NULL;
	Stove *stoves = NULL;
	Lantern *lanterns = NULL;
	string **records = NULL;
	int size = 0;
	prepare(user, tents, stoves, lanterns, records, size);

	// Some menu coding here

	bool quit;
	do {
		quit = executeMenu(selectMenu(user), user, tents, stoves, lanterns, records, size);
	} while (quit);

	cout << endl;
	cout << "Till We Meet Again." << endl;
}

int selectMenu(User *& user) {

	bool isExceed = (user->getNumberOfItemAllowed() == 0);
	bool hasBorrow = (user->getNumberOfItemAllowed() != user->getMaxItem());

	int choice;
	bool execute;
	do {

		cout << endl;
		cout << "Select: " << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "1.) Display Loan Avaliable Equipment";
		cout << endl << endl;
		cout << "2.) Display Borrowed Equipmet";
		cout << endl << endl;
		cout << ( (!isExceed) ? "3.) Borrow Equipment" : "");
		cout << endl << endl;
		cout << ( (hasBorrow) ? "4.) Return Equipment" : "");
		cout << endl << endl;
		cout << "5.) Quit";
		cout << endl << endl;
		cout << "-------------------------------------------------" << endl;
		cout << "Please enter your choice: ";
		cin >> choice;
		cout << "-------------------------------------------------" << endl;

		execute = true;

		if (isExceed && choice == 3)
			execute = false;

		if (!hasBorrow && choice == 4)
			execute = false;

		if (choice < 1 || choice > 5)
			execute = false;

	} while (!execute);
	return choice;
}

bool executeMenu(int choice, User *const &user, Tent *const &tents, Stove *const &stoves, Lantern *const &lanterns, string**& records, int &size) {

	switch (choice) {
	case 1:
		performDisplayLoanAvailableItem(tents, stoves, lanterns);
		break;
	case 2:
		performDisplayUserBorrowedItem(user, tents, stoves, lanterns, records, size);
		break;
	case 3:
		performBorrowEquipment(user, tents, stoves, lanterns, records, size);
		break;
	case 4:
		performReturnItem(user, tents, stoves, lanterns, records, size);
		break;
	case 5:
		return false;
	}

	return true;
}