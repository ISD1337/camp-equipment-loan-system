#include "Menu.h"
using namespace std;

void menu() {

	string **records;
	int size;
	getLoanRecord(records, size);

	records[0][0] = "1";

	updateLoanRecord(records, size);
}