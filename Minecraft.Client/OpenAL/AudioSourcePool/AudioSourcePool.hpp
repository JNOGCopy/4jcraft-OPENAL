#pragma once

#include <AL/al.h>
#include <memory>
#include <vector>

class AudioSource;
class SoundDevice;

struct AudioSourceConfig{
    float xPos = 0, yPos = 0, zPos = 0;
    float pitch = 1;
    float volume = 1;
};

class AudioSourcePool{
private:
    AudioSourcePool();
    int getFreeAudioSource();

    // IF YOU DELETE ONE, IT BROKES -- TO FIX -- CHANGE TO ARRAY OR SOMETHING
    std::vector<std::unique_ptr<AudioSource>> mAudioSourcePool;

    std::vector<int> mFreeAudioSource;
    std::vector<int> mUsingAudioSource;
public:
    static AudioSourcePool* createAudioSourcePool();

    void playSound(const AudioSourceConfig audioConfig, ALuint soundId);
    void tick();
};