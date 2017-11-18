#include "TriggerCollisionCache.h"

#include "EngineUtils.h"
#include "Collider.h"


bool TriggerCollisionCache::cache(CollidersPair collPair)
{
	if (indexOf(registeredCollPairs, collPair) != -1)
	{
		return false;
	}

	registeredCollPairs.push_back(collPair);
	return (indexOf(collPairs, collPair) == -1);
}


void TriggerCollisionCache::refresh()
{
	// We'll go through all the collPairs
	// If a pair is found in collPairs, but not in registeredCollPairs, 
	// then that pair is no longer in collision, so OnTriggerExit should be called for both Colliders
	for (unsigned int mainIndex = 0; mainIndex < collPairs.size(); ++mainIndex)
	{
		CollidersPair pair = collPairs[mainIndex];
		int regIndex = indexOf(registeredCollPairs, pair);
		if (regIndex == -1)
		{
			auto coll1 = pair.first;
			auto coll2 = pair.second;
			if (coll1 && coll2)
			{
				coll1->onTriggerExit(coll2);
				coll2->onTriggerExit(coll1);
			}
		}
	}
	// Now we clear the collPairs and swap with registeredCollPairs to update the list
	collPairs.clear();
	collPairs.swap(registeredCollPairs);
}


int TriggerCollisionCache::indexOf(const std::vector<CollidersPair>& collPairVector, const CollidersPair& collPair)
{
	for (unsigned int i = 0; i < collPairVector.size(); ++i)
	{
		const CollidersPair& pair = collPairVector.at(i);
		if (pair.first == collPair.first && pair.second == collPair.second
			|| pair.first == collPair.second && pair.second == collPair.first)
		{
			return i;
			return true;
		}
	}
	return -1;
}
