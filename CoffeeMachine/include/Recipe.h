#pragma once

#include <string>
#include <vector>
#include <utility>

// Stores a recipe: drink name + list of (ingredient_name, portions)
class Recipe {
public:
    Recipe(const std::string& name,
           const std::vector<std::pair<std::string, int>>& ingredients);

    const std::string& getName() const;
    const std::vector<std::pair<std::string, int>>& getIngredients() const;

private:
    std::string name_;
    std::vector<std::pair<std::string, int>> ingredients_;
};
