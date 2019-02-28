#pragma once
#include <iostream>
#include <stdlib.h>
#include "FileHandler.h"
#include "User.h"
using namespace std;

#define USER_PATH "txt/user.txt"

bool isWordCharacter(char c);

string *getUserInformation(string userInput);