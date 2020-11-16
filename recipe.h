#ifndef RECIPE_H
#define RECIPE_H
#include "ingredient.h"

class Recipe {
private:
    int size = 0;
    struct Queue
    {
        Ingredient unit;
        Queue *next;
        Queue *prev;
    };
    Queue *first=NULL;

public:
    Recipe();
    Recipe(const Recipe &copy); //cp
    ~Recipe() = default; //rm

    Recipe::Queue *get_fst() const { return first; }
    Recipe::Queue *get_lst() const;
    Ingredient &get_unit(int position) const;

    void add_unit(const Ingredient &unit);
    void rm_unit(int position);
    void rm_all();
    void read_file(const std::string input);
    void save_file(const std::string output);

    int get_size() const { return size; }
};

#endif // RECIPE_H