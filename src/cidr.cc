#include <napi.h>

namespace Subnet {
  #include "subnet/cidr.hh"
  #include "subnet/cidr.cc"
}

class CIDR : Subnet::CIDR, public Napi::ObjectWrap<CIDR> {
  public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    CIDR(const Napi::CallbackInfo& info);

  private:
    Napi::Value toString(const Napi::CallbackInfo& info);
};

Napi::Object CIDR::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func = DefineClass(env, "CIDR", {
    InstanceMethod("toString", &CIDR::toString),
  });

  Napi::FunctionReference* constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  exports.Set("CIDR", func);
  env.SetInstanceData<Napi::FunctionReference>(constructor);

  return exports;
}

CIDR::CIDR(const Napi::CallbackInfo& info) : Napi::ObjectWrap<CIDR>(info) {
  if (info.Length() <= 0) {
      this->set("0.0.0.0/0");
      return;
    }

    if (info[0].IsString()) {
      this->set(info[0].ToString());
    } else {
      Napi::Error::New(info.Env(), "value is not convertible to CIDR").ThrowAsJavaScriptException();
    }
}

Napi::Value CIDR::toString(const Napi::CallbackInfo& info) {
  return Napi::String::From(info.Env(), this->str());
}
