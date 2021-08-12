#pragma once

#include "vector"


class MapFiles
{

private:



public:

	int map1[20][25] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1},
		{1,1,1,1,1,1,1,4,2,2,2,2,2,2,2,2,2,2,12,2,6,1,1,1,1},
		{1,1,1,1,1,1,1,4,2,2,2,2,2,2,2,2,2,2,12,2,6,1,1,1,1},
		{1,1,1,1,1,1,1,4,2,2,9,5,5,5,5,5,5,5,5,5,1,1,1,1,1},
		{1,1,1,1,1,1,1,4,2,0,6,1,3,3,3,3,3,3,3,3,1,1,1,1,1},
		{1,1,1,1,1,1,1,4,2,2,6,4,2,2,2,11,2,2,2,2,6,1,1,1,1},
		{1,1,1,1,1,1,1,4,2,2,6,4,2,2,2,11,2,2,2,2,6,1,1,1,1},
		{1,1,1,1,1,1,1,4,2,2,6,1,5,5,5,5,5,10,2,2,6,1,1,1,1},
		{1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1,1,4,2,2,6,1,1,1,1},
		{1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1,1,4,2,2,6,1,1,1,1},
		{1,1,1,1,1,1,1,4,2,2,7,3,3,3,3,3,3,8,2,2,6,1,1,1,1},
		{1,1,1,1,1,1,1,4,2,2,0,2,2,2,2,2,2,2,2,2,6,1,1,1,1},
		{1,1,1,1,1,1,1,4,2,2,2,2,2,2,2,2,2,2,2,2,6,1,1,1,1},
		{1,1,1,1,1,1,1,1,5,5,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	//1 = grass
	//2 = main
	//3 = botwall
	//4 = leftwall
	//5 = topWall
	//6 = rightWall
	//7 = botRightCorner
	//8 = botLeftCorner
	//9 = topRightCorner
	//10 = topLeftCorner
	//11 = start
	//12 = finish
	//0 = puddle

	int map2[20][25] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1	,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};


	//1 is grass
	//12 is main
	//4 botwall
	//5 leftwall
	//6 topwall
	//7 rgithwall
	//8 = botRightCorner
	//9 = botLeftCorner
	//10 = topRightCorner
	//11 = topLeftCorner
	//12 = start
	//null = finish
	//11 = puddle
	int map3[20][25] =
	{
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,12 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  },
		{ 1,1,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,1  },
		{ 1,1,1,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,9,3,3,3,3,3,3,3,3,3,10,2,2,6,1,1,1,1,1 },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,7,5,5,5,5,5,5,5,5,5,8,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,2,2,2,2,11,2,2,2,2,2,2,2,2,6,1,1,1,1,1 },
		{ 1,1,1,4,2,2,2,2,2,2,11,2,2,2,2,2,2,2,2,6,1,1,1,1,1 },
		{ 1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1  },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  }
	};

	std::vector<glm::vec2> collisionMap3() 
	{
		std::vector<glm::vec2> collisionMap3Vec;
		glm::vec2 a(6786, 5176);
		glm::vec2 b(4780, 1989);
		glm::vec2 c(1983, 3970);
		glm::vec2 d(1583, 6776);

		collisionMap3Vec.push_back(a);
		collisionMap3Vec.push_back(b);
		collisionMap3Vec.push_back(c);
		collisionMap3Vec.push_back(d);

		return collisionMap3Vec;
	}
};


/*

	int map3[20][25] =
	{
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,12 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  },
		{ 1,1,1,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,1,1,1,1,1  },
		{ 1,1,1,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,9,3,3,3,3,3,3,3,3,3,10,2,2,6,1,1,1,1,1 },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,0,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,0,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,6,1,1,1,1,1,1,1,1,1,4,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,7,5,5,5,5,5,5,5,5,5,8,2,2,6,1,1,1,1,1  },
		{ 1,1,1,4,2,2,2,2,2,2,11,2,2,2,2,2,2,2,2,6,1,1,1,1,1 },
		{ 1,1,1,4,0,2,2,2,2,2,11,2,2,2,2,2,2,2,2,6,1,1,1,1,1 },
		{ 1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1  },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  }
	};

*/