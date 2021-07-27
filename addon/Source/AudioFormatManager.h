/*
  ==============================================================================

    AudioFormatManager.h
    Created: 19 Jun 2021 2:07:20am
    Author:  mmckenzie

  ==============================================================================
*/

#pragma once
#include <napi.h>
#include <juce_audio_formats/juce_audio_formats.h>


class AudioFormatManager : public Napi::ObjectWrap<AudioFormatManager>
{
public:
    AudioFormatManager(const Napi::CallbackInfo&);
    void registerBasicFormats(const Napi::CallbackInfo&);

    static Napi::Function GetClass(Napi::Env);

private:
    juce::AudioFormatManager* _audioFormatManager;
};
