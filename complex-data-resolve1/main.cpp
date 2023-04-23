#include <iostream>
#include <dbus-cxx.h>

constexpr auto RESOLVED_DEST = "org.freedesktop.resolve1";
constexpr auto RESOLVED_NODE = "/org/freedesktop/resolve1";
constexpr auto RESOLVED_MANAGER_INTERFACE = "org.freedesktop.resolve1.Manager";

class ResolvedManagerObject : public ::DBus::ObjectProxy
{
protected:
	explicit ResolvedManagerObject(std::shared_ptr<::DBus::Connection> connection)
			: ::DBus::ObjectProxy(std::move(connection), RESOLVED_DEST, RESOLVED_NODE)
	{
		m_methodRegisterService = this->create_method<::DBus::Path(std::string, std::string, std::string, uint16_t, uint16_t, uint16_t, std::vector<std::map<std::string, std::vector<uint8_t>>>)>(RESOLVED_MANAGER_INTERFACE, "RegisterService");
	}

public:
	static std::shared_ptr<ResolvedManagerObject> Create(const std::shared_ptr<::DBus::Connection>& connection)
	{
		auto managerObject = std::shared_ptr<ResolvedManagerObject>(new ResolvedManagerObject(connection));
		connection->register_object_proxy(managerObject);
		return managerObject;
	}

	::DBus::Path RegisterService(const std::string& name, const std::string& name_template, const std::string& type, uint16_t service_port, uint16_t service_priority, uint16_t service_weight, const std::vector<std::map<std::string, std::vector<uint8_t>>>& txt_data)
	{
		return (*m_methodRegisterService)(name, name_template, type, service_port, service_priority, service_weight, txt_data);
	}

private:
	std::shared_ptr<::DBus::MethodProxy<::DBus::Path(std::string, std::string, std::string, uint16_t, uint16_t, uint16_t, std::vector<std::map<std::string, std::vector<uint8_t>>>)>> m_methodRegisterService;
};

inline static std::vector<uint8_t> StrToBinary(const std::string& data)
{
	return std::vector<uint8_t>(data.begin(), data.end());
}

void compareVariantsStr(std::string prefix, DBus::Variant variant1, DBus::Variant variant2){
    std::cout << prefix << ":\n";
    std::cout << "  variant 1 type: " << variant1.type() << "\n";
    std::cout << "  variant 2 type: " << variant2.type() << "\n";
    bool equal = false;
    if(variant1.type() == DBus::DataType::STRING &&
            variant2.type() == DBus::DataType::STRING){
        equal = variant1.to_string() == variant2.to_string();

        std::cout << "  data: " << variant1.to_string() << "\n";
    }
    if(variant1.type() == DBus::DataType::SIGNATURE &&
            variant2.type() == DBus::DataType::SIGNATURE){
        equal = variant1.to_signature().str() == variant2.to_signature().str();
    }
    if(variant1.type() == DBus::DataType::OBJECT_PATH &&
            variant2.type() == DBus::DataType::OBJECT_PATH){
        equal = variant1.to_path() == variant2.to_path();
        std::cout << "  data: " << variant1.to_path() << "\n";
    }
    std::cout << "  equal? " << (equal ? "true" : "false") << "\n";
}

void compareMessages(std::shared_ptr<DBus::Message> msg1, std::shared_ptr<DBus::Message> msg2){
     compareVariantsStr("path", msg1->header_field(DBus::MessageHeaderFields::Path),
                                msg2->header_field(DBus::MessageHeaderFields::Path));
     compareVariantsStr("interface", msg1->header_field(DBus::MessageHeaderFields::Interface),
                                msg2->header_field(DBus::MessageHeaderFields::Interface));
     compareVariantsStr("member", msg1->header_field(DBus::MessageHeaderFields::Member),
                                msg2->header_field(DBus::MessageHeaderFields::Member));
     compareVariantsStr("destination", msg1->header_field(DBus::MessageHeaderFields::Destination),
                                msg2->header_field(DBus::MessageHeaderFields::Destination));
     compareVariantsStr("Signature", msg1->header_field(DBus::MessageHeaderFields::Signature),
                                msg2->header_field(DBus::MessageHeaderFields::Signature));
}

int main(int argc, char* argv[])
{
	std::vector<std::map<std::string, std::vector<uint8_t>>> txt_data =
		{{{
            {"key1", StrToBinary("value1")},
		}}};

	::DBus::Path result;
//    DBus::set_log_level(SL_LogLevel::SL_TRACE);
//    DBus::set_logging_function(DBus::log_std_err);
//    DBus::set_default_endianess(DBus::Endianess::Little);

    try
    {
        auto dispatcher = ::DBus::StandaloneDispatcher::create();
        auto connection = dispatcher->create_connection(::DBus::BusType::SYSTEM);
        auto managerObject = ResolvedManagerObject::Create(connection);
        result = managerObject->RegisterService("test4", "%m", "_http._tcp", 0, 0, 0, txt_data);
    }
    catch (const ::DBus::Error& ex)
    {
        std::cerr << "main: Caught exception: " << ex.name() << ": " << ex.message() << std::endl;
        return -1;
    }
    catch (...)
    {
        std::exception_ptr p = std::current_exception();
        std::string ex = (p ? p.__cxa_exception_type()->name() : "null");
        std::cerr << "main: Caught exception: " << ex << std::endl;
        return -1;
    }

    std::cout << "Success: " << result << std::endl;

//    /* Frame (286 bytes) */
//    static const unsigned char dbuscxx_packet[286] = {
//    0x42, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x4e, /* B......N */
//    0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0xbf, /* ........ */
//    0x01, 0x01, 0x6f, 0x00, 0x00, 0x00, 0x00, 0x19, /* ..o..... */
//    0x2f, 0x6f, 0x72, 0x67, 0x2f, 0x66, 0x72, 0x65, /* /org/fre */
//    0x65, 0x64, 0x65, 0x73, 0x6b, 0x74, 0x6f, 0x70, /* edesktop */
//    0x2f, 0x72, 0x65, 0x73, 0x6f, 0x6c, 0x76, 0x65, /* /resolve */
//    0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 1....... */
//    0x02, 0x01, 0x73, 0x00, 0x00, 0x00, 0x00, 0x20, /* ..s....  */
//    0x6f, 0x72, 0x67, 0x2e, 0x66, 0x72, 0x65, 0x65, /* org.free */
//    0x64, 0x65, 0x73, 0x6b, 0x74, 0x6f, 0x70, 0x2e, /* desktop. */
//    0x72, 0x65, 0x73, 0x6f, 0x6c, 0x76, 0x65, 0x31, /* resolve1 */
//    0x2e, 0x4d, 0x61, 0x6e, 0x61, 0x67, 0x65, 0x72, /* .Manager */
//    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
//    0x03, 0x01, 0x73, 0x00, 0x00, 0x00, 0x00, 0x0f, /* ..s..... */
//    0x52, 0x65, 0x67, 0x69, 0x73, 0x74, 0x65, 0x72, /* Register */
//    0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x00, /* Service. */
//    0x06, 0x01, 0x73, 0x00, 0x00, 0x00, 0x00, 0x18, /* ..s..... */
//    0x6f, 0x72, 0x67, 0x2e, 0x66, 0x72, 0x65, 0x65, /* org.free */
//    0x64, 0x65, 0x73, 0x6b, 0x74, 0x6f, 0x70, 0x2e, /* desktop. */
//    0x72, 0x65, 0x73, 0x6f, 0x6c, 0x76, 0x65, 0x31, /* resolve1 */
//    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
//    0x08, 0x01, 0x67, 0x00, 0x0d, 0x73, 0x73, 0x73, /* ..g..sss */
//    0x71, 0x71, 0x71, 0x61, 0x61, 0x7b, 0x73, 0x61, /* qqqaa{sa */
//    0x79, 0x7d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* y}...... */
//    0x07, 0x01, 0x73, 0x00, 0x00, 0x00, 0x00, 0x06, /* ..s..... */
//    0x3a, 0x31, 0x2e, 0x32, 0x39, 0x35, 0x00, 0x00, /* :1.295.. */
//    0x00, 0x00, 0x00, 0x05, 0x74, 0x65, 0x73, 0x74, /* ....test */
//    0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, /* 2....... */
//    0x25, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, /* %m...... */
//    0x5f, 0x68, 0x74, 0x74, 0x70, 0x2e, 0x5f, 0x74, /* _http._t */
//    0x63, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* cp...... */
//    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, /* ........ */
//    0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x00, /* ........ */
//    0x00, 0x00, 0x00, 0x04, 0x6b, 0x65, 0x79, 0x31, /* ....key1 */
//    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, /* ........ */
//    0x76, 0x61, 0x6c, 0x75, 0x65, 0x31              /* value1 */
//    };

//    /* Frame (286 bytes) */
//    static const unsigned char gdbus_packet[286] = {
//    0x6c, 0x01, 0x00, 0x01, 0x4e, 0x00, 0x00, 0x00, /* l...N... */
//    0x03, 0x00, 0x00, 0x00, 0xbf, 0x00, 0x00, 0x00, /* ........ */
//    0x01, 0x01, 0x6f, 0x00, 0x19, 0x00, 0x00, 0x00, /* ..o..... */
//    0x2f, 0x6f, 0x72, 0x67, 0x2f, 0x66, 0x72, 0x65, /* /org/fre */
//    0x65, 0x64, 0x65, 0x73, 0x6b, 0x74, 0x6f, 0x70, /* edesktop */
//    0x2f, 0x72, 0x65, 0x73, 0x6f, 0x6c, 0x76, 0x65, /* /resolve */
//    0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 1....... */
//    0x02, 0x01, 0x73, 0x00, 0x20, 0x00, 0x00, 0x00, /* ..s. ... */
//    0x6f, 0x72, 0x67, 0x2e, 0x66, 0x72, 0x65, 0x65, /* org.free */
//    0x64, 0x65, 0x73, 0x6b, 0x74, 0x6f, 0x70, 0x2e, /* desktop. */
//    0x72, 0x65, 0x73, 0x6f, 0x6c, 0x76, 0x65, 0x31, /* resolve1 */
//    0x2e, 0x4d, 0x61, 0x6e, 0x61, 0x67, 0x65, 0x72, /* .Manager */
//    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
//    0x06, 0x01, 0x73, 0x00, 0x18, 0x00, 0x00, 0x00, /* ..s..... */
//    0x6f, 0x72, 0x67, 0x2e, 0x66, 0x72, 0x65, 0x65, /* org.free */
//    0x64, 0x65, 0x73, 0x6b, 0x74, 0x6f, 0x70, 0x2e, /* desktop. */
//    0x72, 0x65, 0x73, 0x6f, 0x6c, 0x76, 0x65, 0x31, /* resolve1 */
//    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
//    0x08, 0x01, 0x67, 0x00, 0x0d, 0x73, 0x73, 0x73, /* ..g..sss */
//    0x71, 0x71, 0x71, 0x61, 0x61, 0x7b, 0x73, 0x61, /* qqqaa{sa */
//    0x79, 0x7d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* y}...... */
//    0x03, 0x01, 0x73, 0x00, 0x0f, 0x00, 0x00, 0x00, /* ..s..... */
//    0x52, 0x65, 0x67, 0x69, 0x73, 0x74, 0x65, 0x72, /* Register */
//    0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x00, /* Service. */
//    0x07, 0x01, 0x73, 0x00, 0x06, 0x00, 0x00, 0x00, /* ..s..... */
//    0x3a, 0x31, 0x2e, 0x32, 0x39, 0x37, 0x00, 0x00, /* :1.297.. */
//    0x05, 0x00, 0x00, 0x00, 0x74, 0x65, 0x73, 0x74, /* ....test */
//    0x32, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, /* 2....... */
//    0x25, 0x6d, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, /* %m...... */
//    0x5f, 0x68, 0x74, 0x74, 0x70, 0x2e, 0x5f, 0x74, /* _http._t */
//    0x63, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* cp...... */
//    0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, /* ........ */
//    0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
//    0x04, 0x00, 0x00, 0x00, 0x6b, 0x65, 0x79, 0x31, /* ....key1 */
//    0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, /* ........ */
//    0x76, 0x61, 0x6c, 0x75, 0x65, 0x31              /* value1 */
//    };

//    std::shared_ptr<DBus::Message> cxx = DBus::Message::create_from_data((unsigned char*)dbuscxx_packet, sizeof(dbuscxx_packet));
//    std::shared_ptr<DBus::Message> gdbus = DBus::Message::create_from_data((unsigned char*)gdbus_packet, sizeof(gdbus_packet));

//    std::cout << "headers:\n";
//    compareMessages(cxx, gdbus);
//    std::cout << "\n";

//    std::cout << "data cxx:\n";
//    std::string cxx_name;
//    std::string cxx_name_template;
//    std::string cxx_type;
//    uint16_t cxx_service_port;
//    uint16_t cxx_service_priority;
//    uint16_t cxx_service_weight;
//    std::vector<std::map<std::string, std::vector<uint8_t>>> cxx_txt_data;

//    cxx >> cxx_name >> cxx_name_template >> cxx_type >> cxx_service_port >> cxx_service_priority >> cxx_service_weight >> cxx_txt_data;
//    std::cout << "  cxx name: " << cxx_name << "\n";
//    std::cout << "  cxx name template: " << cxx_name_template << "\n";
//    std::cout << "  cxx type: " << cxx_type << "\n";
//    std::cout << "  cxx service port: " << cxx_service_port << "\n";
//    std::cout << "  cxx service priority: " << cxx_service_priority << "\n";
//    std::cout << "  cxx service weight: " << cxx_service_weight << "\n";
//    std::cout << "  txt data:\n";
//    for(auto& vec_entry : cxx_txt_data){
//        for(auto& map_entry : vec_entry){
//            std::cout << "    " << map_entry.first << " : ";
//            for(int x = 0; x < map_entry.second.size(); x++){
//                std::cout << map_entry.second[x] << " ";
//            }
//            std::cout << "\n";
//        }
//    }
//    //----------------------
//    std::cout << "data gdbus:\n";
//    std::string gdbus_name;
//    std::string gdbus_name_template;
//    std::string gdbus_type;
//    uint16_t gdbus_service_port;
//    uint16_t gdbus_service_priority;
//    uint16_t gdbus_service_weight;
//    std::vector<std::map<std::string, std::vector<uint8_t>>> gdbus_txt_data;

//    gdbus >> gdbus_name >> gdbus_name_template >> gdbus_type >> gdbus_service_port >> gdbus_service_priority >> gdbus_service_weight >> gdbus_txt_data;
//    std::cout << "  gdbus name: " << gdbus_name << "\n";
//    std::cout << "  gdbus name template: " << gdbus_name_template << "\n";
//    std::cout << "  gdbus type: " << gdbus_type << "\n";
//    std::cout << "  gdbus service port: " << gdbus_service_port << "\n";
//    std::cout << "  gdbus service priority: " << gdbus_service_priority << "\n";
//    std::cout << "  gdbus service weight: " << gdbus_service_weight << "\n";
//    std::cout << "  txt data:\n";
//    for(auto& vec_entry : gdbus_txt_data){
//        for(auto& map_entry : vec_entry){
//            std::cout << "    " << map_entry.first << " : ";
//            for(int x = 0; x < map_entry.second.size(); x++){
//                std::cout << map_entry.second[x] << " ";
//            }
//            std::cout << "\n";
//        }
//    }

	return 0;
}
