#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient  {
public:
    inline static const std::string default_name = "pickle";
    inline static const std::string default_unit = "thing";
    inline static const std::string default_operation = "cut";
    static const int default_time = 10;
    static const int default_quantity = 1;

    Ingredient();
    Ingredient(const std::string &name, const std::string &unit, const std::string &operation, const int &time, const int &quantity); //init
    Ingredient(const Ingredient &copy); //cp
    ~Ingredient() = default; //rm

    std::string get_name() const { return name; }
    std::string get_unit() const { return unit; }
    std::string get_operation() const { return operation; }
    int get_time() const { return time; }
    int get_quantity() const { return quantity; }

    void set_name(const std::string &name);
    void set_unit(const std::string &unit);
    void set_operation(const std::string &operation);
    void set_time(const int &time);
    void set_quantity(const int &quantity);

private:
    std::string name;
    std::string unit;
    std::string operation;
    int time;
    int quantity;
};

#endif // INGREDIENT_H
