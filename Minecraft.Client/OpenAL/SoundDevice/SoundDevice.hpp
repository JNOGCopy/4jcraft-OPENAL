#pragma once

#include <algorithm>
#include <memory>
#include <AL/alc.h>

class SoundDevice{
private:
    SoundDevice(ALCdevice* alcDevice, ALCcontext* alcContext);
public:
    ~SoundDevice();

    static SoundDevice* createSoundDevice(); // Factory pattern
    static void freeCurrentContext();
    void setCurrentContext();

    // It seems that you can't make a unique ptr of these both, comprensible
    ALCdevice* pAlcDevice = nullptr;
    ALCcontext* pAlcContext = nullptr;
};