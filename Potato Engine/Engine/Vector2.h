#ifndef H_VECTOR2
#define H_VECTOR2


class Vector2 final
{
	friend Vector2 operator- (const Vector2& v2);
	friend Vector2 operator+ (Vector2 lhs, const Vector2& rhs);
	friend Vector2 operator- (Vector2 lhs, const Vector2& rhs);
	friend Vector2 operator* (double num, const Vector2& v2);
	friend Vector2 operator/ (double num, const Vector2& v2);
	friend Vector2 operator* (Vector2 v2, double num);
	friend Vector2 operator/ (Vector2 v2, double num);
	friend bool operator== (const Vector2& v1, const Vector2& v2);
	friend bool operator!= (const Vector2& v1, const Vector2& v2);

public:
	Vector2();
	Vector2(double x, double y);

	double getLength() const;
	double getLengthSquared() const;
	Vector2 normalized() const;
	void normalize();
	void rotateCCWDegrees(double degrees);
	void rotateCCWRadians(double radians);

	Vector2& operator+= (const Vector2& rhs);
	Vector2& operator-= (const Vector2& rhs);
	Vector2& operator*= (double num);
	Vector2& operator/= (double num);

	static double distance(const Vector2& lhs, const Vector2& rhs);
	static double dot(const Vector2& lhs, const Vector2& rhs);

	double x;
	double y;
};


#endif // !H_VECTOR2
