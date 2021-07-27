/*
  ==============================================================================

    AudioFormatManager.cpp
    Created: 19 Jun 2021 2:07:20am
    Author:  mmckenzie

  ==============================================================================
*/
#include "AudioFormatManager.h"
#include "../codecs/WavAudioFormat.h"

AudioFormatManager::AudioFormatManager(const Napi::CallbackInfo& info) : ObjectWrap(info) {
    // Napi::Env env = info.Env();
    this->_audioFormatManager = new juce::AudioFormatManager();
}
AudioFormatManager::~AudioFormatManager() {
  // this->~_audioFormatManager();
}


Napi::Value AudioFormatManager::getNumKnownFormats(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int knownFormats = this->_audioFormatManager->getNumKnownFormats();
  return Napi::Number::New(env, knownFormats); 
}

void AudioFormatManager::registerBasicFormats(const Napi::CallbackInfo& info) {
    this->_audioFormatManager->registerBasicFormats();
}

//AudioFormat *newFormat, bool makeThisTheDefaultFormat
void AudioFormatManager::registerFormat(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Object newFormatParam = info[0].As<Napi::Object>();
  Napi::Boolean defaultFormatParam = info[1].As<Napi::Boolean>();
  AudioFormat* obj;
  napi_unwrap(env, newFormatParam, reinterpret_cast<void**>(&obj));

  // WavAudioFormat* example_parent = Napi::ObjectWrap<WavAudioFormat>::Unwrap(newFormatParam);
  this->_audioFormatManager->registerFormat(obj->getJUCEObject(), defaultFormatParam.Value());
///  this->_audioFormatManager->
  
}
Napi::Value AudioFormatManager::getKnownFormats(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Array retVal = Napi::Array::New(env);
  int numKnownFormats = this->_audioFormatManager->getNumKnownFormats();
  for(int i = 0; i < numKnownFormats; i++) {
    juce::AudioFormat* itr = this->_audioFormatManager->getKnownFormat(i);
      //push into array?
      
    WavAudioFormat* waf = WavAudioFormat::NewInstance(info, itr);
    waf->setJUCEObject(itr);
    retVal.Set(i, waf->Value());
  }
  // for (itr = this->_audioFormatManager->begin(); itr != this->_audioFormatManager->end(); ++itr) {

  // }
  return retVal;
}
void AudioFormatManager::setKnownFormats(const Napi::CallbackInfo& info, const Napi::Value& value) {

}

Napi::Function AudioFormatManager::GetClass(Napi::Env env) {
    return DefineClass(env, "AudioFormatManager", {
        AudioFormatManager::InstanceMethod("registerBasicFormats", &AudioFormatManager::registerBasicFormats),
        AudioFormatManager::InstanceMethod("getNumKnownFormats", &AudioFormatManager::getNumKnownFormats),
        AudioFormatManager::InstanceMethod("registerFormat", &AudioFormatManager::registerFormat),
        // AudioFormatManager::InstanceMethod("getKnownFormats", &AudioFormatManager::getKnownFormats),
        AudioFormatManager::InstanceAccessor("knownFormats", &AudioFormatManager::getKnownFormats, &AudioFormatManager::setKnownFormats),
    });
}
