#pragma once

class User
{
protected:
	char *userId;
	char *username;
	char *section;
	char *dob;
	char *address;

public:
	virtual char *getUserId();
	virtual char *getUsername();
	virtual char *getSection();
	virtual char *getPassword();
	virtual char *getAddress();

	User(char *const _userId, char *const _username, char *const _section,
		char *const _dob, char *const _address);
	virtual ~User();
};

// RoverScout publicly inheriting User
class RoverScout : public User
{

};

// VentureScout publicly inheriting User
class VentureScout : public User
{

};

// Scout publicly inheriting User
class Scout : public User
{
protected:
	char *rank;

public:
	Scout(char *const _userId, char *const _username, char *const _section,
		char *const _dob, char *const _address, char *const _rank);
	virtual ~Scout();
};

// Scouter publicly inheriting Scout
class Scouter : public Scout
{

};
