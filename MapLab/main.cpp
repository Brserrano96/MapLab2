//
//  main.cpp
//  MapLab
//
//  Created by BRANDON SERRANO on 4/7/17.
//  Copyright © 2017 Trendsverse. All rights reserved.
//

#include <iostream>
#include "Map.h"
using namespace std;

void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);


int main()
{
	auto map = Map("Home");
	int choice = -1;
	while (choice != 0) 
	{
		system("cls");
		cout << "1) Display Current Location" << endl;
		cout << "2) Go North" << endl;
		cout << "3) Go East" << endl;
		cout << "4) Go South" << endl;
		cout << "5) Go West" << endl;
		cout << "6) Ready to head Home" << endl;
		cout << "0) Exit" << endl;
		cin >> choice;

		switch (choice) 
		{
		case 1: cout << "Current Location: " << map.CurrentLocation->DisplayLocationInfo(); break;
		case 2: GoNorth(map); break;
		case 3: GoEast(map); break;
		case 4: GoSouth(map); break;
		case 5: GoWest(map); break;
		case 6: system("cls");  cout << map.GetPathBackToHome() << endl; break;
		default: cout << "Enter a valid option"; break;
		}
		system("pause");
	}
	
	return 0;
}

void GoNorth(Map &map) 
{
	auto newLocation = map.CurrentLocation->North;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();
	if (newLocation == nullptr) 
	{
		
		int newX = currentX;
		int newY = currentY + 1; 
		auto existing = map.LookupLocationOnMap(newX, newY);
		if (existing == nullptr)
		{
			system("cls");
			cout << "You haven't been here before, Please enter a name for this new place: ";
			string name;
			cin >> name;
			newLocation = new Location(name, newX, newY);
			cout << "This place is now called: " + name << endl;
			string direction = name + " (" + to_string(newX) + "," + to_string(newY) + ")";
			map.addedDirections(direction);

		}
		else
        {
			cout << "You've been here before." << existing->DisplayLocationInfo();
			newLocation = existing;
		}
	}
	else
	{
		cout << "You're at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->South = map.CurrentLocation;
	map.CurrentLocation->North = newLocation;
	map.Move(newLocation);
	
	return;
}

void GoEast(Map &map)
{
	auto newLocation = map.CurrentLocation->East;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();
	if (newLocation == nullptr)
	{

		int newX = currentX +1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);
		if (existing == nullptr)
		{
			system("cls");
			cout << "You haven't been here before, enter a name for this place: ";
			string name;
			cin >> name;
			newLocation = new Location(name, newX, newY);
			cout << "This place is now called: " + name << endl;
			string direction = name  + " (" + to_string(newX) + "," + to_string(newY) + ")";
			map.addedDirections(direction);

		}
		else
        {
			cout << "You've been here before." << existing->DisplayLocationInfo();
			newLocation = existing;
		}
	}
	else
	{
		cout << "You're at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->West = map.CurrentLocation;
	map.CurrentLocation->East = newLocation; 
	map.Move(newLocation);
	return;
}

void GoSouth(Map &map)
{
	auto newLocation = map.CurrentLocation->South;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();
	if (newLocation == nullptr)
	{

		int newX = currentX;
		int newY = currentY - 1;
		auto existing = map.LookupLocationOnMap(newX, newY);
		if (existing == nullptr)
		{
			system("cls");
			cout << "You haven't been here before, enter a name for this place: ";
			string name;
			cin >> name;
			newLocation = new Location(name, newX, newY);
			cout << "This place is now called: " + name << endl;
			string direction = name  + " (" + to_string(newX) + "," + to_string(newY) + ")";
			map.addedDirections(direction);
		}
		else
        {
			cout << "You've been here before." << existing->DisplayLocationInfo();
			newLocation = existing;
		}
	}
	else
	{
		cout << "You're at: " + newLocation->DisplayLocationInfo();
		
	}
	newLocation->North = map.CurrentLocation;
	map.CurrentLocation->South = newLocation;
	map.Move(newLocation);
	return;
}

void GoWest(Map &map)
{
	auto newLocation = map.CurrentLocation->West;
	int currentX = map.CurrentLocation->getX();
	int currentY = map.CurrentLocation->getY();
	if (newLocation == nullptr)
	{

		int newX = currentX -1 ;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);
		if (existing == nullptr)
		{
			system("cls");
			cout << "You haven't been here before, enter a name for this place: ";
			string name;
			cin >> name;
			newLocation = new Location(name, newX, newY);
			cout << "This place is now called: " + name << endl;
			string direction = name  + " (" + to_string(newX) + "," + to_string(newY) + ")";
			map.addedDirections(direction);
		}
		else
        {
			cout << "You've been here before." << existing->DisplayLocationInfo();
			newLocation = existing;
		}
	}
	else
	{
		cout << "You're at: " + newLocation->DisplayLocationInfo();
	}
	newLocation->East = map.CurrentLocation;
	map.CurrentLocation->West = newLocation;
	map.Move(newLocation);
	return;
}
