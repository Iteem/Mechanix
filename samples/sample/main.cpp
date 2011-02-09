#include <SFML/Graphics.hpp>
#include <mechanix/polygon.hpp>
#include <mechanix/line.hpp>
#include <mechanix/bodydef.hpp>
#include <mechanix/body.hpp>

#include <iostream>

const float PI = 3.14159265;

int main(void)
{
    mx::Line line1(mx::Vector2f(1, 1), mx::Vector2f(2, 1));
    mx::Line line2(mx::Vector2f(3, 1), mx::Vector2f(-1, 2));

    std::cout << "t1: " << line1.intersects(line2) << " t2: " << line2.intersects(line1) << std::endl;
    mx::Vector2f vec(line1.getPoint() + line1.intersects(line2) * line1.getDirectionVector());
    std::cout << "Point of intersection: " << vec.x << " " << vec.y << std::endl;

    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "PhysikTest", sf::Style::Default, sf::ContextSettings(24, 8, 6));
    app.SetFramerateLimit(60);

    mx::Polygon p1(3);
    p1.setPoint(0, mx::Vector2f(   0, .5f));
    p1.setPoint(1, mx::Vector2f(-.5f,  0));
    p1.setPoint(2, mx::Vector2f( .5f,  0));
    p1.setOrigin(mx::Vector2f(0, .25f));
    p1.setPosition(mx::Vector2f(1.f,1.f));
    mx::Polygon p2(p1);
    p2.setNumberOfPoints(4);
    p2.setPoint(3, mx::Vector2f(.5f, .5f));
    p2.setPosition(mx::Vector2f(4.f,4.f));
    p2.setRotation(PI);

    mx::BodyDef def;
    def.setMass(10.f);
    def.setMomentOfInertia(2.f);

    mx::Body b1(def, &p1);
    mx::Body b2(def, &p2);

    b1.acceleration(mx::Vector2f(0.5f, 1.f));
    b1.angularAcceleration(PI/4);

    b2.acceleration(mx::Vector2f(-0.5f, 0.f));
    b2.angularAcceleration(PI);

    sf::Shape s1;
    s1.AddPoint(  0,-50);
    s1.AddPoint(-50,  0);
    s1.AddPoint( 50,  0);
    s1.SetOrigin(sf::Vector2f(0, -25));
    s1.SetPosition(100, 600-100);
    s1.SetColor(sf::Color::Blue);
    sf::Shape s2(s1);
    s2.AddPoint(sf::Vector2f(50, -50));
    s2.SetPosition(400, 600-400);
    s2.SetRotation(180);

    sf::Shape cp1 = sf::Shape::Circle(0, 0, 3, sf::Color::White);
    sf::Shape cp2 = sf::Shape::Circle(0, 0, 3, sf::Color::White);

    while(app.IsOpened()){
        sf::Event event;
        while(app.GetEvent(event)){
            if(event.Type == sf::Event::Closed){
            app.Close();
            }
            else if(event.Type == sf::Event::MouseButtonPressed){
                if(event.MouseButton.Button == sf::Mouse::Left){
                    //p1.setPosition(mx::Vector2f(event.MouseButton.X, 600-event.MouseButton.Y));
                    //s1.SetPosition(event.MouseButton.X, event.MouseButton.Y);
                }
                else if(event.MouseButton.Button == sf::Mouse::Right){
                    //p2.setPosition(mx::Vector2f(event.MouseButton.X, 600-event.MouseButton.Y));
                    //s2.SetPosition(event.MouseButton.X, event.MouseButton.Y);
                }
            }
            else if(event.Type == sf::Event::KeyPressed){
                /*if(event.Key.Code == sf::Key::Return){
                    if(p1.collide(&p2)){
                        mx::Vector2f vec(p1.MTD(&p2));
                        p1.setPosition(p1.getPosition()+vec*1.01f);
                        s1.SetPosition(p1.getPosition().x, 600-p1.getPosition().y);
                    }
                }*/
            }
        }


        /*if(app.GetInput().IsKeyDown(sf::Key::P)){
            p1.setRotation(p1.getRotation()+app.GetFrameTime()*PI);
            s1.SetRotation(p1.getRotation()/PI*180);
        }
        if(app.GetInput().IsKeyDown(sf::Key::O)){
            p2.setRotation(p2.getRotation()+app.GetFrameTime()*PI);
            s2.SetRotation(p2.getRotation()/PI*180);
        }*/

        b1.update(app.GetFrameTime());
        b2.update(app.GetFrameTime());

        s1.SetPosition(b1.getShape()->getPosition().x * 100,
                       600 - b1.getShape()->getPosition().y * 100);
        s1.SetRotation(b1.getShape()->getRotation() * 180 / PI);
        s2.SetPosition(b2.getShape()->getPosition().x * 100,
                       600 - b2.getShape()->getPosition().y * 100);
        s2.SetRotation(b2.getShape()->getRotation() * 180 / PI);

        if(b1.getShape()->collide(b2.getShape())){
            s1.SetColor(sf::Color::Red);
            s2.SetColor(sf::Color::Red);
            /*cp1.SetColor(sf::Color::Green);
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
                            cp1.SetPosition(vec.x, 600 - vec.y);
                        else
                            cp2.SetPosition(vec.x, 600 - vec.y);

                        b = false;
                    }
                }
            }*/
        }else{
            s1.SetColor(sf::Color::Blue);
            s2.SetColor(sf::Color::Blue);
            //cp1.SetColor(sf::Color(0,0,0,0));
            //cp2.SetColor(sf::Color(0,0,0,0));
        }

        app.Clear();

        app.Draw(s1);
        app.Draw(s2);
        app.Draw(cp1);
        app.Draw(cp2);

        app.Display();
    }
}
