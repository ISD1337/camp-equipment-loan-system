#include "FileHandler.h"



FileHandler::FileHandler()
{
}


FileHandler::~FileHandler()
{
}

char* FileHandler::fileRead(const char* path) {
	std::ifstream fileInput;

	char *buffer;

	fileInput.open(path, std::ifstream::binary);
	if (fileInput) {

		// get length of file
		fileInput.seekg(0, fileInput.end);
		int length = fileInput.tellg();
		length = length + 1;
		fileInput.seekg(0, fileInput.beg);

		buffer = new char[length]();

		fileInput.read(buffer, length);

		fileInput.close();
	}
	else {
		perror("Error opening file");

		return NULL;
	}

	return buffer;
}

void FileHandler::fileWrite(const char* path, const char* text) {
	std::ofstream fileOutput;

	fileOutput.open(path, std::ios::out);

	if (fileOutput) {
		fileOutput << text;
		fileOutput.close();
	}
	else {
		perror("Error opening file");
		std::cout << "Creating New File \""
			<< path
			<< "\"..."
			<< std::endl;
	}
}
