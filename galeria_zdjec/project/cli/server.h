#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include "utils.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
private:
    Displacement displacement;
    Speed speed;
    Acceleration acceleration;
signals:

public slots:
    void receive(float x);

};

#endif // SERVER_H
