#pragma once

#include "Configuration.h"
#include "MediaWrapper.h"
#include <memory>

class Engine {
public:
    Engine();
    ~Engine() = default;

    Configuration getConfiguration() const;
    void playIntro() const;
    void loadMap(const unsigned mapID, const bool savedMap = false) const;
    void run();

private:
    Configuration mConfiguration;
    std::unique_ptr<MediaWrapper> mMediaWrapper { nullptr };
};
