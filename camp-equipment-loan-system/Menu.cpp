#include "Menu.h"
using namespace std;

void menu() {
	// records[0][0] contains the number of records
	// it must not be altered as other value in any scenario
	string **records = getLoanRecord();

	updateLoanRecord(records);
}