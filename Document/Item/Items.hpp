#ifndef OOP_DOCUMENT_ITEM_ITEMS_HPP
#define OOP_DOCUMENT_ITEM_ITEMS_HPP

#include "Item.hpp"

class Line : public Item {
    virtual std::string getName() const override;
    virtual Line* create() override;
};

class Rectangle : public Item {
    virtual std::string getName() const override;
    virtual Rectangle* create() override;
};

class Ellipse : public Item {
    virtual std::string getName() const override;
    virtual Ellipse* create() override;
};

class Triangle : public Item {
    virtual std::string getName() const override;
    virtual Triangle* create() override;
};

class Trapezoid : public Item {
    virtual std::string getName() const override;
    virtual Trapezoid* create() override;
};

class Rhombus : public Item {
    virtual std::string getName() const override;
    virtual Rhombus* create() override;
};

#endif // OOP_DOCUMENT_ITEM_ITEMS_HPP