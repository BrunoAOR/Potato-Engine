#ifndef H_ENGINE_UTILS
#define H_ENGINE_UTILS

#include <vector>
#include "Vector2.h"
#include "ReferenceOwner.h"


namespace EngineUtils
{
	void swapValues(double& a, double& b);
	bool inRange(double value, double a, double b);
	double getRangesSeparationDistance(double aMin, double aMax, double bMin, double bMax);
	double clamp(double value, double a, double b);
	bool isPointInRect(const Vector2& rectCenter, const Vector2& rectSize, const Vector2& point);
	Vector2 closestPointOnOrientedRectFromPoint(const Vector2& rectCenter, const Vector2& rectSize, const Vector2& point);

	
	template <typename T>
	int indexOf(const std::vector<T>& vector, const T& element)
	{
		auto iterator = std::find(vector.begin(), vector.end(), element);

		if (iterator == vector.end())
		{
			return -1;
		}
		else
		{
			return std::distance(vector.begin(), iterator);
		}
	}


	template <typename T, typename U>
	int indexOf(const std::vector<ReferenceOwner<T>>& vector, const Reference<U>& element)
	{
		auto iterator = vector.begin();

		for (; iterator != vector.end(); ++iterator)
		{
			if (*iterator == element)
			{
				break;
			}
		}

		if (iterator == vector.end())
		{
			return -1;
		}
		else
		{
			return std::distance(vector.begin(), iterator);
		}
	}

}


#endif // !H_ENGINE_UTILS
