/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Error
*/

#include "Error.hpp"

Errors::Errors(std::string const &message) : message_(message){};

const char *Errors::what() const noexcept
{
    return (message_.c_str());
}