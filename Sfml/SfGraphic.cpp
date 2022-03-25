/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** SfGraphic
*/

#include "SfGraphic.hpp"

namespace arcade {
SfGraphic::SfGraphic() {
    this->window = std::make_unique<SfWindow>();
}

SfGraphic::~SfGraphic() {
}
} // namespace arcade