#include "LoginSystem.h"

bool isWordCharacter(char c) {

	bool flag = false;

	if		(c >= '0' && c <= '9')
		flag = true;
	else if (c >= 'A' && c <= 'Z')
		flag = true;
	else if (c >= 'a' && c <= 'z')
		flag = true;
	else if (c == ' ' || c == ', ')
		flag = true;

	return flag;
}

string *getUserInformation(string userInput) {
	FileHandler handler;
	string str = handler.fileRead(USER_PATH);

	string *userInfo = new string[7]();
	
	if (!str.empty()) {
		int len = str.length();
		int j = 0;

		string tmp = "";
		for (int i = 0; i < len; i++) {

			if (isWordCharacter(str[i])) {
				tmp = tmp + str[i];
			}
			else if (str[i] == '\n') {
				if (userInfo[0].compare(userInput))
					return userInfo;

				delete userInfo;
				userInfo = new string[7]();

				j = 0;
			}
			else if (str[i] == '|') {
					userInfo[j] = tmp;
					tmp = "";
					j++;
			}
		}
	}

	// release memory
	delete [] userInfo;
		
	return NULL;
}

void login() {
}