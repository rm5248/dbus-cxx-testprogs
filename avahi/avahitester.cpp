#include "avahitester.h"

static std::vector<uint8_t> stringToVector( std::string str ){
    std::vector<uint8_t> ret;

    for( char c : str ){
        ret.push_back( c );
    }

    return ret;
}

AvahiTester::AvahiTester(QObject *parent) : QObject(parent)
{

}

void AvahiTester::setConnection(std::shared_ptr<DBus::Connection> conn){
    m_conn = conn;
}

void AvahiTester::stateChanged( int state, std::string error ){
    qDebug() << "State changed.  State: " << state << " error: " << QString::fromStdString( error );
}

void AvahiTester::start(){
    m_avahiServer = Avahi::ServerProxy::create( m_conn, "org.freedesktop.Avahi", "/" );

    DBus::Path newGroup =
            m_avahiServer->getorg_freedesktop_Avahi_ServerInterface()->EntryGroupNew();

    qDebug() << "new group is: " << newGroup.c_str();

    std::shared_ptr<Avahi::EntryGroupProxy> entryProxy =
            Avahi::EntryGroupProxy::create( m_conn, "org.freedesktop.Avahi", newGroup );

    entryProxy->getorg_freedesktop_Avahi_EntryGroupInterface()
            ->signal_StateChanged()
            ->connect( sigc::mem_fun( *this, &AvahiTester::stateChanged ) );

    std::vector<std::vector<uint8_t>> txtData;
    txtData.push_back( stringToVector( "robert=hi" ) );

    qDebug() << "Adding an entry";
    entryProxy->getorg_freedesktop_Avahi_EntryGroupInterface()
            ->AddService( -1, 0, 0, "fooName", "_foo._tcp", std::string(), std::string(), 5248, txtData );

    qDebug() << "Commiting to server";
    entryProxy->getorg_freedesktop_Avahi_EntryGroupInterface()
            ->Commit();
}
