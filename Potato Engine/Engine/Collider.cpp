#include "Collider.h"

#include "GameObject.h"
#include "Transform.h"
#include "Behaviour.h"
#include "ComponentType.h"
#include "CollisionInfo.h"


Collider::Collider() : offset(0, 0), isStatic(false), isTrigger(false)
{
	m_type = ComponentType::COLLIDER;
}


Collider::~Collider()
{
}


Vector2 Collider::getLocalScaledOffset() const
{
	Vector2 localScale = gameObject()->transform->getLocalScale();
	Vector2 scaledOffset = offset;
	scaledOffset.x *= localScale.x;
	scaledOffset.y *= localScale.y;
	return scaledOffset;
}


Vector2 Collider::getWorldScaledOffset() const
{
	Vector2 worldScale = gameObject()->transform->getWorldScale();
	Vector2 scaledOffset = offset;
	scaledOffset.x *= worldScale.x;
	scaledOffset.y *= worldScale.y;
	return scaledOffset;
}


Vector2 Collider::getLocalPosition() const
{
	return gameObject()->transform->getLocalPosition() + offset;
}


Vector2 Collider::getWorldPosition() const
{
	return gameObject()->transform->getWorldPosition() + offset;
}


float Collider::getWorldRotation() const
{
	return gameObject()->transform->getWorldRotation();
}


void Collider::onCollision(CollisionInfo& info) const
{
	auto behaviours = gameObject()->getComponents<Behaviour>();
	for (Reference<Behaviour>& behaviourRef : behaviours)
	{
		if (behaviourRef)
		{
			behaviourRef->onCollision(info);
		}
	}
}


void Collider::onTriggerEnter(Reference<Collider>& other) const
{
	auto behaviours = gameObject()->getComponents<Behaviour>();
	for (Reference<Behaviour>& behaviourRef : behaviours)
	{
		if (behaviourRef)
		{
			behaviourRef->onTriggerEnter(other);
		}
	}
}


void Collider::onTriggerStay(Reference<Collider>& other) const
{
	auto behaviours = gameObject()->getComponents<Behaviour>();
	for (Reference<Behaviour>& behaviourRef : behaviours)
	{
		if (behaviourRef)
		{
			behaviourRef->onTriggerStay(other);
		}
	}
}


void Collider::onTriggerExit(Reference<Collider>& other) const
{
	auto behaviours = gameObject()->getComponents<Behaviour>();
	for (Reference<Behaviour>& behaviourRef : behaviours)
	{
		if (behaviourRef)
		{
			behaviourRef->onTriggerExit(other);
		}
	}
}
