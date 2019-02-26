#include "FileHandler.h"



FileHandler::FileHandler()
{
}


FileHandler::~FileHandler()
{
}

string FileHandler::fileRead(string path) {
	ifstream fileInput;
	string s = "";

	fileInput.open(path, ios::in);
	if (fileInput) {
		stringstream buffer;
		buffer << fileInput.rdbuf();
		s = buffer.str();

		fileInput.close();
	}
	else {
		perror("Error opening file");
	}

	return s;
}

void FileHandler::fileWrite(string path, string text) {
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
