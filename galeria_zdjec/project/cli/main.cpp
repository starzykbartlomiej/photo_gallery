#include <QCoreApplication>
#include <iostream>

#include "utils.h"
#include "client.h"
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server{};
    Client client{};

    QObject::connect(&client, SIGNAL(send(float)),
                     &server, SLOT(receive(float)));

    client.displace(1);
    client.displace(2);
    client.displace(3);
    client.displace(4);
    client.displace(7);
    client.displace(9);

    return a.exec();
}
