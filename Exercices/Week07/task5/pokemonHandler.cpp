#include "pokemonHandler.hpp"

#include <fstream>
#include <cstring>
#include <cassert>

PokemonHandler::PokemonHandler(const char* fileName, Pokemon* pokemons, std::size_t size)
    : size(size)
{
    assert(fileName && strlen(fileName) < MAX_FILENAME_LEN);
    strcpy(this->fileName, fileName);

    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(pokemons[i] < pokemons[j])
            {
                Pokemon temp = pokemons[i];
                pokemons[i] = pokemons[j];
                pokemons[j] = temp;
            }
        }
    }

    std::ofstream file(fileName, std::ios::binary);
    if(!file)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return;
    }

    for(int i = 0; i < size; i++)
    {
        file.write(reinterpret_cast<char*>(&pokemons[i]), sizeof(Pokemon));
    }

    file.close();
}

const Pokemon PokemonHandler::operator [] (int i) const
{
    if(!(i >= 0 && i < this->size))
    {
        std::cout << "Incorrect index!" << std::endl;
        return Pokemon();
    }

    std::ifstream file(fileName, std::ios::binary);
    if(!file)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return Pokemon();
    }

    Pokemon temp;

    file.seekg(i * sizeof(Pokemon), std::ios::beg);
    file.read(reinterpret_cast<char*>(&temp), sizeof(Pokemon));
    file.close();

    return temp;
}

const Pokemon PokemonHandler::getBestPokemon() const
{
    return (*this)[0];
}
