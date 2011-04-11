#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "renderinfos.hpp"

class State
{
    public:
        State(sf::RenderWindow &app) : m_window(app){};
        virtual ~State(){};

        virtual void init(void) = 0;
        virtual void destroy(void) = 0;

        virtual void update(float elapsedTime) = 0;
        virtual void display(const RenderInfos &renderinfos) const = 0;

    protected:
        sf::RenderWindow &m_window;
};

#endif // STATE_HPP_INCLUDED
