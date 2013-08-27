#include "planet.h"

namespace qmltest {

Planet::Planet(QObject *parent) :
    QObject(parent)
{
}

Moon *Planet::moon() const
{
    return m_moon;
}

void Planet::setMoon(Moon *moon)
{
    m_moon = moon;
    emit moonChanged();
}

QString Planet::name() const
{
    return m_name;
}

void Planet::setName(const QString &name)
{
    m_name = name;
    emit nameChanged();
}

} // namespace qmltest
