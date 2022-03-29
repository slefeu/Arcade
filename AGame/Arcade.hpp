#pragma once

#include "AGame.hpp"
#include "Error.hpp"

#include <vector>
#include <memory>

namespace arcade {
class Arcade {
    public:
        Arcade(int ac, char **av);
        ~Arcade();

        void launchGame();
        std::vector<std::string> getLibFiles();

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