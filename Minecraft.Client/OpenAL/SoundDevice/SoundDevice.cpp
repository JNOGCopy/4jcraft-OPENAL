#include "SoundDevice.hpp"

#include <AL/alc.h>
#include <AL/al.h>

#include <cstddef>
#include <stdexcept>
#include <string>

SoundDevice::SoundDevice(ALCdevice* alcDevice, ALCcontext* alcContext){
    pAlcDevice = alcDevice;
    pAlcContext = alcContext;
}
SoundDevice::~SoundDevice(){
    alcDestroyContext(pAlcContext);
    alcCloseDevice(pAlcDevice);
}

SoundDevice* SoundDevice::createSoundDevice(){
    ALenum error;

    ALCdevice* device = alcOpenDevice(NULL);
    if (!device) { 
        app.DebugPrintf("-- SOUND DEVICE -- : CANNOT OPEN DEVICE %i\n", error);
        throw std::invalid_argument("-- SOUND DEVICE -- : CANNOT OPEN DEVICE " + std::to_string(error)); 
    }

    ALCcontext* context = alcCreateContext(device, NULL);
    if (!context) {
        app.DebugPrintf("-- SOUND DEVICE -- : CANNOT CREATE CONTEXT %i\n", error);
        throw std::invalid_argument("-- SOUND DEVICE -- : CANNOT CREATE CONTEXT " + std::to_string(error));
    }

    if (!alcMakeContextCurrent(context)){
        app.DebugPrintf("-- SOUND DEVICE -- : CANT MAKE ALC CURRENT CONTEXT %i\n", error);
        throw std::invalid_argument("-- SOUND DEVICE -- : CANNOT MAKE CONTEXT CURRENT " + std::to_string(error));
    }

    return new SoundDevice(device, context);
}