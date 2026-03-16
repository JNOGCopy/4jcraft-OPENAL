#pragma once

#include <AL/al.h>
class SoundDevice;

class AudioSource{
private:
    AudioSource(ALuint sourceID);
public:
    ~AudioSource();

    static AudioSource* createAudioSource();

    void play(ALuint id);
    void stop();

    // build pattern!

    AudioSource& setPosition(float xPos, float yPos, float zPos);
    AudioSource& setPitch(float pitch);
    AudioSource& setVolume(float volume);

    bool isPlaying();

    ALuint mSourceID;
};