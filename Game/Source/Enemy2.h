#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Entity.h"
#include "Point.h"
#include "SDL/include/SDL.h"
#include "Animation.h"

struct SDL_Texture;

class Enemy2 : public Entity
{
public:

	Enemy2();

	virtual ~Enemy2();

	bool Awake();

	bool Start();

	bool Update();

	bool CleanUp();

	// L07 DONE 6: Define OnCollision function for the player. Check the virtual function on Entity class
	void OnCollision(PhysBody* physA, PhysBody* physB);
	static Enemy2* instance;

public:
	Animation* currentAnimation = nullptr;

	Animation idleanim;
	Animation rightwalk;
	Animation leftwalk;
	Animation jumpingdreta;
	Animation jumpingesquerra;
	Animation muertesita;
	Animation atacacion;

	bool grounded = false;

private:

	//L02: DONE 1: Declare player parameters
	SDL_Texture* texture;
	const char* texturePath;
	SDL_Texture* texturescene3;
	SDL_Texture* texturescene4;
	const char* texturedeath;
	const char* texturewin;


	// L07 DONE 5: Add physics to the player - declare a Physics body
	PhysBody* pbody;

	int pickCoinFxId;
	int winsound;
	int deathsound;
	int jumpsound;
	int runsound;
	int time = 20;
	bool wincondition = false;
	bool losecondition = false;
	bool ultimatelosecondition = false;
	int godmode = 1;
	bool introactiva = true;
	bool introactiva2 = false;
	bool lose = false;
	bool ganar = false;

	float yVel = 0;

};

#endif // __PLAYER_H__