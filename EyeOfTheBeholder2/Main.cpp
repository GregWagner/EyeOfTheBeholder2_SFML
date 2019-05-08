#include "3DEngine.h"

int main(int argc, char* argv[])
{
    Engine game;

    game.playIntro();
    game.loadMap(game.getConfiguration().getStartingMapID());
    game.run();
}
