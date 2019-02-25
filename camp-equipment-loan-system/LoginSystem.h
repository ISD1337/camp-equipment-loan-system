#pragma once
#include <iostream>
#include <stdlib.h>
#include "FileHandler.h"
#include "User.h"

#define USER_PATH "txt/user.txt"

bool match(char *const username, char *const userInput);

char **findUserInformation(char *const userInput);