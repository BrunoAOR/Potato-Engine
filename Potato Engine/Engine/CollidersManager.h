#ifndef H_COLLIDERS_MANAGER
#define H_COLLIDERS_MANAGER

#include "ComponentManager.h"
#include "TriggerCollisionCache.h"
#include "Reference.h"
class Vector2;
class CircleCollider;
class RectangleCollider;


class CollidersManager final :
	public ComponentManager
{
	friend class ComponentsManager;

public:
	~CollidersManager();

private:
	CollidersManager();

	// Inherited via ComponentManager
	virtual ComponentType managedComponentType() const override;
	virtual void update() override;
	virtual bool init() override;
	virtual void close() override;
	virtual bool initializeComponent(Reference<Component>& component) override;

	bool checkAndResolveCollision(Reference<Collider> coll1, Reference<Collider> coll2, bool shouldResolve);
	bool checkAndResolveCollision(CircleCollider& circColl1, CircleCollider& circColl2, bool shouldResolve);
	bool checkAndResolveCollision(RectangleCollider& rectColl1, RectangleCollider& rectColl2, bool shouldResolve);
	bool checkAndResolveCollision(CircleCollider& circColl, RectangleCollider& rectColl, bool shouldResolve);
	bool checkAndResolveCollision(RectangleCollider& rectColl, CircleCollider& circColl, bool shouldResolve);

	bool shouldResolveCollision(Reference<Collider> coll1, Reference<Collider> coll2) const;
	void resolveCollision(CircleCollider& circColl1, const Vector2& pos1, CircleCollider& circColl2, const Vector2& pos2, float penetrationDistance);
	void resolveCollision(RectangleCollider& rectColl1, RectangleCollider& rectColl2, Vector2& penetrationVector);
	void resolveCollision(CircleCollider& circColl, RectangleCollider& rectColl, const Vector2& penetrationVector);

	void informCollision(Reference<Collider> coll1, Reference<Collider> coll2);

	const float m_minPenetration = 0.01f;

	TriggerCollisionCache triggerCollisionCache;
};


#endif // !H_COLLIDERS_MANAGER
