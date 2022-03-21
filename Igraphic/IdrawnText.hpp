/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** IdrawnText
*/

#ifndef IDRAWNTEXT_HPP_
#define IDRAWNTEXT_HPP_

#include "State.hpp"

namespace arcade {
    class IdrawnText {
        public:
            IdrawnText();
            virtual ~IdrawnText();
            virtual void drawText(const vec2int &pos, const std::string &txt,
                                  const color_uint8 &color,
                                  const color_uint8 back_color = {0, 0, 0}) = 0;

        protected:
        private:
    };
}

#endif /* !IDRAWNTEXT_HPP_ */
