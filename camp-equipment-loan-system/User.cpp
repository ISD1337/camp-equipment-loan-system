#include "User.h"


User::User(string _userId, string _username, string _section,
	string _dob, string _address)
{
	userId		= _userId;
	username	= _username;
	section		= _section;
	dob			= _dob;
	address		= _address;
}

string User::getUserId()
{
	return userId;
}

string User::getUsername()
{
	return username;
}

string User::getSection()
{
	return section;
}

string User::getPassword()
{
	return dob;
}

string User::getAddress()
{
	return address;
}

RoverScout::RoverScout(string _userId, string _username, string _section,
	string _dob, string _address)
	: User(_userId, _username, _section, _dob, _address)
{
	MAX_ITEMS = 5;
	items = MAX_ITEMS;
}

VentureScout::VentureScout(string _userId, string _username, string _section,
	string _dob, string _address)
	: User(_userId, _username, _section, _dob, _address)
{
	MAX_ITEMS = 3;
	items = MAX_ITEMS;
}

Scout::Scout(string _userId, string _username, string _section,
	string _dob, string _address, string _rank)
	: User(_userId, _username, _section, _dob, _address) 
{
	rank		= _rank;
	MAX_ITEMS	= findMaxItems(_rank);
	items		= MAX_ITEMS;
}

int Scout::findMaxItems(string _rank)
{
	int max;
	if (_rank.compare("Patrol Leader"))
		max = 3;
	else if (_rank.compare("Assistant Patrol Leader"))
		max = 3;
	else
		max = 1;

	return max;
}

string Scout::getRank()
{
	return rank;
}

int Scouter::findMaxItems()
{
	int max = 5;
	return max;
}

