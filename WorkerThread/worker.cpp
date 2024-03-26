#include "worker.h"
#include <QDebug>
#include <QThread>


Worker::Worker(QObject *parent)
    : QObject{parent}
{

}

/**
 * @brief Print out welcome message including current thread ID followed by 10 messages.
 *
 * The aim of this function is to simulate an algorithm implemented in separate thread.
 * At the end of the execution, the workDone() signal is emitted.
 */
void Worker::doWork()
{
    qInfo() << "Hello from Worker " << QThread::currentThreadId();
    for(int i = 0; i < 10; i++){
        qInfo() << i << " from thread " << QThread::currentThreadId();
    }
    emit workDone();
}

/**
 * @brief Send message to the standard output.
 *
 * The message is extended by the ID of thread.
 * @param msg Message to be printed out.
 */
void Worker::printMsg(QString msg)
{
    qInfo() << "Msg from thread ID: " << QThread::currentThreadId() << " \"" << msg << "\"";

}
