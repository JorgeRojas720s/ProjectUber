#include "RadioButton.h"

RadioButton::RadioButton(float x, float y, const string& labelText, Font& font, bool defaultSelected) {
    outerCircle.setRadius(10);
    outerCircle.setFillColor(Color::White);
    outerCircle.setOutlineColor(Color::Black);
    outerCircle.setOutlineThickness(2);
    outerCircle.setPosition(x, y);

    innerCircle.setRadius(5);
    innerCircle.setFillColor(Color::Black);
    innerCircle.setPosition(x + 5, y + 5);

    selected = defaultSelected;

    label.setFont(font);
    label.setString(labelText);
    label.setCharacterSize(16);
    label.setFillColor(Color::Black);
    label.setPosition(x + 25, y - 3);
}

void RadioButton::draw(RenderWindow& window) {
    window.draw(outerCircle);
    if (selected) {
        window.draw(innerCircle);
    }
    window.draw(label);
}

bool RadioButton::isClicked(Vector2f mousePos) {
    return outerCircle.getGlobalBounds().contains(mousePos);
}

void RadioButton::select() {
    selected = true;
}

void RadioButton::deselect() {
    selected = false;
}


