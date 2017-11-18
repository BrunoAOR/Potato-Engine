#ifndef H_BEHAVIOUR
#define H_BEHAVIOUR

#include "Component.h"
#include "Reference.h"


class Behaviour :
	public Component
{
	friend class BehavioursManager;

public:	
	Behaviour();
	virtual ~Behaviour() = 0;

	// Defining methods for behaviours to implement
	// Lifecycle related
	virtual void awake();
	virtual void start();
	virtual void update();

private:
	bool m_isAwake;
	bool m_started;
};


#endif // !H_BEHAVIOUR
