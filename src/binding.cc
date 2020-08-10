#include <napi.h>
#include "ipv4.cc"
#include "cidr.cc"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  IPv4::Init(env, exports);
  CIDR::Init(env, exports);

  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);
