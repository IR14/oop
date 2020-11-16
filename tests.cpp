#include "tests.h"
#include "ingredient.h"
#include "recipe.h"
#include <assert.h>
#include <iostream>

void testIngredientWithDefaultConstructor() {
    Ingredient ingredient;
    assert(Ingredient::default_name == ingredient.get_name());
    assert(Ingredient::default_unit == ingredient.get_unit());
    assert(Ingredient::default_operation == ingredient.get_operation());
    assert(Ingredient::default_time == ingredient.get_time());
    assert(Ingredient::default_quantity == ingredient.get_quantity());
}

void testIngredientWithInitConstructor() {
    Ingredient ingredient("papaya", "kg", "crush", 10, 777);
    assert("papaya" == ingredient.get_name());
    assert("kg" == ingredient.get_unit());
    assert("crush" == ingredient.get_operation());
    assert(10 == ingredient.get_time());
    assert(777 == ingredient.get_quantity());
}

void testIngredientWithCopyConstructor() {
    Ingredient ingredient1("papaya", "kg", "crush", 10, 777);
    Ingredient ingredient2(ingredient1);
    assert("papaya" == ingredient2.get_name());
    assert("kg" == ingredient2.get_unit());
    assert("crush" == ingredient2.get_operation());
    assert(10 == ingredient2.get_time());
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

void testIngredientSetOperation() {
    Ingredient ingredient;
    ingredient.set_operation("cut");
    assert("cut" == ingredient.get_operation());
}

void testIngredientSetTime() {
    Ingredient ingredient;
    ingredient.set_time(10);
    assert(10 == ingredient.get_time());
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
    testIngredientSetOperation();
    testIngredientSetTime();
    testIngredientSetQuantity();
    std::cout << "All tests are passed" << std::endl;
}
