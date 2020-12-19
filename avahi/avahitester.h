#ifndef AVAHITESTER_H
#define AVAHITESTER_H

#include <QObject>
#include <dbus-cxx.h>
#include <memory>
#include <QDebug>

#include "ServerProxy.h"
#include "EntryGroupProxy.h"

class AvahiTester : public QObject
{
    Q_OBJECT
public:
    explicit AvahiTester(QObject *parent = nullptr);

    void setConnection( std::shared_ptr<DBus::Connection> conn );

Q_SIGNALS:

public Q_SLOTS:
    void start();

private:
    std::shared_ptr<DBus::Connection> m_conn;
    std::shared_ptr<Avahi::ServerProxy> m_avahiServer;
};

#endif // AVAHITESTER_H
