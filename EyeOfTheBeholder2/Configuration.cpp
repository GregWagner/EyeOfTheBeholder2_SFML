#include "Configuration.h"
#include <fstream>
#include <iostream>

Configuration::Configuration()
{
    std::ifstream configFile("Configs/window.ini");
    if (configFile.is_open()) {
        std::getline(configFile, mGameTitle);
        configFile >> mStartingMapID >> mLanguage >> mWidth >> mHeight
            >> mFullScreen >> mVerticalSyncEnabled >> mFrameRateLimit
            >> mAntialiasingLevel;
    } else {
        std::cerr << "Unable to read config file - Using defaults\n";
    }
    configFile.close();
}

std::string Configuration::getGameTitle() const
{
    return mGameTitle;
}

unsigned Configuration::getWindowWidth() const
{
    return mWidth;
}

unsigned Configuration::getWindowHeight() const
{
    return mHeight;
}

int Configuration::getLanguage() const
{
    return mLanguage;
}

bool Configuration::isFullScreen() const
{
    return mFullScreen;
}

bool Configuration::isVerticalSyncEnabled() const
{
    return false;
}

unsigned Configuration::getAntialiasingLevel() const
{
    return mAntialiasingLevel;
}

unsigned Configuration::getFrameRateLimit() const
{
    return mFrameRateLimit;
}

int Configuration::getStartingMapID() const
{
    return mStartingMapID;
}
