#pragma once

#include "Configuration.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class MediaWrapper {
public:
    MediaWrapper();
    ~MediaWrapper() = default;

    void setupWindow(const Configuration& configuration);
    void run();

private:
    void updateSFMLEvents() const;
    void updateDeltaTime();
    void update() const;
    void render() const;

    std::unique_ptr<sf::RenderWindow> mWindow { nullptr };
    std::vector<sf::VideoMode> mVideoModes;

    sf::Clock mClock;
    float mDeltaTime {};
};
