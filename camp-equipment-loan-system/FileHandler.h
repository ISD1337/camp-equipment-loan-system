#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

class FileHandler
{
public:
	FileHandler();
	~FileHandler();

	char* fileRead(const char*);
	void fileWrite(const char*, const char*);
};


