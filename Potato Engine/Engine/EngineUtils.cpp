#include "EngineUtils.h"


void EngineUtils::swapValues(double & a, double & b)
{
	double temp = a;
	a = b;
	b = temp;
}


bool EngineUtils::inRange(double value, double a, double b)
{
	if (a > b) {
		swapValues(a, b);
	}
	return (value >= a && value <= b);
}


double EngineUtils::getRangesSeparationDistance(double aMin, double aMax, double bMin, double bMax)
{
	if (aMin > aMax)
	{
		swapValues(aMin, aMax);
	}
	if (bMin > bMax)
	{
		swapValues(bMin, bMax);
	}

	return fmax(bMin - aMax, aMin - bMax);

}


double EngineUtils::clamp(double value, double a, double b)
{
	if (a == b)
	{
		return a;
	}
	if (a > b) {
		swapValues(a, b);
	}
	if (value < a)
	{
		return a;
	}
	if (value > b)
	{
		return b;
	}
	return value;
}


bool EngineUtils::isPointInRect(const Vector2 & rectCenter, const Vector2 & rectSize, const Vector2 & point)
{
	double rectMinX = rectCenter.x - rectSize.x / 2;
	double rectMaxX = rectMinX + rectSize.x;

	double rectMinY = rectCenter.y - rectSize.y / 2;
	double rectMaxY = rectMinY + rectSize.y;

	return inRange(point.x, rectMinX, rectMaxX) && inRange(point.y, rectMinY, rectMaxY);
}


Vector2 EngineUtils::closestPointOnOrientedRectFromPoint(const Vector2& rectCenter, const Vector2& rectSize, const Vector2& point)
{
	double rectMinX = rectCenter.x - rectSize.x / 2;
	double rectMaxX = rectMinX + rectSize.x;

	if (rectMinX > rectMaxX)
	{
		swapValues(rectMinX, rectMaxX);
	}

	double rectMinY = rectCenter.y - rectSize.y / 2;
	double rectMaxY = rectMinY + rectSize.y;

	if (rectMinY > rectMaxY)
	{
		swapValues(rectMinY, rectMaxY);
	}

	Vector2 closestPoint(clamp(point.x, rectMinX, rectMaxX), clamp(point.y, rectMinY, rectMaxY));
	
	// Correct for points that lie inside the rect
	if (inRange(closestPoint.x, rectMinX, rectMaxX) && inRange(closestPoint.y, rectMinY, rectMaxY))
	{
		// Distance to vertical lines is viewed on the x-direction
		double closestDistanceToVerticals = fmin(closestPoint.x - rectMinX, rectMaxX - closestPoint.x);
		
		// Distance to horizontal lines is viewed on the y-direction
		double closestDistanceToHorizontals = fmin(closestPoint.y - rectMinY, rectMaxY - closestPoint.y);

		if (closestDistanceToVerticals < closestDistanceToHorizontals)
		{
			// Push point in the x-direction
			if (closestPoint.x - rectMinX < rectMaxX - closestPoint.x)
			{
				closestPoint.x = rectMinX;
			}
			else
			{
				closestPoint.x = rectMaxX;
			}
		}
		else
		{
			// Push point in the y-direction
			if (closestPoint.y - rectMinY < rectMaxY - closestPoint.y)
			{
				closestPoint.y = rectMinY;
			}
			else
			{
				closestPoint.y = rectMaxY;
			}
		}

	}

	return closestPoint;
}
