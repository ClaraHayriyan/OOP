#ifndef OOP_DOCUMENT_ITEM_ITEM_HPP
#define OOP_DOCUMENT_ITEM_ITEM_HPP

#include "Geometry.hpp"
#include "Attributes.hpp"

#include <string>

using ParametersMap = std::unordered_map<std::string, int>;

class Item {
public:
//  Item(int id, Geometry geom, Attributes attr);
    void setId(int id);
    void setGeometry(const Geometry& geom);
    void setAttributes(const Attributes& attr);
    void setPatameter(std::string key, int value);
    int getParameter(std::string key);
    int getId() const;
    virtual std::string getName() const =0;
    virtual Item* create() =0;
    virtual ~Item() =default;

protected:
    int id_;
    Geometry geometry_;
    Attributes attributes_;
};

#endif // OOP_DOCUMENT_ITEM_ITEM_HPP