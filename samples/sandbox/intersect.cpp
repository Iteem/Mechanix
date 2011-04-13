#include "intersect.hpp"

const float PI = 3.14159265;

Intersect::Intersect(sf::RenderWindow &app) :
State(app)
{
}

Intersect::~Intersect()
{
}

void Intersect::init(void)
{
    p1.setNumberOfPoints(3);
    p1.setPoint(0, mx::Vector2f(   0, .5f));
    p1.setPoint(1, mx::Vector2f(-.5f,  0));
    p1.setPoint(2, mx::Vector2f( .5f,  0));
    p1.setOrigin(mx::Vector2f(0, .25f));
    p1.setPosition(mx::Vector2f(1.f,1.f));

    p2.setNumberOfPoints(4);
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

    s2 = s1;
    s2.AddPoint(sf::Vector2f(50, -50));
    s2.SetPosition(400, 600-400);
    s2.SetRotation(180);

    cp1 = sf::Shape::Circle(0, 0, 3, sf::Color::White);
    cp2 = sf::Shape::Circle(0, 0, 3, sf::Color::White);
}

void Intersect::destroy(void)
{
}

void Intersect::update(float elapsedTime)
{
    sf::Vector2f mousePos = m_window.ConvertCoords(m_window.GetInput().GetMouseX(),
                                                   m_window.GetInput().GetMouseY());

    if(m_window.GetInput().IsMouseButtonDown(sf::Mouse::Left)){
        p1.setPosition(mx::Vector2f(mousePos.x/100.f, (600-mousePos.y)/100.f));
        s1.SetPosition(mousePos);
    }
    else if(m_window.GetInput().IsMouseButtonDown(sf::Mouse::Right)){
        p2.setPosition(mx::Vector2f(mousePos.x/100.f, (600-mousePos.y)/100.f));
        s2.SetPosition(mousePos);
    }



    if(m_window.GetInput().IsKeyDown(sf::Key::P)){
        p1.setRotation(p1.getRotation()+elapsedTime*PI);
        s1.SetRotation(p1.getRotation()/PI*180);
    }
    if(m_window.GetInput().IsKeyDown(sf::Key::O)){
        p2.setRotation(p2.getRotation()+elapsedTime*PI);
        s2.SetRotation(p2.getRotation()/PI*180);
    }

    if(p1.collide(&p2)){
        s1.SetColor(sf::Color::Red);
        s2.SetColor(sf::Color::Red);
        cp1.SetColor(sf::Color::Green);
        cp2.SetColor(sf::Color::Green);

        bool b = true;
        for(int i = 0; i < p1.getNumberOfPoints(); ++i){
            mx::Line line1;
            if(i == p1.getNumberOfPoints() - 1)
                line1 = mx::Line(p1.getTransformedPoint(i), p1.getTransformedPoint(0)-p1.getTransformedPoint(i));
            else
                line1 = mx::Line(p1.getTransformedPoint(i), p1.getTransformedPoint(i+1)-p1.getTransformedPoint(i));
            for(int j = 0; j < p2.getNumberOfPoints(); ++j){
                mx::Line line2;
                if(j == p2.getNumberOfPoints() - 1)
                    line2 = mx::Line(p2.getTransformedPoint(j), p2.getTransformedPoint(0)-p2.getTransformedPoint(j));
                else
                    line2 = mx::Line(p2.getTransformedPoint(j), p2.getTransformedPoint(j+1)-p2.getTransformedPoint(j));

                float t1 = line1.intersects(line2);
                float t2 = line2.intersects(line1);

                if(0.f < t1 and t1 < 1.f and 0.f < t2 and t2 < 1.f){
                    mx::Vector2f vec = line1.getPoint() + t1 * line1.getDirectionVector();
                    if(b)
                        cp1.SetPosition(vec.x*100, 600 - vec.y*100);
                    else
                        cp2.SetPosition(vec.x*100, 600 - vec.y*100);

                    b = false;
                }
            }
        }
    }else{
        s1.SetColor(sf::Color::Blue);
        s2.SetColor(sf::Color::Blue);
        cp1.SetColor(sf::Color(0,0,0,0));
        cp2.SetColor(sf::Color(0,0,0,0));
    }

    aabb1 = sf::Shape::Rectangle(p1.getAABB().bottomLeftCorner.x * 100.f,
                                 600 - p1.getAABB().rightUpperCorner.y * 100.f,
                                 (p1.getAABB().rightUpperCorner.x - p1.getAABB().bottomLeftCorner.x) * 100.f,
                                 (p1.getAABB().rightUpperCorner.y - p1.getAABB().bottomLeftCorner.y) * 100.f ,
                                 sf::Color(0, 0, 0, 0), 1, sf::Color::White);
    aabb2 = sf::Shape::Rectangle(p2.getAABB().bottomLeftCorner.x * 100.f,
                                 600 - p2.getAABB().rightUpperCorner.y * 100.f,
                                 (p2.getAABB().rightUpperCorner.x - p2.getAABB().bottomLeftCorner.x) * 100.f,
                                 (p2.getAABB().rightUpperCorner.y - p2.getAABB().bottomLeftCorner.y) * 100.f ,
                                 sf::Color(0, 0, 0, 0), 1, sf::Color::White);
    if(p1.getAABB().intersects(p2.getAABB()))
    {
        aabb1.SetColor(sf::Color::Red);
        aabb2.SetColor(sf::Color::Red);
    }
}

void Intersect::display(const RenderInfos &renderinfos) const
{
    m_window.Draw(s1);
    m_window.Draw(s2);
    m_window.Draw(cp1);
    m_window.Draw(cp2);
    m_window.Draw(aabb1);
    m_window.Draw(aabb2);
}
