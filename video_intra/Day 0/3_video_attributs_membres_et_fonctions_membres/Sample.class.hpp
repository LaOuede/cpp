#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

	int foo; // attribut membre

	Sample( void ); // permet de déclarer un constructeur
	~Sample( void ); // permet de déclarer un destructeur

	void bar(); // fonction membre
};

#endif