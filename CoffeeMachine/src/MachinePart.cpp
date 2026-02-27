#include "MachinePart.h"

// --- Grinder ---

std::string Grinder::getName() const { return "Кофемолка"; }

bool Grinder::canProcess(const Ingredient& ingredient) const {
    return ingredient.getType() == "coffee";
}

int Grinder::process(Ingredient& ingredient) const {
    auto* coffee = dynamic_cast<CoffeeBean*>(&ingredient);
    if (!coffee) return 0;
    return coffee->getGrindTime() * coffee->getPortions();
}

// --- BrewingGroup ---

std::string BrewingGroup::getName() const { return "Группа заваривания"; }

bool BrewingGroup::canProcess(const Ingredient& ingredient) const {
    return ingredient.getType() == "coffee";
}

int BrewingGroup::process(Ingredient& ingredient) const {
    auto* coffee = dynamic_cast<CoffeeBean*>(&ingredient);
    if (!coffee) return 0;
    return coffee->getBrewTime() * coffee->getPortions();
}

// --- Boiler ---

std::string Boiler::getName() const { return "Бойлер"; }

bool Boiler::canProcess(const Ingredient& ingredient) const {
    if (ingredient.getType() != "wet") return false;
    auto* wet = dynamic_cast<const WetIngredient*>(&ingredient);
    return wet && wet->getTargetTemperature() >= 100.0;
}

int Boiler::process(Ingredient& ingredient) const {
    auto* wet = dynamic_cast<WetIngredient*>(&ingredient);
    if (!wet) return 0;
    int time = wet->getHeatingTime() * wet->getPortions();
    wet->setTemperature(wet->getTargetTemperature());
    return time;
}

// --- SteamNozzle ---

std::string SteamNozzle::getName() const { return "Форсунка"; }

bool SteamNozzle::canProcess(const Ingredient& ingredient) const {
    if (ingredient.getType() == "dry") return true;
    if (ingredient.getType() == "wet") {
        auto* wet = dynamic_cast<const WetIngredient*>(&ingredient);
        return wet && wet->getTargetTemperature() < 100.0
                   && wet->getTargetTemperature() > wet->getTemperature();
    }
    return false;
}

int SteamNozzle::process(Ingredient& ingredient) const {
    if (ingredient.getType() == "dry") {
        auto* dry = dynamic_cast<DryIngredient*>(&ingredient);
        if (!dry) return 0;
        return dry->getDissolveTime() * dry->getPortions();
    }
    auto* wet = dynamic_cast<WetIngredient*>(&ingredient);
    if (!wet) return 0;
    int time = wet->getHeatingTime() * wet->getPortions();
    wet->setTemperature(wet->getTargetTemperature());
    return time;
}
