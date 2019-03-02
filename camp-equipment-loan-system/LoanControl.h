#pragma once
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include "Equipment.h"
#include "User.h"
#include "FileHandler.h"
using namespace std;	// delete this

bool isWordCharacter(char c);

void getUserInformation(User *&user, string userInput);

void convertUserInformation(User *&user, string *const userInfo);

void getEquipments(Tent*& tents, Stove*& stoves, Lantern*& lanterns);

void updateEquipments(Tent* const&tents, Stove* const&stoves, Lantern* const&lanterns);

void getLoanRecord(string **&records, int &size);

void updateLoanRecord(string *const*const records, int size);

void performDisplayLoanAvailableItem(Tent * const & tents, Stove * const & stoves, Lantern * const & lanterns);

void performBorrowEquipment(User* const& user, Tent* const& tents, Stove* const& stoves, Lantern* const& lanterns, string**& records, int &size);

void performDisplayUserBorrowedItem(User* const& user, Tent* const& tents, Stove* const& stoves, Lantern* const& lanterns, string**& records, int &size);
