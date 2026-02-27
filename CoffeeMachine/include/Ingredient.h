#pragma once

#include <string>

// Base abstract class for all ingredients
class Ingredient {
public:
    Ingredient(const std::string& name, int portions, double temperature = 24.0);
    virtual ~Ingredient() = default;

    const std::string& getName() const;
    int getPortions() const;
    double getTemperature() const;
    void setTemperature(double temp);

    virtual std::string getType() const = 0;

protected:
    std::string name_;
    int portions_;
    double temperature_;
};

// Wet ingredients: water, milk, cream, syrup, etc.
// Some require heating to a target temperature
class WetIngredient : public Ingredient {
public:
    WetIngredient(const std::string& name, int portions, double targetTemp);

    std::string getType() const override;
    double getTargetTemperature() const;
    int getHeatingTime() const;

private:
    double targetTemperature_;
};

// Dry ingredients: sugar, cinnamon, etc.
// Some require time to dissolve or mix
class DryIngredient : public Ingredient {
public:
    DryIngredient(const std::string& name, int portions, int dissolveTimeSec);

    std::string getType() const override;
    int getDissolveTime() const;

private:
    int dissolveTimeSec_;
};

// Coffee bean is a special ingredient: ground first, then brewed
class CoffeeBean : public Ingredient {
public:
    CoffeeBean(int portions);

    std::string getType() const override;
    int getGrindTime() const;
    int getBrewTime() const;

private:
    int grindTimeSec_;
    int brewTimeSec_;
};
