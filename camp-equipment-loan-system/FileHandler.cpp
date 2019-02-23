#include "FileHandler.h"



FileHandler::FileHandler()
{
}


FileHandler::~FileHandler()
{
}

char* FileHandler::fileRead(const char* path) {
	ifstream fileInput;
	char *buffer = new char[100]();
	int count = 0;

	fileInput.open(path, ios::in);
	if (!fileInput.is_open()) {
		perror("Error opening file");

		return NULL;
	}
	else {
		while (!fileInput.eof()) {
			fileInput.get(buffer[count]);
			count++;
		}

		fileInput.close();
	}

	return buffer;
}

void FileHandler::fileWrite(const char* path, const char* text) {
	ofstream fileOutput;

	fileOutput.open(path, ios::out);

	cout << fileOutput.is_open() << endl;

	if (!fileOutput.is_open()) {
		perror("Error opening file");
		cout << "Creating New File \"" << path << "\"..." << endl;
	}
	else {
		fileOutput << text;
		fileOutput.close();
	}
}
