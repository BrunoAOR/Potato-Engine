#ifndef H_COMPONENT
#define H_COMPONENT

#include "Reference.h"
class GameObject;
enum class ComponentType;


class Component
{
	friend class ComponentsManager;
	friend class ComponentManager;

public:
	virtual ~Component() = 0;
	
	Reference<GameObject>& gameObject();
	void setActive(bool activeState);
	bool isActive();

protected:
	Component();

	ComponentType type;

private:
	// TESTING FIELDS START
	static int s_alive;
	static int s_nextId;
	int m_id;
	// TESTING FIELDS END

	Reference<GameObject> m_gameObject;
	bool m_isActive;
};


#endif // !H_COMPONENT
