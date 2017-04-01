#include <stdio.h>
#include <dbus-cxx.h>
#include <string.h>
#include <unistd.h>

using namespace std;

char datebuffer[ 128 ];

void mylog( const char* logger_name, const struct SL_LogLocation* location,
      const enum SL_LogLevel level,
      const char* log_string ){
    time_t now = time( NULL );
    struct tm* timeinfo;
 
    timeinfo = localtime( &now );
    strftime( datebuffer, 128, "%H:%M:%S", timeinfo );
    std::cerr << "[" << datebuffer << "] " 
        <<  logger_name << " - " << log_string << std::endl;
}


int main(int argc, char** argv){

        DBus::setLoggingFunction( mylog );

	//First we have to init the dbus.
	DBus::init();
	//The dispatcher sends us information.  Make sure that it doesn't go out of scope or bad things will happen.
	DBus::Dispatcher::pointer dispatcher = DBus::Dispatcher::create();
	//Create a connection to the session bus
	DBus::Connection::pointer connection = dispatcher->create_connection( DBus::BUS_SESSION );

	//Create a pointer to a remote object with the specified interface and path.
	DBus::ObjectProxy::pointer object = connection->create_object_proxy("com.rm5248", "/");

	//Make a method that returns an int and takes in a string
	DBus::MethodProxy<int, string>& echoMessage = *(object->create_method<int, string>("com.rm5248.ReceiveInterface", "echoMessage"));
	
	//Make a method that returns an int and takes in a string and two ints
	DBus::MethodProxy<int, string, int, int>& echoAndAdd = *(object->create_method<int, string, int, int>
		("com.rm5248.ReceiveInterface", "echoAndAdd"));

	DBus::MethodProxy<void,std::string>& voidMethod = *(object->create_method<void,std::string>
		("com.rm5248.ReceiveInterface", "voidMethod"));
		
	//We can now call these methods as though they were defined in this file, or in an included file
	int firstResult = echoMessage("Hello Java from C++!");
	printf("%d\n", firstResult);
	
	int secondResult = echoAndAdd("Testing the addition", 42, 19);
	printf("%d\n", secondResult);

try{
	while( 1 ){
		//usleep( 1000 );
		//sleep( 10 );
	//	printf( "about to do four method calls\n");
	//	printf( "=======================================\n");
  		voidMethod("one");
  		voidMethod("two");
  		voidMethod("three");
  		voidMethod("four");
	//	printf( "done four method calls\n");
	//	printf( "=======================================\n");
	}
}catch( DBusCxxPointer<DBus::Error> err ){
printf( "exiting due to error: %s\n", err->what() );
printf( "Message: %s\n", err->message() );
printf( "Message name: %s\n", err->name() );
}

  	return 0;
}
