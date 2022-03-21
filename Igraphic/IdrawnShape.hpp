/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** IdrawnShape
*/

#ifndef IDRAWNSHAPE_HPP_
#define IDRAWNSHAPE_HPP_

#include "State.hpp"

namespace arcade {
    class IdrawnShape {
        public:
            IdrawnShape();
            virtual ~IdrawnShape();
            virtual void drawRectangle(const vec2int &pos, const vec2int &size,
                                       const color_uint8 &color, bool fill) = 0;
    
            virtual void drawLine(const vec2int &pos, const vec2int &size,
                                  const color_uint8 &color) = 0;
    
            virtual void drawCircle(const vec2int &pos,
                                    const unsigned int &rayon,
                                    const color_uint8 &color, bool fill) = 0;
    
            virtual void drawPoint(const vec2int &pos,
                                   const color_uint8 &color) = 0;
    
        protected:
        private:
    };
}

#endif /* !IDRAWNSHAPE_HPP_ */
