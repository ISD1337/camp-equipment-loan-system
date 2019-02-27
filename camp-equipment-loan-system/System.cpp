#include "System.h"

#define EQUIPMENT_PATH "txt/camp_equipment.txt"
using namespace std;

Equipment *getEquipemts() {
	FileHandler handler;
	string str = handler.fileRead(EQUIPMENT_PATH);

	if (!str.empty()) {
		int len = str.length;
		int cTent, cStove, cLantern;
		cTent = cStove = cLantern = 0;
		int ieol = 0;

		// count the number of Tent, Stove and Lantern
		for (int i = 0; i < len; i++) {

			if (isWordCharacter(str[i])) {
				ieol++;
			}
			else if (str[i] == '\n') {
				char c = str[i - ieol];

				if (c == 'T')
					cTent++;
				else if (c == 'S')
					cStove++;
				else if (c == 'L')
					cLantern++;

				ieol = 0;
			}
		}

		Tent *tents = new Tent[cTent];
		Stove *stoves = new Stove[cStove];
		Lantern *lanterns = new Lantern[cLantern];
		Equipment *equipments [] = { tents, stoves, lanterns };

		string tmp[10];
		tmp->clear;

		int j = 0;
		int nTent, nStove, nLantern;
		nTent = nStove = nLantern = 0;
		for (int i = 0; i < len; i++) {

			if (isWordCharacter(str[i])) {
				tmp[j] += str[i];
			}
			else if (str[i] == '\n') {
				char c = tmp[j][0];

				if (c == 'T')
				{
					Tent *t = new Tent("", "", "", "", "","", "", "", "", "","", "");
					tents[i] = *t;

					delete t;
				}
				else if (c == 'S')
				{

				}
				else if (c == 'L')
				{

				}
				
			}
		}

	}

	return NULL;
}

void system() {

}