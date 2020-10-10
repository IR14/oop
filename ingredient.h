#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {
public:
    static const std::string default_name = "pickle";
    static const std::string default_unit = "thing";
    static const int default_quantity = 1;

    Ingredient();
    Ingredient(const std::string &name, const std::string &unit, const int &quantity); //init
    Ingredient(const Ingredient &copy); //cp

    std::string get_name() const { return name; }
    std::string get_unit() const { return unit; }
    int get_quantity() const { return quantity; }

    void set_name(const std::string &name);
    void set_unit(const std::string &unit);
    void set_quantity(const int &quantity);

private:
    std::string name;
    std::string unit;
    int quantity;
};

#endif // INGREDIENT_H
