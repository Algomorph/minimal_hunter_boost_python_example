#include <boost/python.hpp>

char const* greet()
{
   return "hello, world";
}
class World {
public:
	void set(std::string msg) { this->msg = msg; }
	std::string greet() { return msg; }
	std::string msg;
};
BOOST_PYTHON_MODULE(hello_ext)
{
    using namespace boost::python;
	class_<World>("World")
		.def("greet", &World::greet)
		.def("set", &World::set)
		; 
    def("greet", greet);
}
