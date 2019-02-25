#include "User.h"


char *User::getUserId()
{
	return (this->userId);
}

char *User::getUsername()
{
	return (this->username);
}

char *User::getSection()
{
	return (this->section);
}

char *User::getPassword()
{
	return (this->dob);
}

char *User::getAddress()
{
	return (this->address);
}

User::User(char *const _userId, char *const _username, char *const _section,
	char *const _dob, char *const _address)
{
	this->userId	= _userId;
	this->username	= _username;
	this->section	= _section;
	this->dob		= _dob;
	this->address	= _address;
}


User::~User()
{
	delete this->userId;
	delete this->username;
	delete this->section;
	delete this->dob;
	delete this->address;
}

Scout::Scout(char *const _userId, char *const _username, char *const _section,
	char *const _dob, char *const _address, char *const _rank)
	: User(_userId, _username, _section, _dob, _address) 
{
	this->rank = _rank;
}

Scout::~Scout()
{
	delete this->userId;
	delete this->username;
	delete this->section;
	delete this->dob;
	delete this->address;
	delete this->rank;
}
