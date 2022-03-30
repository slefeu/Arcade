/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(std::string const& message) noexcept
  : message_(message){};

const char* Error::what() const noexcept
{
    return (message_.c_str());
}

ArgumentError::ArgumentError(std::string const& message)
  : Error(message){};