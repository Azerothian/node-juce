/*
  ==============================================================================

    AudioFormatManager.cpp
    Created: 19 Jun 2021 2:07:20am
    Author:  mmckenzie

  ==============================================================================
*/

#include "AudioFormatManager.h"

AudioFormatManager::AudioFormatManager(const Napi::CallbackInfo& info) : ObjectWrap(info) {
    Napi::Env env = info.Env();
    this->_audioFormatManager = new juce::AudioFormatManager();
}


void AudioFormatManager::registerBasicFormats(const Napi::CallbackInfo& info) {
    this->_audioFormatManager->registerBasicFormats();
}


Napi::Function AudioFormatManager::GetClass(Napi::Env env) {
    return DefineClass(env, "AudioFormatManager", {
        AudioFormatManager::InstanceMethod("registerBasicFormats", &AudioFormatManager::registerBasicFormats),
    });
}
