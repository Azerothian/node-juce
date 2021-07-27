/*
  ==============================================================================

    AudioFormatManager.cpp
    Created: 19 Jun 2021 2:07:20am
    Author:  mmckenzie

  ==============================================================================
*/
#include "AudioFormat.h"

juce::AudioFormat* AudioFormat::getJUCEObject() {
  return NULL;
}
// AudioFormat::AudioFormat(const Napi::CallbackInfo& info) : ObjectWrap(info) {
//     // Napi::Env env = info.Env();
//     // this->_audioFormatManager = new juce::AudioFormatManager();
// }
// AudioFormat::~AudioFormat() {
//   // this->~_audioFormatManager();
// }


// Napi::Function AudioFormat::GetClass(Napi::Env env) {
//     return DefineClass(env, "AudioFormat", {});
// }
