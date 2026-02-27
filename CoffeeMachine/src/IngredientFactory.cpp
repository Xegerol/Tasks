#include "IngredientFactory.h"

std::unique_ptr<Ingredient> IngredientFactory::create(const std::string& name, int portions) {
    if (name == "кофе") {
        return std::make_unique<CoffeeBean>(portions);
    }
    if (name == "вода") {
        return std::make_unique<WetIngredient>("вода", portions, 100.0);
    }
    if (name == "молоко") {
        return std::make_unique<WetIngredient>("молоко", portions, 68.0);
    }
    if (name == "сливки") {
        return std::make_unique<WetIngredient>("сливки", portions, 68.0);
    }
    if (name == "сироп") {
        return std::make_unique<WetIngredient>("сироп", portions, 24.0);
    }
    if (name == "бренди") {
        return std::make_unique<WetIngredient>("бренди", portions, 24.0);
    }
    if (name == "сахар") {
        return std::make_unique<DryIngredient>("сахар", portions, 5);
    }
    if (name == "ванильный сахар") {
        return std::make_unique<DryIngredient>("ванильный сахар", portions, 5);
    }
    if (name == "корица") {
        return std::make_unique<DryIngredient>("корица", portions, 3);
    }

    // Unknown ingredient defaults to dry with no dissolve time
    return std::make_unique<DryIngredient>(name, portions, 0);
}
