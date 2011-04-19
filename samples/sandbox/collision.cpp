#include "collision.hpp"
#include <iostream>

const float PI = 3.14159265;

Collision::Collision(sf::RenderWindow &app) :
State(app)
{
}

Collision::~Collision()
{
}

void Collision::init(void)
{
    mx::Polygon p1(3);
    p1.setPoint(0, mx::Vector2f(   0, .5f));
    p1.setPoint(1, mx::Vector2f(-.5f,  0));
    p1.setPoint(2, mx::Vector2f( .5f,  0));
    p1.setOrigin(mx::Vector2f(0, .25f));
    p1.setPosition(mx::Vector2f(1.f,1.f));

    mx::Polygon p2(4);
    p2.setPoint(0, mx::Vector2f(   0, .5f));
    p2.setPoint(1, mx::Vector2f(-.5f,  0));
    p2.setPoint(2, mx::Vector2f( .5f,  0));
    p2.setPoint(3, mx::Vector2f(.5f, .5f));
    p2.setOrigin(mx::Vector2f(0, .25f));
    p2.setPosition(mx::Vector2f(4.f,4.f));
    p2.setRotation(PI);

    s1.AddPoint(  0,-50);
    s1.AddPoint(-50,  0);
    s1.AddPoint( 50,  0);
    s1.SetOrigin(sf::Vector2f(0, -25));
    s1.SetPosition(100, 600-100);
    s1.SetColor(sf::Color::Blue);

    s2.AddPoint(  0,-50);
    s2.AddPoint(-50,  0);
    s2.AddPoint( 50,  0);
    s2.AddPoint( 50,-50);
    s2.SetOrigin(sf::Vector2f(0, -25));
    s2.SetPosition(100, 600-100);
    s2.SetColor(sf::Color::Blue);

    mx::BodyDef bodyDef;
    bodyDef.setMass(40);
    bodyDef.setMomentOfInertia(5);

    b1 = m_world.createBody(bodyDef, &p1);
    b2 = m_world.createBody(bodyDef, &p2);

    b1->acceleration(mx::Vector2f(1.1, 1));
    b2->acceleration(mx::Vector2f(-0.8, -0.7));
    b1->angularAcceleration( 0.8f);
    b2->angularAcceleration(-1.0f);

    m_world.setGravitation(mx::Vector2f(0, 0));
}

void Collision::destroy(void)
{
}

void Collision::update(float elapsedTime)
{
    m_world.update(elapsedTime);

    s1.SetPosition(b1->getShape()->getPosition().x * 100, 600 - b1->getShape()->getPosition().y * 100);
    s1.SetRotation(b1->getShape()->getRotation()*180/PI);
    s2.SetPosition(b2->getShape()->getPosition().x * 100, 600 - b2->getShape()->getPosition().y * 100);
    s2.SetRotation(b2->getShape()->getRotation()*180/PI);
}

void Collision::display(const RenderInfos &renderinfos) const
{
    m_window.Draw(s1);
    m_window.Draw(s2);
}
