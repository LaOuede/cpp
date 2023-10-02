#include <iostream>
#include "Sample.class.hpp"

int main() {

	Sample instance1( 42 );
	Sample instance2( 42 );

	if ( &instance1 == &instance1) // adresses
		std::cout << "instance1 and instance1 are physically equal" << std::endl;
	else
		std::cout << "instance1 and instance1 are NOT physically equal" << std::endl;

	if ( &instance1 == &instance2) // adresses
		std::cout << "instance1 and instance2 are physically equal" << std::endl;
	else
		std::cout << "instance1 and instance2 are NOT physically equal" << std::endl;
	
	if ( instance1.compare( &instance1 ) == 0) // contenu
		std::cout << "instance1 and instance1 are structurally equal" << std::endl;
	else
		std::cout << "instance1 and instance1 are NOT structurally equal" << std::endl;

	if ( instance1.compare( &instance2 ) == 0) // contenu
		std::cout << "instance1 and instance2 are structurally equal" << std::endl;
	else
		std::cout << "instance1 and instance2 are NOT structurally equal" << std::endl;

	return 0;
}