#pragma once

#include <AL/al.h>
#include <memory>
#include <vector>

class AudioSource;
class SoundDevice;

struct AudioSourceConfig{
    float xPos = 0, yPos = 0, zPos = 0;
    float pitch = 0;
    float volume = 0;
};

class AudioSourcePool{
private:
    AudioSourcePool(SoundDevice* soundDevice);
    int getFreeAudioSource();

    SoundDevice* pSoundDevice;

    // IF YOU DELETE ONE, IT BROKES -- TO FIX -- CHANGE TO ARRAY OR SOMETHING
    std::vector<std::unique_ptr<AudioSource>> mAudioSourcePool;

    std::vector<int> mFreeAudioSource;
    std::vector<int> mUsingAudioSource;
public:
    AudioSourcePool* createAudioSourcePool(SoundDevice* soundDevice);

    void playSound(const AudioSourceConfig audioConfig, ALuint soundId);
    void tick();
};