#include "pokemonHandler.hpp"

int main()
{
    Pokemon arr[6] = {Pokemon("Pokemon1", Type::FIRE, 200), Pokemon("Pokemon2", Type::ELECTRIC, 150),
                      Pokemon("Pokemon3", Type::WATER, 200), Pokemon("Pokemon4", Type::FLYING, 210),
                      Pokemon("Pokemon5", Type::GHOST, 180), Pokemon("Pokemon6", Type::GRASS, 120)};

    PokemonHandler ph("pokemon.bin", arr, 6);

    std::cout << ph[0] << ph[1] << ph[2] << ph[3]<< ph[4] << ph[5] << ph[6];
    std::cout << "\nBest pokemon -> " << ph.getBestPokemon();
    return 0;
}
