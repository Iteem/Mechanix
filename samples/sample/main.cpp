#include <SFML/Graphics.hpp>
#include <mechanix/polygon.hpp>
#include <mechanix/line.hpp>

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
    p1.setPoint(0, mx::Vector2f(  0, 50));
    p1.setPoint(1, mx::Vector2f(-50,  0));
    p1.setPoint(2, mx::Vector2f( 50,  0));
    p1.setPosition(mx::Vector2f(100,100));
    mx::Polygon p2(p1);
    p2.setPosition(mx::Vector2f(400,400));
    p2.setRotation(1.5f);

    sf::Shape s1;
    s1.AddPoint(  0,-50);
    s1.AddPoint(-50,  0);
    s1.AddPoint( 50,  0);
    s1.SetPosition(100, 600-100);
    s1.SetColor(sf::Color::Blue);
    sf::Shape s2(s1);
    s2.SetPosition(400, 600-400);
    s2.SetRotation(1.5f/PI*180);

    while(app.IsOpened()){
        sf::Event event;
        while(app.GetEvent(event)){
            if(event.Type == sf::Event::Closed){
            app.Close();
            }
            else if(event.Type == sf::Event::MouseButtonPressed){
                if(event.MouseButton.Button == sf::Mouse::Left){
                    p1.setPosition(mx::Vector2f(event.MouseButton.X, 600-event.MouseButton.Y));
                    s1.SetPosition(event.MouseButton.X, event.MouseButton.Y);
                }
                else if(event.MouseButton.Button == sf::Mouse::Right){
                    p2.setPosition(mx::Vector2f(event.MouseButton.X, 600-event.MouseButton.Y));
                    s2.SetPosition(event.MouseButton.X, event.MouseButton.Y);
                }
            }
            else if(event.Type == sf::Event::KeyPressed){
                if(event.Key.Code == sf::Key::Return){
                    if(p1.collide(&p2)){
                        mx::Vector2f vec(p1.MTD(&p2));
                        p1.setPosition(p1.getPosition()+vec*1.01f);
                        s1.SetPosition(p1.getPosition().x, 600-p1.getPosition().y);
                    }
                }
            }
        }


        if(app.GetInput().IsKeyDown(sf::Key::P)){
            p1.setRotation(p1.getRotation()+app.GetFrameTime()*PI);
            s1.SetRotation(p1.getRotation()/PI*180);
        }
        if(app.GetInput().IsKeyDown(sf::Key::O)){
            p2.setRotation(p2.getRotation()+app.GetFrameTime()*PI);
            s2.SetRotation(p2.getRotation()/PI*180);
        }


        if(p1.collide(&p2)){
            s1.SetColor(sf::Color::Red);
            s2.SetColor(sf::Color::Red);
            mx::Vector2f vec(p1.MTD(&p2));
        }else{
            s1.SetColor(sf::Color::Blue);
            s2.SetColor(sf::Color::Blue);
        }

        app.Clear();

        app.Draw(s1);
        app.Draw(s2);

        app.Display();
    }
}
