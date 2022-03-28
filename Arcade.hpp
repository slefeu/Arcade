#pragma once

#include "Error.hpp"
#include "Core.hpp"

namespace arcade {
class Arcade {
    public:
        Arcade(int ac, char **av);
        ~Arcade() = default noexcept;

        void launchGame();

    private:
        //methods
    	void usage() noexcept;
        std::vector<std::unique_ptr<AGame>> getGames();
        std::vector<std::unique_ptr<AWindow>> getLibraries();
        //atributes
        std::vector<std::unique_ptr<AWindow>> allLibraries;
        std::vector<std::unique_ptr<AGame>> allGames;
        std::unique_ptr<Core> arcadeCore;
};
} //namespace arcade