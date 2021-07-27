#include <napi.h>
#include "./juce-tmpl.h"


template <typename JType, typename NType>
NType* JuceTmpl<JType, NType>::NewInstance(const Napi::CallbackInfo& info, JType* arg) {
  Napi::Env env = info.Env();
  Napi::Object obj = constructor.New({});
  JuceTmpl<JType, NType>* waf;
  napi_unwrap(env, obj, reinterpret_cast<void**>(&waf));
  waf->setJUCEObject(arg);
  return reinterpret_cast<NType*>(waf);
}

template <typename JType, typename NType>
Napi::FunctionReference JuceTmpl<JType, NType>::constructor;

// template <typename JType, typename NType>
// Napi::Function JuceTmpl<JType, NType>::DefineClass(Napi::Env env) {
  
// }

// template <typename JType, typename NType>
// Napi::Function JuceTmpl<JType, NType>::GetClass(Napi::Env env) {
//   Napi::Function func = JuceTmpl<JType, NType>::DefineClass(env);
//   constructor = Napi::Persistent(func);
//   constructor.SuppressDestruct();
//   return func;
// }
