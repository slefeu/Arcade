/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Agraphic
*/

#include "Awindow.hpp"

namespace arcade {
    class Agraphic {
        public:
            Agraphic() = default;
            virtual ~Agraphic();

            Agraphic(Agraphic &&) = delete;
            Agraphic(const Agraphic &) = delete;
            Agraphic &operator=(Agraphic &&) = delete;
            Agraphic &operator=(const Agraphic &) = delete;

            virtual bool status(void) = 0;
            virtual void changeInfos(std::string name, vec2int size) = 0;
            std::unique_ptr<Awindow> getWindow() const;
        
        protected:
            std::unique_ptr<Awindow> window;
    };
} // namespace arcade