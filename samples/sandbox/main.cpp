#include <SFML/Graphics.hpp>
#include <mechanix/polygon.hpp>
#include <mechanix/line.hpp>
#include <mechanix/bodydef.hpp>
#include <mechanix/body.hpp>

#include <iostream>

#include <SFGUI/GUI.hpp>
#include <SFGUI/Container.hpp>
#include <SFGUI/Button.hpp>
#include <SFGUI/Listbox.hpp>

const float PI = 3.14159265;

int main(void)
{
    sfg::GUI gui(sf::FloatRect(0, 0, 800, 600));

    sfg::StringListbox::Ptr listbox = sfg::StringListbox::Create(sf::FloatRect(620, 20, 160, 100));
    listbox->AddItem("Sample");
    listbox->AddItem("Intersects");
    listbox->AddItem("Collision");

    gui.AddWidget(listbox);
    gui.LoadSkinFromFile("data/skins/black.skin");

    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "PhysikTest", sf::Style::Default, sf::ContextSettings(24, 8, 6));
    app.EnableVerticalSync(true);
    //app.SetFramerateLimit(60);
    app.ShowMouseCursor(false);


    while(app.IsOpened()){
        sf::Event event;
        while(app.GetEvent(event)){
            if(event.Type == sf::Event::Closed){
                app.Close();
            }
            gui.HandleEvent(event);
        }

        app.Clear(sf::Color::Black);

        gui.Render(app);

        app.Display();
    }
}
