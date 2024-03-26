#ifndef WORKER_H
#define WORKER_H

#include <QObject>

/**
 * @brief The Worker class designed as standard class derived from QObject.
 *
 * This class aim of this class is to be executed in separate thread to parallelize algorithm execution.
 */
class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

public slots:
    void doWork();
    void printMsg(QString msg);
signals:
    void workDone();
};

#endif // WORKER_H
