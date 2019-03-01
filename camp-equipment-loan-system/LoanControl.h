#pragma once
#include <stdlib.h>
#include "Equipment.h"
#include "User.h"
#include "FileHandler.h"
using namespace std;	// delete this

bool isWordCharacter(char c);

string *getUserInformation(string userInput);

Equipment **getEquipments();

void updateEquipments(Equipment *const*const equipments);

string **getLoanRecord();

void updateLoanRecord(string *const*const records);