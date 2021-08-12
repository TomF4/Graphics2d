#pragma once

#include "GameCharacter.h"

class Enemy : public GameCharacter
{
private:

	float speed;

public:

	void  setSpeed(float spd) { speed = spd;  }
	float getSpeed()          { return speed; }

	using GameCharacter::GameCharacter;

	using GameCharacter::incVelocity;
	using GameCharacter::getVelocity;
	using GameCharacter::setVelocity;

	using GameCharacter::getPosX;
	using GameCharacter::getPosY;
	using GameCharacter::setPosX;
	using GameCharacter::setPosY;

	using GameCharacter::setHeading;
	using GameCharacter::getHeading;

	using GameCharacter::incHeading;
	using GameCharacter::incPos;

};