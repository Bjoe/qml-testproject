#include "mainuicontroller.h"

#include <QtQml/QQmlContext>
#include <QUrl>
#include <QDebug>

#include <QtQml>

#include "universe.h"

namespace qmltest {

MainUiController::MainUiController()
    : m_engine(),
      m_window(nullptr)
{
    qRegisterMetaType<qmltest::Moon *>("qmltest::Moon *");
    qRegisterMetaType<qmltest::Planet *>("qmltest::Planet *");

    qmlRegisterType<Universe>("qmltest", 1, 0, "Universe");
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

}


} // namespace qmltest
