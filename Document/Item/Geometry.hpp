#ifndef OOP_DOCUMENT_ITEM_GEOMETRY_HPP
#define OOP_DOCUMENT_ITEM_GEOMETRY_HPP

#include <string>
#include <unordered_map>

class Geometry {
public:
    Geometry();
    Geometry(int tl_x, int tl_y, int br_x, int br_y);
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

#endif // OOP_DOCUMENT_ITEM_GEOMETRY_HPP