#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

/**
 * @brief Class derived from QThread in order to perform some actions in separate thread.
 *
 * This approach can be used to execute some actions in new, separated thread.
 *
 * ONLY run() FUNCTION IS EXECUTED IN CONTEXT OF NEW THREAD! Other functions and slots are executed in context of
 * the original thread.
 *
 * Communication by using slots & signals is "thread safe". You can use it to transform messages between different threads.
 */
class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread() = default;

public slots:
    void printFromTheThread(QString msg);

signals:
    void workDone();

protected:
    void run() override;
};

#endif // MYTHREAD_H
