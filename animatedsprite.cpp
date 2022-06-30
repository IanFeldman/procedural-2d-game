#include "animatedsprite.h"
#include "actor.h"
#include "game.h"
#include <SDL2/SDL.h>

AnimatedSprite::AnimatedSprite(Actor* owner, SDL_Texture* spritesheet, int drawOrder)
	:SpriteComponent(owner, drawOrder)
    ,mSpritesheet(spritesheet)
{
}

void AnimatedSprite::Update(float deltaTime) {
    float frameInterval = 1.0f / mAnimFPS;

    if(!mAnimName.empty()) {
        if(!mIsPaused) {
            mAnimTimer += deltaTime;

            // new frame
            if (mAnimTimer >= frameInterval) {
                mAnimTimer = 0.0f;
                mFrame = (mFrame + 1) % mAnims[mAnimName].size();
                SetTexture(mAnims[mAnimName][mFrame]);
            }
        }
    }
}

void AnimatedSprite::SetAnimation(const std::string* name, bool resetTimer) {
	if (mAnimName != *name)
	{
		mAnimName = *name;
	}
	
	if (resetTimer)
	{
		mAnimTimer = 0.0f;
	}
}

void AnimatedSprite::AddAnimation(const std::string* name, const std::vector<SDL_Rect*>* frames) {
    SDL_Renderer* rend = mOwner->GetGame()->GetRenderer()->GetSDLRenderer();
    std::vector<SDL_Texture*> animation;

    // render frames to textures and add to mAnims
    for (SDL_Rect* sourceRect : *frames) {
        // create texture
        SDL_Texture* frame = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 16, 16);
        SDL_SetRenderTarget(rend, frame);
        SDL_RenderCopy(rend, mSpritesheet, sourceRect, nullptr);
        animation.push_back(frame);
    }
	mAnims.emplace(*name, animation);

    SDL_SetRenderTarget(rend, nullptr);
    // TODO:
    // DESTROY TEXTURES
}
