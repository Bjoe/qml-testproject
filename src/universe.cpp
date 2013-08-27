#include "universe.h"

namespace qmltest {

Universe::Universe(QObject *parent) :
    QObject(parent)
{
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

} // namespace qmltest
