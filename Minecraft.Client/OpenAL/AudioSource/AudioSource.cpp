#include "AudioSource.hpp"
#include <AL/al.h>
#include <string>

AudioSource::AudioSource(ALuint sourceID, SoundDevice* soundDevice){
    pSoundDevice = soundDevice;
    mSourceID = sourceID;
}

AudioSource::~AudioSource(){
    alDeleteSources(1, &mSourceID);
}

AudioSource* AudioSource::createAudioSource(SoundDevice* soundDevice){
    ALuint source;

    alGenSources(1, &source);
    ALenum error = alGetError();

    if (error != AL_NO_ERROR){
        throw "-- AUDIO SOURCE -- : CANNOT CREATE AUDIO SOURCE " + std::to_string(error);
    }

    return new AudioSource(source, soundDevice);
}

void AudioSource::play(ALuint id){
    alSourcePlay(id);
}
void AudioSource::stop(ALuint id){
    alSourceStop(id);
}

// build pattern!

AudioSource& AudioSource::setPosition(float xPos, float yPos, float zPos){
    alSource3f(mSourceID, AL_POSITION, xPos, yPos, zPos);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR){
        throw "-- AUDIO SOURCE -- : CANNOT SET POSITION " + std::to_string(error);
    }
    return *this;
}
AudioSource& AudioSource::setPitch(float pitch){
    alSourcef(mSourceID, AL_PITCH, pitch);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR){
        throw "-- AUDIO SOURCE -- : CANNOT SET PITCH " + std::to_string(error);
    }
    return *this;
}
AudioSource& AudioSource::setVolume(float volume){
    alSourcef(mSourceID, AL_GAIN, volume);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR){
        throw "-- AUDIO SOURCE -- : CANNOT SET VOLUME " + std::to_string(error);
    }
    return *this;
}