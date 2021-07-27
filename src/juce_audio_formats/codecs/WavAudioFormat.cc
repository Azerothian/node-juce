/*
  ==============================================================================

    WavAudioFormat.cpp
    Created: 19 Jun 2021 2:07:20am
    Author:  mmckenzie

  ==============================================================================
*/
#include "WavAudioFormat.h"


WavAudioFormat::WavAudioFormat(const Napi::CallbackInfo& info) : 
  ObjectWrap<WavAudioFormat>(info) {
    // Napi::Env env = info.Env();
    // this->_wavAudioFormat = new juce::WavAudioFormat();
}
WavAudioFormat::~WavAudioFormat() {
  //this->_wavAudioFormat();
}

void WavAudioFormat::initialise(const Napi::CallbackInfo& info) {
  this->_juceObject = new juce::WavAudioFormat();
}

Napi::Function WavAudioFormat::GetClass(Napi::Env env) {
  Napi::Function func = DefineClass(env, "WavAudioFormat", {});
  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();
  return func;
}



// /*
//   ==============================================================================

//     WavAudioFormat.cpp
//     Created: 19 Jun 2021 2:07:20am
//     Author:  mmckenzie

//   ==============================================================================
// */
// #include "WavAudioFormat.h"


// WavAudioFormat::WavAudioFormat(const Napi::CallbackInfo& info) : ObjectWrap<WavAudioFormat>(info) {
//     // Napi::Env env = info.Env();
//     // this->_wavAudioFormat = new juce::WavAudioFormat();
// }
// WavAudioFormat::~WavAudioFormat() {
//   //this->_wavAudioFormat();
// }

// void WavAudioFormat::initialise(const Napi::CallbackInfo& info) {
//   this->_wavAudioFormat = new juce::WavAudioFormat();
// }


// juce::AudioFormat* WavAudioFormat::getJUCEObject() {
//   return this->_wavAudioFormat;
  
// }
// void WavAudioFormat::setJUCEObject(juce::AudioFormat* af) {
//   this->_wavAudioFormat = reinterpret_cast<juce::WavAudioFormat*>(af);
// }



// WavAudioFormat* WavAudioFormat::NewInstance(const Napi::CallbackInfo& info, juce::AudioFormat* arg) {
//   Napi::Env env = info.Env();
//   Napi::Object obj = constructor.New({});
//   WavAudioFormat* waf;
//   napi_unwrap(env, obj, reinterpret_cast<void**>(&waf));
//   waf->setJUCEObject(arg);
//   return waf;
// }

// Napi::FunctionReference WavAudioFormat::constructor;
// Napi::Function WavAudioFormat::GetClass(Napi::Env env) {
//   Napi::Function func = DefineClass(env, "WavAudioFormat", {});
//   constructor = Napi::Persistent(func);
//   constructor.SuppressDestruct();
//   return func;
// }
