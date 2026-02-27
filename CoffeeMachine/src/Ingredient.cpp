#include "Ingredient.h"

// --- Ingredient base ---

Ingredient::Ingredient(const std::string& name, int portions, double temperature)
    : name_(name), portions_(portions), temperature_(temperature) {}

const std::string& Ingredient::getName() const { return name_; }
int Ingredient::getPortions() const { return portions_; }
double Ingredient::getTemperature() const { return temperature_; }
void Ingredient::setTemperature(double temp) { temperature_ = temp; }

// --- WetIngredient ---

WetIngredient::WetIngredient(const std::string& name, int portions, double targetTemp)
    : Ingredient(name, portions), targetTemperature_(targetTemp) {}

std::string WetIngredient::getType() const { return "wet"; }

double WetIngredient::getTargetTemperature() const { return targetTemperature_; }

int WetIngredient::getHeatingTime() const {
    double diff = targetTemperature_ - temperature_;
    return (diff > 0) ? static_cast<int>(diff) : 0;
}

// --- DryIngredient ---

DryIngredient::DryIngredient(const std::string& name, int portions, int dissolveTimeSec)
    : Ingredient(name, portions), dissolveTimeSec_(dissolveTimeSec) {}

std::string DryIngredient::getType() const { return "dry"; }

int DryIngredient::getDissolveTime() const { return dissolveTimeSec_; }

// --- CoffeeBean ---

CoffeeBean::CoffeeBean(int portions)
    : Ingredient("кофе", portions), grindTimeSec_(17), brewTimeSec_(22) {}

std::string CoffeeBean::getType() const { return "coffee"; }

int CoffeeBean::getGrindTime() const { return grindTimeSec_; }

int CoffeeBean::getBrewTime() const { return brewTimeSec_; }
