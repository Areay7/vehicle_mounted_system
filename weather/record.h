#ifndef RECORD_H
#define RECORD_H

#include <QObject>
#include <QThread>


class record : public QThread
{
    Q_OBJECT
public:
    virtual void run();

public slots:
    void recordCorlRunFlag(int flag);
signals:
    void recordCorlRunFlagSignal(int flag);
};




#endif // RECORD_H
