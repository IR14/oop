#include <iostream>
#include "ingredient.h"
#include <string>

Ingredient::Ingredient() {
    name = default_name;
    unit = default_unit;
    operation = default_operation;
    time = default_time;
    quantity = default_quantity;
}

Ingredient::Ingredient(const std::string &name, const std::string &unit, const std::string &operation, const int &time,
                       const int &quantity) {
    this->name = name;
    this->unit = unit;
    this->operation = operation;
    this->time = time;
    this->quantity = quantity;
}

Ingredient::Ingredient(const Ingredient &copy) {
    name = copy.name;
    unit = copy.unit;
    operation = copy.operation;
    time = copy.time;
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

void Ingredient::set_operation(const std::string &operation) {
    if (operation.length() > 0)
        this->operation = operation;
    else
        this->operation = default_operation;
}

void Ingredient::set_time(const int &time) {
    if (duration > 0)
        this->time = time;
    else
        this->time = default_time;
}

void Ingredient::set_quantity(const int &quantity) {
    if (quantity > 0)
        this->quantity = quantity;
    else
        this->quantity = default_quantity;
}
