#pragma once

#include "MachinePart.h"
#include "Recipe.h"
#include <memory>
#include <string>
#include <vector>

// Result of preparing a drink
struct DrinkResult {
    std::string name;
    int totalTimeSec;
};

// Orchestrates coffee machine parts to prepare drinks from recipes
class CoffeeMachine {
public:
    CoffeeMachine();

    DrinkResult prepare(const Recipe& recipe) const;

private:
    std::vector<std::unique_ptr<IMachinePart>> parts_;

    int processIngredient(Ingredient& ingredient) const;
};
