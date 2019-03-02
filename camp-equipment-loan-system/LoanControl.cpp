#include "LoanControl.h"

#define USER_PATH "txt/user.txt"
#define EQUIPMENT_PATH "txt/camp_equipment.txt"
#define LOANRECORD_PATH "txt/loan_record.txt"
#define LOG "txt/log.txt"
using namespace std;

// Login stage must be done before preparation and user should not be NULL;
void prepare(User*& user, Tent*& tents, Stove*& stoves, Lantern*& lanterns, string**& records, int &size) {

	getEquipments(tents, stoves, lanterns);
	getLoanRecord(records, size);

	// find the number of item allowed to borrow
	int count;
	getUserCurrentBorrowRecord(user, records, size, count);
	for (int i = 0; i < count; i++)
		user->borrowItem();
}

// Check whether c is a valid letter(include space and comma)
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

string getDate() {
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	char str[10];
	strftime(str, 10, "%d%m%Y", &timeinfo);

	return str;
}

void getUserInformation(User*& user, string userInput) {
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
				userInfo[j] = tmp;

				if (!userInfo[0].compare(userInput)) {

					convertUserInformation(user, userInfo);

					delete[] userInfo;
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

void convertUserInformation(User*& user, string *const userInfo) {
	
	string rank = userInfo[0].substr(0, 3);
	
	if (!rank.compare("VEN")) {
		user = new VentureScout(userInfo[0], userInfo[1], userInfo[2], userInfo[3], userInfo[4]);
	} 
	else if (!rank.compare("ROV")) {
		user = new RoverScout(userInfo[0], userInfo[1], userInfo[2], userInfo[3], userInfo[4]);
	}
	else if (!rank.compare("SCT")) {
		user = new Scout(userInfo[0], userInfo[1], userInfo[2], userInfo[3], userInfo[4], userInfo[5]);
	}
	else if (!rank.compare("SCM")) {
		user = new Scouter(userInfo[0], userInfo[1], userInfo[2], userInfo[3], userInfo[4], userInfo[5]);
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

void updateEquipments(Tent *const &tents, Stove *const &stoves, Lantern *const &lanterns) {
	string str = "";
	for (int i = 0; i < tents->getTotal(); i++) {
		str += tents[i].getInfo() + "\n";
	}

	for (int i = 0; i < stoves->getTotal(); i++) {
		str += stoves[i].getInfo() + "\n";
	}

	for (int i = 0; i < lanterns->getTotal(); i++) {
		str += lanterns[i].getInfo() + "\n";
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

void performDisplayLoanAvailableItem(Tent *const &tents, Stove *const &stoves, Lantern *const &lanterns) {

	string statusIn = "in";
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
		string condtion = tents[i].getCondition();
		if (condtion.compare("good"))
			continue;

		if (statusIn.compare(tents[i].getStatus()))
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
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

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
		string condtion = tents[i].getCondition();
		if (condtion.compare("good"))
			continue;

		if (statusIn.compare(stoves[i].getStatus()))
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
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

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
		string condtion = tents[i].getCondition();
		if (condtion.compare("good"))
			continue;

		if (statusIn.compare(lanterns[i].getStatus()))
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
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	count = 0;
	// end of lanterns'
}

void performBorrowEquipment(User* const& user, Tent* const& tents, Stove* const& stoves, Lantern* const& lanterns, string**& records, int &size) {

	string username = user->getUsername();
	bool isExceed = (!user->getNumberOfItemAllowed());		// check whether the number of rank allowed item == 0
	string input_itemId;

	while (!isExceed) {
		cout << endl;
		cout << "Please enter the item's Id that you wanted to borrow:  ";
		cin >> input_itemId;

		bool found = false;
		Equipment *item = NULL;
		int total;

		total = tents->getTotal();
		for (int j = 0; (j < total) && !found; j++) {
			if (!input_itemId.compare(tents[j].getItemId())) {
				item = &tents[j];
				found = true;
			}
		}

		total = stoves->getTotal();
		for (int j = 0; (j < total) && !found; j++) {
			if (!input_itemId.compare(stoves[j].getItemId())) {
				item = &stoves[j];
				found = true;
			}
		}

		total = lanterns->getTotal();
		for (int j = 0; (j < total) && !found; j++) {
			if (!input_itemId.compare(lanterns[j].getItemId())) {
				item = &lanterns[j];
				found = true;
			}
		}

		string date = getDate();
		if (found) {
			if (item->getStatus().compare("out")) {		// the item is not borrowed yet
				if (!item->getCondition().compare("good")) {		// the item has a good condition

					item->setStatus("out");
					user->borrowItem();

					string **tmpRecords = new string*[size + 1];
					for (int i = 0; i < size; i++) {
						tmpRecords[i] = records[i];
					}

					tmpRecords[size] = new string[7];
					tmpRecords[size][0] = date;
					tmpRecords[size][1] = item->getItemId();
					tmpRecords[size][2] = item->getItemName();
					tmpRecords[size][3] = "NA";
					tmpRecords[size][4] = user->getUsername();
					tmpRecords[size][5] = item->getStatus();
					size = size + 1;

					if (!records)
						delete[] records;
					records = tmpRecords;

					updateLoanRecord(records, size);
					updateEquipments(tents, stoves, lanterns);

					cout << "item " << input_itemId << " has been successfully borrowed." << endl;

					return;
				}
				else {		// bad condition
					cout << "item " << input_itemId << " is currently not available." << endl;
				}
			}
			else {		// status == out
				cout << "item " << input_itemId << " is currently borrowed by others." << endl;
			}

		}
		else {	// 404 item not found
			cout << "item " << input_itemId << " not found." << endl;
		}

	} // end of while

	cout << "User " << username << " has exceed the limit of allowed number of item borrowing." << endl;
}

// Return dynamic 2d array containing the "loan date", "borrowed equipment Ids", "equipment name" and "date of return" of user's borrowed items
string **getUserCurrentBorrowRecord(User* const& user, string *const*const records, int &size, int &idSize) {
	string str = "";
	string username = user->getUsername();
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (!records[i][4].compare(username)) {		// check whether is user related loan check

			string itemId = records[i][1];
			if (!records[i][5].compare("out")) {		// check whether equipment is borrowed by user in the past
				bool returned = false;

				// check whether the item has been returned
				for (int j = i + 1; j < size && !returned; j++) {
					if ((!records[j][4].compare(username)) && (!records[j][1].compare(itemId))) {		// if the record is match is related to the user and the item
						if (!records[j][5].compare("in")) {	// if record has showed the item has already been returned
							returned = true;
						}
					}
				}

				if (!returned) {
					str += records[i][0] + "|" + records[i][1] + "|" + records[i][2] + "|" + records[i][3] + "\n";
					count++;
				}
			}
		}
	}

	string **ids = new string*[count];
	for (int i = 0; i < count; i++) {
		ids[i] = new string[4]();
	}

	int j, k;
	j = k = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '|')
			k++;
		else if (str[i] == '\n') {
			k = 0;
			j++;
		}
		else
			ids[j][k] += str[i];
	}
	idSize = count;

	return ids;
}

void performDisplayUserBorrowedItem(User *const &user, Tent *const &tents, Stove *const &stoves, Lantern *const &lanterns, string** &records, int &size) {

	string **ids;

	int count;
	ids = getUserCurrentBorrowRecord(user, records, size, count);

	cout << endl;
	cout << "BORROWED EQUIPMENTS" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(15) << left << "LOAN DATE"
		<< setw(15) << left << "ITEM ID"
		<< setw(25) << left << "ITEM NAME"
		<< setw(20) << left << "DATE OF RETURN"
		<< endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < count; i++) {
		cout << setw(15) << left << ids[i][0]
			<< setw(15) << left << ids[i][1]
			<< setw(25) << left << ids[i][2]
			<< setw(20) << left << ids[i][3]
			<< endl;
	}

	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < count; i++) {
		delete[] ids[i];
	}
	delete[] ids;
}

void performReturnItem(User* const& user, Tent* const& tents, Stove* const& stoves, Lantern* const& lanterns, string** &records, int &size) {

	string username = user->getUsername();
	bool hasBorrow = (user->getNumberOfItemAllowed() != user->getMaxItem());
	string input_itemId;

	while (hasBorrow) {
		cout << endl;
		cout << "Please enter the item's Id that you wanted to return:  ";
		cin >> input_itemId;

		bool match = false;
		int count;
		int i = 0;
		string **borrowedIds = getUserCurrentBorrowRecord(user, records, size, count);
		do {
			if (!borrowedIds[i][1].compare(input_itemId))
				match = true;
			i++;
		} while (i < count && !match);
		string loan_date = records[i-1][0];

		if (match) {
			int total;
			bool found = false;
			Equipment *item = NULL;

			total = tents->getTotal();
			for (int j = 0; (j < total) && !found; j++) {
				if (!input_itemId.compare(tents[j].getItemId())) {
					item = &tents[j];
					found = true;
				}
			}

			total = stoves->getTotal();
			for (int j = 0; (j < total) && !found; j++) {
				if (!input_itemId.compare(stoves[j].getItemId())) {
					item = &stoves[j];
					found = true;
				}
			}

			total = lanterns->getTotal();
			for (int j = 0; (j < total) && !found; j++) {
				if (!input_itemId.compare(lanterns[j].getItemId())) {
					item = &lanterns[j];
					found = true;
				}
			}


			if (found) {
				string date = getDate();

				item->setStatus("in");
				user->returnItem();

				string **tmpRecords = new string*[size + 1];
				for (int i = 0; i < size; i++) {
					tmpRecords[i] = records[i];
				}

				tmpRecords[size] = new string[7];
				tmpRecords[size][0] = loan_date;
				tmpRecords[size][1] = item->getItemId();
				tmpRecords[size][2] = item->getItemName();
				tmpRecords[size][3] = date;
				tmpRecords[size][4] = user->getUsername();
				tmpRecords[size][5] = item->getStatus();
				size = size + 1;

				if (!records)
					delete[] records;
				records = tmpRecords;

				updateLoanRecord(records, size);
				updateEquipments(tents, stoves, lanterns);

				cout << "item " << input_itemId << " has been successfully returned." << endl;

				return;
			}
			else {	// 404 item not found
				cout << "item " << input_itemId << " not found." << endl;
			}
		}
	} // end of while

	cout << "User " << username << " has not borrow any equipment yet." << endl;
}