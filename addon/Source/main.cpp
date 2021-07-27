/*
  ==============================================================================

    main.cpp
    Created: 19 Jun 2021 2:07:09am
    Author:  mmckenzie

  ==============================================================================
*/

#include <napi.h>
#include "AudioFormatManager.h"


Napi::Object Init(Napi::Env env, Napi::Object exports) {
    Napi::String name = Napi::String::New(env, "AudioFormatManager");
    exports.Set(name, AudioFormatManager::GetClass(env));
    return exports;
}

NODE_API_MODULE(addon, Init)
