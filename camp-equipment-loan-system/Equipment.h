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

	static int totalOf;

public:
	string getItemId();
	string getItemName();
	string getBrand();
	string getItemType();
	string getDateOfPurchase();
	string getCondition();
	string getStatus();
	virtual int getTotal();

	bool setCondition(string condition);
	bool setStatus(string status);

	virtual Equipment& operator= (const Equipment &eq);

	Equipment();
	Equipment(const Equipment &eq);
	Equipment(string itemId, string itemName, string brand, string itemType,
		string dateOfPurchase, string condition, string status);
	virtual ~Equipment();
};

class Tent : public Equipment
{
private:
	string _tentSize;
	string _tentType;
	string _numberOfDoors;
	string _isDoubleLayer;
	string _colour;

	static int totalOfTent;	

public:
	string getTentSize();
	string getTentType();
	string getNumberOfDoors();
	string getIsDoubleLayer();	
	string getColour();
	virtual int getTotal();

	virtual Tent& operator= (const Tent &t);

	Tent();
	Tent(const Tent &t);
	Tent(string itemdid, string itemName, string brand, string itemType,
		string dateOfPurchase, string condition, string status,
		string tentSize, string tentType, string numberOfDoors, string isDoubleLayer, string colour);
	~Tent();
	
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
	virtual int getTotal();

	virtual Stove& operator= (const Stove &st);

	Stove();
	Stove(const Stove &st);
	Stove(string itemId, string itemName, string brand, string itemType,
		string dateOfPurchase, string condition, string status,
		string stoveType, string fuelType);
	~Stove();
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
	virtual int getTotal();

	virtual Lantern& operator= (const Lantern &lan);

	Lantern();
	Lantern(const Lantern &lan);
	Lantern(string itemId, string itemName, string brand, string itemType,
		string dateOfPurchase, string condition, string status,
		string lanternSize, string lanternType, string fuelType);
	~Lantern();

};


