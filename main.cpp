#include <iostream>
#include "tests.h"
#include "ingredient.h"
#include "recipe.h"
#include <string>

int main() {
    testIngredient();

    Ingredient ingredient("melon", "l", "split", 35, 6);

    std::cout << ingredient.get_name() << std::endl;
    std::cout << ingredient.get_unit() << std::endl;
    std::cout << ingredient.get_operation() << std::endl;
    std::cout << ingredient.get_time() << std::endl;
    std::cout << ingredient.get_quantity() << std::endl;

    ingredient.set_name("pumpkin");
    ingredient.set_unit("mgr");
    ingredient.set_operation("fire");
    ingredient.set_time(13);
    ingredient.set_quantity(666);

    std::cout << ingredient.get_name() << std::endl;
    std::cout << ingredient.get_unit() << std::endl;
    std::cout << ingredient.get_operation() << std::endl;
    std::cout << ingredient.get_time() << std::endl;
    std::cout << ingredient.get_quantity() << std::endl;

    return 0;
}
