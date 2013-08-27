#include "moon.h"

namespace qmltest {

Moon::Moon(QObject *parent) :
    QObject(parent), m_size(0)
{
}

int Moon::size() const
{
    return m_size;
}

void Moon::setSize(int size)
{
    m_size = size;
    emit sizeChanged();
}

QString Moon::name() const
{
    return m_name;
}

void Moon::setName(const QString &name)
{
    m_name = name;
    emit nameChanged();
}

} // namespace qmltest
