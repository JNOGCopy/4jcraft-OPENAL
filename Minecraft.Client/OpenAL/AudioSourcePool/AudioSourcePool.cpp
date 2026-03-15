#include "AudioSourcePool.hpp"
#include <memory>
#include <utility>
#include <vector>
#include "../SoundDevice/SoundDevice.hpp"
#include "../AudioSource/AudioSource.hpp"

AudioSourcePool::AudioSourcePool(SoundDevice* soundDevice){
    pSoundDevice = soundDevice;
}
AudioSourcePool* AudioSourcePool::createAudioSourcePool(SoundDevice* soundDevice){
    return new AudioSourcePool(soundDevice);
}

int AudioSourcePool::getFreeAudioSource(){
    if (mFreeAudioSource.empty()){
        mAudioSourcePool.push_back(std::unique_ptr<AudioSource>(AudioSource::createAudioSource(pSoundDevice)));
        mFreeAudioSource.push_back(mAudioSourcePool.size()-1);
    }
    return mFreeAudioSource.back();
}

void AudioSourcePool::playSound(const AudioSourceConfig audioConfig, ALuint soundId){
    int audioSourceIdx = getFreeAudioSource();
    mFreeAudioSource.pop_back();
    mUsingAudioSource.push_back(audioSourceIdx);
}

void AudioSourcePool::tick(){
    std::vector<int> newUsingAudioSource;

    for (int idx : mUsingAudioSource){
        bool isPlaying = mAudioSourcePool[idx].get();
        if (isPlaying){
            mFreeAudioSource.push_back(idx);
        } else {
            newUsingAudioSource.push_back(idx);
        }
    }

    mUsingAudioSource = std::move(newUsingAudioSource);
}