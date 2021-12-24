#pragma once
#include <string>
#include <cstring>
#include <fstream>

using namespace std;
class Drawer 
{
protected:
	double x, y;
	Drawer()
	{
		this->x = 0;
		this->y = 0;
	}
public: static void Draw(string pic)
	{
    string line;
    ifstream file(pic);
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