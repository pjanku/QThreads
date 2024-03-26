#include <QCoreApplication>
#include "controller.h"
#include <QDebug>
#include <QThread>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // Create an instance of Controller
    Controller ctrl;

    // Print out message from the newly created thread
    ctrl.printMsgInSeparateThread("Test message");

    // Execute some operations in the newly created thread
    ctrl.doSomeWorkInSeparateThread();

    // Print some message including thread ID of a main (original) thread
    qInfo() << "Message from main "  << QThread::currentThreadId();

    return a.exec();
}
