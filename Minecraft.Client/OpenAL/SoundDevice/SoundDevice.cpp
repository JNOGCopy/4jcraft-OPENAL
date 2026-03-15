#include "SoundDevice.hpp"

#include <AL/alc.h>
#include <AL/al.h>

#include <memory>

SoundDevice::SoundDevice(ALCdevice* alcDevice, ALCcontext* alcContext){
    pAlcDevice = alcDevice;
    pAlcContext = alcContext;
}
SoundDevice::~SoundDevice(){
    alcDestroyContext(pAlcContext);
    alcCloseDevice(pAlcDevice);
}

SoundDevice* SoundDevice::createSoundDevice(){
    ALCdevice* device = alcOpenDevice(nullptr);
    if (!device) throw("-- AUDIO SOURCE -- : CANNOT OPEN DEVICE");

    ALCcontext* context = alcCreateContext(device, nullptr);
    if (!context) throw("-- AUDIO SOURCE -- : CANNOT CREATE CONTEXT"); 
}

void SoundDevice::setCurrentContext(){
    alcMakeContextCurrent(pAlcContext);
}