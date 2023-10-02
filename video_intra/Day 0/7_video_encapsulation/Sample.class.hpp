#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:
	
	int m_publicFoo;

	Sample( void );
	~Sample( void );

	void publicBar( void ) const;

private:

	int _m_privateFoo;
	void _privateBar( void ) const;

};

#endif