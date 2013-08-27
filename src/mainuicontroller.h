#ifndef QMLTEST_MAINUICONTROLLER_H
#define QMLTEST_MAINUICONTROLLER_H

#include <QtQml/QQmlApplicationEngine>
#include <QtQuick/QQuickWindow>

namespace qmltest {

class MainUiController
{
public:
    static MainUiController *createInstance(const QString &qmlUrl);
    void show();

private:
    void initContext();
    void init();
    MainUiController();

    QQmlApplicationEngine m_engine;
    QQuickWindow *m_window;
};

} // namespace qmltest

#endif // QMLTEST_MAINUICONTROLLER_H
