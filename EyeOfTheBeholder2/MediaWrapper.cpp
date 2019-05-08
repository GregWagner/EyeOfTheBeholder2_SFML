#include "MediaWrapper.h"

MediaWrapper::MediaWrapper()
{
}

void MediaWrapper::setupWindow(const Configuration& configuration)
{
    mVideoModes = sf::VideoMode::getFullscreenModes();

    sf::ContextSettings windowSettings;
    windowSettings.antialiasingLevel = configuration.getAntialiasingLevel();

    sf::VideoMode windowBounds;
    windowBounds.width = configuration.getWindowWidth();
    windowBounds.height = configuration.getWindowHeight();

    if (configuration.isFullScreen()) {
        mWindow = std::make_unique<sf::RenderWindow>(windowBounds, configuration.getGameTitle(),
            sf::Style::Fullscreen, windowSettings);
    } else {
        mWindow = std::make_unique<sf::RenderWindow>(windowBounds, configuration.getGameTitle(),
            sf::Style::Titlebar | sf::Style::Close, windowSettings);
    }
    mWindow->setFramerateLimit(configuration.getFrameRateLimit());
    mWindow->setVerticalSyncEnabled(configuration.isVerticalSyncEnabled());
}

void MediaWrapper::run()
{
    while (mWindow->isOpen()) {
        updateDeltaTime();
        update();
        render();
    }
}

void MediaWrapper::updateSFMLEvents() const
{
    sf::Event event;
    while (mWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow->close();
        }
    }
}

void MediaWrapper::updateDeltaTime()
{
    mDeltaTime = mClock.restart().asSeconds();
}

void MediaWrapper::update() const
{
    updateSFMLEvents();
}

void MediaWrapper::render() const
{
    mWindow->clear();
    mWindow->display();
}
