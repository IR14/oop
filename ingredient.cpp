#include <iostream>
#include "ingredient.h"
#include <string>

Ingredient::Ingredient() {
    name = default_name;
    unit = default_unit;
    quantity = default_quantity;
}

Ingredient::Ingredient(const std::string &name, const std::string &unit, const int &quantity) {
    this->name = name;
    this->unit = unit;
    this->quantity = quantity;
}

Ingredient::Ingredient(const Ingredient &copy) {
    name = copy.name;
    unit = copy.unit;
    quantity = copy.quantity;
}

void Ingredient::set_name(const std::string &name) {
    if (name.length() > 0)
        this->name = name;
    else
        this->name = default_name;
}

void Ingredient::set_unit(const std::string &unit) {
    if (unit.length() > 0)
        this->unit = unit;
    else
        this->unit = default_unit;
}

void Ingredient::set_quantity(const int &quantity) {
    if (quantity > 0)
        this->quantity = quantity;
    else
        this->quantity = default_quantity;
}