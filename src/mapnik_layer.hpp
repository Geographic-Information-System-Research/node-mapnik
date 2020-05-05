#ifndef __NODE_MAPNIK_LAYER_H__
#define __NODE_MAPNIK_LAYER_H__

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wshadow"
#include <napi.h>
#include <uv.h>
#pragma GCC diagnostic pop

// stl
#include <string>
#include <memory>



namespace mapnik { class layer; }
typedef std::shared_ptr<mapnik::layer> layer_ptr;

class Layer : public Napi::ObjectWrap<Layer> {
public:
    static Napi::FunctionReference constructor;
    static void Initialize(Napi::Object target);
    static Napi::Value New(Napi::CallbackInfo const& info);

    static Napi::Value NewInstance(mapnik::layer const& lay_ref);
    static Napi::Value describe(Napi::CallbackInfo const& info);

    Napi::Value get_prop(Napi::CallbackInfo const& info);
    void set_prop(Napi::CallbackInfo const& info, const Napi::Value& value);

    Layer(std::string const& name);
    Layer(std::string const& name, std::string const& srs);
    Layer();
    inline layer_ptr get() { return layer_; }

private:
    ~Layer();
    layer_ptr layer_;
};

#endif
