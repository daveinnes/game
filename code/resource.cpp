#include "resource.h"
#include <json/json.h>

Resource::Resource(const Json::Value& v)
:Resource(v[0].asInt(), v[1].asInt()) {

}