#include "Layer.h"

Layer::Layer(rapidjson::Value& value) {
    if (value.HasMember("data")) {
        for (auto& a : value["data"].GetArray()) {
            data.push_back(a.GetInt());
        }
    }

    if (value.HasMember("objects")) {
        for (auto& a : value["objects"].GetArray()) {
            objects.push_back(LayerObject(
                    a["x"].GetFloat(),
                    a["y"].GetFloat(),
                    a["width"].GetFloat(),
                    a["height"].GetFloat()
            ));
        }
    }

    if (value.HasMember("height")) {
        height = value["height"].GetInt();
    }

    id = value["id"].GetInt();

    if (value.HasMember("image")) {
        image = value["image"].GetString();
    }

    name = value["name"].GetString();
    opacity = value["opacity"].GetInt();
    type = value["type"].GetString();
    visible = value["visible"].GetBool();

    if (value.HasMember("width")) {
        width = value["width"].GetInt();
    }

    x = value["x"].GetInt();
    y = value["y"].GetInt();
}

Layer::~Layer() = default;

LayerObject::LayerObject(float x, float y, float width, float height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}
