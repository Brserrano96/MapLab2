#include "Location.h"
using namespace std;


Location::Location(string name, int x, int y) : _name(name), _x(x), _y(y)
{
}


Location::~Location()
{
}

string Location::DisplayLocationInfo()
{
	return "Location is " + _name + " (" + to_string(_x) + "," + to_string(_y) + ") " + "\n";
}
