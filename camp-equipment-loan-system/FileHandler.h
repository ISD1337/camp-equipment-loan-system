#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>


class FileHandler
{
public:
	FileHandler();
	~FileHandler();

	string fileRead(string);
	void fileWrite(string, string);
};


