#include "GL\glew.h"
#include "GL\wglew.h"
#include "GL\freeglut.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"

#pragma comment(lib, "glew32.lib")

#include "GameCharacter.h"
#include "Sprite.h"
#include "shaders/Shader.h"

class Player : public  GameCharacter
{
private:

	//Sprite playerSprite;

	//float playerSpeed;
	//float Angle = 0.0f;

	//float playerVelocity = 0.0f;
	//float playerPosX, playerPosY = 0.0f;
	//float playerHeading = 0.0f;
	//int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	//int  oldTimeSinceStart = 0;
	//#define PI 3.1415926535897932384626433832795

public:
	using GameCharacter::GameCharacter;

	using GameCharacter::incVelocity;
	using GameCharacter::getVelocity;
	using GameCharacter::setVelocity;

	using GameCharacter::getPosX;
	using GameCharacter::getPosY;
	using GameCharacter::setPosX;
	using GameCharacter::setPosY;

	using GameCharacter::getHeading;
	using GameCharacter::setHeading;
	
	using GameCharacter::incHeading;
	using GameCharacter::incPos;
	using GameCharacter::decreasePos;


	//void setSprite(Sprite spr);
	//void keyPress(int key, int x, int y);
	//void keyRelease(int key, int x, int y);
	//void keyProcess();
	//void idle();

	//void incHeading(float hInc)
	//{
	//	playerHeading += hInc;
	//}
	//void incVelocity(float vInc)
	//{
	//	playerVelocity += vInc;
	//}
	//void incPos()
	//{
	//	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	//	int deltaTime      = timeSinceStart - oldTimeSinceStart;

	//	oldTimeSinceStart  = timeSinceStart;
	//	playerPosX         += playerVelocity * cos((90.0f + playerHeading) * (PI / 180.0f))*deltaTime;
	//	playerPosY         += playerVelocity * sin((90.0f + playerHeading) * (PI / 180.0f))*deltaTime;
	//}

	////getters and setters
	//float getPosX() { return playerPosX; }
	//float getPosY() { return playerPosY; }

	//void setPosX(float posX) { playerPosX = posX; }
	//void setPosY(float posY) { playerPosY = posY; }

	//void setHeading(float heading) { playerHeading = heading; }
	//float getHeading() { return playerHeading; }

	//float getVelocity() { return playerVelocity; }
	//void setVelocity(float velocity){ playerVelocity = velocity; }
};