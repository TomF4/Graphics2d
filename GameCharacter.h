#pragma once

#include "GL\glew.h"
#include "GL\wglew.h"
#include "GL\freeglut.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#pragma comment(lib, "glew32.lib")

#include <ctime>

extern float deltaTime;
#include "Sprite.h"
#include "shaders/Shader.h"
#include <iostream>

class GameCharacter
{
private:

	Sprite sprite;

	float Angle = 0.0f;
	float Velocity = 0.0f;
	float PosX, PosY = 0.0f;
	float Heading = 0.0f;

	#define PI 3.1415926535897932384626433832795

public:

	GameCharacter(Sprite spr, float x, float y) {
		sprite = spr;
		PosX = x;
		PosY = y;
	};

	void incPos(){
		PosX += Velocity * cos((90.0f + Heading) * (PI / 180.0f)) * deltaTime;
		PosY += Velocity * sin((90.0f + Heading) * (PI / 180.0f)) * deltaTime;
	}
	void decreasePos(){
		PosX -= Velocity * 4.2f * cos((90.0f + Heading) * (PI / 180.0f)) * deltaTime;
		PosY -= Velocity * 4.2f * sin((90.0f + Heading) * (PI / 180.0f)) * deltaTime;
	}

	//getters and setters
	float getPosX()                   { return PosX; }
	float getPosY()                   { return PosY; }

	void  setPosX(float posX)         { PosX = posX; }
	void  setPosY(float posY)         { PosY = posY; }
	void  setHeading(float heading)   { Heading = heading; }
	void  setVelocity(float velocity) { Velocity = velocity; }
	void  setSprite(Sprite spr)       { sprite = spr;}

	float getHeading()                {return this->Heading;}
	float getVelocity()               {return Velocity; }

	void  incHeading(float hInc)      {Heading += hInc;}
	void  incVelocity(float vInc)     {Velocity += vInc;}
};