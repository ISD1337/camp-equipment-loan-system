#pragma once
#include <string>
using namespace std;

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

public:
	string getItemId();
	string getItemName();
	string getBrand();
	string getItemType();
	string getDateOfPurchase();
	string getCondition();
	string getStatus();

	void setCondition(string condition);
	void setStatus(string status);

	Equipment(string itemId, string itemName, string brand, string itemType,
		string DateOfPurchase, string condition, string status);
};

class Tent : public Equipment
{
private:
	string _tentSize;
	string _tentType;
	string _numberOfDoors;
	string _isDoubleLayer;

public:
	string getTentSize();
	string getTentType();
	string getNumberOfDoors();
	string getIsDoubleLayer();	

	Tent(string itemdD, string itemName, string brand, string itemType,
		string DateOfPurchase, string condition, string status,
		string tentSize, string tentType, string numberOfDoors, string isDoubleLayer);
	

};

class Stove : public Equipment
{
private:
	string _stoveType;
	string _fuelType;

public:
	string getStoveType();
	string getFuelType();

	Stove(string itemId, string itemName, string brand, string itemType,
		string DateOfPurchase, string condition, string status,
		string stoveType, string fuelType);
};

class Lantern : public Equipment
{
private:
	string _lanternSize;
	string _lanternType;
	string _fuelType;

public:
	string getLanternSize();
	string getLanternType();
	string getFuelType();

	Lantern(string itemId, string itemName, string brand, string itemType,
		string DateOfPurchase, string condition, string status,
		string lanternSize, string lanternType, string fuelType);
};


