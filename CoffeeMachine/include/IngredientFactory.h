#pragma once

#include "Ingredient.h"
#include <memory>
#include <string>

// Factory for creating ingredient objects by name
class IngredientFactory {
public:
    static std::unique_ptr<Ingredient> create(const std::string& name, int portions);
};
