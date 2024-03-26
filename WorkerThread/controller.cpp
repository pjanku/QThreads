#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    // Create a new thread
    pWorkerThread = new QThread();

    // Create a new worker object
    pWorker = new Worker();

    // Move the whole object to the context of the newly created thread
    pWorker->moveToThread(pWorkerThread);

    // Connect signal, which schedule worker object deletion as soon as possible
    connect(pWorkerThread, &QThread::finished, pWorker, &Worker::deleteLater);

    // Connect signals to send messages to the worker in separate thread
    connect(this, &Controller::messageToBePrinted, pWorker, &Worker::printMsg);
    connect(this, &Controller::workToBeDone, pWorker, &Worker::doWork);

    // Start the newly created thread
    pWorkerThread->start();
}

Controller::~Controller()
{
    // Send a "quit" signal to the worker thread - doesn't mean that the thread is stopped immediately
    pWorkerThread->quit();
    /// Wait till the thread will be already finished.
    pWorkerThread->wait();

    delete pWorkerThread;
}
/**
 * @brief Send a message to the worker object to print it out from a separate thread
 * @param msg Message to be sent
 */
void Controller::printMsgInSeparateThread(QString msg)
{
    emit messageToBePrinted(msg);
}

/**
 * @brief Send a command to the worker object to execute some actions
 */
void Controller::doSomeWorkInSeparateThread()
{
    emit workToBeDone();
}
