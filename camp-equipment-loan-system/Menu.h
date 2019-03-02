#pragma once
#include <iostream>
#include <stdlib.h>
#include "LoanControl.h"
using namespace std; // delete this

void menu();

int selectMenu(User *& user);

bool executeMenu(int choice, User *const &user, Tent *const &tents, Stove *const &stoves, Lantern *const &lanterns, string**& records, int &size);