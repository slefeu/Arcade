#pragma once

#include <memory>
#include <vector>

#include "Core.hpp"
#include "Error.hpp"
#include "Loader.hpp"
namespace arcade
{
class Arcade
{
  public:
    Arcade(int ac, char** av);
    ~Arcade() = default;

    void launchGame();

  protected:
  private:
    // methods
    static void usage() noexcept;
    static std::vector<std::string> setGames(std::vector<std::string>& allFiles);
    static std::vector<std::string> setLibraries(std::vector<std::string>& allFiles);
    static bool isLibFile(const std::string&) noexcept;
    static std::vector<std::string> getLibFiles();
    static bool isGraphicLibrary(const std::string&) noexcept;
    static bool isGameLibrary(const std::string&) noexcept;
    static std::string getFirstLibName(const std::string&);

    // attributes
    std::unique_ptr<Core> arcadeCore;
};
} // namespace arcade