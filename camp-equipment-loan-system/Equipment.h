#pragma once
#include <string>
using namespace std;

class Equipment
{
protected:
	string itemID;
	string itemName;
	string brand;
	string itemType;
	string dataOfPurchase;
	string condition;
	string status;

public:
	Equipment(string _itemID, string _itemName, string _brand, string _itemType,
		string _dataOfPurchase, string _condition, string _status);
	~Equipment();
};

class Tent : public Equipment
{
private:
	string tentSize;
	string tentType;
	string numberOfDoors;
	string doubleLayer;

public:

	Tent(string _itemID, string _itemName, string _brand, string _itemType,
		string _dataOfPurchase, string _condition, string _status,
		string _tentSize, string _tentType, string _numberOfDoors, string _doubleLayer);
	

};

class Stove : public Equipment
{
private:
	string stoveType;
	string fuelType;

public:
	Stove(string _itemID, string _itemName, string _brand, string _itemType,
		string _dataOfPurchase, string _condition, string _status,
		string _stoveType, string fuelType);
};

class Lantern : public Equipment
{
private:
	string lanternSize;
	string lanternType;
	string fuelType;

public:
	Lantern(string _itemID, string _itemName, string _brand, string _itemType,
		string _dataOfPurchase, string _condition, string _status,
		string _lanternSize, string lanternType, string fuelType);
};

