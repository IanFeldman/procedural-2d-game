#include "component.h"
#include "actor.h"

Component::Component(Actor* owner, int updateOrder)
	:mOwner(owner)
	,mUpdateOrder(updateOrder)
{
	mOwner->AddComponent(this);
}

Component::~Component()
{
}

void Component::Update(float deltaTime)
{
}
