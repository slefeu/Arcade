/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

namespace arcade
{
extern "C" std::unique_ptr<IGame> createGame()
{
    return (std::make_unique<Nibbler>());
}

void Nibbler::start(IWindow& window)
{
    try {
        parseList();
    } catch (Error const& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }
    initDefault();
    window.setSize({WindowX, WindowY + 3});
    window.setFramerate(30);
}

void Nibbler::restart() noexcept
{
    body = {};
    obstacleList = {};
    appleList = {};
    hasMoved = false;
    isDead = false;
    isFinish = false;
    hasWin = false;
    score = 0;
    tick = 0;
    direction = NbRight;
}

Status Nibbler::getStatus()
{
    if (isFinish) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        return Exit;
    }
    if (isDead || hasWin) {
        isFinish = true;
        return Nothing;
    }
    return Nothing;
}

void Nibbler::displayEndText(IWindow& window) const noexcept
{
    Text endText;
    endText.setPosition({(WindowX / 2) - 2, WindowY / 2});
    if (isDead) {
        endText.setString("You Lose !");
        endText.setColor({1, 1, 255});
    }
    if (hasWin) {
        endText.setString("Victory !");
        endText.setColor({1, 255, 1});
    }
    endText.setBackColor({0, 0, 0});
    window.draw(endText);
}

void Nibbler::displayStat(IWindow& window) noexcept
{
    Text scoreText;
    Text waveText;
    Line border;
    border.setPosition({0, WindowY});
    border.setLineEnd({WindowX, WindowY});
    border.setColor({1, 30, 255});
    scoreText.setPosition({5, WindowY + 2});
    waveText.setPosition({5, WindowY + 1});
    scoreText.setString("Score: " + std::to_string(score));
    waveText.setString("Size: " + std::to_string(body.size()));
    window.draw(border);
    window.draw(scoreText);
    window.draw(waveText);
}

void Nibbler::initBody(vec2int pos) noexcept
{
    body.push_back(pos);
    body.push_back({pos.x - 1, pos.y});
    body.push_back({pos.x - 2, pos.y});
    body.push_back({pos.x - 3, pos.y});
}

void Nibbler::initDefault() noexcept
{
    if (body.empty())
        initBody({WindowX / 2, WindowY / 2});
    if (obstacleList.empty()) {
        for (int y = 0; y < WindowY; y++) {
            for (int x = 0; x < WindowX; x++) {
                if (y == 0 || y == WindowY - 1) {
                    obstacleList.push_back({x, y});
                    continue;
                }
                if (x == 0 || x == WindowX - 1) {
                    obstacleList.push_back({x, y});
                    continue;
                }
            }
        }
    }
    if (appleList.empty())
        respawnApple(8);
}

void Nibbler::parseList()
{
    srand(time(nullptr));
    std::vector<std::string> listNameMap = listMap();
    int choice = (rand() % static_cast<int>(listNameMap.size()));
    std::string path = "Games/Nibbler/map/" + listNameMap.at(choice);
    std::ifstream file(path.c_str());
    int y = 0;

    if (file) {
        for (std::string line; getline(file, line);) {
            for (int x = 0; x < line.size() && x < WindowX; x++) {
                if (line.at(x) == 'w')
                    obstacleList.push_back({x, y});
                if (line.at(x) == 'a')
                    appleList.push_back({x, y});
                if (line.at(x) == 's')
                    initBody({x, y});
            }
            y++;
        }
    } else
        throw(Error("Map file could not be opened correctly"));
}

std::vector<std::string> Nibbler::listMap()
{
    const std::string path = "Games/Nibbler/map";
    std::vector<std::string> allFiles = {};
    DIR* dir = opendir(path.c_str());
    struct dirent* ent = nullptr;

    if (dir != nullptr) {
        while ((ent = readdir(dir)) != nullptr) {
            std::string file = ent->d_name;
            if (!(file.compare("..") == 0) && !(file.compare(".") == 0))
                allFiles.push_back(file);
        }
        closedir(dir);
    } else
        throw(ArgumentError("Could not open the folder Nibbler/map"));
    return (allFiles);
}

int Nibbler::getScore() const noexcept
{
    return (score);
}

vec2int Nibbler::getSize() const noexcept
{
    return (vec2int{WindowX, WindowY + 3});
}

void Nibbler::exec(IWindow& window, Events& event) noexcept
{
    this->event = event;
    if (tick == 0)
        start(window);
    displayObstacle(window);
    displayApple(window);
    updatePlayer(window);
    displayStat(window);
    displayEndText(window);
    window.setFramerate(30 + static_cast<int>(body.size()));
    tick++;
}

void Nibbler::updatePlayer(IWindow& window) noexcept
{
    changeDirection();
    movePlayer();
    if (isPlayerHit())
        isDead = true;
    if (tick % 10 == 0)
        hasMoved = false;
    tryEat();
    displayPlayer(window);
}

bool Nibbler::isPlayerHit() const noexcept
{
    for (int i = 1; i < body.size(); i++) {
        if (body.at(i).x == body.at(0).x && body.at(i).y == body.at(0).y)
            return true;
    }
    return false;
}

std::vector<vec2int> Nibbler::getValidPos() noexcept
{
    bool isValid = true;
    std::vector<vec2int> validList = {};
    for (int y = 0; y < WindowY; y++) {
        for (int x = 0; x < WindowX; x++) {
            isValid = true;
            if (didCollideWall({x, y}))
                isValid = false;
            for (vec2int fragment : body) {
                if (fragment.x == x && fragment.y == y)
                    isValid = false;
            }
            if (isValid)
                validList.push_back({x, y});
        }
    }
    return validList;
}

void Nibbler::respawnApple(int nbApple) noexcept
{
    std::vector<vec2int> validPos = getValidPos();
    if (validPos.empty())
        hasWin = true;
    int validSize = validPos.size();
    for (int i = 0; i < nbApple && validSize > 0; i++) {
        int pos = rand() % validSize;
        appleList.push_back(validPos.at(pos));
        validPos.erase(validPos.begin() + pos);
        validSize--;
    }
}

void Nibbler::tryEat() noexcept
{
    int appleSize = appleList.size();
    for (int i = 0; i < appleSize; i++) {
        if (appleList.at(i).x == body.at(0).x
            && appleList.at(i).y == body.at(0).y) {
            body.push_back(
                {body.at(body.size() - 1).x, body.at(body.size() - 1).y});
            appleList.erase(appleList.begin() + i);
            score = score + 20;
            respawnApple(1);
            return;
        }
    }
    if (appleList.empty())
        respawnApple(1);
}

bool Nibbler::didCollideWall(const vec2int& loc) noexcept
{
    for (vec2int obstacle : obstacleList) {
        if (obstacle.x != loc.x)
            continue;
        if (obstacle.y == loc.y) {
            return true;
        }
    }
    return false;
}

void Nibbler::changeDirection()
{
    if (event.isPressed(Up) && direction != NbDown) {
        if (!didCollideWall({body.at(0).x, body.at(0).y - 1}))
            direction = NbUp;
        return;
    }
    if (event.isPressed(Down) && direction != NbUp) {
        if (!didCollideWall({body.at(0).x, body.at(0).y + 1}))
            direction = NbDown;
        return;
    }
    if (event.isPressed(Right) && direction != NbLeft) {
        if (!didCollideWall({body.at(0).x + 1, body.at(0).y}))
            direction = NbRight;
        return;
    }
    if (event.isPressed(Left) && direction != NbRight) {
        if (!didCollideWall({body.at(0).x - 1, body.at(0).y}))
            direction = NbLeft;
        return;
    }
}

void Nibbler::movePlayer() noexcept
{
    if (hasMoved)
        return;
    if (direction == NbUp) {
        if (body.at(0).y - 1 < 0)
            isDead = true;
        if (body.at(0).y - 1 >= 0
            && !didCollideWall({body.at(0).x, body.at(0).y - 1})) {
            body.emplace(body.begin(), vec2int{body.at(0).x, body.at(0).y - 1});
            body.pop_back();
            hasMoved = true;
            return;
        }
    }
    if (direction == NbDown) {
        if (body.at(0).y + 1 >= WindowY)
            isDead = true;
        if (body.at(0).y + 1 < WindowY
            && !didCollideWall({body.at(0).x, body.at(0).y + 1})) {
            body.emplace(body.begin(), vec2int{body.at(0).x, body.at(0).y + 1});
            body.pop_back();
            hasMoved = true;
            return;
        }
    }
    if (direction == NbLeft) {
        if (body.at(0).x - 1 < 0)
            isDead = true;
        if (body.at(0).x - 1 >= 0
            && !didCollideWall({body.at(0).x - 1, body.at(0).y})) {
            body.emplace(body.begin(), vec2int{body.at(0).x - 1, body.at(0).y});
            body.pop_back();
            hasMoved = true;
            return;
        }
    }
    if (direction == NbRight) {
        if (body.at(0).x + 1 >= WindowX)
            isDead = true;
        if (body.at(0).x + 1 < WindowX
            && !didCollideWall({body.at(0).x + 1, body.at(0).y})) {
            body.emplace(body.begin(), vec2int{body.at(0).x + 1, body.at(0).y});
            body.pop_back();
            hasMoved = true;
            return;
        }
    }
}

void Nibbler::displayObstacle(IWindow& window) noexcept
{
    for (vec2int obs : obstacleList) {
        Point point;
        point.setPosition(obs);
        point.setColor({0, 200, 200});
        window.draw(point);
    }
}

void Nibbler::displayPlayer(IWindow& window) noexcept
{
    Point bodyFragment;
    for (int i = 0; i < body.size(); i++) {
        bodyFragment.setPosition(body.at(i));
        if (i == 1)
            bodyFragment.setColor({150, 250, 10});
        window.draw(bodyFragment);
    }
    bodyFragment.setColor({200, 200, 20});
    bodyFragment.setPosition(body.at(0));
    window.draw(bodyFragment);
}

void Nibbler::displayApple(IWindow& window) noexcept
{
    for (vec2int apple : appleList) {
        Point point;
        point.setPosition(apple);
        point.setColor({255, 0, 0});
        window.draw(point);
    }
}
}
