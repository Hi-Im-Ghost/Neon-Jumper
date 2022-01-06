//
// Created by ToQly on 27.11.2021.
//

#ifndef PLATFORMER2D_LAYER_H
#define PLATFORMER2D_LAYER_H

#include <SFML/Graphics.hpp>
#include "rapidjson/include/rapidjson/document.h"

class LayerObject {
public:
    LayerObject(float x, float y, float width, float height);

    float x;
    float y;
    float width;
    float height;
};

class Layer {
public:
    Layer(){};
    Layer(rapidjson::Value& value);
    ~Layer();

    std::vector<int> getData() { return data; }
    int getHeight() { return height; }
    int getId() { return id; }
    std::string getImage() { return image; }
    std::string getName() { return name; }
    int getOpacity() { return opacity; }
    std::string getType() { return type; }
    bool isVisible() { return visible; }
    int getWidth() { return width; }
    int getX() { return x; }
    int getY() { return y; }
    std::vector<LayerObject> getObjects() {return objects;}

private:
    std::vector<int> data;
    int height;
    int id;
    std::string image;
    std::string name;
    int opacity;
    std::string type;
    bool visible;
    int width;
    int x;
    int y;
    std::vector<LayerObject> objects;
};


#endif //PLATFORMER2D_LAYER_H
