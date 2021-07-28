#pragma once

#include <napi.h>
#include <juce_audio_devices/midi_io/juce_MidiDevices.h>
#include "../../utils/juce-tmpl.h"

class MidiDeviceInfo :
    public JuceTmpl<juce::MidiDeviceInfo, MidiDeviceInfo>,
    public Napi::ObjectWrap<MidiDeviceInfo>
{
public:
    MidiDeviceInfo(const Napi::CallbackInfo&);
    virtual ~MidiDeviceInfo();
    void initialise(const Napi::CallbackInfo&);
    static Napi::Function GetClass(Napi::Env);
};

