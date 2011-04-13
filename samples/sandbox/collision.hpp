#ifndef COLLLISION_HPP_INCLUDED
#define COLLLISION_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <mechanix/mechanix.hpp>
#include "state.hpp"

class Collision : public State
{
    public:
        Collision(sf::RenderWindow &app);
        virtual ~Collision();

        virtual void init(void);
        virtual void destroy(void);

        virtual void update(float elapsedTime);
        virtual void display(const RenderInfos &renderinfos) const;
    private:
        mx::World m_world;

        mx::Body::Ptr b1;
        mx::Body::Ptr b2;

        sf::Shape s1;
        sf::Shape s2;
};

#endif // COLLLISION_HPP_INCLUDED
