/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** main
*/

#include "Arcade.hpp"

int main(int ac, char **av)
{
    try {
        arcade::Arcade arcade(ac, av);
        arcade.getDirectoryFiles();
    } catch (Error) {
        return (84);
    }
    return (0);
}