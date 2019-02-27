#pragma once
#include <string>
using namespace std;		// delete this, screw visual studio

class Equipment
{
protected:
	string _itemId;
	string _itemName;
	string _brand;
	string _itemType;
	string _dateOfPurchase;
	string _condition;
	string _status;
	string _isBorrowed;

	static int totalOf;

public:
	string getItemId();
	string getItemName();
	string getBrand();
	string getItemType();
	string getDateOfPurchase();
	string getCondition();
	string getStatus();
	string borrowed();

	bool setCondition(string condition);
	bool setStatus(string status);
	void setBorrowed(bool isBorrow);

	void operator= (const Equipment &eq);

	Equipment();
	Equipment(const Equipment &eq);
	Equipment(string itemId, string itemName, string brand, string itemType,
		string dateOfPurchase, string condition, string status, bool isBorrowed);
};

class Tent : public Equipment
{
private:
	string _tentSize;
	string _tentType;
	string _numberOfDoors;
	string _isDoubleLayer;

	static int totalOfTent;

public:
	string getTentSize();
	string getTentType();
	string getNumberOfDoors();
	string getIsDoubleLayer();	

	void operator= (const Tent &t);

	Tent();
	Tent(const Tent &t);
	Tent(string itemdD, string itemName, string brand, string itemType,
		string dateOfPurchase, string condition, string status, bool isBorrowed,
		string tentSize, string tentType, string numberOfDoors, string isDoubleLayer);
	
};

class Stove : public Equipment
{
private:
	string _stoveType;
	string _fuelType;

	static int totalOfStove;

public:
	string getStoveType();
	string getFuelType();

	void operator= (const Stove &st);

	Stove();
	Stove(const Stove &st);
	Stove(string itemId, string itemName, string brand, string itemType,
		string dateOfPurchase, string condition, string status, bool isBorrowed,
		string stoveType, string fuelType);
};

class Lantern : public Equipment
{
private:
	string _lanternSize;
	string _lanternType;
	string _fuelType;

	static int totalOfLantern;

public:
	string getLanternSize();
	string getLanternType();
	string getFuelType();

	void operator= (const Lantern &lan);

	Lantern();
	Lantern(const Lantern &lan);
	Lantern(string itemId, string itemName, string brand, string itemType,
		string dateOfPurchase, string condition, string status, bool isBorrowed,
		string lanternSize, string lanternType, string fuelType);

};


