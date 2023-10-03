#ifndef COMMAND_CONTROLLER_ITEM_ITEM
#define COMMAND_CONTROLLER_ITEM_ITEM

#include <string>
#include <unordered_map>

using ParametersMap = std::unordered_map<std::string, int>;

class Item {
public:
    Item();
    void setId(int id);
    void setPatameter(std::string key, int value);
    int getId() const;
    std::string getParams() const;
    virtual std::string getName() const =0;
    virtual Item* create() =0;
    virtual ~Item() =default;

protected:
    void registerParams();

protected:
    ParametersMap params_;
    int id_;
};

#endif // COMMAND_CONTROLLER_ITEM_ITEM