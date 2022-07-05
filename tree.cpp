#include "collisioncomponent.h"
#include "game.h"
#include "spritecomponent.h"
#include "tree.h"
#include <SDL2/SDL.h>

Tree::Tree(Game* game)
	:Actor(game)
{
    // sprite component
    mSpriteComponent = new SpriteComponent(this, 100);

    // set texture
    SDL_Rect r = { 8 * 16, 0 * 16, 32, 32 };
    mSpriteComponent->SetTexture(mGame->GetRenderer()->GetTexture(r));

    // create collision component
    mCC = new CollisionComponent(this, 24, 32);
}

void Tree::OnUpdate(float deltaTime)
{
}

