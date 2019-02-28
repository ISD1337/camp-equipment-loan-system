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
		Equipment *equipments [] = { tents, stoves, lanterns };

		string tmp[12];
		tmp->clear();

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
						Tent tempEquip(tmp[0], tmp[1], tmp[2], tmp[3],
							tmp[4], tmp[5], tmp[6], false,
							tmp[7], tmp[8], tmp[9], tmp[10], tmp[11]);
						tents[nTent] = tempEquip;
					}
					else if (c == 'S')
					{
						Stove tempEquip(tmp[0], tmp[1], tmp[2], tmp[3],
							tmp[4], tmp[5], tmp[6], false,
							tmp[7], tmp[8]);
						stoves[nStove] = tempEquip;
					}
					else if (c == 'L')
					{
						Lantern tempEquip(tmp[0], tmp[1], tmp[2], tmp[3],
							tmp[4], tmp[5], tmp[6], false,
							tmp[7], tmp[8], tmp[9]);
						lanterns[nLantern] = tempEquip;
					}

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

void startSystem() {
	Equipment **equipments = getEquipments();

	if (equipments) {
		cout << equipments[0]->getTotal();
	}
	else
		cout << "Equipment not found"
			 << endl;
}