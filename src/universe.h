#ifndef QMLTEST_UNIVERSE_H
#define QMLTEST_UNIVERSE_H

#include <QObject>

#include "planet.h"

namespace qmltest {

class Universe : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Planet* planet READ planet WRITE setPlanet NOTIFY planetChanged)

public:
    explicit Universe(QObject *parent = 0);
    
    Planet *planet() const;
    void setPlanet(Planet *planet);

signals:
    void planetChanged();
    
public slots:
    
private:
    Planet *m_planet;
};

} // namespace qmltest

#endif // QMLTEST_UNIVERSE_H