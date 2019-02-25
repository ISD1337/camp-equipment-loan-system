#include "LoginSystem.h"


bool match(char *const username, char *const userInput) {

	for (int i = 0; ; i++) {
		if ((username[i] != userInput[i]) || (username[i] == '\0') || (userInput[i] == '\0'))
			return false;

	}

	return true;

}

char **findUserInformation(char *const userInput) {
	FileHandler handler;
	char *str = handler.fileRead(USER_PATH);
	
	char **user = new char*[20]();

	int count = 0;
	int i, j;

	do {
		for (i = 0; i < 7; i++) {
			if (str[count + 1] == '\n')
				break;

			for (j = 0 ; (str[count+1] != '|'); j++) {
				user[i][j] = str[count];
			}

		}

		if (match(user[i], userInput))
			return user;

	} while (str[count] != '\0');
		
	return NULL;
}

void login() {
	
}