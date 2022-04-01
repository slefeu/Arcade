/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** core
*/

#include "Core.hpp"
#include "Text.hpp"

namespace arcade
{
Core::Core(std::unique_ptr<AWindow> lib,
    std::vector<std::string>& libs,
    std::vector<std::string>& games) noexcept
    : usedLib(std::move(lib))
    , allLibs(libs)
    , allGames(games)
    , isEnd(false)
    , playerName("")
{
}

void Core::displayGame(Status& input) noexcept
{
}

bool Core::isLetter(Key& key) const noexcept
{
    if (key >= A && key <= Z)
        return (true);
    return (false);
}
void Core::changePlayerName(Events& event) noexcept
{
    for (int i = 0; i < event.key_pressed.size(); i++) {
        if (isLetter(event.key_pressed[i]) && playerName.size() < 10)
            playerName += event.key_pressed[i] + 'A';
        if (event.key_pressed[i] == Backspace && !playerName.empty())
            playerName.pop_back();
    }
}

void Core::displayMenu(Status& input) noexcept
{
    Events event;

    usedLib->draw(Text({35, 0}, ("MENU")));
    usedLib->pollEvent(event);
    if (event.getStatus() == Exit || usedLib->getStatus() == Exit) {
        isEnd = true;
        return;
    }
    changePlayerName(event);
    usedLib->draw(Text({35, 5}, "Player Name: "));
    if (playerName != "")
        usedLib->draw(Text({35, 7}, playerName));
    displayAvailableLibs();
}

void Core::displayAvailableLibs() const noexcept
{
    int position = 5;

    usedLib->draw(Text({0, position}, "Graphic libraries availables :"));
    for (int i = 0; i < allLibs.size(); i++) {
        position += 2;
        usedLib->draw(Text({0, position}, allLibs[i]));
    }
    usedLib->draw(Text({0, position + 10}, "Games availables :"));
    for (int i = 0; i < allGames.size(); i++) {
        position += 2;
        usedLib->draw(Text({42, position}, allGames[i]));
    }
}

void changeGraphicLib()
{

}

void Core::executeLoop()
{
    while (!isEnd) {
        usedLib->clear();
        Status input = usedLib->getStatus();
        if (isMenu)
            displayMenu(input);
        else
            displayGame(input);
        usedLib->display();
    }
}
} // namespace arcade