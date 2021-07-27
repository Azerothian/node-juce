#pragma once

#include <napi.h>
#include <juce_audio_formats/juce_audio_formats.h>
#include "../formats/AudioFormat.h"

#include "../../utils/juce-tmpl.h"

class WavAudioFormat : 
    public Napi::ObjectWrap<WavAudioFormat>,
    public JuceTmpl<juce::AudioFormat, WavAudioFormat>
{
public:
    WavAudioFormat(const Napi::CallbackInfo&);
    virtual ~WavAudioFormat();
    void initialise(const Napi::CallbackInfo&);
    static Napi::Function GetClass(Napi::Env);

};




// class WavAudioFormat : public 
//     Napi::ObjectWrap<WavAudioFormat>, AudioFormat
// {
// public:
//     WavAudioFormat(const Napi::CallbackInfo&);
//     virtual ~WavAudioFormat();

//     juce::AudioFormat* getJUCEObject() override;
//     void setJUCEObject(juce::AudioFormat*);

//     void initialise(const Napi::CallbackInfo&);

//     static Napi::Function GetClass(Napi::Env);
//     static WavAudioFormat* NewInstance(const Napi::CallbackInfo&, juce::AudioFormat*);
// private:
//     static Napi::FunctionReference constructor;
//     juce::WavAudioFormat* _wavAudioFormat;
// };
