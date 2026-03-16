#include "AudioSourcePool.hpp"
#include <cstdlib>
#include <memory>
#include <utility>
#include <vector>
#include "../SoundDevice/SoundDevice.hpp"
#include "../AudioSource/AudioSource.hpp"

AudioSourcePool::AudioSourcePool(){
    
}
AudioSourcePool* AudioSourcePool::createAudioSourcePool(){
    return new AudioSourcePool();
}

int AudioSourcePool::getFreeAudioSource(){
    if (mFreeAudioSource.empty()){
        mAudioSourcePool.push_back(std::unique_ptr<AudioSource>(AudioSource::createAudioSource()));
        mFreeAudioSource.push_back(mAudioSourcePool.size()-1);

        app.DebugPrintf("-- AUDIO SOURCE POOL -- : Creating new audio source in order to supply AudioSourcePool\n");
    } else { app.DebugPrintf("-- AUDIO SOURCE POOL -- : Using audio source already made\n"); }

    int idx = mFreeAudioSource.back();
    mFreeAudioSource.pop_back();

    return idx;
}

void AudioSourcePool::playSound(const AudioSourceConfig audioConfig, ALuint soundId){
    int audioSourceIdx = getFreeAudioSource();
    
    mAudioSourcePool[audioSourceIdx].get()->setPitch(audioConfig.pitch).setPosition(audioConfig.xPos, audioConfig.yPos, audioConfig.zPos).setVolume(audioConfig.volume).play(soundId);
    mUsingAudioSource.push_back(audioSourceIdx);

    app.DebugPrintf("-- AUDIO SOURCE POOL -- : Try play sound %i\n", soundId);
}

void AudioSourcePool::tick(){
    std::vector<int> newUsingAudioSource;

    for (int idx : mUsingAudioSource){
        bool isPlaying = mAudioSourcePool[idx].get()->isPlaying();
        if (!isPlaying){
            mFreeAudioSource.push_back(idx);
            app.DebugPrintf("-- AUDIO SOURCE POOL -- : Stop using audio source, so send it to mFreeAudioSource");
        } else {
            newUsingAudioSource.push_back(idx);
        }
    }

    mUsingAudioSource = std::move(newUsingAudioSource);
}