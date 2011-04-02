#include "sandbox.hpp"
#include <sstream>

Sandbox::Sandbox() :
m_window(sf::VideoMode(800, 600, 32), "PhysikTest", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(24, 8, 6)),
m_guiBackground(sf::Shape::Rectangle(600, 0, 200, 600, sf::Color(50, 50, 50))),
m_gui(sf::FloatRect(0, 0, 800, 600)),
m_listbox(sfg::StringListbox::Create(sf::FloatRect(620, 20, 160, 100))),
m_runButton(sfg::Button::Create(sf::FloatRect(650, 150, 100, 30), "Run")),
m_pauseButton(sfg::Button::Create(sf::FloatRect(650, 200, 100, 30), "Pause")),
m_stepButton(sfg::Button::Create(sf::FloatRect(650, 250, 100, 30), "Single step")),
m_scrollbar(sfg::Scrollbar::Create(sf::FloatRect(660, 300, 110, 20), true)),
m_scrollbarLabel(sfg::Label::Create(sf::Vector2f(0, 0))),
m_run(false),
m_makeStep(false)
{
    m_window.SetFramerateLimit(60);
    m_window.ShowMouseCursor(false);

    m_listbox->AddItem("Sample");
    m_listbox->AddItem("Intersects");
    m_listbox->AddItem("Collision");

    m_scrollbar->SetMinimum(10);
    m_scrollbar->SetMaximum(100);
    m_scrollbar->SetValue(60);
    onScrollbarChanged(m_scrollbar);

    m_runButton->Clicked = sfg::Slot<sfg::Button::ClickSlot>(&Sandbox::onRunButtonClicked, this);
    m_pauseButton->Clicked = sfg::Slot<sfg::Button::ClickSlot>(&Sandbox::onPauseButtonClicked, this);
    m_stepButton->Clicked = sfg::Slot<sfg::Button::ClickSlot>(&Sandbox::onStepButtonClicked, this);
    m_scrollbar->Changed = sfg::Slot<sfg::Scrollbar::ChangeSlot>(&Sandbox::onScrollbarChanged, this);

    m_gui.AddWidget(m_listbox);
    m_gui.AddWidget(m_runButton);
    m_gui.AddWidget(m_pauseButton);
    m_gui.AddWidget(m_stepButton);
    m_gui.AddWidget(m_scrollbar);
    m_gui.AddWidget(m_scrollbarLabel);
    m_gui.LoadSkinFromFile("data/skins/black.skin");
}

Sandbox::~Sandbox()
{
}

int Sandbox::run()
{
    while(m_window.IsOpened()){
        sf::Event event;
        while(m_window.GetEvent(event)){
            if(event.Type == sf::Event::Closed){
                m_window.Close();
            }
            m_gui.HandleEvent(event);
        }

        m_window.Clear(sf::Color::Black);

        m_window.Draw(m_guiBackground);
        m_gui.Render(m_window);

        m_window.Display();
    }

    return 0;
}

void Sandbox::onRunButtonClicked(sfg::Widget::Ptr widget)
{
    m_run = true;
}

void Sandbox::onPauseButtonClicked(sfg::Widget::Ptr widget)
{
    m_run = false;
}

void Sandbox::onStepButtonClicked(sfg::Widget::Ptr widget)
{
    m_makeStep = true;
}

void Sandbox::onScrollbarChanged(sfg::Widget::Ptr widget)
{
    std::stringstream str;
    str << m_scrollbar->GetValue();

    m_scrollbarLabel->SetString(str.str());
    sfg::AlignWidgetInRect(
		*m_scrollbarLabel,
		sf::FloatRect(620, 300, 20, 30),
		sfg::AlignRight | sfg::AlignTop,
		sf::Vector2f(0, 0)
	);
}
