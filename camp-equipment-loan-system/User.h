#pragma once
#include <string>

class User
{
protected:
	string _userId;
	string _username;
	string _section;
	string _dob;
	string _address;

	// number of items left that allowed to borrow
	int items;
	int MAX_ITEMS;

public:
	string getUserId();
	string getUsername();
	string getSection();
	string getPassword();
	string getAddress();

	User(string userId, string username, string section,
		string dob, string address);
};

// RoverScout publicly inheriting User
class RoverScout : public User
{
public:
	RoverScout(string userId, string username, string section,
		string dob, string address);
};

// VentureScout publicly inheriting User
class VentureScout : public User
{
public:
	VentureScout(string userId, string username, string section,
		string dob, string address);
};

// Scout publicly inheriting User
class Scout : public User
{
protected:
	string _rank;
	virtual int findMaxItems(string rank);

public:
	string getRank();

	Scout(string userId, string username, string section,
		string dob, string address, string rank);
};

// Scouter publicly inheriting Scout
class Scouter : public Scout
{
protected:
	virtual int findMaxItems();
};
