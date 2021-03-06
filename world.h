#pragma once
#include "fastnoiselite.h"
#include "math.h"
#include <SDL2/SDL.h>
#include <vector>

class World {

public:
    World(class Game* game);
    void Generate(int playerX, int playerY);
    void DetWaterTex(float height, int sampleX, int sampleY, int* tilesetX, int* tilesetY, float* sourceRotation);
    bool IsWater(int x, int y);

protected:
    class Game* mGame;
    FastNoiseLite mNoise;
    float mNoiseFreq;
    int mTileCount, mTileSize, mSpriteTileSize;
    float mWaterLine;
    SDL_Texture* mTileset;

    std::vector<Vector2> mTreePositions;
};

