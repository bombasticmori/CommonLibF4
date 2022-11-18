#pragma once

namespace RE
{
	class NiPoint3
	{
	public:
		using value_type = float;
		using size_type = std::size_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;

		/* reference operator[](size_type a_pos) noexcept
		{
			assert(a_pos < 3);
			return reinterpret_cast<pointer>(std::addressof(x))[a_pos];
		}

		const_reference operator[](size_type a_pos) const noexcept
		{
			assert(a_pos < 3);
			return reinterpret_cast<const_pointer>(std::addressof(x))[a_pos];
		}*/

		float& operator[](std::size_t a_idx)
		{
			assert(a_idx < 3);
			return std::addressof(x)[a_idx];
		}

		const float& operator[](std::size_t a_idx) const
		{
			assert(a_idx < 3);
			return std::addressof(x)[a_idx];
		}

		bool operator==(const NiPoint3& a_rhs) const
		{
			return (x == a_rhs.x && y == a_rhs.y && z == a_rhs.z);
		}

		bool operator!=(const NiPoint3& a_rhs) const
		{
			return !operator==(a_rhs);
		}

		NiPoint3 operator+(const NiPoint3& a_rhs) const
		{
			return NiPoint3(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
		}

		NiPoint3 operator-(const NiPoint3& a_rhs) const
		{
			return NiPoint3(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
		}

		float operator*(const NiPoint3& a_rhs) const
		{
			return x * a_rhs.x + y * a_rhs.y + z * a_rhs.z;
		}

		NiPoint3 operator*(float a_scalar) const
		{
			return NiPoint3(x * a_scalar, y * a_scalar, z * a_scalar);
		}

		NiPoint3 operator/(float a_scalar) const
		{
			return operator*(1.0F / a_scalar);
		}

		NiPoint3 operator-() const
		{
			return NiPoint3(-x, -y, -z);
		}

		NiPoint3& operator+=(const NiPoint3& a_rhs)
		{
			x += a_rhs.x;
			y += a_rhs.y;
			z += a_rhs.z;
			return *this;
		}

		NiPoint3& operator-=(const NiPoint3& a_rhs)
		{
			x -= a_rhs.x;
			y -= a_rhs.y;
			z -= a_rhs.z;
			return *this;
		}

		NiPoint3& operator*=(const NiPoint3& a_rhs)
		{
			x *= a_rhs.x;
			y *= a_rhs.y;
			z *= a_rhs.z;
			return *this;
		}

		NiPoint3& operator/=(const NiPoint3& a_rhs)
		{
			x /= a_rhs.x;
			y /= a_rhs.y;
			z /= a_rhs.z;
			return *this;
		}

		NiPoint3& operator*=(float a_scalar)
		{
			x *= a_scalar;
			y *= a_scalar;
			z *= a_scalar;
			return *this;
		}

		NiPoint3& operator/=(float a_scalar)
		{
			return operator*=(1.0F / a_scalar);
		}

		NiPoint3 Cross(const NiPoint3& a_pt) const
		{
			return NiPoint3(
				y * a_pt.z - z * a_pt.y,
				z * a_pt.x - x * a_pt.z,
				x * a_pt.y - y * a_pt.x);
		}

		float Dot(const NiPoint3& a_pt) const
		{
			return x * a_pt.x + y * a_pt.y + z * a_pt.z;
		}

		float GetDistance(const NiPoint3& a_pt) const noexcept
		{
			return std::sqrtf(GetSquaredDistance(a_pt));
		}

		float GetSquaredDistance(const NiPoint3& a_pt) const noexcept
		{
			const float dx = a_pt.x - x;
			const float dy = a_pt.y - y;
			const float dz = a_pt.z - z;
			return dx * dx + dy * dy + dz * dz;
		}

		float Length() const
		{
			return std::sqrtf(x * x + y * y + z * z);
		}

		float SqrLength() const
		{
			return x * x + y * y + z * z;
		}

		NiPoint3 UnitCross(const NiPoint3& a_pt) const
		{
			auto cross = Cross(a_pt);
			cross.Unitize();
			return cross;
		}

		 float Unitize()
		{
			auto length = Length();
			if (length == 1.f) {
				return length;
			} else if (length > FLT_EPSILON) {
				operator/=(length);
			} else {
				x = 0.0;
				y = 0.0;
				z = 0.0;
				length = 0.0;
			}
			return length;
		}

		// members
		value_type x{ 0.0F };  // 0
		value_type y{ 0.0F };  // 4
		value_type z{ 0.0F };  // 8
	};
	static_assert(sizeof(NiPoint3) == 0xC);

	class alignas(0x10) NiPoint3A :
		public NiPoint3
	{
	public:
	};
	static_assert(sizeof(NiPoint3A) == 0x10);
}
