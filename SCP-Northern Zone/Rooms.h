#pragma once

#include <iostream>
#include <conio.h>
#include <string>
#include <Math.h>
#include "Draw.h"
#include "Actors.h"
#include "Vectors.h"

class Room {
protected: int id;
protected: string enemy;
protected: float heal;
protected: string discription;
		 Room()
		 {
			 this->id = 0;
			 this->enemy = "no";
			 this->heal = 0;
			 this->discription = "standartRoom";

		 }
		 Room( string enemy, float heal, string discription)
		 {
			 this->id = 0;
			 this->enemy = enemy;
			 this->heal = heal;
			 this->discription = discription;

		 }
public: static void loadRoom(int Id) 
{
	string line;
	ifstream file(Id + ".txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			cout << line << endl;
		}
	}
	file.close();
}
};