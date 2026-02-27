#pragma once

#include "Ingredient.h"
#include <memory>
#include <string>

// Abstract base class for coffee machine parts
class IMachinePart {
public:
    virtual ~IMachinePart() = default;

    virtual std::string getName() const = 0;
    virtual bool canProcess(const Ingredient& ingredient) const = 0;
    virtual int process(Ingredient& ingredient) const = 0;
};

// Grinds coffee beans (14-19 seconds)
class Grinder : public IMachinePart {
public:
    std::string getName() const override;
    bool canProcess(const Ingredient& ingredient) const override;
    int process(Ingredient& ingredient) const override;
};

// Brews ground coffee (19-24 seconds)
class BrewingGroup : public IMachinePart {
public:
    std::string getName() const override;
    bool canProcess(const Ingredient& ingredient) const override;
    int process(Ingredient& ingredient) const override;
};

// Heats water to 100 degrees
class Boiler : public IMachinePart {
public:
    std::string getName() const override;
    bool canProcess(const Ingredient& ingredient) const override;
    int process(Ingredient& ingredient) const override;
};

// Heats milk/cream to 65-70 degrees, dissolves dry ingredients
class SteamNozzle : public IMachinePart {
public:
    std::string getName() const override;
    bool canProcess(const Ingredient& ingredient) const override;
    int process(Ingredient& ingredient) const override;
};
