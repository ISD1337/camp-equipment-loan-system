#pragma once
#include <stdlib.h>
#include "Equipment.h"
#include "User.h"
#include "FileHandler.h"
using namespace std;	// delete this

bool isWordCharacter(char c);

void getUserInformation(string *&userInfo, string userInput);

void getEquipments(Tent *&tents, Stove *&stoves, Lantern *&lanterns);

void updateEquipments(Equipment *const*const equipments);

void getLoanRecord(string **&records, int &size);

void updateLoanRecord(string *const*const records, int size);