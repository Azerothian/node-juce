#pragma once

#include <napi.h>
#include <juce_audio_formats/juce_audio_formats.h>


class AudioFormatManager : public Napi::ObjectWrap<AudioFormatManager>
{
public:
    AudioFormatManager(const Napi::CallbackInfo&);
    ~AudioFormatManager();


    void registerBasicFormats(const Napi::CallbackInfo&);
    void registerFormat(const Napi::CallbackInfo&);
    Napi::Value getNumKnownFormats(const Napi::CallbackInfo&);
    Napi::Value getKnownFormats(const Napi::CallbackInfo&);
    void setKnownFormats(const Napi::CallbackInfo&, const Napi::Value& value);

    static Napi::Function GetClass(Napi::Env);

private:
    juce::AudioFormatManager* _audioFormatManager;
};
