#include <iostream>
#include "my_lib.h"

#include "ProjectConfig.h"

#include "loguru.hpp"

#include "cxxopts.hpp"


#ifdef USE_PRINTF
	#define my_print_function printf_hello_world
#else
	#define my_print_function cout_hello_world
#endif

int main(int argc, char** argv){


	std::cout << "Version: "<< PROJECT_VERSION_MAJOR << "." << PROJECT_VERSION_MINOR << "." << PROJECT_VERSION_PATCH << std::endl;
 
	//my_print_function();


	//print_linalg_vector();

	//print_boost_version();

	loguru::init(argc,argv);

	LOG_F(INFO, "Hello from main!");
	LOG_F(ERROR, "Hello error from main!");



	cxxopts::Options options("MyProgram", "One line description of MyProgram");

	options.add_options()
	("d,debug", "Enable debugging") // a bool parameter
	("i,integer", "Int param", cxxopts::value<int>())
	("f,file", "File name", cxxopts::value<std::string>())
	("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"));


	auto result = options.parse(argc, argv);


	if(result.count("debug")){
		bool debug = result["debug"].as<bool>();
		std::cout << "debug " << debug << std::endl; 
	}

	if(result.count("integer")){
		int integer = result["integer"].as<int>();
		std::cout << "integer " << integer << std::endl; 
	}

	if(result.count("file")){
		std::string string = result["file"].as<std::string>();
		std::cout << "string " << string << std::endl; 
	}

	if(result.count("verbose")){
		bool verbose = result["verbose"].as<bool>();
		std::cout << "verbose " << verbose << std::endl; 
	}



	return 0;
}