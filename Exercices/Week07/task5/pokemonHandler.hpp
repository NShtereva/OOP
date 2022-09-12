#ifndef __POKEMONHANDLER__HPP
#define __POKEMONHANDLER__HPP

#include "pokemon.hpp"

#include <iostream>

const unsigned MAX_FILENAME_LEN = 255;

class PokemonHandler
{
    private:
        char fileName[MAX_FILENAME_LEN];
        std::size_t size;

    public:
        PokemonHandler(const char* fileName, Pokemon* pokemons, std::size_t size);

        const Pokemon operator [] (int i) const;
        const Pokemon getBestPokemon() const;
};

#endif
