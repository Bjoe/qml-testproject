#ifndef QMLTEST_UNIVERSE_H
#define QMLTEST_UNIVERSE_H

#include <QQuickItem>

#include "planet.h"

namespace qmltest {

class Universe : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(qmltest::Planet* planet READ planet WRITE setPlanet NOTIFY planetChanged)

public:
    explicit Universe(QQuickItem *parent = 0);
    ~Universe();
    
    Planet *planet() const;
    void setPlanet(Planet *planet);

signals:
    void planetChanged();
    
public slots:
    void onCreatePlanet();
    
private:
    Planet *m_planet;

    void deletePlanet();
};

} // namespace qmltest

#endif // QMLTEST_UNIVERSE_H
