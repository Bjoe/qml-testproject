
#include <stdio.h>
#include <stdlib.h>

#include <QString>
#include <QByteArray>
//#include <QtGui/QGuiApplication>
#include <QtWidgets/QApplication>

#include <QtMessageHandler>
#include <QMessageLogContext>

#include "config.h"
#include "mainuicontroller.h"

void messageHandlerOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(messageHandlerOutput);

    QApplication app(argc, argv);

    qmltest::MainUiController *uiController = qmltest::MainUiController::createInstance(QML_PATH);
    uiController->show();

    return app.exec();
}
