#ifndef RENDERINFOS_HPP_INCLUDED
#define RENDERINFOS_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class RenderInfos
{
    public:
        RenderInfos();
        ~RenderInfos();

        void setZoom(float zoom);
        float getZoom(void) const;

        void setPosition(sf::Vector2f pos);
        sf::Vector2f getPosition(void) const;

        void showAABB(bool enable);
        bool showAABB(void) const;

        void showQuadtree(bool enable);
        bool showQuadtree(void) const;
    private:
        float m_zoom;
        sf::Vector2f m_pos;

        bool m_showAABB;
        bool m_showQuadtree;
};

#endif // RENDERINFOS_HPP_INCLUDED
