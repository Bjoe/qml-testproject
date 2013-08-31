#include "universe.h"

namespace qmltest {

Universe::Universe(QQuickItem *parent) :
    QQuickItem(parent),
    m_planet(nullptr)
{
}

Universe::~Universe()
{
    deletePlanet();
}

Planet *Universe::planet() const
{
    return m_planet;
}

void Universe::setPlanet(Planet *planet)
{
    m_planet = planet;
    emit planetChanged();
}

void Universe::onCreatePlanet()
{
    deletePlanet();
    m_planet = new Planet();
    Moon *moon = new Moon(m_planet);
    m_planet->setMoon(moon);

    emit planetChanged();
}

void Universe::deletePlanet()
{
    if(m_planet != nullptr) {
        delete m_planet;
    }
}

} // namespace qmltest
