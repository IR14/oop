#include <iostream>
#include "recipe.h"
#include "ingredient.h"
#include <string>
#include <fstream>

Recipe::Recipe() {
    this->size = 0;
    this->first = NULL;
}

Recipe::Recipe(const Recipe &copy) {
    this->first = copy.first;
    this->size = copy.size;
}

void Recipe::add_unit(const Ingredient &unit) {
    this->size++;
    if (!first) {
        first = new Queue;
        first->next = NULL;
        first->prev = NULL;
        first->unit = unit;
    } else {
        Recipe::Queue *future;
        auto curr = first;
        while (curr->next)
            curr = curr->next;
        future = new Recipe::Queue;
        curr->next = future;
        future->prev = curr;
        future->unit = unit;
        future->next = NULL;
    }
}

void Recipe::rm_unit(int position) {
    auto curr = first;
    for (int i = 0; i < position && curr; i++, curr = curr->next);
    if (curr) {
        if (curr->prev)
            curr->prev->next = curr->next;
        else
            first = curr->next;
        if (curr->next)
            curr->next->prev = curr->prev;
        delete curr;
        this->size--;
    } else {
        std::cout << "There is no unit with such index." << std::endl;
        exit(1);
    }
}

void Recipe::rm_all() {
    this->size = 0;
    auto curr = first;
    while (curr) {
        curr = first->next;
        delete first;
        first = curr;
    }
    std::cout << "Completed." << std::endl;
}

void Recipe::read_file(const std::string input) {
    std::string line;
    int num = 0;
    Ingredient new_unit;
    std::ifstream file(input);
    if (file.is_open()) {
        while (!file.eof()) {
            file >> line;
            new_unit.set_name(line);

            file >> line;
            new_unit.set_unit(line);

            file >> line;
            new_unit.set_operation(line);

            file >> line;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] >= 0x30 && line[i] <= 0x39)
                    num = num * 10 + (line[i] - 0x30);
                else {
                    std::cout << "Input format is incorrect!" << std::endl;
                    exit(1);
                }
            }
            new_unit.set_time(num);
            num = 0;

            file >> line;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] >= 0x30 && line[i] <= 0x39)
                    num = num * 10 + (line[i] - 0x30);
                else {
                    std::cout << "Input format is incorrect!" << std::endl;
                    exit(1);
                }
            }
            new_unit.set_quantity(num);
            num = 0;

            add_unit(new_unit);
        }
        file.close();
    } else {
        std::cout << "File with such name hasn't been found!" << std::endl;
        exit(1);
    }
}

void Recipe::save_file(const std::string output) {
    std::ofstream file(output);
    auto curr = first;
    if (file.is_open()) {
        if (!curr)
            std::cout << "Empty recipe." << std::endl;
        else {
            while (curr) {
                file << curr->unit.get_name() << std::endl;
                file << curr->unit.get_unit() << std::endl;
                file << curr->unit.get_operation() << std::endl;
                file << curr->unit.get_time() << std::endl;
                file << curr->unit.get_quantity() << std::endl;
                curr = curr->next;
            }
        }
    }
    file.close();
}

Recipe::Queue *Recipe::get_lst() const {
    auto curr = first;
    while (curr->next)
        curr = curr->next;
    return curr;
}

Ingredient &Recipe::get_unit(int position) const {
    auto curr = first;
    for (int i = 0; i < position && curr; i++, curr = curr->next);
    if (curr)
        return curr->unit;
    else {
        std::cout << "There is no unit with such index." << std::endl;
        exit(1);
    }
}
