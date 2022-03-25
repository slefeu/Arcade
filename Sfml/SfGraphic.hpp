/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** SfGraphic
*/

#ifndef SFGRAPHIC_HPP_
#define SFGRAPHIC_HPP_

#include "Agraphic.hpp"

namespace arcade {
class SfGraphic : public Agraphic {
  public:
    SfGraphic();
    ~SfGraphic();
    virtual bool status(void) override;
    virtual void changeInfos(std::string name, vec2int size) override;

  protected:
  private:
};
}; // namespace arcade

#endif /* !SFGRAPHIC_HPP_ */
