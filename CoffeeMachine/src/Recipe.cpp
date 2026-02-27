#include "Recipe.h"

Recipe::Recipe(const std::string& name,
               const std::vector<std::pair<std::string, int>>& ingredients)
    : name_(name), ingredients_(ingredients) {}

const std::string& Recipe::getName() const { return name_; }

const std::vector<std::pair<std::string, int>>& Recipe::getIngredients() const {
    return ingredients_;
}
