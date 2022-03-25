/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(std::string msg) {
    this->msg = std::move(msg);
}
