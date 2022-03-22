/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** ASound
*/

#ifndef ASOUND_HPP_
#define ASOUND_HPP_

#include "State.hpp"

namespace arcade {
class ASound {
  public:
    ASound();
    virtual ~ASound();

  protected:
    std::string path_ = "";
    int volume_       = 0;

  private:
};
} // namespace arcade

#endif /* !ASOUND_HPP_ */
