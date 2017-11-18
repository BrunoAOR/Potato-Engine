#include "Collider.h"

#include "GameObject.h"
#include "Transform.h"
#include "Behaviour.h"
#include "ComponentType.h"
#include "CollisionInfo.h"


Collider::Collider() : offset(0, 0), isStatic(false), isTrigger(false)
{
	type = ComponentType::Collider;
}


Collider::~Collider()
{
}


Vector2 Collider::getLocalPosition()
{
	auto transform = gameObject()->transform;
	Vector2 localPos = transform->getLocalPosition() + offset;
	return localPos;
}


Vector2 Collider::getWorldPosition()
{
	auto transform = gameObject()->transform;
	Vector2 worldPos = transform->getLocalPosition() + offset;
	worldPos = transform->localToWorldPosition(worldPos);
	return worldPos;
}


float Collider::getWorldRotation()
{
	return gameObject()->transform->getWorldRotation();
}


void Collider::onCollision(CollisionInfo info)
{
	auto behaviours = gameObject()->getComponents<Behaviour>();
	for (auto behaviourRef : behaviours)
	{
		if (behaviourRef)
		{
			behaviourRef->onCollision(info);
		}
	}
}


void Collider::onTriggerEnter(Reference<Collider> other)
{
	auto behaviours = gameObject()->getComponents<Behaviour>();
	for (auto behaviourRef : behaviours)
	{
		if (behaviourRef)
		{
			behaviourRef->onTriggerEnter(other);
		}
	}
}


void Collider::onTriggerStay(Reference<Collider> other)
{
	auto behaviours = gameObject()->getComponents<Behaviour>();
	for (auto behaviourRef : behaviours)
	{
		if (behaviourRef)
		{
			behaviourRef->onTriggerStay(other);
		}
	}
}


void Collider::onTriggerExit(Reference<Collider> other)
{
	auto behaviours = gameObject()->getComponents<Behaviour>();
	for (auto behaviourRef : behaviours)
	{
		if (behaviourRef)
		{
			behaviourRef->onTriggerExit(other);
		}
	}
}
