#include "CoffeeMachine.h"
#include "IngredientFactory.h"

#include <iostream>

CoffeeMachine::CoffeeMachine() {
    parts_.push_back(std::make_unique<Grinder>());
    parts_.push_back(std::make_unique<BrewingGroup>());
    parts_.push_back(std::make_unique<Boiler>());
    parts_.push_back(std::make_unique<SteamNozzle>());
}

int CoffeeMachine::processIngredient(Ingredient& ingredient) const {
    int totalTime = 0;
    for (const auto& part : parts_) {
        if (part->canProcess(ingredient)) {
            int time = part->process(ingredient);
            std::cout << "  " << part->getName() << " обработала "
                      << ingredient.getName() << ": " << time << " сек" << std::endl;
            totalTime += time;
        }
    }
    return totalTime;
}

DrinkResult CoffeeMachine::prepare(const Recipe& recipe) const {
    std::cout << "Готовим: " << recipe.getName() << std::endl;

    int totalTime = 0;

    for (const auto& [name, portions] : recipe.getIngredients()) {
        auto ingredient = IngredientFactory::create(name, portions);
        totalTime += processIngredient(*ingredient);
    }

    std::cout << std::endl;
    return {recipe.getName(), totalTime};
}
