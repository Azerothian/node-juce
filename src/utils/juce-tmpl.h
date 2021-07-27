#pragma once

#include <napi.h>

template <typename JType, typename NType>
class JuceTmpl {
  public:
    JType* getJUCEObject();
    void setJUCEObject(JType*);

    static NType* NewInstance(const Napi::CallbackInfo&, JType*);
    // virtual static Napi::Function DefineClass(Napi::Env);
    // static Napi::Function GetClass(Napi::Env);
    JType* _juceObject;
    static Napi::FunctionReference constructor;
  private:
};
