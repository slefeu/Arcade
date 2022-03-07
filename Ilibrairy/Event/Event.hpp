/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <utility>
#include <string>
#include <iostream>

enum EventType {
    Key,
    MouseClick,
    MouseMove,
    Undefined
};

class Event {
    public:
        Event() = default;
        ~Event() = default;
        void setType(EventType type);
        void setLocation(std::pair<double, double> location);
        void setKey(char key);
        EventType getType() const;
        std::pair <double, double> getLocation() const;
        char getKey() const;

    protected:
    private:
        EventType type_ = Undefined;
        std::pair <double, double> location_ = std::make_pair(-1, -1);
        char key = -1;
};

#endif /* !EVENT_HPP_ */
