/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <iostream>
#include <utility>

class Error : public std::exception {
  public:
    Error(std::string msg);
    Error()  = default;
    ~Error() = default;
    const char* what() const noexcept {
        return msg.c_str();
    };

  protected:
  private:
    std::string msg;
};

#endif /* !ERROR_HPP_ */
