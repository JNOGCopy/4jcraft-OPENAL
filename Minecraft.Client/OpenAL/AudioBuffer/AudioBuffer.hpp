#pragma once 

#include <AL/al.h>
#include <string>
#include <unordered_map>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION

class SoundDevice;

class AudioBuffer{
private:
    AudioBuffer(SoundDevice* soundDevice);

    std::unordered_map<std::string, ALuint> mAudioBuffer; // PATH ---> AUDIO ID (OpenAL)
    SoundDevice* pSoundDevice;
public:
    AudioBuffer* createAudioBuffer(SoundDevice* soundDevice);
    ALuint addAudio(std::string path);
    ALuint getAudio(std::string path);
};