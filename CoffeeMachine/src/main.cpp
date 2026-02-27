#include "CoffeeMachine.h"
#include "RecipeLoader.h"

#include <iostream>

int main() {
    RecipeLoader loader("data/recipes.txt");
    auto recipes = loader.load();

    CoffeeMachine machine;

    for (const auto& recipe : recipes) {
        auto result = machine.prepare(recipe);
        std::cout << result.name << std::endl;
        std::cout << result.totalTimeSec << " секунд" << std::endl;
        std::cout << "---" << std::endl;
    }

    return 0;
}
