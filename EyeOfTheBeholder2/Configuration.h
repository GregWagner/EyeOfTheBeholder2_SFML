#pragma once

#include <string>

class Configuration {
public:
    Configuration();
    ~Configuration() = default;

    std::string getGameTitle() const;
    unsigned getWindowWidth() const;
    unsigned getWindowHeight() const;
    bool isFullScreen() const;
    bool isVerticalSyncEnabled() const;
    unsigned getAntialiasingLevel() const;
    unsigned getFrameRateLimit() const;
    int getLanguage() const;
    int getStartingMapID() const;

private:
    std::string mGameTitle {};
    int mWidth {};
    int mHeight {};
    int mFullScreen {};
    int mVerticalSyncEnabled {};
    int mAntialiasingLevel {};
    int mFrameRateLimit { 120 };

    int mLanguage {};
    int mStartingMapID {};
};
