#ifndef PLATFORMER2D_TILEMAP_H
#define PLATFORMER2D_TILEMAP_H

#include <SFML/Graphics.hpp>
#include "TileSet.h"
#include "Layer.h"
#include <cmath>
/**
 * @class TileMap - Klasa, która przechowuje kafelki i je wczytuje
 */
class TileMap : public sf::Drawable, public sf::Transformable {
public:
    /***
     * Służy do ładowania kafelków użytych w wskazanej przez parametr warstwie
     * @param tileset - obiekt z kafelkami
     * @param layer - warstwa
     * @return zwraca true w przypadku załadowania poprawnego lub false w przypadku niepowodzenia
     */
    bool load(TileSet tileset, Layer layer) {
        tex.loadFromFile(tileset.getImage());

        verts.setPrimitiveType(sf::Quads);
        verts.resize(layer.getWidth() * layer.getHeight() * 4);

        std::vector<int> data = layer.getData();

        for (size_t i = 0; i < data.size(); i++) {
            if (data[i] != 0) {
                size_t columns = tileset.getColumns();
                size_t val = data[i] - tileset.getFirstGid();

                size_t y = floor(val / columns);
                size_t x = val % columns;

                size_t yPos = floor(i / layer.getWidth());
                size_t xPos = i % layer.getWidth();

                sf::Vertex* quad = &verts[i*4];

                float xPos1 = xPos * tileset.getTileWidth();
                float xPos2 = (xPos + 1) * tileset.getTileWidth();
                float yPos1 = yPos * tileset.getTileHeight();
                float yPos2 = (yPos + 1) * tileset.getTileHeight();

                float x1 = x * tileset.getTileWidth();
                float x2 = (x + 1) * tileset.getTileWidth();
                float y1 = y * tileset.getTileHeight();
                float y2 = (y + 1) * tileset.getTileHeight();

                quad[0].position = sf::Vector2f(xPos1, yPos1);
                quad[1].position = sf::Vector2f(xPos2, yPos1);
                quad[2].position = sf::Vector2f(xPos2, yPos2);
                quad[3].position = sf::Vector2f(xPos1, yPos2);

                quad[0].texCoords = sf::Vector2f(x1, y1);
                quad[1].texCoords = sf::Vector2f(x2, y1);
                quad[2].texCoords = sf::Vector2f(x2, y2);
                quad[3].texCoords = sf::Vector2f(x1, y2);
            }
        }
        return true;
    }
private:
    /***
     * Wirtualna metoda, który służy do przenoszenia elemntów do wyrenderowania na ekran
     * @param target - element do wyrenderowania
     * @param states - stany używane do renderowania
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = &tex;
        target.draw(verts, states);
    }
    ///Tablica która przechowuje wierzchołki
    sf::VertexArray verts;
    ///Przechowuje teksture kafelków
    sf::Texture tex;
};


#endif //PLATFORMER2D_TILEMAP_H
