#pragma once
#include "GL\glew.h"
#include "GL\wglew.h"
#include "GL\freeglut.h"
#include "Sprite.h"
#include "shaders/Shader.h"
#include "vector"
#include "FreeImage.h"

#include <iostream> 
class Map
{
private:


	Shader shader;



	int map[20][25];

public:

	float posX = 0;
	float posY = 0;

	float startingPosX = 0.0f;
	float startingPosY = 0.0f;
	Map();
	Sprite grass;
	Sprite puddle;
	Sprite mainRoad2;
	Sprite leftWall;
	Sprite rightWall;
	Sprite botWall;
	Sprite topWall;
	Sprite mainRoad;
	Sprite botRightCorner;
	Sprite topRightCorner;
	Sprite topLeftCorner;
	Sprite botLeftCorner;
	Sprite startSprite;
	Sprite finish;
	

	void LoadMap(int arr[20][25]);
	std::vector<Sprite> DrawMap();
	std::vector<glm::vec2> collisionMap(std::vector<glm::vec2> cols);

	std::vector<Sprite> trackMap;
	std::vector<Sprite> collisionVector;

	float getStartPosX() { return startingPosX; }
	float getStartPosY() { return startingPosY; }


};