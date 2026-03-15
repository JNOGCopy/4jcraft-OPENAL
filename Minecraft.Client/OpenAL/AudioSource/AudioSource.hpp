#pragma once

#include <AL/al.h>
class SoundDevice;

class AudioSource{
private:
    AudioSource(ALuint sourceID, SoundDevice* soundDevice);
    SoundDevice* pSoundDevice;
public:
    ~AudioSource();

    static AudioSource* createAudioSource(SoundDevice* soundDevice);

    void play(ALuint id);
    void stop(ALuint id);

    // build pattern!

    AudioSource& setPosition(float xPos, float yPos, float zPos);
    AudioSource& setPitch(float pitch);
    AudioSource& setVolume(float volume);

    bool isPlaying();

    ALuint mSourceID;
};