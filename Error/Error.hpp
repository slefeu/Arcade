/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Error
*/

#pragma once

#include <exception>
#include <string>

class Error : public std::exception
{
public:
  explicit Error(std::string const &) noexcept;
  Error(const Error &other) noexcept = default;
  Error(Error &&other) noexcept = default;
  ~Error() noexcept = default;

  Error &operator=(const Error &) noexcept = default;
  Error &operator=(Error &&) noexcept = default;
  const char *what() const noexcept override;

protected:
private:
  std::string message_;
};