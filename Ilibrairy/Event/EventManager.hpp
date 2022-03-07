/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** EventManager
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

#include <vector>
#include "Event.hpp"

class EventManager {
    public:
        EventManager();
        ~EventManager();
        void addEvent(Event event);
        void clearList();
        std::vector<Event> getEventList() const;

    protected:
    private:
        std::vector<Event> eventList_ = {};
};

#endif /* !EVENTMANAGER_HPP_ */
