/*
  ==============================================================================

    MidiDevices.cpp
    Created: 19 Jun 2021 2:07:20am
    Author:  mmckenzie

  ==============================================================================
*/
#include "MidiDevices.h"

MidiDeviceInfo::MidiDeviceInfo(const Napi::CallbackInfo &info) : 
    ObjectWrap<MidiDeviceInfo>(info)
{

}
MidiDeviceInfo::~MidiDeviceInfo() {
  //this->_wavAudioFormat();
}

Napi::Function MidiDeviceInfo::GetClass(Napi::Env env) {
  Napi::Function func = DefineClass(env, "MidiDeviceInfo", {});
  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();
  return func;
}
