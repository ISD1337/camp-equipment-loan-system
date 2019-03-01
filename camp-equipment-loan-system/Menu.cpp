#include "Menu.h"
using namespace std;

void menu() {
	Tent *tents;
	Stove *stoves;
	Lantern *lanterns;
	getEquipments(tents, stoves, lanterns);

	performDisplayLoanAvailableItem(tents, stoves, lanterns);
}