#include "RecipeLoader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

RecipeLoader::RecipeLoader(const std::string& filePath)
    : filePath_(filePath) {}

std::string RecipeLoader::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    size_t end = str.find_last_not_of(" \t\r\n");
    return str.substr(start, end - start + 1);
}

std::vector<Recipe> RecipeLoader::load() const {
    std::ifstream file(filePath_);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл рецептов: " + filePath_);
    }

    std::vector<Recipe> recipes;
    std::string line;

    while (std::getline(file, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;

        // Format: "Drink Name: ingredient1:portions, ingredient2:portions"
        size_t colonPos = line.find(':');
        if (colonPos == std::string::npos) continue;

        std::string drinkName = trim(line.substr(0, colonPos));
        std::string ingredientsPart = line.substr(colonPos + 1);

        std::vector<std::pair<std::string, int>> ingredients;
        std::istringstream iss(ingredientsPart);
        std::string token;

        while (std::getline(iss, token, ',')) {
            token = trim(token);
            if (token.empty()) continue;

            size_t lastColon = token.rfind(':');
            if (lastColon == std::string::npos) continue;

            std::string ingredientName = trim(token.substr(0, lastColon));
            int portions = std::stoi(trim(token.substr(lastColon + 1)));

            ingredients.emplace_back(ingredientName, portions);
        }

        if (!ingredients.empty()) {
            recipes.emplace_back(drinkName, ingredients);
        }
    }

    return recipes;
}
