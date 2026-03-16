#include "AudioSource.hpp"
#include <AL/al.h>
#include <exception>
#include <stdexcept>
#include <string>

#include "../SoundDevice/SoundDevice.hpp"

AudioSource::AudioSource(ALuint sourceID){
    mSourceID = sourceID;
}

AudioSource::~AudioSource(){
    alDeleteSources(1, &mSourceID);
}

AudioSource* AudioSource::createAudioSource(){
    ALuint source;

    alGenSources(1, &source);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR){
        app.DebugPrintf("-- AUDIO SOURCE -- : CANNOT CREATE AUDIO SOURCE %s \n", error);
        throw std::invalid_argument("-- AUDIO SOURCE -- : CANNOT CREATE AUDIO SOURCE " + std::to_string(error));
    }
    return new AudioSource(source);
}

void AudioSource::play(ALuint id){
    app.DebugPrintf("-- AUDIO SOURCE -- : play (%f) \n");

    alSourcei(mSourceID, AL_BUFFER, id);
    alSourcePlay(mSourceID);
}
void AudioSource::stop(){
    app.DebugPrintf("-- AUDIO SOURCE -- : stop \n");

    alSourceStop(mSourceID);
}

// build pattern!

AudioSource& AudioSource::setPosition(float xPos, float yPos, float zPos){
    alSource3f(mSourceID, AL_POSITION, xPos, yPos, zPos);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR){
        app.DebugPrintf("-- AUDIO SOURCE -- : CANNOT SET POSITION (%f, %f, %f) - %s \n", xPos, yPos, zPos, error);
        throw std::invalid_argument("-- AUDIO SOURCE -- : CANNOT SET POSITION " + std::to_string(error));
    }
    return *this;
}
AudioSource& AudioSource::setPitch(float pitch){
    alSourcef(mSourceID, AL_PITCH, pitch);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR){
        app.DebugPrintf("-- AUDIO SOURCE -- : CANNOT SET PITCH (%f) - %s \n", pitch, error);
        throw std::invalid_argument("-- AUDIO SOURCE -- : CANNOT SET PITCH " + std::to_string(error));
    }
    return *this;
}
AudioSource& AudioSource::setVolume(float volume){
    alSourcef(mSourceID, AL_GAIN, volume);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR){
        app.DebugPrintf("-- AUDIO SOURCE -- : CANNOT SET VOLUME (%f) - %s \n", volume, error);
        throw std::invalid_argument("-- AUDIO SOURCE -- : CANNOT SET VOLUME " + std::to_string(error));
    }
    return *this;
}

bool AudioSource::isPlaying(){
    ALenum state;
    alGetSourcei(mSourceID, AL_SOURCE_STATE, &state);

    return state == AL_PLAYING;
}