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
    std::unordered_map<ALuint, std::string> mAudioBuffer_REVERSE; // AUDIO ID (OpenAL) ---> PATH
    SoundDevice* pSoundDevice;
public:
    AudioBuffer* createAudioBuffer(SoundDevice* soundDevice);
    ALuint addAudio(std::string path);
    ALuint getAudio(std::string path);

    void removeAudio(std::string path);
    void removeAudio(ALuint id);

    ~AudioBuffer();
};