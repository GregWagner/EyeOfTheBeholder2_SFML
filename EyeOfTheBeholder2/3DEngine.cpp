#include "3DEngine.h"

Engine::Engine()
{
    mMediaWrapper = std::make_unique<MediaWrapper>();
    mMediaWrapper->setupWindow(mConfiguration);
}

Configuration Engine::getConfiguration() const
{
    return mConfiguration;
}

void Engine::playIntro() const
{
}

void Engine::loadMap(const unsigned mapID, const bool savedMap) const
{
}

void Engine::run()
{
    mMediaWrapper->run();
}
