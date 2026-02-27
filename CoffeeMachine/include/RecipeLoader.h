#pragma once

#include "Recipe.h"
#include <string>
#include <vector>

// Loads recipes from a text file
class RecipeLoader {
public:
    explicit RecipeLoader(const std::string& filePath);

    std::vector<Recipe> load() const;

private:
    std::string filePath_;

    static std::string trim(const std::string& str);
};
