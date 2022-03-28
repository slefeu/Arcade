#pragma once

#include "Error.hpp"

class Arcade {
    public:
        Arcade(int ac, char **av);
        ~Arcade() = default noexcept;

        void launchGame();

    private:
    	void usage() noexcept;
        std::vector<std::unique_ptr<arcade::AGame>> getGames();
        std::vector<std::unique_ptr<arcade::AWindow>> getLibraries();
        std::vector<std::unique_ptr<arcade::AWindow>> allLibraries;
        std::vector<std::unique_ptr<arcade::AGame>> allGames;
};