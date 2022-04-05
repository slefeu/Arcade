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
    explicit Error(std::string) noexcept;
    Error(const Error& other) noexcept = default;
    Error(Error&& other) noexcept = default;
    ~Error() noexcept override = default;

    Error& operator=(const Error&) noexcept = default;
    Error& operator=(Error&&) noexcept = default;
    const char* what() const noexcept override;

  protected:
  private:
    std::string message_;
};

class ArgumentError : public Error
{
  public:
    explicit ArgumentError(std::string) noexcept;
    ArgumentError(const ArgumentError& other) noexcept = default;
    ArgumentError(ArgumentError&& other) noexcept = default;
    ~ArgumentError() noexcept override = default;

    ArgumentError& operator=(const ArgumentError& rhs) noexcept = default;
    ArgumentError& operator=(ArgumentError&& rhs) noexcept = default;

  protected:
  private:
};