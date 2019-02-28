#include "System.h"

#define EQUIPMENT_PATH "txt/camp_equipment.txt"
using namespace std;

Equipment **getEquipments() {
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

		Tent *tents = new Tent[cTent];
		Stove *stoves = new Stove[cStove];
		Lantern *lanterns = new Lantern[cLantern];
		Equipment *equipments[] = { tents, stoves, lanterns };

		string *tmp= new string[12]();

		int j = 0;
		int nTent, nStove, nLantern;
		nTent = nStove = nLantern = 0;
		for (int i = 0; i < len; i++) {

			if (isWordCharacter(str[i])) {
				tmp[j] += str[i];

				if (str[i+1] == '\n') {
					char c = tmp[0][0];

					if (c == 'T')
					{
						Tent tempObj(tmp[0], tmp[1], tmp[2], tmp[3],
							tmp[4], tmp[5], tmp[6], 
							tmp[7],	tmp[8], tmp[9], tmp[10], tmp[11]);

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

		return equipments;

	}

	return NULL;
}

void system() {
	Equipment **equipments = getEquipments();

	if (equipments) {
		Tent *tents = (Tent*)equipments[0];
		Stove *stoves = (Stove*)equipments[1];
		Lantern *lanterns = (Lantern*)equipments[2];

		cout << "camp_equipment.txt existed, "
			<< " "
			<< "preparing login section..." << endl;

		cout << "Done." << endl;
		cout << endl;

		string username;
		string *user;

		do {
			cout << "Please enter the username: ";
			cin >> username;

			user = getUserInformation(username);
			if (user)
				break;

			cout << "User "
				<< username
				<< " does not exited, "
				<< "enter again" 
				<< endl << endl;
		} while (true);

		cout << "Welcome " << username << endl;


		// release memory
		delete[] tents;
		delete[] stoves;
		delete[] lanterns;
	}
	else {
		cout << "camp_equipment.txt not found:"
			<< "please put camp_equipment.txt into root directory /txt"
			<< endl;
	}
	cout << "============ Till We Meet Again ============" << endl;
}