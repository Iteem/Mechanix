#ifndef SANDBOX_HPP_INCLUDED
#define SANDBOX_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include <SFGUI/GUI.hpp>
#include <SFGUI/Container.hpp>
#include <SFGUI/Button.hpp>
#include <SFGUI/Listbox.hpp>
#include <SFGUI/Scrollbar.hpp>
#include <SFGUI/Label.hpp>

#include "renderinfos.hpp"
#include "state.hpp"

class Sandbox
{
    public:
        Sandbox(void);
        ~Sandbox(void);

        int run(void);
    private:
        sf::RenderWindow m_window;
        sf::Shape m_guiBackground;

        sfg::GUI m_gui;

        sfg::StringListbox::Ptr m_listbox;
        sfg::Button::Ptr m_runButton;
        sfg::Button::Ptr m_pauseButton;
        sfg::Button::Ptr m_stepButton;
        sfg::Scrollbar::Ptr m_scrollbar;
        sfg::Label::Ptr m_scrollbarLabel;

        void onRunButtonClicked(sfg::Widget::Ptr widget);
        void onPauseButtonClicked(sfg::Widget::Ptr widget);
        void onStepButtonClicked(sfg::Widget::Ptr widget);
        void onScrollbarChanged(sfg::Widget::Ptr widget);
        void onListboxScrolled(sfg::Widget::Ptr widget);

        bool m_run;
        bool m_makeStep;

        RenderInfos m_renderInfos;
        State *m_state;
};

#endif // SANDBOX_HPP_INCLUDED
