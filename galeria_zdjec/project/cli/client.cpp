#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{

}

void Client::displace(float x)
{
    emit send(x);
}
