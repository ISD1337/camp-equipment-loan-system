#pragma once
#include <string>
using namespace std;

class User
{
protected:
	string userId;
	string username;
	string section;
	string dob;
	string address;

	// number of items left that allowed to borrow
	int items;
	int MAX_ITEMS;

public:
	string getUserId();
	string getUsername();
	string getSection();
	string getPassword();
	string getAddress();

	User(string _userId, string _username, string _section,
		string _dob, string _address);
};

// RoverScout publicly inheriting User
class RoverScout : public User
{
public:
	RoverScout(string _userId, string _username, string _section,
		string _dob, string _address);
};

// VentureScout publicly inheriting User
class VentureScout : public User
{
public:
	VentureScout(string _userId, string _username, string _section,
		string _dob, string _address);
};

// Scout publicly inheriting User
class Scout : public User
{
protected:
	string rank;
	virtual int findMaxItems(string _rank);

public:
	string getRank();

	Scout(string _userId, string _username, string _section,
		string _dob, string _address, string _rank);
};

// Scouter publicly inheriting Scout
class Scouter : public Scout
{
protected:
	virtual int findMaxItems();
};
