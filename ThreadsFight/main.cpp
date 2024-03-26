#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <chrono>
#include <QMutex>

// Global variable holding commonly used value
qint64 value = 0;

// Amount of operations performed over "value" variable
qint64 upTo = pow(10,6);

// Lock to eliminate race condition over the "value" variable
QMutex myLock;

/**
 * Class that increments global variable in separate thread
 */
class Increment: public QThread{
    void run() override{
        myLock.lock();
        qint64 tmp = value;
        myLock.unlock();
        for (qint64 i = 0; i < upTo; i++){
            tmp++;
        }
        myLock.lock();
        value += tmp;
        myLock.unlock();
    }
};

/**
 * Class that decrements global variable in separate thread
 */
class Decrement: public QThread{
    void run() override{
        myLock.lock();
        qint64 tmp = value;
        myLock.unlock();
        for (qint64 i = 0; i < upTo; i++){
            tmp--;
        }
        myLock.lock();
        value += tmp;
        myLock.unlock();
    }
};

using namespace  std::chrono;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create objects based on previous clases.
    Increment inc;
    Decrement dec;

    // Start time measurement
    auto start = high_resolution_clock::now();

    // Start the execution
    inc.start(); dec.start();

    // Stop the threads
    inc.quit(); dec.quit();

    // Wait till the threads finis it's work
    inc.wait();dec.wait();

    // Stop the time measurement
    auto stop = high_resolution_clock::now();

    // Print out the results
    qInfo() << "Finished in " << duration_cast<microseconds>(stop-start).count();
    qInfo() << "Final value is " << value ;

    return a.exec();
}
