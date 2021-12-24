#pragma once

#include "Vectors.h"

class Actor
{
protected:
	double x, y;
	string name;
public:
	Actor()
	{
		this->x = 0;
		this->y = 0;
		this->name = "DefaultActor";
	}
	Actor(double x) :Actor()
	{
		this->x = x;
	}
	Actor(double x, double y) : Actor(x)
	{
		this->y = y;
	}
	Actor(string name) :Actor()
	{
		this->name = name;
	}
	public: virtual void moveToPosition(double newX, double newY) 
	{
		this->x = newX;
		this->y = newY;
	}
	public: virtual void moveToPosition(const Vector2& newPosition)
	{
		this->x = newPosition.x;
		this->y = newPosition.y;
	}
	public: Vector2 getPosition()
	{
		Vector2 position(this->x, this->y);
		return position;
	}
};

class Player: public Actor
{
public:
	double move;
	double hitPoints;
	double maxHP;
	double toughness;
	double save;
	double strength;

public:
	Player() 
	{
		this->x = 0;
		this->y = 0;
		this->move = 1;
		this->hitPoints = 5;
		this->maxHP = 5;
		this->toughness = 3;
		this->save = 4;
		this->strength = 3;
	}
	Player(double x) :Player()
	{
		this->x = x;
	}
	Player(double x, double y) : Player(x)
	{
		this->y = y;
	}
	Player(double x, double y, double hitPoints, double maxHP, double toughness, double save, double strength) : Player(x, y)
	{
		this->hitPoints = hitPoints;
		this->maxHP = maxHP;
		this->toughness = toughness;
		this->save = save;
		this->strength = strength;
	}

public: virtual void moveToPosition(double deltaX, double deltaY)
{
	if (abs(deltaX) > move)
		this->x = this->x + move;
	else
		this->x = this->x + deltaX;
	if (abs(deltaY) > move)
		this->y = this->y + move;
	else
		this->y = this->y + deltaY;
}
public: virtual void moveToPosition(const Vector2& deltaPosition)
{
	if (abs(deltaPosition.x) > move)
		this->x = this->x + move;
	else
		this->x = this->x + deltaPosition.x;
	if (abs(deltaPosition.y) > move)
		this->y = this->y + move;
	else
		this->y = this->y + deltaPosition.y;
}

};

class Enemy : public Player
{
public:
	double criticalChance;
public:
	Enemy()
	{
		this->x = 0;
		this->y = 0;
		this->move = 1;
		this->hitPoints = 3;
		this->maxHP = 3;
		this->toughness = 2;
		this->save = 5;
		this->strength = 4;
		this->criticalChance = 4;
	}
	Enemy(double x, double y, double hitPoints, double maxHP, double toughness, double save, double strength, double criticalChance) : Enemy()
	{
		this->hitPoints = hitPoints;
		this->maxHP = maxHP;
		this->toughness = toughness;
		this->save = save;
		this->strength = strength;
		this->criticalChance = criticalChance;
	}
};