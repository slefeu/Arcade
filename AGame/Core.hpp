/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** core
*/

#pragma once

namespace arcade {
class Core
{
public:
    Core() noexcept = default;
    Core(const Core &other) noexcept = default;
    Core(Core &&other) noexcept = default;
    ~Core() noexcept = default;

    Core &operator=(const Core &rhs) noexcept = default;
    Core &operator=(Core &&rhs) noexcept = default;
    void executeLoop();

protected:
private:
};
} //namespace arcade