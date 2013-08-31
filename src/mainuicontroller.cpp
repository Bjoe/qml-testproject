#include "mainuicontroller.h"

#include <QtQml/QQmlContext>
#include <QUrl>
#include <QDebug>

#include <QQmlComponent>
#include <QQuickItem>

#include "universe.h"
#include "planet.h"
#include "moon.h"

namespace qmltest {

MainUiController::MainUiController()
    : m_engine(),
      m_window(nullptr)
{
    //qRegisterMetaType<qmltest::Moon *>("Moon *");
    //qRegisterMetaType<qmltest::Planet *>("Planet *");


    qmlRegisterType<Universe>("qmltest", 1, 0, "Universe");
    qmlRegisterType<Planet>("qmltest", 1, 0, "Planet");
    qmlRegisterType<Moon>("qmltest", 1, 0, "Moon");
}

MainUiController *MainUiController::createInstance(const QString &qmlUrl)
{

    MainUiController *instance = new MainUiController();
    instance->initContext();
    instance->m_engine.load(QUrl(qmlUrl));
    instance->init();
    return instance;
}

void MainUiController::show()
{
    m_window->show();
}

void MainUiController::initContext()
{
    qDebug() << "initialize context";
    QQmlContext *context = m_engine.rootContext();

}

void MainUiController::init()
{
    qDebug() << "initialize QQuickWindow";
    QList<QObject *> list = m_engine.rootObjects();
    QObject *topLevel = list.value(0);

    m_window = qobject_cast<QQuickWindow *>(topLevel);
    QQuickItem *item = m_window->findChild<QQuickItem *>("layout");

    QQmlComponent component(&m_engine, QUrl("qrc:/assets/qml/component.qml"));
    Universe *universe = qobject_cast<Universe *>(component.create());
    if(universe) {
        universe->connect(m_window, SIGNAL(createPlanet()), SLOT(onCreatePlanet()));

        // How can I add universe in QML ?

    } else {
        qWarning() << component.errors();
    }
}


} // namespace qmltest
