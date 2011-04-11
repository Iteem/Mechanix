#ifndef INTERSECTS_HPP_INCLUDED
#define INTERSECTS_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <mechanix/mechanix.hpp>
#include "state.hpp"

class Intersect : public State
{
    public:
        Intersect(sf::RenderWindow &app);
        virtual ~Intersect();

        virtual void init(void);
        virtual void destroy(void);

        virtual void update(float elapsedTime);
        virtual void display(const RenderInfos &renderinfos) const;
    private:
        mx::Polygon p1;
        mx::Polygon p2;

        sf::Shape s1;
        sf::Shape s2;

        sf::Shape cp1;
        sf::Shape cp2;
};

#endif // INTERSECTS_HPP_INCLUDED
