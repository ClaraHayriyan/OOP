#include "Items.hpp"

std::string Line::getName() const {
    return "Line";
}

Line* Line::create() {
    return new Line;
}

std::string Rectangle::getName() const {
    return "Rectangle";
}

Rectangle* Rectangle::create() {
    return new Rectangle;
}

std::string Ellipse::getName() const {
    return "Ellipse";
}

Ellipse* Ellipse::create() {
    return new Ellipse;
}

std::string Triangle::getName() const {
    return "Triangle";
}

Triangle* Triangle::create() {
    return new Triangle;
}

std::string Trapezoid::getName() const {
    return "Trapezoid";
}

Trapezoid* Trapezoid::create() {
    return new Trapezoid;
}

std::string Rhombus::getName() const {
    return "Rhombus";
}

Rhombus* Rhombus::create() {
    return new Rhombus;
}
