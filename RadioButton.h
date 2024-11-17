#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class RadioButton {
public:
    CircleShape outerCircle;
    CircleShape innerCircle;
    Text label;
    bool selected;

    RadioButton(float x, float y, const string& labelText, Font& font, bool defaultSelected = false);

    void draw(RenderWindow& window);
    bool isClicked(Vector2f mousePos);
    void select();
    void deselect();
};

