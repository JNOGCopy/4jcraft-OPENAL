#pragma once 

#include <AL/al.h>
#include <string>
#include <unordered_map>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION

class SoundDevice;

class AudioBuffer{
private:

    std::unordered_map<std::string, ALuint> mAudioBuffer; // PATH ---> AUDIO ID (OpenAL)
    std::unordered_map<ALuint, std::string> mAudioBuffer_REVERSE; // AUDIO ID (OpenAL) ---> PATH
public:
    AudioBuffer();
    static AudioBuffer* createAudioBuffer();
    ALuint addAudio(std::string path, std::string identifier);
    ALuint getAudio(std::string identifier);

    void removeAudio(std::string identifier);
    void removeAudio(ALuint id);

    ~AudioBuffer();
};