#include "server.h"
#include <QtDebug>
Server::Server(QObject *parent) : QObject(parent)
{
    displacement = Displacement();
    speed = Speed();
    acceleration = Acceleration();
}

void Server::receive(float x)
{
    displacement.set(x);
    speed.notify(x);
    acceleration.notify(x);

    qDebug() << "displacement" << x;
    qDebug() << "speed" << speed.get();
    qDebug() << "acceleration" << acceleration.get();
}
