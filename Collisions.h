#pragma once

#include "OBB.h"
#include "Sprite.h"
#include "vector"
#include "GameCharacter.h"

class Collisions
{
private:

public:

	//static void handleCollision(Player player, Sprite characterSprite, std::vector<Sprite> track) {
	//	for (int i = 0; i < track.size(); i++)
	//	{
	//		//TAR == SLOWDOWN
	//		if (track[i].getName() == "tar") {
	//			float tarVelocity = player.getVelocity() / 2;
	//			if (characterSprite.IsInCollision(track[i].GetOBB())) {
	//				if (player.getVelocity() >= 0.5f)
	//					player.incVelocity(-tarVelocity);
	//				if (player.getVelocity() <= -0.5f)
	//					player.incVelocity(-tarVelocity);
	//			}
	//		}
	//		//WALL == NO PENETRATION AND BOUNCE
	//		if (track[i].getName() == "wall") {
	//			if (characterSprite.IsInCollision(track[i].GetOBB())) {
	//				player.decreasePos();
	//				if (player.getVelocity() > 0.0) {
	//					player.setVelocity(0.f);
	//					player.incVelocity(-0.2f);
	//				}
	//				else if (player.getVelocity() < 0.0) {
	//					player.setVelocity(0.f);
	//					player.incVelocity(0.2f);
	//				}
	//			}
	//		}
	//		if (track[i].getName() == "finish")
	//		{
	//			if (characterSprite.IsInCollision(track[i].GetOBB())) {
	//				std::cout << "wtf" << std::endl;
	//			}
	//		}
	//	}
	//}
};