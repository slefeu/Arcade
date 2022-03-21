/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Awindow
*/

#ifndef IWINDOW_HPP_
#define IWINDOW_HPP_

#include "State.hpp"
#include "IdrawnText.hpp"
#include "IdrawnShape.hpp"
#include "Isprite.hpp"
#include "Isound.hpp"
#include <memory>

namespace arcade {
    class Awindow {
        public:
            Awindow();
            virtual ~Awindow();
            virtual void display(void) = 0;
            virtual void clear(void) = 0;
            virtual Events pollEvent(void) = 0;
            std::unique_ptr<IdrawnText> getText(void) const;
            std::unique_ptr<IdrawnShape> getShape(void) const;
            std::unique_ptr<Isprite> getSprite(void) const;
            std::unique_ptr<Isound> getSound(void) const;

          protected:
            std::unique_ptr<IdrawnText> text_;
            std::unique_ptr<IdrawnShape> shape_;
            std::unique_ptr<Isprite> sprite_;
            std::unique_ptr<Isound> sound_;
        private:
    };
} // namespace arcade

#endif /* !IWINDOW_HPP_ */
