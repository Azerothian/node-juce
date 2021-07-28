#include <napi.h>
// #include "juce_audio_formats/formats/AudioFormatManager.h"
// #include "juce_audio_formats/codecs/WavAudioFormat.h"

#include "utils/juce-tmpl.cc"

#include "juce_audio_formats/formats/AudioFormat.cc"
#include "juce_audio_formats/formats/AudioFormatManager.cc"
#include "juce_audio_formats/codecs/WavAudioFormat.cc"
#include "juce_audio_devices/midi_io/MidiDevices.cc"

Napi::Object Init(Napi::Env env, Napi::Object exports)
{

    exports.Set(Napi::String::New(env, "AudioFormatManager"), AudioFormatManager::GetClass(env));
    exports.Set(Napi::String::New(env, "WavAudioFormat"), WavAudioFormat::GetClass(env));
    return exports;
}

NODE_API_MODULE(addon, Init)
