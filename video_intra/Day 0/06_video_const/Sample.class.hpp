#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:
	
	float const m_pi;
	int m_qd;

	Sample( float const f );
	~Sample( void );

	void bar( void ) const;

};

#endif