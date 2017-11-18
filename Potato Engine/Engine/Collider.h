#ifndef H_COLLIDER
#define H_COLLIDER

#include "Component.h"
#include "Reference.h"
#include "Vector2.h"
struct CollisionInfo;


class Collider :
	public Component
{
	friend class CollidersManager;

public:
	Collider();
	virtual ~Collider() = 0;

	Vector2 getLocalPosition();
	Vector2 getWorldPosition();
	float getWorldRotation();

	// Callbacks to reroute to Behaviours
	void onCollision(CollisionInfo info);
	void onTriggerEnter(Reference<Collider> other);
	void onTriggerStay(Reference<Collider> other);
	void onTriggerExit(Reference<Collider> other);

	Vector2 offset;
	bool isStatic;
	bool isTrigger;
};


#endif // !H_COLLIDER
