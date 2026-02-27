cmake_minimum_required(VERSION 3.14)
project(CoffeeMachine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CoffeeMachine
    src/main.cpp
    src/Ingredient.cpp
    src/IngredientFactory.cpp
    src/MachinePart.cpp
    src/Recipe.cpp
    src/RecipeLoader.cpp
    src/CoffeeMachine.cpp
)

target_include_directories(CoffeeMachine PRIVATE include)
