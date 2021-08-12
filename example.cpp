/*
		Thomas Franks
		2D Track Game

		02/03/2021

		Main class
*/

#include <iostream>
#include <windows.h>
using namespace std;

//--- OpenGL ---
#include "GL\glew.h"
#include "GL\wglew.h"
#pragma comment(lib, "glew32.lib")
//--------------

#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"

#include "shaders\Shader.h"
#include "GL\freeglut.h"
#include "FreeImage.h"

#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "MapFiles.h"

#include "GameCharacter.h"
#include "textImages.h"

#include <string>
#include <ctime> // time header
#include <chrono>    


using namespace std;

#define PI 3.1415926535897932384626433832795
float Angle = 0.0f;

glm::mat4 ViewMatrix;  // matrix for the modelling and viewing
glm::mat4 ProjectionMatrix; // matrix for the orthographic projection
int screenWidth = 1024, screenHeight = 768;

/*General Player Controlls*/
bool Left      = false;
bool Right     = false;
bool Up        = false;
bool Down      = false;
bool Spacebar  = false;
bool EscapeKey = false;
bool isMovingB = false;
bool isMovingF = false;
/**************************/

/***GAME LOGIC BOOLS**/
bool   start              = false;
bool   gameCountdownCheck = true;
bool   gameOverCheck	  = true;
bool   winCheck           = false;
bool   w1                 = false;
bool   w2                 = false;
bool   restart            = false;
bool   w3                 = false;
bool   w4                 = false;
bool   w5                 = false;
float  lap                = 0;
float  enemyLap			  = 0;
bool   collisionsLoaded   = false;
int    life               = 0;
bool   countSoundPlayed   = false;


bool   faceN = false;
bool   faceE = false;
bool   faceS = false;
bool   faceW = false;

//DO OIL COLLISISOINOSN
bool   inOil			  = false;

bool onMain  = false;
bool onStart = false;
/**********************/

/*CAMERA STUFF*/
float  l = 0.0f;
float  r = 0.0f;
float  b = 0.0f;
float  t = 0.0f;
float  textSize  = 200.f;
bool   zoomedIn  = false;
bool   zoomedOut = true;
double aspectRatio;
/*************/

Shader shader;

/***PLAYER***/
Sprite playerSprite;
Player player(playerSprite,0.0f,0.0f);
float  playerHeading  = player.getHeading();
float  playerVelocity = player.getVelocity();
/*************/

/****ENEMY*****/
Sprite enemySprite;
Enemy enemy(enemySprite,0.f,0.f);
float enemySpeed = 1.6;
std::vector<float> enemyPath;

int close = 400;
//1.1 waypoints

glm::vec2 waypoint1(6853, 6584);	glm::vec2 waypoint1_1(6551, 6464);
glm::vec2 waypoint2(6967, 1901);	glm::vec2 waypoint1_2(6616, 6452);
glm::vec2 waypoint3(2094, 1668);	glm::vec2 waypoint1_3(6670, 6424);
glm::vec2 waypoint4(1731, 6482);	glm::vec2 waypoint1_4(6720, 6356);
glm::vec2 waypoint5(3856, 6657);	glm::vec2 waypoint1_5(6730, 6302);

float enemyHead;

std::vector<glm::vec2> waypoints;
/**************/

/*****MAP*****/
Map map;
MapFiles mapFiles;
std::vector<Sprite> track;
std::vector<glm::vec2> trackCollisions;
Sprite oilSpill;

/*************/

/**TEXT**/
Sprite ControllsText;
Sprite gameOver;
Sprite win;
Sprite blind;

Sprite number1;
Sprite number2;
Sprite number3;

Sprite tutorialText;
Sprite youWinText;
Sprite youLoseText;

Sprite lap1_2;

glm::mat4 CenterScreen;
/********/

/**Variables for timing**/
float oldTimeSinceStart = 0;
float deltaTime = 0;
/************************/

//OPENGL FUNCTION PROTOTYPES
void display();				         
void reshape(int width, int height); 
void init();				         
void gameStart();
void textInit();
void gameCountdown();
void gameWinCountdown();
void enemyMove(glm::vec2 &vec, Enemy &enemy);
bool isClose(glm::vec2 vec, glm::vec2 enemyVec);

/*************    START OF OPENGL FUNCTIONS   ****************/
void reshape(int width, int height)		
{
	screenWidth   = width;
	screenHeight  = height;
	screenWidth  *= 1.5;
	screenHeight *= 1.5;
	glViewport(0, 0, width, height);					
}

void display()									
{	
	float velocity = player.getVelocity();

	waypoints.push_back(waypoint1);
	waypoints.push_back(waypoint2);
	waypoints.push_back(waypoint2);
	waypoints.push_back(waypoint4);

	glClear(GL_COLOR_BUFFER_BIT);

	/****DELTA TIME****/
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
	/******************/

	ViewMatrix = glm::translate(glm::mat4(1.0), glm::vec3(0.0, 0.0, 0.0));

	glm::mat4 PlayerTransform;
	glm::mat4 EnemyTransform;
	glm::mat4 TrackMatrix;
	glm::mat4 TrackCollisionMatrix;

	glm::mat4 ControllsTextMatrix;
	glm::mat4 GameOverMatrix;
	glm::mat4 topScreen;

	glEnable(GL_BLEND);

	//track render loop	
	for (int i = 0; i < track.size(); i++)
	{
		TrackMatrix = glm::translate(ViewMatrix, glm::vec3(track[i].GetXPos(), track[i].GetYPos(), 0.0f));
		track[i].Render(shader, TrackMatrix, ProjectionMatrix);
	}
	//track render collisions
	for (int i = 0; i < trackCollisions.size(); i++)
	{
		TrackCollisionMatrix = glm::translate(ViewMatrix, glm::vec3(trackCollisions[i].x, trackCollisions[i].y, 0.0f));
		oilSpill.Render(shader, TrackCollisionMatrix, ProjectionMatrix);

		if (playerSprite.IsInCollision(oilSpill.GetOBB())) {
			cout << "AGHHH" << endl;
			float tarVelocity = player.getVelocity() / 2;
			player.incHeading(1.f);
			if (player.getVelocity() >= 0.5f)
				player.incVelocity(-tarVelocity);
			if (player.getVelocity() <= -0.5f)
				player.incVelocity(-tarVelocity);
		}
	}

	gameCountdown();
	//cout << player.getHeading() << endl;
	//collisions
	for (int i = 0; i < track.size(); i++)
	{	
		//WALL == NO PENETRATION AND BOUNCE
		if (track[i].getName() == "wall") {
			if (playerSprite.IsInCollision(track[i].GetOBB())){
				player.decreasePos();
				sndPlaySound(TEXT("textures/TEXT/hit.wav"), SND_ASYNC);
				if (player.getVelocity() > 0.0) {
					player.setVelocity(0.f);
					player.incVelocity(-0.2f);
				}
				else if (player.getVelocity() < 0.0) {
					player.setVelocity(0.f);
					player.incVelocity(0.2f);
				}
			}
		}
		if (track[i].getName() == "finish")
		{
			if (playerSprite.IsInCollision(track[i].GetOBB())) {
				cout << "FINISHED WOO" << endl;
				restart = true;	
				gameStart();
			}
		}
		if (track[i].getName() == "start") {
			if (playerSprite.IsInCollision(track[i].GetOBB()) && onStart == false) {
			onStart = true;						
			cout << "WROKR" << endl;
			float lapTemp = lap;
				lap += 1;
				if (lapTemp < lap) {
					if(lap > 1)
						sndPlaySound(TEXT("textures/TEXT/lapComplete.wav"), SND_ASYNC);
					if (lap >= 3)
						winCheck = true;
				}
			}
		}
	}
	if (lap == 2 && onStart) {
		lap1_2.Render(shader, CenterScreen, ProjectionMatrix);
	}
	//CHECK TO SEE IF PLAYER CROSSED THE LINE OR NOT
	if((int)player.getPosX() < 3754 && (int)player.getPosY() < 6800)
		onStart = false;
	if((int)player.getPosX() > 4275 && (int)player.getPosY() > 6800)
		onStart = false;


	ControllsTextMatrix = glm::translate(ViewMatrix, glm::vec3(l+125, b-125, 0.0));
	ControllsText.Render(shader, ControllsTextMatrix, ProjectionMatrix);
	
	/*Player RENDER*/
	PlayerTransform = glm::translate(ViewMatrix   , glm::vec3(player.getPosX() , player.getPosY(), 0.0));
	PlayerTransform = glm::rotate(PlayerTransform , 4.7f, glm::vec3(0.0, 0.0, 1.0));
	PlayerTransform = glm::rotate(PlayerTransform , glm::radians(player.getHeading()), glm::vec3(0.0, 0.0, 1.0));
	playerSprite.Render(shader, PlayerTransform   , ProjectionMatrix);

	/*Enemy RENDER*/
	EnemyTransform = glm::translate(ViewMatrix    , glm::vec3(enemy.getPosX(), enemy.getPosY(), 0.0f));
	EnemyTransform = glm::rotate(EnemyTransform   , enemyHead, glm::vec3(0.0,0.0,1.0));
	enemySprite.Render(shader, EnemyTransform, ProjectionMatrix);


	//ENEMY COLLISION
	if (playerSprite.IsInCollision(enemySprite.GetOBB()) ) {
		life += 1;
		player.decreasePos();
		if (player.getVelocity() > 0.0) {
			player.setVelocity(0.f);
			player.incVelocity(-0.2f);
		}
		else if (player.getVelocity() < 0.0) {
			player.setVelocity(0.f);
			player.incVelocity(0.2f);
		}
	}
	if (life >= 2)
		cout << "DEAD!!!!!!!!!" << endl;

	//conditions for start
	if (start == false)
		gameStart();

	if (winCheck == true) {
		youWinText.Render(shader, CenterScreen, ProjectionMatrix);
		//restart = true;
		//gameStart();
		lap = 0;
		bool timeDone = false;
		auto timer = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - timer;
		if (gameOverCheck) {
			if (elapsed.count() < 3.1) {
				CenterScreen = glm::translate(ViewMatrix, glm::vec3(player.getPosX(), player.getPosY() + 350, 0.0));
				glm::mat4 RightScreen = glm::translate(ViewMatrix, glm::vec3(player.getPosX() + 500, player.getPosY(), 0.0));
			}
		}
	}		
	if (enemyLap >= 2) {
		CenterScreen = glm::translate(ViewMatrix, glm::vec3(player.getPosX(), player.getPosY() + 350, 0.0));
		youLoseText.Render(shader, CenterScreen, ProjectionMatrix);
	}

	glDisable(GL_BLEND);

	glm::vec2 dirToWaypoint;
	/****** WAYPOINTS FOR ENEMY *******/
	glm::vec2 direction;
	if (!restart) {
		glm::vec2 enemyVec(enemy.getPosX(), enemy.getPosY());
		if (!w1 ) {
			enemyMove(waypoint1, enemy);
			if (abs(enemy.getPosX() - waypoint1.x) < 3)
				w1 = true;
		}
		else if (!w2 && w1) {
			enemyMove(waypoint2, enemy);
			if (abs(enemy.getPosX() - waypoint2.x) < 3) 
				w2 = true;
		}
		else if (!w3 && w2) {
			enemyMove(waypoint3, enemy);
			if (abs(enemy.getPosX() - waypoint3.x) < 3)
				w3 = true;
		}
		else if (!w4 && w3) {
			enemyMove(waypoint4, enemy);
			if (abs(enemy.getPosX() - waypoint4.x) < 3)
				w4 = true;
		}
		else if (!w5 && w4) {
			enemyMove(waypoint5, enemy);
			if (abs(enemy.getPosX() - waypoint5.x) < 3) {
				cout << "E=LAPS" << enemyLap << endl;
				enemyLap++;
				w5 = false;
				w1 = false;
				w2 = false;
				w3 = false;
				w4 = false;
			}
		}
	}

	//center the player in middle of camera
	l = player.getPosX() - (screenWidth  / 2.0);
	r = l + screenWidth;
	t = player.getPosY() - (screenHeight / 2.0);
	b = t + screenHeight;
	ProjectionMatrix = glm::ortho(l,r,t,b);

	//for rotations
	Angle += 0.05f;
	if (Angle >= 360)
		Angle = 0;

	glutSwapBuffers();
}

void enemyMove(glm::vec2 &vec, Enemy &enemy) {
	glm::vec2 direction;
	direction.x = vec.x - enemy.getPosX();
	direction.y = vec.y - enemy.getPosY();

	float hyp = sqrt((direction.x * direction.x) + (direction.y * direction.y));
	direction /= hyp;
	enemy.setPosX(enemy.getPosX() + direction.x * deltaTime / enemySpeed);
	enemy.setPosY(enemy.getPosY() + direction.y * deltaTime / enemySpeed);

	enemy.setHeading(atan2(direction.y, direction.x));
	enemyHead = enemy.getHeading();
}

void init()
{
	FreeImage_Initialise();
	glClearColor(0.0,1.0,0.0,0.0);	//sets the back colour
	float red[3] = { 1,0,0 };

	//Load the GLSL program 
	if (!shader.load("Basic", "./glslfiles/basicTexture.vert" , "./glslfiles/basicTexture.frag"))
	{
		std::cout << "failed to load shader" << std::endl;
	}

	/*GAME CHARACTERS*/
	playerSprite.SetWidth (60.f * (60 / 40));
	playerSprite.SetHeight(45.f * (60 / 40));
	playerSprite.Init(shader, red, "textures/cars/testing.png", 1, 1);

	enemySprite.SetWidth(75.0f * (64 / 64));
	enemySprite.SetHeight(75.0f * (64 / 64));
	enemySprite.setName("enemy");
	enemySprite.Init(shader, red, "textures/cars/GreenStrip.png",1,1);
	/*****************/

	oilSpill.SetWidth (250.0f);
	oilSpill.SetHeight(250.0f);
	oilSpill.Init(shader,red,"textures/floor/oilSpill2.png",1,1);

	textInit();

	map.LoadMap(mapFiles.map3);
	track = map.DrawMap();
	trackCollisions = mapFiles.collisionMap3();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void keyboardFunc(unsigned char key, int x, int y)
{
	if (key == 119)
		Up        = true;
	if (key == 115)
		Down      = true;
	if (key == 97)
		Left      = true;
	if (key == 100)
		Right     = true;
	if (key == 32)
		Spacebar  = true;
	if (key == 27)
		EscapeKey = true;
}
void keyboardFuncUp(unsigned char key, int x, int y)
{
	if (key == 119) {
		Up         = false;
	}
	if (key == 115) {
		Down       = false;
	}
	if (key == 97)
		Left       = false;
	if (key == 100)
		Right      = false;
	if (key == 32)
		Spacebar   = false;
	if (key == 27)
		EscapeKey  = false;
}
void processKeys()
{
	if (Up == false && Down == false) {
		if (player.getVelocity() > 0.0f) {
			player.incVelocity(-0.002f);
		}
		else if (player.getVelocity() < 0.0f) {
			player.incVelocity(0.002f);
		}
	}
	if (Left){
		if (Up || Down || player.getVelocity() > 0.1 || player.getVelocity() < -0.1)
			player.incHeading(0.6f);
		else
			player.incHeading(0.0f);
	}
	if (Right){
		if (Up || Down || player.getVelocity() >  0.1|| player.getVelocity() < -0.1)
			player.incHeading(-0.6f);
		else
			player.incHeading(-0.0f);
	}
	if (Up)
		player.incVelocity(0.002f);
	if (Down){
		if (playerVelocity > 0.0025f)
			player.incVelocity(-0.0025f);
		player.incVelocity(-0.002f);
	}
	if (EscapeKey)
		glutLeaveMainLoop();	
	if (Spacebar) {
		if (player.getVelocity() > 0.01f)
			player.incVelocity(-0.0025f);
		if (player.getVelocity() < -0.01f)
			player.incVelocity(0.0025f);
	}
}
void mouse(int button, int state, int mx, int my)
{
	if (GLUT_UP == state)
	{
		

		float zoomFactor = 1.5;
		if (button == GLUT_LEFT_BUTTON && zoomedIn == false)
		{
			// zoom in
			screenWidth  /= zoomFactor;
			screenHeight /= zoomFactor;
			ControllsText.SetHeight(ControllsText.getHeight() /zoomFactor);
			ControllsText.SetWidth(ControllsText.getWidth()   /zoomFactor);
			zoomedIn  = true;
			zoomedOut = false;
			//glutMouseFunc()
			//cout << "Cursor Position at (" << xpos << " : " << ypos << endl;
		}

		if (button == GLUT_RIGHT_BUTTON && zoomedOut == false)
		{
			// zoom out
			screenWidth  *= zoomFactor;
			screenHeight *= zoomFactor;
			ControllsText.SetHeight(ControllsText.getHeight() * zoomFactor);
			ControllsText.SetWidth(ControllsText.getWidth()   * zoomFactor);
			zoomedOut = true;
			zoomedIn  = false;
		}
	}
	glutPostRedisplay();
}
void idle()
{	
	processKeys();
	player.incPos();
	playerHeading = player.getHeading();
	playerVelocity = player.getVelocity();

	//speed limiter
	if (player.getVelocity() > 1.2f)
		player.setVelocity(1.2f);
	if (player.getVelocity() < -1.2f)
		player.setVelocity(-1.2f);

	/*   I DONT THINK THIS IS NECESSARY */
	//if (player.getHeading() >= 140.f || player.getHeading() <= -140.f) 
	//	faceS = true;
	//else
	//	faceS = false;

	//if (player.getHeading() <= 40.f )
	//	if(player.getHeading() < 0.f && player.getHeading() >= -40.f)
	//		faceN = true;
	//else 
	//	faceN = false;


	if (player.getHeading() < -180) {
		player.setHeading(180.f);
	}
	else if (player.getHeading() > 180) {
		player.setHeading(-180.f);
	}

	//might use this
	if (player.getHeading() >= 270)
		player.setHeading(-90);
	else if (player.getHeading() <= -450)
		player.setHeading(-90);
	glutPostRedisplay();
}


//Checks whether the enemy is close to a waypoint
bool isClose(glm::vec2 vec,glm::vec2 vec2) {
	float distance2 = distance(vec, vec2);
	if (distance2 <= 222) {
		return true;
	}
	else {
		return false;
	}
}

//images used for text stuff
void textInit() {
	float red[3] = { 1,0,0 };
	ControllsText.SetWidth(200.f * (630 / 610));
	ControllsText.SetHeight(200.f * (630 / 610));
	ControllsText.Init(shader, red, "textures/TEXT/controlsPanel.png", 1, 1);

	if (start == false) {
		number1.SetWidth(200.f * (630 / 610));
		number1.SetHeight(200.f * (630 / 610));
		number1.Init(shader, red, "textures/TEXT/count1.png", 1, 1);
		number2.SetWidth(200.f * (630 / 610));
		number2.SetHeight(200.f * (630 / 610));
		number2.Init(shader, red, "textures/TEXT/count2.png", 1, 1);
		number3.SetWidth(200.f * (630 / 610));
		number3.SetHeight(200.f * (630 / 610));
		number3.Init(shader, red, "textures/TEXT/count3.png", 1, 1);

		tutorialText.SetWidth(400.f * (1015 / 632));
		tutorialText.SetHeight(400.f * (1015 / 632));
		tutorialText.Init(shader, red, "textures/TEXT/raceStartText.png", 1, 1);
	}



	gameOver.SetWidth(222.f * (64 / 64));
	gameOver.SetHeight(222.f);
	gameOver.Init(shader, red, "textures/TEXT/gameOver.png", 1, 1);

	blind.SetWidth(5000.f);
	blind.SetHeight(5000.f);
	blind.Init(shader, red, "textures/floor/blind.png", 1, 1);

	youWinText.SetWidth(400.f * (1015 / 632));
	youWinText.SetHeight(400.f * (1015 / 632));
	youWinText.Init(shader, red, "textures/TEXT/youWin.png", 1, 1);

	youLoseText.SetWidth(400.f * (1015 / 632));
	youLoseText.SetHeight(400.f * (1015 / 632));
	youLoseText.Init(shader, red, "textures/TEXT/youLose.png", 1, 1);


	lap1_2.SetWidth (300 *  (725 / 344));
	lap1_2.SetHeight(200 *  (725 / 344));
	lap1_2.Init(shader, red, "textures/TEXT/lap1_2.png", 1, 1);
	


}
//init game logic
void gameStart() {
	bool w1 = false;
	bool w2 = false;
	bool w3 = false;
	bool w4 = false;
	bool w5 = false;

	player.setVelocity(0.0f);
	player.setPosX(map.getStartPosX());
	player.setPosY(map.getStartPosY());
	player.setHeading(-90.0f);

	glm::mat4 EnemyStartTransform;
	glm::vec2 enemyStart;
	enemyStart.x = (map.getStartPosX() - 100);
	enemyStart.y = (map.getStartPosY());
	EnemyStartTransform = glm::translate(ViewMatrix, glm::vec3(enemyStart.x, enemyStart.y, 0.0f));
	enemy.setPosX(enemyStart.x);
	enemy.setPosY(enemyStart.y - 300);
	start   = true;
	restart = false;
	lap     = 0;
}
//game count down
void gameCountdown() {
	bool playedOnce = true;
	if (gameCountdownCheck) {
		int timer = clock();
		bool timerDone = false;
		if ((timer / 1000) < 3.1)
		{
			CenterScreen = glm::translate(ViewMatrix, glm::vec3(player.getPosX(), player.getPosY() + 350, 0.0));
			glm::mat4 RightScreen = glm::translate(ViewMatrix, glm::vec3(player.getPosX() + 500, player.getPosY(), 0.0));
			player.setVelocity(0.f);
			w5 = true;
			w1 = true;
			w2 = true;
			w3 = true;
			w4 = true;
			timer = clock();
			int test44 = timer / 1000;
			tutorialText.Render(shader, CenterScreen, ProjectionMatrix);
			//cout << "Seconds since started: " << test44 << endl;
			if (timer < 1000) {
				number1.Render(shader, RightScreen, ProjectionMatrix);
			}
			else if (timer <= 2000) {
				number2.Render(shader, RightScreen, ProjectionMatrix);
			}
			else if (timer <= 3000) {
				number3.Render(shader, RightScreen, ProjectionMatrix);
			}
			if (timer >= 3000)
				timerDone = true;
		}
		if (timerDone) {
			w5 = false;
			w1 = false;
			w2 = false;
			w3 = false;
			w4 = false;
			gameCountdownCheck = false;
		}
	}
}

/**************** END OPENGL FUNCTIONS *************************/
// FREEGLUT WINDOW SET UP
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGl Track Game");

	glutReshapeFunc(reshape);

	//This initialises glew - it must be called after the window is created.
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		cout << " GLEW ERROR" << endl;
	}

	//Check the OpenGL version being used
	int OpenGLVersion[2];
	glGetIntegerv(GL_MAJOR_VERSION, &OpenGLVersion[0]);
	glGetIntegerv(GL_MINOR_VERSION, &OpenGLVersion[1]);
	cout << OpenGLVersion[0] << " " << OpenGLVersion[1] << endl;

	//initialise the objects for rendering
	init();
	//specify which function will be called to refresh the screen.
	glutDisplayFunc(display);

	//userinput etc
	glutKeyboardFunc(keyboardFunc);
	glutKeyboardUpFunc(keyboardFuncUp);
	glutMouseFunc(mouse);
	glutIdleFunc(idle);

	//starts the main loop. Program loops and calls callback functions as appropriate.	
	//sndPlaySound(TEXT("textures/TEXT/hit2.wav"), SND_ASYNC);

	glutMainLoop();

	return 0;
}