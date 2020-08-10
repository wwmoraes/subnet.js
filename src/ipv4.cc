#include <napi.h>

namespace Subnet {
  #include "subnet/ipv4.hh"
  #include "subnet/ipv4.cc"
}

class IPv4 : Subnet::IPv4, public Napi::ObjectWrap<IPv4> {
  public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    IPv4(const Napi::CallbackInfo& info);

  private:
    Napi::Value toString(const Napi::CallbackInfo& info);
};

Napi::Object IPv4::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func = DefineClass(env, "IPv4", {
    InstanceMethod("toString", &IPv4::toString),
  });

  Napi::FunctionReference* constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  exports.Set("IPv4", func);
  env.SetInstanceData<Napi::FunctionReference>(constructor);

  return exports;
}

IPv4::IPv4(const Napi::CallbackInfo& info) : Napi::ObjectWrap<IPv4>(info) {
    if (info.Length() <= 0) {
      this->setIP(0);
      return;
    }

    if (info[0].IsString()) {
      this->setIP(info[0].ToString());
    } else if (info[0].IsNumber()) {
      this->setIP(info[0].ToNumber());
    } else {
      Napi::Error::New(info.Env(), "value is not convertible to IP").ThrowAsJavaScriptException();
    }
}

Napi::Value IPv4::toString(const Napi::CallbackInfo& info) {
  return Napi::String::From(info.Env(), this->str());
}
