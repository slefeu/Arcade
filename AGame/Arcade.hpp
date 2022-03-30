#pragma once

#include <memory>
#include <vector>

#include "AGame.hpp"
#include "Error.hpp"
#include "Loader.hpp"
namespace arcade
{
class Arcade
{
  public:
    Arcade(int ac, char** av);
    ~Arcade();

    void launchGame();

  protected:
  private:
    // methods
    void usage() noexcept;
    std::vector<std::string> setGames(std::vector<std::string>& allFiles);
    std::vector<std::string> setLibraries(std::vector<std::string>& allFiles);
    bool isLibFile(const std::string&) noexcept;
    std::vector<std::string> getLibFiles();
    bool isGraphicLibrary(std::string&) noexcept;
    bool isGameLibrary(std::string&) noexcept;
    std::string getFirstLibName(const std::string&) noexcept;

    // attributes
    std::unique_ptr<Core> arcadeCore;
    std::vector<std::string> allLibs;
    std::vector<std::string> allGames;
    Loader libLoader;
};
} // namespace arcade