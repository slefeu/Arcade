/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <dirent.h>

#include <fstream>
#include <iostream>
#include <sstream>

#include "Error.hpp"
#include "IGame.hpp"

namespace arcade {
class Nibbler : public IGame {
    public:
      Nibbler() noexcept = default;
      Nibbler(const Nibbler& other) noexcept = default;
      Nibbler(Nibbler&& other) noexcept = default;
      virtual ~Nibbler() noexcept = default;

      Nibbler& operator=(const Nibbler& rhs) noexcept = default;
      Nibbler& operator=(Nibbler&& rhs) noexcept = default;

      void exec(IWindow&, Events& event) noexcept final;
      void restart() noexcept final;
      Status getStatus();
      int getScore() const noexcept final;

    protected:
    private:
        void start() noexcept;
        std::vector<std::string> listMap();
        std::vector<vec2int> body = {};
        std::vector<vec2int> obstacleList = {};
        int score = 0;
        int tick = 0;
};
}

#endif /* !NIBBLER_HPP_ */
