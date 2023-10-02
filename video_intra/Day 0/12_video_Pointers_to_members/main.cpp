#include <iostream>
#include "Sample.class.hpp"

int main() {

	Sample instance;
	Sample *instancep = &instance; // déclaration d'un pointeur à qui on assigne l'adresse de la variable instance

	int Sample::*p = NULL; // on déclare un pointeur sur un entier qui est membre de la classe Sample
	void (Sample::*f)( void ) const; // on déclare un pointeur sur une fonction;

	p = &Sample::m_Foo; // on assigne l'adresse du membre Foo au pointeur;
	std::cout << "Value of member foo: " << instance.m_Foo << std::endl;
	instance.*p = 21; // utilisation de .* pour spécifier quelle instance
	std::cout << "Value of member foo: " << instance.m_Foo << std::endl;
	instancep->*p = 42; // même chose qu'au dessus mais pour un pointeur
	std::cout << "Value of member foo: " << instance.m_Foo << std::endl;

	f = &Sample::Bar; // pointeur f pointe vers fonction membre Bar de la classe
	(instance.*f)(); // on utilise directement la variable instance déclarer plus hau
	(instancep->*f)(); // on utilise un pointeur sur fonction membre
	
	return 0;
}