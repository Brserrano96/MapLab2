#pragma once
#include <stack>
#include "Location.h"
#include <unordered_map>
#include <vector>
#include <iostream> 
using namespace std;
class Map
{
private:
	vector <string> _toHome;
	stack<Location *> _locationsVisited;
	unordered_map<string, Location *> _mapLookup;
public:
	void addedDirections(string Way)
    {
		_toHome.push_back(Way);
	}
	void displayWayHome()
    {
		cout << "Hello There, You got here by taking this path" << endl;
		for (auto x = 0; x < _toHome.size(); x++)
        {
			cout << _toHome[x] << endl;
		
		}
	}
	Map(string startLocationName);
	~Map();

	Location * CurrentLocation = nullptr;
	string GetPathBackToHome()
    {
		displayWayHome();
		return "I will like to wish you a great journey back";
	}

	void Move(Location *newLocation);
	Location * LookupLocationOnMap(int x, int y);
};

