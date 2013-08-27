#ifndef QMLTEST_MOON_H
#define QMLTEST_MOON_H

#include <QObject>
#include <QString>

namespace qmltest {

class Moon : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int size READ size WRITE setSize NOTIFY sizeChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit Moon(QObject *parent = 0);
    
    int size() const;
    void setSize(int size);

    QString name() const;
    void setName(const QString &name);

signals:
    void sizeChanged();
    void nameChanged();
    
public slots:

private:
    QString m_name;
    int m_size;
    
};

} // namespace qmltest

#endif // QMLTEST_MOON_H
