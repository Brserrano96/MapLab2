#include "Map.h"
using namespace std;


Map::Map(string startLocationName)
{
	CurrentLocation = new Location(startLocationName, 0, 0);
	string hash = "(0,0)";
	_mapLookup[hash] = CurrentLocation;
}


Map::~Map()
{
}

void Map::Move(Location *newLocation) 
{	
	_locationsVisited.push(newLocation);
	CurrentLocation = newLocation;
}

Location * Map::LookupLocationOnMap(int x, int y)
{
	string hash = "(" + to_string(x) + "," + to_string(y) + ")";
	return _mapLookup[hash];
}
