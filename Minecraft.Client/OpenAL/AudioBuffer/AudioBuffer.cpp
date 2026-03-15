#include "AudioBuffer.hpp"
#include <AL/al.h>
#include <AL/alc.h>
#include <sndfile.h>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <string>

#include "../SoundDevice/SoundDevice.hpp"

AudioBuffer::AudioBuffer(SoundDevice* soundDevice){
    pSoundDevice = soundDevice;
}
AudioBuffer::~AudioBuffer(){
    for (auto id : mAudioBuffer){
        alDeleteBuffers(1, &id.second);
    }
    mAudioBuffer.clear();
    mAudioBuffer_REVERSE.clear();
}

// In order to make this function, I watched this video https://www.youtube.com/watch?v=kWQM1iQ1W0E
AudioBuffer* AudioBuffer::createAudioBuffer(SoundDevice* soundDevice){
   return new AudioBuffer(soundDevice);
}

/*!
 * ONLY COMPATIBLE WITH .OGG!!!!!
 */
ALuint AudioBuffer::addAudio(std::string path){
    ALenum          error, format;
    ALuint          buffer;
    SNDFILE*        sndFile;
    SF_INFO         sfInfo;
    short*          memoryBuffer;
    sf_count_t      numberOfFrames;
    ALsizei         numberOfBytes;
    
    sndFile = sf_open(path.c_str(), SFM_READ, &sfInfo);
    if (!sndFile) { throw "-- AUDIO BUFFER -- : AUDIO WASN'T FOUNDED: " + path; }
    if (sfInfo.frames < 1 || sfInfo.frames > (sf_count_t)(INT_MAX / sizeof(short)) / sfInfo.channels){
        sf_close(sndFile);
        throw "-- AUDIO BUFFER -- : BAD SAMPLE COUNT!: " + path; 
    }

    format = AL_NONE;

    switch (sfInfo.channels){
        case 1: format = AL_FORMAT_MONO16; break;
        case 2: format = AL_FORMAT_STEREO16; break;
    }

    if (!format) { sf_close(sndFile); throw  "-- AUDIO BUFFER -- : UNSUPPORTED CHANNEL! : " + path; }

    memoryBuffer = static_cast<short*>(malloc((size_t)(sfInfo.frames * sfInfo.channels) * sizeof(short)));
    numberOfFrames = sf_read_short(sndFile, memoryBuffer, sfInfo.frames);

    if (numberOfFrames < 1){
        free(memoryBuffer);
        sf_close(sndFile);
        throw  "-- AUDIO BUFFER -- : FAILED READING SAMPLE : " + path;
    }

    numberOfBytes = (ALsizei)(numberOfFrames * sfInfo.channels) * (ALsizei)sizeof(short);

    pSoundDevice->setCurrentContext();

    buffer = 0;
    alGenBuffers(1, &buffer);
    alBufferData(buffer, format, memoryBuffer, numberOfBytes, sfInfo.samplerate);

    free(memoryBuffer);
    sf_close(sndFile);

    error = alGetError();
    if (error != AL_NO_ERROR){
        if (buffer && alIsBuffer(buffer))
            alDeleteBuffers(1, &buffer);
        throw "-- AUDIO BUFFER -- : OPENAL ERROR GENERATING BUFFER : " + std::to_string(error);
    }

    pSoundDevice->freeCurrentContext();

    mAudioBuffer.try_emplace(path, buffer);
    mAudioBuffer_REVERSE.try_emplace(buffer, path);

    return buffer;
}

ALuint AudioBuffer::getAudio(std::string path){
    if (mAudioBuffer.find(path) == mAudioBuffer.end()) return -1;
    return mAudioBuffer.at(path);
}

void AudioBuffer::removeAudio(std::string path){
    if (mAudioBuffer.find(path) == mAudioBuffer.end()) throw "-- AUDIO BUFFER -- : CANNOT DELETE, PATH " + path + " DOESNT EXISTS"; 

    mAudioBuffer_REVERSE.erase(mAudioBuffer[path]);
    mAudioBuffer.erase(path);
}
void AudioBuffer::removeAudio(ALuint id){
    if (mAudioBuffer_REVERSE.find(id) == mAudioBuffer_REVERSE.end()) throw "-- AUDIO BUFFER -- : CANNOT DELETE, SOUND ID " + std::to_string(id) + " DOESNT EXISTS"; 

    mAudioBuffer.erase(mAudioBuffer_REVERSE[id]);
    mAudioBuffer_REVERSE.erase(id);
}

ALuint removeAudio(ALuint id);
