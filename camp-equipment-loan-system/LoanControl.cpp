#include "LoanControl.h"

#define USER_PATH "txt/user.txt"
#define EQUIPMENT_PATH "txt/camp_equipment.txt"
#define LOANRECORD_PATH "txt/loan_record.txt"
#define LOG "txt/log.txt"
using namespace std;

// check whether c is a valid letter(include space and comma)
bool isWordCharacter(char c) {

	bool flag = false;

	if (c >= '0' && c <= '9')
		flag = true;
	else if (c >= 'A' && c <= 'Z')
		flag = true;
	else if (c >= 'a' && c <= 'z')
		flag = true;
	else if (c == ' ' || c == ', ')
		flag = true;

	return flag;
}

void getUserInformation(string *&userInfo, string userInput) {
	FileHandler handler;
	string str = handler.fileRead(USER_PATH);

	if (!str.empty()) {
		int len = str.length();
		int j = 0;
		string *userInfo = new string[7]();

		string tmp = "";
		for (int i = 0; i < len; i++) {

			if (isWordCharacter(str[i])) {
				tmp = tmp + str[i];
			}
			else if (str[i] == '\n') {
				if (!userInfo[0].compare(userInput)) {
					break;
				}

				delete[] userInfo;
				userInfo = new string[7]();

				j = 0;
				tmp = "";
			}
			else if (str[i] == '|') {
				userInfo[j] = tmp;

				tmp = "";
				j++;
			}
		}
	}
}

void getEquipments(Tent*& tents, Stove*& stoves, Lantern*& lanterns) {
	FileHandler handler;
	string str = handler.fileRead(EQUIPMENT_PATH);

	if (!str.empty()) {
		int len = str.length();
		int cTent, cStove, cLantern;
		cTent = cStove = cLantern = 0;
		int ieol = 0;

		// count the number of Tent, Stove and Lantern
		for (int i = 0; i < len; i++) {

			if (str[i] == '\n') {

				char c = str[i - ieol];

				if (c == 'T')
					cTent++;
				else if (c == 'S')
					cStove++;
				else if (c == 'L')
					cLantern++;

				ieol = 0;
			}
			else
				ieol++;
		}

		tents = new Tent[cTent];
		stoves = new Stove[cStove];
		lanterns = new Lantern[cLantern];

		string *tmp = new string[12]();

		int j = 0;
		int nTent, nStove, nLantern;
		nTent = nStove = nLantern = 0;
		for (int i = 0; i < len; i++) {

			if (isWordCharacter(str[i])) {
				tmp[j] += str[i];

				if (str[i + 1] == '\n') {
					char c = tmp[0][0];

					if (c == 'T')
					{
						Tent tempObj(tmp[0], tmp[1], tmp[2], tmp[3],
							tmp[4], tmp[5], tmp[6],
							tmp[7], tmp[8], tmp[9], tmp[10], tmp[11]);

						tents[nTent] = tempObj;

						nTent++;

					}
					else if (c == 'S')
					{
						Stove tempObj(tmp[0], tmp[1], tmp[2], tmp[3],
							tmp[4], tmp[5], tmp[6],
							tmp[7], tmp[8]);

						stoves[nStove] = tempObj;

						nStove++;
					}
					else if (c == 'L')
					{
						Lantern tempObj(tmp[0], tmp[1], tmp[2], tmp[3],
							tmp[4], tmp[5], tmp[6],
							tmp[7], tmp[8], tmp[9]);

						lanterns[nLantern] = tempObj;

						nLantern++;
					}

					// release and reallocate memory
					delete[] tmp;
					tmp = new string[12]();

					j = 0;
				}
			}
			else if (str[i] == '|') {
				j++;
			}
		}
	}
}

void updateEquipments(Tent* const&tents, Stove* const&stoves, Lantern* const&lanterns) {
	string str = "";

	for (int i = 0; i < tents->getTotal(); i++) {
		str += tents[i].getInfo();
	}

	for (int i = 0; i < stoves->getTotal(); i++) {
		str += stoves[i].getInfo();
	}

	for (int i = 0; i < lanterns->getTotal(); i++) {
		str += lanterns[i].getInfo();
	}

	FileHandler handler;
	handler.fileWrite(&str, EQUIPMENT_PATH);
}

void getLoanRecord(string **&records, int &size) {
	FileHandler handler;
	string str = handler.fileRead(LOANRECORD_PATH);

	if (!str.empty()) {
		int count = 0;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '\n') {
				if (isWordCharacter(str[i - 1]))
					count++;
			}
		} 
		size = count;

		records = new string*[count];
		for (int i = 0; i < count; i++) {
			records[i] = new string[6]();
		}
		
		string tmp = "";
		int k = 0;
		for (int i = 0, j = 0; i < str.length(); i++) {

			if (isWordCharacter(str[i])) {
				tmp += str[i];

				if (str[i + 1] == '\n') {
					records[k][j] = tmp;

					j = 0;
					k++;
					tmp = "";
				}
				
			}
			else if (str[i] == '|') {
				records[k][j] = tmp;

				j++;
				tmp = "";
			}
		}
	}
}

void updateLoanRecord(string *const*const records, int size) {
	FileHandler handler;
	string str = "";

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 6; j++) {
			if (j)
				str += "|";

			str += records[i][j];
		}
		str += "\n";
	}

	handler.fileWrite(&str, LOANRECORD_PATH);
}

void performDisplayLoanAvailableItem(Tent * const &tents, Stove * const & stoves, Lantern * const & lanterns) {

	string statusOut = "out";
	int count = 0;

	// Table of Tents
	cout << endl;
	cout << "TENTS" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(15) << left << "ITEM ID"
		<< setw(25) << left << "ITEM NAME"
		<< setw(15) << left << "BRAND"

		<< setw(20) << left << "TENT SIZE"
		<< setw(20) << left << "TENT TYPE"
		<< setw(20) << left << "NUMBER OF DOORS"
		<< setw(20) << left << "IS DOUBLE LAYER"
		<< setw(20) << left << "COLOUR"
		<< endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < tents->getTotal(); i++) {
		if (!statusOut.compare(tents[i].getStatus()))
			continue;

		cout << setw(15) << left << tents[i].getItemId()
			<< setw(25) << left << tents[i].getItemName()
			<< setw(15) << left << tents[i].getBrand()

			<< setw(20) << left << tents[i].getTentSize()
			<< setw(20) << left << tents[i].getTentType()
			<< setw(20) << left << tents[i].getNumberOfDoors()
			<< setw(20) << left << tents[i].getIsDoubleLayer()
			<< setw(20) << left << tents[i].getColour()
			<< endl;

		count++;
	}

	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(140) << right << "Available Left: "
		<< setw(5) << right << count << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl
		<< endl;

	count = 0;
	// end of Tents'


	// Table of Stoves
	cout << endl;
	cout << "STOVES" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(15) << left << "ITEM ID"
		<< setw(25) << left << "ITEM NAME"
		<< setw(15) << left << "BRAND"

		<< setw(20) << left << "STOVE SIZE"
		<< setw(20) << left << "FUEL TYPE"
		<< endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < stoves->getTotal(); i++) {
		if (!statusOut.compare(stoves[i].getStatus()))
			continue;

		cout << setw(15) << left << stoves[i].getItemId()
			<< setw(25) << left << stoves[i].getItemName()
			<< setw(15) << left << stoves[i].getBrand()

			<< setw(20) << left << stoves[i].getStoveType()
			<< setw(20) << left << stoves[i].getFuelType()
			<< endl;

		count++;
	}

	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(140) << right << "Available Left: "
		<< setw(5) << right << count << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl
	<< endl;

	count = 0;
	// end of Stoves'


	// table of Lanterns
	cout << endl;
	cout << "LANTERNS" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(15) << left << "ITEM ID"
		<< setw(25) << left << "ITEM NAME"
		<< setw(15) << left << "BRAND"

		<< setw(20) << left << "LANTERN SIZE"
		<< setw(20) << left << "LANTERN TYPE"
		<< setw(20) << left << "FUEL TYPE"
		<< endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < lanterns->getTotal(); i++) {
		if (!statusOut.compare(lanterns[i].getStatus()))
			continue;

		cout << setw(15) << left << lanterns[i].getItemId()
			<< setw(25) << left << lanterns[i].getItemName()
			<< setw(15) << left << lanterns[i].getBrand()

			<< setw(20) << left << lanterns[i].getLanternSize()
			<< setw(20) << left << lanterns[i].getLanternType()
			<< setw(20) << left << lanterns[i].getFuelType()
			<< endl;

		count++;
	}

	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(140) << right << "Available Left: "
		<< setw(5) << right << count << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl
	<< endl;

	count = 0;
	// end of lanterns'
}

void performBorrowEquipment(User* const& user, Tent* const& tents, Stove* const& stoves, Lantern* const& lanterns, string*& records, int &size) {

}

void performDisplayUserBorrowedItem(User * const & user, Tent * const & tents, Stove * const & stoves, Lantern * const & lanterns, string *& records, int & size) {

}