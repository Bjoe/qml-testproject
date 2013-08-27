#ifndef QMLTEST_PLANET_H
#define QMLTEST_PLANET_H

#include <QObject>

#include "moon.h"

namespace qmltest {

class Planet : public QObject
{
    Q_OBJECT

    Q_PROPERTY(qmltest::Moon *moon READ moon WRITE setMoon NOTIFY moonChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit Planet(QObject *parent = 0);

    Moon* moon() const;
    void setMoon(Moon* moon);

    QString name() const;
    void setName(const QString &name);

signals:
    void moonChanged();
    void nameChanged();
    
public slots:

private:
    QString m_name;
    Moon *m_moon;
};

} // namespace qmltest

#endif // QMLTEST_PLANET_H
