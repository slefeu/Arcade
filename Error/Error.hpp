/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Error
*/

#pragma once

#include <exception>
#include <string>

class Errors : public std::exception
{
public:
    explicit Errors(std::string const &message);
    const char *what() const noexcept override;

private:
    std::string message_;
};