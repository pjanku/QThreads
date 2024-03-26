#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "worker.h"
#include <QThread>

/**
 * @brief Class implementing all necessary steps to execute Worker class methods in context of new thread.
 * @sa Worker
 */
class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    void printMsgInSeparateThread(QString msg);
    void doSomeWorkInSeparateThread();
signals:
    void messageToBePrinted(QString msg);   /**< Signal for sending messages to the Worker class to be printed from new thread*/
    void workToBeDone();                    /**< Signal for sending command to the Worker class to be executed in new thread */
private:
    Worker *pWorker;            /**< Pointer to a Worker class - will be moved to a new thread */
    QThread *pWorkerThread;     /**< Pointer to a new thread */
};

#endif // CONTROLLER_H
