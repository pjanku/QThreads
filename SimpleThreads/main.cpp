#include <QCoreApplication>
#include "mythread.h"
#include <QThread>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // New MyThread object (MyThread is derived from QThread)
    MyThread *pMyThread = new MyThread;

    // Connect for a signal coming from the MyThread object
    QObject::connect(pMyThread, &MyThread::workDone, [](){
        qInfo() << "Thread " << QThread::currentThreadId() << " done it's work";
    });

    // Start new thread (start the even loop and execute "run()" function
    pMyThread->start();

    // Call the function implemented in MyThread - execution is done in main thread not the new one!!!!!!
    pMyThread->printFromTheThread("Testing message");

    // Print out message from main thread including thread ID.
    qDebug() << "Hello from Main - ID: " << QThread::currentThreadId();

    return a.exec();
}
