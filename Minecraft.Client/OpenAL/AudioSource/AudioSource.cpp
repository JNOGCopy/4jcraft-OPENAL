#include "AudioSource.hpp"
#include <AL/al.h>
#include <string>

#include "../SoundDevice/SoundDevice.hpp"

AudioSource::AudioSource(ALuint sourceID, SoundDevice* soundDevice){
    pSoundDevice = soundDevice;
    mSourceID = sourceID;
}

AudioSource::~AudioSource(){
    pSoundDevice->setCurrentContext();

    alDeleteSources(1, &mSourceID);

    SoundDevice::freeCurrentContext();
}

AudioSource* AudioSource::createAudioSource(SoundDevice* soundDevice){
    soundDevice->setCurrentContext();

    ALuint source;

    alGenSources(1, &source);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR){
        throw "-- AUDIO SOURCE -- : CANNOT CREATE AUDIO SOURCE " + std::to_string(error);
    }
    SoundDevice::freeCurrentContext();

    return new AudioSource(source, soundDevice);
}

void AudioSource::play(ALuint id){
    pSoundDevice->setCurrentContext();
    
    alSourcePlay(id);

    SoundDevice::freeCurrentContext();
}
void AudioSource::stop(ALuint id){
    pSoundDevice->setCurrentContext();

    alSourceStop(id);

    SoundDevice::freeCurrentContext();
}

// build pattern!

AudioSource& AudioSource::setPosition(float xPos, float yPos, float zPos){
    pSoundDevice->setCurrentContext();
    alSource3f(mSourceID, AL_POSITION, xPos, yPos, zPos);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR){
        throw "-- AUDIO SOURCE -- : CANNOT SET POSITION " + std::to_string(error);
    }
    SoundDevice::freeCurrentContext();
    return *this;
}
AudioSource& AudioSource::setPitch(float pitch){
    pSoundDevice->setCurrentContext();
    alSourcef(mSourceID, AL_PITCH, pitch);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR){
        throw "-- AUDIO SOURCE -- : CANNOT SET PITCH " + std::to_string(error);
    }
    SoundDevice::freeCurrentContext();
    return *this;
}
AudioSource& AudioSource::setVolume(float volume){
    pSoundDevice->setCurrentContext();
    alSourcef(mSourceID, AL_GAIN, volume);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR){
        throw "-- AUDIO SOURCE -- : CANNOT SET VOLUME " + std::to_string(error);
    }
    SoundDevice::freeCurrentContext();
    return *this;
}

bool AudioSource::isPlaying(){
    ALenum state;
    alGetSourcei(mSourceID, AL_SOURCE_STATE, &state);

    return state == AL_PLAYING;
}