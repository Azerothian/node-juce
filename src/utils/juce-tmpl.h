#pragma once

#include <napi.h>

template <typename JType, typename NType>
class JuceTmpl {
  public:
    JType* getJUCEObject();
    void setJUCEObject(JType*);
    JType* _juceObject;

    static NType* NewInstance(const Napi::CallbackInfo&, JType*);
    // virtual static Napi::Function DefineClass(Napi::Env);
    // static Napi::Function GetClass(Napi::Env);
    static Napi::FunctionReference constructor;
  private:
};
