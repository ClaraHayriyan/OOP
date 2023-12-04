#ifndef OOP_DOCUMENT_ITEM_ATTRIBUTES_HPP
#define OOP_DOCUMENT_ITEM_ATTRIBUTES_HPP

#include <string>
#include <unordered_map>

class Attributes {
public:
    Attributes();
    Attributes(int lineWidth, int lineColor, int fillColor);
    void set(std::string key, int value);
    int get(std::string key) const;
    bool find(std::string key) const;

private:
    using Registry = std::unordered_map<std::string, int>;

private:
    void registerAttributes();

private:
    Registry reg_;
};

#endif // OOP_DOCUMENT_ITEM_ATTRIBUTES_HPP