#include "tests.h"
#include "ingredient.h"
#include <assert.h>
#include <iostream>

void testIngredientWithDefaultConstructor() {
    Ingredient ingredient;
    assert(Ingredient::default_name == ingredient.get_name());
    assert(Ingredient::default_unit == ingredient.get_unit());
    assert(Ingredient::default_quantity == ingredient.get_quantity());
}

void testIngredientWithInitConstructor() {
    Ingredient ingredient("papaya", "kg", 777);
    assert("papaya" == ingredient.get_name());
    assert("kg" == ingredient.get_unit());
    assert(777 == ingredient.get_quantity());
}

void testIngredientWithCopyConstructor() {
    Ingredient ingredient1("papaya", "kg", 777);
    Ingredient ingredient2(ingredient1);
    assert("papaya" == ingredient2.get_name());
    assert("kg" == ingredient2.get_unit());
    assert(777 == ingredient2.get_quantity());
}

void testIngredientSetName() {
    Ingredient ingredient;
    ingredient.set_name("peach");
    assert("peach" == ingredient.get_name());
}

void testIngredientSetUnit() {
    Ingredient ingredient;
    ingredient.set_unit("gr");
    assert("gr" == ingredient.get_unit());
}

void testIngredientSetQuantity() {
    Ingredient ingredient;
    ingredient.set_quantity(69);
    assert(69 == ingredient.get_quantity());
}

void testIngredient() {
    testIngredientWithDefaultConstructor();
    testIngredientWithInitConstructor();
    testIngredientWithCopyConstructor();
    testIngredientSetName();
    testIngredientSetUnit();
    testIngredientSetQuantity();
    std::cout << "All tests are passed" << std::endl;
}
