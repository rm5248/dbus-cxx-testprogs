all: signalCollector signalEmitter

signalCollector: signalCollector.cpp myData.cpp
	g++ -o signalCollector signalCollector.cpp myData.cpp $(shell pkg-config --cflags --libs dbus-cxx-1.0)

signalEmitter: signalEmitter.cpp myData.cpp
	g++ -o signalEmitter signalEmitter.cpp myData.cpp $(shell pkg-config --cflags --libs dbus-cxx-1.0)
