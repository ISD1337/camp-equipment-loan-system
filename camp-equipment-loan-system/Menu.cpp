#include "Menu.h"
using namespace std;

void menu() {
	Tent *tents = NULL;
	Stove *stoves = NULL;
	Lantern *lanterns = NULL;
	User *user = NULL;
	string **records = NULL;
	int size = 0;

	getLoanRecord(records, size);
	getEquipments(tents, stoves, lanterns);
	getUserInformation(user, "VEN001");

	performDisplayLoanAvailableItem(tents, stoves, lanterns);
	performBorrowEquipment(user, tents, stoves, lanterns, records, size);
}