#include <iostream>
#include <stdio.h>
#include "my_lib.h"
#include "linalg.h"
#include "boost/version.hpp"


void printf_hello_world(){
	printf("Hallo Welt 5 Better Project Structure from print\n");
}


void cout_hello_world(){
	std::cout << "Hallo Welt 3 Better Project Structure from cout" << std::endl;
}


void print_linalg_vector(){
	linalg::aliases::float3 my_float3 {1,2,3};

	std::cout << "Vec: " << my_float3[0] << ", " << my_float3[1] << ", " << my_float3[2] << std::endl;

}

void print_boost_version(){
	std::cout << "Boost Version: " << BOOST_VERSION << " " << std::endl;
}

std::int32_t compute_avarage(std::int32_t a, std::int32_t b){
	return (a + b) / 2;
}