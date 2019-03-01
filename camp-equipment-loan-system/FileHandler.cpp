#include "FileHandler.h"
using namespace std;

FileHandler::FileHandler()
{
}


FileHandler::~FileHandler()
{
}

// get string from .txt file
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

// write file with string
void FileHandler::fileWrite(string const* ptext, string path) {
	ofstream fileOutput;

	fileOutput.open(path, std::ios::out);

	if (fileOutput) {
		fileOutput << *ptext;
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
