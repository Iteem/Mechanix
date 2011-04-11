#include "renderinfos.hpp"

RenderInfos::RenderInfos() :
m_zoom(1),
m_pos(),
m_showAABB(false),
m_showQuadtree(false)
{
}

RenderInfos::~RenderInfos()
{
}

void RenderInfos::setZoom(float zoom)
{
    m_zoom = zoom;
}

float RenderInfos::getZoom(void) const
{
    return m_zoom;
}

void RenderInfos::setPosition(sf::Vector2f pos)
{
    m_pos = pos;
}

sf::Vector2f RenderInfos::getPosition(void) const
{
    return m_pos;
}

void RenderInfos::showAABB(bool enable)
{
    m_showAABB = enable;
}

bool RenderInfos::showAABB(void) const
{
    return m_showAABB;
}

void RenderInfos::showQuadtree(bool enable)
{
    m_showQuadtree = enable;
}

bool RenderInfos::showQuadtree(void) const
{
    return m_showQuadtree;
}
