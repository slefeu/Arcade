#pragma once

#include "AWindow.hpp"
#include "Core.hpp"
#include <memory>

namespace arcade {
    class AGame {
        public:
            AGame() = default;
            ~AGame() = default;
            AGame(AGame &&) = delete;
            AGame(const AGame &) = delete;

            AGame &operator=(AGame &&) = delete;
            AGame &operator=(const AGame &) = delete;
            virtual void exec() = 0;
            virtual bool status() = 0;
            void setWindow(std::unique_ptr<AWindow> &&win);

        protected:
            std::unique_ptr<AWindow> window = nullptr;
        private:
    };
}