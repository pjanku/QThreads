#include "mythread.h"
#include <QDebug>

/**
 * @brief Print out message by using qInfo()
 *
 * The message is extended by the ID of thread.
 * @param msg Message to be printed
 */
void MyThread::printFromTheThread(QString msg)
{
    qInfo() << "Msg from thread ID: " << currentThreadId() <<  msg;
}

/**
 * @brief Print out welcome message for the new thread followed by 10 messages in sequence.
 */
void MyThread::run()
{
    qInfo() << "Hello from MyThread " << currentThreadId();
    for(int i = 0; i < 10; i++){
        qInfo() << i << " from thread " << currentThreadId();
    }
    emit workDone();
}
