#pragma once
#include <iostream>
#include <stdlib.h>
#include "FileHandler.h"
#include "User.h"

#define USER_PATH "txt/user.txt"

string *getUserInformation(string userInput);

void login();