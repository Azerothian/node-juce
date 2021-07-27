#pragma once

#include <napi.h>
#include <juce_audio_formats/juce_audio_formats.h>


class AudioFormat
{
public:
    virtual juce::AudioFormat* getJUCEObject();

private:
    juce::AudioFormat* _audioFormat;
};
