#pragma once
#include <string>
using namespace std;
class Location
{
private:
	string _name;
	int _x;
	int _y;
	
public:
	Location(string name, int x, int y);
	~Location();
	string DisplayLocationInfo();

	Location *North = nullptr;
	Location *South = nullptr;
	Location *East = nullptr;
	Location *West = nullptr;

	int getX() { return _x; }
	int getY() { return _y; }
};

