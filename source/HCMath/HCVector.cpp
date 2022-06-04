
#include <math.h>
#include <cassert>

#include "HCVector.h"

#pragma region FloatingPointVectors
#pragma region Vec2

inline Vec2::Vec2() : x(0.0f), y(0.0f) {}
inline Vec2::Vec2(float _x, float _y) : x(_x), y(_y) {}
inline Vec2::Vec2(const Vec2& _other) { (*this) = _other; }

inline Vec2& Vec2::operator=(const Vec2& _other) {
	if (this != &_other) {
		this->x = _other.x;
		this->y = _other.y;
	}
	return *this;
}

inline Vec2& Vec2::operator+=(const Vec2& _other) {
	*this = *this + _other;
	return *this;
}

inline Vec2& Vec2::operator-=(const Vec2& _other) {
	*this = *this - _other;
	return *this;
}

inline Vec2& Vec2::operator*=(const float _scale) {
	*this = *this * _scale;
	return *this;
}

inline float& Vec2::operator[](int _ndx) {
	assert(_ndx < 2);
	return xy[_ndx];
}

inline float Vec2::operator[](int _ndx) const {
	assert(_ndx < 2);
	return xy[_ndx];
}

inline Vec2 Vec2::operator+(const Vec2& _other) const {
	return Vec2(this->x + _other.x, this->y + _other.y);
}

inline Vec2 Vec2::operator-(const Vec2& _other) const {
	return Vec2(this->x - _other.x, this->y - _other.y);
}

inline Vec2 Vec2::operator*(const float _scale) const {
	return Vec2(this->x * _scale, this->y * _scale);
}

inline float Vec2::operator*(const Vec2& _other) const {
	return (this->x * _other.x) + (this->y * _other.y);
}

inline float Vec2::operator&(const Vec2& _other) const {
	return (this->x * _other.y) - (this->y * _other.x);
}

inline Vec2 Vec2::operator~() const {
	return Vec2();
}

inline Vec2 Vec2::operator-() const {
	return Vec2(-this->x, -this->y);
}

inline bool Vec2::operator==(const Vec2& _other) const {
	return this->x == _other.x && this->y == _other.y;
}

inline bool Vec2::operator<(const Vec2& _other) const {
	return this->LengthSquared() < _other.LengthSquared();
}

inline bool Vec2::operator>(const Vec2& _other) const {
	return this->LengthSquared() > _other.LengthSquared();
}

inline bool Vec2::operator<=(const Vec2& _other) const {
	return this->LengthSquared() <= _other.LengthSquared();
}

inline bool Vec2::operator>=(const Vec2& _other) const {
	return this->LengthSquared() >= _other.LengthSquared();
}

inline bool Vec2::operator!=(const Vec2& _other) const {
	return this->x != _other.x || this->y != _other.y;
}

inline float Vec2::Length() const {
	return sqrtf((*this) * (*this));
}

inline float Vec2::LengthSquared() const {
	return (*this) * (*this);
}

inline void Vec2::Normalize() {
	float len = Length();
	if (!len) return;

	this->x /= len;
	this->y /= len;
}

inline Vec2 Vec2::Normalized() const {
	float len = Length();
	if (!len) return Vec2();

	return Vec2(this->x / len, this->x / len);
}

inline float Vec2::AngleBetween(const Vec2& _other) const {
	return acosf(this->Normalized() * _other.Normalized());
}

inline float Vec2::Dot(const Vec2& _other) const {
	return *this * _other;
}

inline float Vec2::Cross(const Vec2& _other) const {
	return *this & _other;
}

inline void Vec2::Add(const Vec2& _other) {
	*this += _other;
}

inline void Vec2::Subtract(const Vec2& _other) {
	*this -= _other;
}

inline void Vec2::Scale(const float _scale) {
	*this *= _scale;
}

inline void Vec2::Zero() {
	*this = ~(*this);
}

inline void Vec2::Negate() {
	*this = -(*this);
}

inline bool Vec2::Equals(const Vec2& _other) const {
	return *this == _other;
}

inline bool Vec2::Less(const Vec2& _other) const {
	return *this < _other;
}

inline bool Vec2::LessThanOrEquals(const Vec2& _other) const {
	return *this <= _other;
}

inline bool Vec2::Greater(const Vec2& _other) const {
	return *this > _other;
}

inline bool Vec2::GreaterThanOrEquals(const Vec2& _other) const {
	return *this >= _other;
}

inline bool Vec2::NotEquals(const Vec2& _other) const {
	return *this != _other;
}

inline float& Vec2::X() { return this->x; }
inline float& Vec2::Y() { return this->y; }
inline float Vec2::X() const { return this->x; }
inline float Vec2::Y() const { return this->y; }

inline Vec2 Vec2::XX() const { return Vec2(this->x, this->x); }
inline Vec2 Vec2::YY() const { return Vec2(this->y, this->y); }
inline Vec2 Vec2::YX() const { return Vec2(this->y, this->x); }
inline Vec2 Vec2::RR() const { return Vec2(this->x, this->x); }
inline Vec2 Vec2::GG() const { return Vec2(this->y, this->y); }
inline Vec2 Vec2::GR() const { return Vec2(this->y, this->x); }

#pragma endregion

#pragma region Vec3

inline Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
inline Vec3::Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
inline Vec3::Vec3(const Vec2& _xy, float _z) : x(_xy.X()), y(_xy.Y()), z(_z) {}
inline Vec3::Vec3(float _x, const Vec2& _yz) : x(_x), y(_yz.X()), z(_yz.Y()) {}
inline Vec3::Vec3(const Vec3& _other) { *this = _other; }

inline Vec3& Vec3::operator=(const Vec3& _other) {
	if (this != &_other) {
		this->x = _other.x;
		this->y = _other.y;
		this->z = _other.z;
	}
	return *this;
}

inline Vec3& Vec3::operator+=(const Vec3& _other) {
	*this = *this + _other;
	return *this;
}

inline Vec3& Vec3::operator-=(const Vec3& _other) {
	*this = *this - _other;
	return *this;
}

inline Vec3& Vec3::operator*=(const float _scale) {
	*this = *this * _scale;
	return *this;
}

inline Vec3& Vec3::operator&=(const Vec3& _other) {
	*this = *this & _other;
	return *this;
}

inline float& Vec3::operator[](int _ndx) {
	assert(_ndx < 3);
	return xyz[_ndx];
}

inline float Vec3::operator[](int _ndx) const {
	assert(_ndx < 3);
	return xyz[_ndx];
}

inline Vec3 Vec3::operator+(const Vec3& _other) const {
	return Vec3(this->x + _other.x, this->y + _other.y, this->z + _other.z);
}

inline Vec3 Vec3::operator-(const Vec3& _other) const {
	return Vec3(this->x - _other.x, this->y - _other.y, this->z - _other.z);
}

inline Vec3 Vec3::operator*(const float _scale) const {
	return Vec3(this->x * _scale, this->y * _scale, this->z * _scale);
}

inline float Vec3::operator*(const Vec3& _other) const {
	return (this->x * _other.x) + (this->y * _other.y) + (this->z * _other.z);
}

inline Vec3 Vec3::operator&(const Vec3& _other) const {
	return Vec3((this->y * _other.z) - (this->z * _other.y), (this->x * _other.z) - (this->z * _other.x), (this->x * _other.y) - (this->y * _other.x));
}

inline Vec3 Vec3::operator~() const {
	return Vec3(0.0f, 0.0f, 0.0f);
}

inline Vec3 Vec3::operator-() const {
	return Vec3(-this->x, -this->y, -this->z);
}

inline bool Vec3::operator==(const Vec3& _other) const {
	return this->x == _other.x && this->y == _other.y && this->z == _other.z;
}

inline bool Vec3::operator<(const Vec3& _other) const {
	return this->LengthSquared() < _other.LengthSquared();
}

inline bool Vec3::operator>(const Vec3& _other) const {
	return this->LengthSquared() > _other.LengthSquared();
}

inline bool Vec3::operator<=(const Vec3& _other) const {
	return this->LengthSquared() <= _other.LengthSquared();
}

inline bool Vec3::operator>=(const Vec3& _other) const {
	return this->LengthSquared() >= _other.LengthSquared();
}

inline bool Vec3::operator!=(const Vec3& _other) const {
	return this->x != _other.x || this->y != _other.y || this->z != _other.z;
}

inline float Vec3::Length() const {
	return sqrtf((*this) * (*this));
}

inline float Vec3::LengthSquared() const {
	return (*this) * (*this);
}

inline void Vec3::Normalize() {
	float len = Length();
	if (!len) return;

	this->x /= len;
	this->y /= len;
	this->z /= len;
}

inline Vec3 Vec3::Normalized() const {
	float len = Length();
	if (!len) return Vec3();

	return Vec3(this->x / len, this->y / len, this->z / len);
}

inline float Vec3::AngleBetween(const Vec3& _other) const {
	return acosf(this->Normalized() * _other.Normalized());
}

inline float Vec3::Dot(const Vec3& _other) const {
	return *this * _other;
}

inline void Vec3::Cross(const Vec3& _other) {
	*this &= _other;
}

inline void Vec3::Add(const Vec3& _other) {
	*this += _other;
}

inline void Vec3::Subtract(const Vec3& _other) {
	*this -= _other;
}

inline void Vec3::Scale(const float _scale) {
	*this *= _scale;
}

inline void Vec3::Negate() {
	*this = -(*this);
}

inline void Vec3::Zero() {
	*this = ~(*this);
}

inline bool Vec3::Equals(const Vec3& _other) const {
	return *this == _other;
}

inline bool Vec3::Less(const Vec3& _other) const {
	return *this < _other;
}

inline bool Vec3::LessThanOrEquals(const Vec3& _other) const {
	return *this <= _other;
}

inline bool Vec3::Greater(const Vec3& _other) const {
	return *this > _other;
}

inline bool Vec3::GreaterThanOrEquals(const Vec3& _other) const {
	return *this >= _other;
}

inline bool Vec3::NotEquals(const Vec3& _other) const {
	return *this != _other;
}

inline float& Vec3::X() { return this->x; }
inline float& Vec3::Y() { return this->y; }
inline float& Vec3::Z() { return this->z; }
inline float Vec3::X() const { return this->x; }
inline float Vec3::Y() const { return this->y; }
inline float Vec3::Z() const { return this->z; }

//Vec2 Swizzle
inline Vec2 Vec3::XX() const { return Vec2(this->x, this->x); }
inline Vec2 Vec3::YY() const { return Vec2(this->y, this->y); }
inline Vec2 Vec3::ZZ() const { return Vec2(this->z, this->z); }
inline Vec2 Vec3::XY() const { return Vec2(this->x, this->y); }
inline Vec2 Vec3::XZ() const { return Vec2(this->x, this->z); }
inline Vec2 Vec3::YX() const { return Vec2(this->y, this->x); }
inline Vec2 Vec3::YZ() const { return Vec2(this->y, this->z); }
inline Vec2 Vec3::ZX() const { return Vec2(this->z, this->x); }
inline Vec2 Vec3::ZY() const { return Vec2(this->z, this->y); }
inline Vec2 Vec3::RR() const { return Vec2(this->x, this->x); }
inline Vec2 Vec3::GG() const { return Vec2(this->y, this->y); }
inline Vec2 Vec3::BB() const { return Vec2(this->z, this->z); }
inline Vec2 Vec3::RG() const { return Vec2(this->x, this->y); }
inline Vec2 Vec3::RB() const { return Vec2(this->x, this->z); }
inline Vec2 Vec3::GR() const { return Vec2(this->y, this->x); }
inline Vec2 Vec3::GB() const { return Vec2(this->y, this->z); }
inline Vec2 Vec3::BR() const { return Vec2(this->z, this->x); }
inline Vec2 Vec3::BG() const { return Vec2(this->z, this->y); }

//Vec3 Swizzle
inline Vec3 Vec3::XXX() const { return Vec3(this->x, this->x, this->x); }
inline Vec3 Vec3::XXY() const { return Vec3(this->x, this->x, this->y); }
inline Vec3 Vec3::XXZ() const { return Vec3(this->x, this->x, this->z); }
inline Vec3 Vec3::XYX() const { return Vec3(this->x, this->y, this->x); }
inline Vec3 Vec3::XYY() const { return Vec3(this->x, this->y, this->y); }
inline Vec3 Vec3::XZX() const { return Vec3(this->x, this->z, this->x); }
inline Vec3 Vec3::XZY() const { return Vec3(this->x, this->z, this->y); }
inline Vec3 Vec3::XZZ() const { return Vec3(this->x, this->z, this->z); }
inline Vec3 Vec3::YXX() const { return Vec3(this->y, this->x, this->x); }
inline Vec3 Vec3::YXY() const { return Vec3(this->y, this->x, this->y); }
inline Vec3 Vec3::YXZ() const { return Vec3(this->y, this->x, this->z); }
inline Vec3 Vec3::YYX() const { return Vec3(this->y, this->y, this->x); }
inline Vec3 Vec3::YYY() const { return Vec3(this->y, this->y, this->y); }
inline Vec3 Vec3::YYZ() const { return Vec3(this->y, this->y, this->z); }
inline Vec3 Vec3::YZX() const { return Vec3(this->y, this->z, this->x); }
inline Vec3 Vec3::YZY() const { return Vec3(this->y, this->z, this->y); }
inline Vec3 Vec3::YZZ() const { return Vec3(this->y, this->z, this->z); }
inline Vec3 Vec3::ZXX() const { return Vec3(this->z, this->x, this->x); }
inline Vec3 Vec3::ZXY() const { return Vec3(this->z, this->x, this->y); }
inline Vec3 Vec3::ZXZ() const { return Vec3(this->z, this->x, this->z); }
inline Vec3 Vec3::ZYX() const { return Vec3(this->z, this->y, this->x); }
inline Vec3 Vec3::ZYY() const { return Vec3(this->z, this->y, this->y); }
inline Vec3 Vec3::ZYZ() const { return Vec3(this->z, this->y, this->z); }
inline Vec3 Vec3::ZZX() const { return Vec3(this->z, this->z, this->x); }
inline Vec3 Vec3::ZZY() const { return Vec3(this->z, this->z, this->y); }
inline Vec3 Vec3::ZZZ() const { return Vec3(this->z, this->z, this->z); }
inline Vec3 Vec3::RRR() const { return Vec3(this->x, this->x, this->x); }
inline Vec3 Vec3::RRG() const { return Vec3(this->x, this->x, this->y); }
inline Vec3 Vec3::RRB() const { return Vec3(this->x, this->x, this->z); }
inline Vec3 Vec3::RGR() const { return Vec3(this->x, this->y, this->x); }
inline Vec3 Vec3::RGG() const { return Vec3(this->x, this->y, this->y); }
inline Vec3 Vec3::RBR() const { return Vec3(this->x, this->z, this->x); }
inline Vec3 Vec3::RBG() const { return Vec3(this->x, this->z, this->y); }
inline Vec3 Vec3::RBB() const { return Vec3(this->x, this->z, this->z); }
inline Vec3 Vec3::GRR() const { return Vec3(this->y, this->x, this->x); }
inline Vec3 Vec3::GRG() const { return Vec3(this->y, this->x, this->y); }
inline Vec3 Vec3::GRB() const { return Vec3(this->y, this->x, this->z); }
inline Vec3 Vec3::GGR() const { return Vec3(this->y, this->y, this->x); }
inline Vec3 Vec3::GGG() const { return Vec3(this->y, this->y, this->y); }
inline Vec3 Vec3::GGB() const { return Vec3(this->y, this->y, this->z); }
inline Vec3 Vec3::GBR() const { return Vec3(this->y, this->z, this->x); }
inline Vec3 Vec3::GBG() const { return Vec3(this->y, this->z, this->y); }
inline Vec3 Vec3::GBB() const { return Vec3(this->y, this->z, this->z); }
inline Vec3 Vec3::BRR() const { return Vec3(this->z, this->x, this->x); }
inline Vec3 Vec3::BRG() const { return Vec3(this->z, this->x, this->y); }
inline Vec3 Vec3::BRB() const { return Vec3(this->z, this->x, this->z); }
inline Vec3 Vec3::BGR() const { return Vec3(this->z, this->y, this->x); }
inline Vec3 Vec3::BGG() const { return Vec3(this->z, this->y, this->y); }
inline Vec3 Vec3::BGB() const { return Vec3(this->z, this->y, this->z); }
inline Vec3 Vec3::BBR() const { return Vec3(this->z, this->z, this->x); }
inline Vec3 Vec3::BBG() const { return Vec3(this->z, this->z, this->y); }
inline Vec3 Vec3::BBB() const { return Vec3(this->z, this->z, this->z); }

#pragma endregion

#pragma region Vec4

inline Vec4::Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
inline Vec4::Vec4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}
inline Vec4::Vec4(const Vec2& _xy, float _z, float _w) : x(_xy.X()), y(_xy.Y()), z(_z), w(_w) {}
inline Vec4::Vec4(float _x, const Vec2& _yz, float _w) : x(_x), y(_yz.X()), z(_yz.Y()), w(_w) {}
inline Vec4::Vec4(float _x, float _y, const Vec2& _zw) : x(_x), y(_y), z(_zw.X()), w(_zw.Y()) {}
inline Vec4::Vec4(const Vec2& _xy, const Vec2& _zw) : x(_xy.X()), y(_xy.Y()), z(_zw.X()), w(_zw.Y()) {}
inline Vec4::Vec4(const Vec3& _xyz, float _w) : x(_xyz.X()), y(_xyz.Y()), z(_xyz.Z()), w(_w) {}
inline Vec4::Vec4(float _x, const Vec3& _yzw) : x(_x), y(_yzw.X()), z(_yzw.Y()), w(_yzw.Z()) {}
inline Vec4::Vec4(const Vec4& _other) { (*this) = _other; }

inline Vec4& Vec4::operator=(const Vec4& _other) {
	if (this != &_other) {
		this->x = _other.x;
		this->y = _other.y;
		this->z = _other.z;
		this->w = _other.w;
	}
	return *this;
}

inline Vec4& Vec4::operator+=(const Vec4& _other) {
	*this = *this + _other;
	return *this;
}

inline Vec4& Vec4::operator-=(const Vec4& _other) {
	*this = *this - _other;
	return *this;
}

inline Vec4& Vec4::operator*=(const float _scale) {
	*this = *this * _scale;
	return *this;
}

inline Vec4& Vec4::operator&=(const Vec4& _other) {
	*this = *this & _other;
	return *this;
}

inline float& Vec4::operator[](int _ndx) {
	assert(_ndx < 4);
	return xyzw[_ndx];
}

inline float Vec4::operator[](int _ndx) const {
	assert(_ndx < 4);
	return xyzw[_ndx];
}

inline Vec4 Vec4::operator+(const Vec4& _other) const {
	return Vec4(this->x + _other.x, this->y + _other.y, this->z + _other.z, this->w + _other.w);
}

inline Vec4 Vec4::operator-(const Vec4& _other) const {
	return Vec4(this->x - _other.x, this->y - _other.y, this->z - _other.z, this->w - _other.w);
}

inline Vec4 Vec4::operator*(const float _scale) const {
	return Vec4(this->x * _scale, this->y * _scale, this->z * _scale, this->w * _scale);
}

inline float Vec4::operator*(const Vec4& _other) const {
	return (this->x * _other.x) + (this->y * _other.y) + (this->z * _other.z);
}

inline Vec4 Vec4::operator&(const Vec4& _other) const {
	return Vec4((this->y * _other.z) - (this->z * _other.y), (this->x * _other.z) - (this->z * _other.x), (this->x * _other.y) - (this->y * _other.x), 0.0f);
}

inline Vec4 Vec4::operator~() const {
	return Vec4();
}

inline Vec4 Vec4::operator-() const {
	return Vec4(-this->x, -this->y, -this->z, -this->w);
}

inline bool Vec4::operator==(const Vec4& _other) const {
	return this->x == _other.x && this->y == _other.y && this->z == _other.z && this->w == _other.w;
}

inline bool Vec4::operator<(const Vec4& _other) const {
	return this->LengthSquared() < _other.LengthSquared();
}

inline bool Vec4::operator>(const Vec4& _other) const {
	return this->LengthSquared() > _other.LengthSquared();
}

inline bool Vec4::operator<=(const Vec4& _other) const {
	return this->LengthSquared() <= _other.LengthSquared();
}

inline bool Vec4::operator>=(const Vec4& _other) const {
	return this->LengthSquared() >= _other.LengthSquared();
}

inline bool Vec4::operator!=(const Vec4& _other) const {
	return this->x != _other.x || this->y != _other.y || this->z != _other.z || this->w != _other.w;
}

inline float Vec4::Length() const {
	return sqrtf((*this) * (*this));
}

inline float Vec4::LengthSquared() const {
	return (*this) * (*this);
}

inline void Vec4::Normalize() {
	float len = this->Length();
	if (len == 0.0f) return;

	this->x /= len;
	this->y /= len;
	this->z /= len;
	this->w /= len;
}

inline Vec4 Vec4::Normalized() const {
	float len = this->Length();
	if (len == 0.0f) return;

	return Vec4(this->x / len, this->y / len, this->z / len, this->w / len);
}

inline float Vec4::AngleBetween(const Vec4& _other) const {
	return acosf(*this * _other);
}

inline float Vec4::Dot(const Vec4& _other) const {
	return *this * _other;
}

inline void Vec4::Cross(const Vec4& _other) {
	*this &= _other;
}

inline void Vec4::Add(const Vec4& _other) {
	*this += _other;
}

inline void Vec4::Subtract(const Vec4& _other) {
	*this -= _other;
}

inline void Vec4::Scale(const float _scale) {
	*this *= _scale;
}

inline void Vec4::Negate() {
	*this = -(*this);
}

inline void Vec4::Zero() {
	*this = ~(*this);
}

inline bool Vec4::Equals(const Vec4& _other) const {
	return *this == _other;
}

inline bool Vec4::Less(const Vec4& _other) const {
	return *this < _other;
}

inline bool Vec4::LessThanOrEquals(const Vec4& _other) const {
	return *this <= _other;
}

inline bool Vec4::Greater(const Vec4& _other) const {
	return *this > _other;
}

inline bool Vec4::GreaterThanOrEquals(const Vec4& _other) const {
	return *this >= _other;
}

inline bool Vec4::NotEquals(const Vec4& _other) const {
	return *this != _other;
}

inline float& Vec4::X() { return this->x; }
inline float& Vec4::Y() { return this->y; }
inline float& Vec4::Z() { return this->z; }
inline float& Vec4::W() { return this->w; }
inline float Vec4::X() const { return this->x; }
inline float Vec4::Y() const { return this->y; }
inline float Vec4::Z() const { return this->z; }
inline float Vec4::W() const { return this->w; }

//Vec2 Swizzle
inline Vec2 Vec4::XX() const { return Vec2(this->x, this->x); }
inline Vec2 Vec4::YY() const { return Vec2(this->y, this->y); }
inline Vec2 Vec4::ZZ() const { return Vec2(this->z, this->z); }
inline Vec2 Vec4::WW() const { return Vec2(this->w, this->w); }
inline Vec2 Vec4::XY() const { return Vec2(this->x, this->y); }
inline Vec2 Vec4::XZ() const { return Vec2(this->x, this->z); }
inline Vec2 Vec4::XW() const { return Vec2(this->x, this->w); }
inline Vec2 Vec4::YX() const { return Vec2(this->y, this->x); }
inline Vec2 Vec4::YZ() const { return Vec2(this->y, this->z); }
inline Vec2 Vec4::YW() const { return Vec2(this->y, this->w); }
inline Vec2 Vec4::ZX() const { return Vec2(this->z, this->x); }
inline Vec2 Vec4::ZY() const { return Vec2(this->z, this->y); }
inline Vec2 Vec4::ZW() const { return Vec2(this->z, this->w); }
inline Vec2 Vec4::WX() const { return Vec2(this->w, this->x); }
inline Vec2 Vec4::WY() const { return Vec2(this->w, this->y); }
inline Vec2 Vec4::WZ() const { return Vec2(this->w, this->z); }
inline Vec2 Vec4::RR() const { return Vec2(this->x, this->x); }
inline Vec2 Vec4::GG() const { return Vec2(this->y, this->y); }
inline Vec2 Vec4::BB() const { return Vec2(this->z, this->z); }
inline Vec2 Vec4::AA() const { return Vec2(this->w, this->w); }
inline Vec2 Vec4::RG() const { return Vec2(this->x, this->y); }
inline Vec2 Vec4::RB() const { return Vec2(this->x, this->z); }
inline Vec2 Vec4::RA() const { return Vec2(this->x, this->w); }
inline Vec2 Vec4::GR() const { return Vec2(this->y, this->x); }
inline Vec2 Vec4::GB() const { return Vec2(this->y, this->z); }
inline Vec2 Vec4::GA() const { return Vec2(this->y, this->w); }
inline Vec2 Vec4::BR() const { return Vec2(this->z, this->x); }
inline Vec2 Vec4::BG() const { return Vec2(this->z, this->y); }
inline Vec2 Vec4::BA() const { return Vec2(this->z, this->w); }
inline Vec2 Vec4::AR() const { return Vec2(this->w, this->x); }
inline Vec2 Vec4::AG() const { return Vec2(this->w, this->y); }
inline Vec2 Vec4::AB() const { return Vec2(this->w, this->z); }

//Vec3 Swizzle
inline Vec3 Vec4::XXX() const { return Vec3(this->x, this->x, this->x); }
inline Vec3 Vec4::XXY() const { return Vec3(this->x, this->x, this->y); }
inline Vec3 Vec4::XXZ() const { return Vec3(this->x, this->x, this->z); }
inline Vec3 Vec4::XXW() const { return Vec3(this->x, this->x, this->w); }
inline Vec3 Vec4::XYX() const { return Vec3(this->x, this->y, this->x); }
inline Vec3 Vec4::XYY() const { return Vec3(this->x, this->y, this->y); }
inline Vec3 Vec4::XYW() const { return Vec3(this->x, this->y, this->w); }
inline Vec3 Vec4::XZX() const { return Vec3(this->x, this->z, this->x); }
inline Vec3 Vec4::XZY() const { return Vec3(this->x, this->z, this->y); }
inline Vec3 Vec4::XZZ() const { return Vec3(this->x, this->z, this->z); }
inline Vec3 Vec4::XZW() const { return Vec3(this->x, this->z, this->w); }
inline Vec3 Vec4::XWX() const { return Vec3(this->x, this->w, this->x); }
inline Vec3 Vec4::XWY() const { return Vec3(this->x, this->w, this->y); }
inline Vec3 Vec4::XWZ() const { return Vec3(this->x, this->w, this->z); }
inline Vec3 Vec4::XWW() const { return Vec3(this->x, this->w, this->w); }
inline Vec3 Vec4::YXX() const { return Vec3(this->y, this->x, this->x); }
inline Vec3 Vec4::YXY() const { return Vec3(this->y, this->x, this->y); }
inline Vec3 Vec4::YXZ() const { return Vec3(this->y, this->x, this->z); }
inline Vec3 Vec4::YXW() const { return Vec3(this->y, this->x, this->w); }
inline Vec3 Vec4::YYX() const { return Vec3(this->y, this->y, this->x); }
inline Vec3 Vec4::YYY() const { return Vec3(this->y, this->y, this->y); }
inline Vec3 Vec4::YYZ() const { return Vec3(this->y, this->y, this->z); }
inline Vec3 Vec4::YYW() const { return Vec3(this->y, this->y, this->w); }
inline Vec3 Vec4::YZX() const { return Vec3(this->y, this->z, this->x); }
inline Vec3 Vec4::YZY() const { return Vec3(this->y, this->z, this->y); }
inline Vec3 Vec4::YZZ() const { return Vec3(this->y, this->z, this->z); }
inline Vec3 Vec4::YZW() const { return Vec3(this->y, this->z, this->w); }
inline Vec3 Vec4::YWX() const { return Vec3(this->y, this->w, this->x); }
inline Vec3 Vec4::YWY() const { return Vec3(this->y, this->w, this->y); }
inline Vec3 Vec4::YWZ() const { return Vec3(this->y, this->w, this->z); }
inline Vec3 Vec4::YWW() const { return Vec3(this->y, this->w, this->w); }
inline Vec3 Vec4::ZXX() const { return Vec3(this->z, this->x, this->x); }
inline Vec3 Vec4::ZXY() const { return Vec3(this->z, this->x, this->y); }
inline Vec3 Vec4::ZXZ() const { return Vec3(this->z, this->x, this->z); }
inline Vec3 Vec4::ZXW() const { return Vec3(this->z, this->x, this->w); }
inline Vec3 Vec4::ZYX() const { return Vec3(this->z, this->y, this->x); }
inline Vec3 Vec4::ZYY() const { return Vec3(this->z, this->y, this->y); }
inline Vec3 Vec4::ZYZ() const { return Vec3(this->z, this->y, this->z); }
inline Vec3 Vec4::ZYW() const { return Vec3(this->z, this->y, this->w); }
inline Vec3 Vec4::ZZX() const { return Vec3(this->z, this->z, this->x); }
inline Vec3 Vec4::ZZY() const { return Vec3(this->z, this->z, this->y); }
inline Vec3 Vec4::ZZZ() const { return Vec3(this->z, this->z, this->z); }
inline Vec3 Vec4::ZZW() const { return Vec3(this->z, this->z, this->w); }
inline Vec3 Vec4::ZWX() const { return Vec3(this->z, this->w, this->x); }
inline Vec3 Vec4::ZWY() const { return Vec3(this->z, this->w, this->y); }
inline Vec3 Vec4::ZWZ() const { return Vec3(this->z, this->w, this->z); }
inline Vec3 Vec4::ZWW() const { return Vec3(this->z, this->w, this->w); }
inline Vec3 Vec4::WXX() const { return Vec3(this->w, this->x, this->x); }
inline Vec3 Vec4::WXY() const { return Vec3(this->w, this->x, this->y); }
inline Vec3 Vec4::WXZ() const { return Vec3(this->w, this->x, this->z); }
inline Vec3 Vec4::WXW() const { return Vec3(this->w, this->x, this->w); }
inline Vec3 Vec4::WYX() const { return Vec3(this->w, this->y, this->x); }
inline Vec3 Vec4::WYY() const { return Vec3(this->w, this->y, this->y); }
inline Vec3 Vec4::WYZ() const { return Vec3(this->w, this->y, this->z); }
inline Vec3 Vec4::WYW() const { return Vec3(this->w, this->y, this->w); }
inline Vec3 Vec4::WZX() const { return Vec3(this->w, this->z, this->x); }
inline Vec3 Vec4::WZY() const { return Vec3(this->w, this->z, this->y); }
inline Vec3 Vec4::WZZ() const { return Vec3(this->w, this->z, this->z); }
inline Vec3 Vec4::WZW() const { return Vec3(this->w, this->z, this->w); }
inline Vec3 Vec4::WWX() const { return Vec3(this->w, this->w, this->x); }
inline Vec3 Vec4::WWY() const { return Vec3(this->w, this->w, this->y); }
inline Vec3 Vec4::WWZ() const { return Vec3(this->w, this->w, this->z); }
inline Vec3 Vec4::WWW() const { return Vec3(this->w, this->w, this->w); }
inline Vec3 Vec4::RRR() const { return Vec3(this->x, this->x, this->x); }
inline Vec3 Vec4::RRG() const { return Vec3(this->x, this->x, this->y); }
inline Vec3 Vec4::RRB() const { return Vec3(this->x, this->x, this->z); }
inline Vec3 Vec4::RRA() const { return Vec3(this->x, this->x, this->w); }
inline Vec3 Vec4::RGR() const { return Vec3(this->x, this->y, this->x); }
inline Vec3 Vec4::RGG() const { return Vec3(this->x, this->y, this->y); }
inline Vec3 Vec4::RGA() const { return Vec3(this->x, this->y, this->w); }
inline Vec3 Vec4::RBR() const { return Vec3(this->x, this->z, this->x); }
inline Vec3 Vec4::RBG() const { return Vec3(this->x, this->z, this->y); }
inline Vec3 Vec4::RBB() const { return Vec3(this->x, this->z, this->z); }
inline Vec3 Vec4::RBA() const { return Vec3(this->x, this->z, this->w); }
inline Vec3 Vec4::RAR() const { return Vec3(this->x, this->w, this->x); }
inline Vec3 Vec4::RAG() const { return Vec3(this->x, this->w, this->y); }
inline Vec3 Vec4::RAB() const { return Vec3(this->x, this->w, this->z); }
inline Vec3 Vec4::RAA() const { return Vec3(this->x, this->w, this->w); }
inline Vec3 Vec4::GRR() const { return Vec3(this->y, this->x, this->x); }
inline Vec3 Vec4::GRG() const { return Vec3(this->y, this->x, this->y); }
inline Vec3 Vec4::GRB() const { return Vec3(this->y, this->x, this->z); }
inline Vec3 Vec4::GRA() const { return Vec3(this->y, this->x, this->w); }
inline Vec3 Vec4::GGR() const { return Vec3(this->y, this->y, this->x); }
inline Vec3 Vec4::GGG() const { return Vec3(this->y, this->y, this->y); }
inline Vec3 Vec4::GGB() const { return Vec3(this->y, this->y, this->z); }
inline Vec3 Vec4::GGA() const { return Vec3(this->y, this->y, this->w); }
inline Vec3 Vec4::GBR() const { return Vec3(this->y, this->z, this->x); }
inline Vec3 Vec4::GBG() const { return Vec3(this->y, this->z, this->y); }
inline Vec3 Vec4::GBB() const { return Vec3(this->y, this->z, this->z); }
inline Vec3 Vec4::GBA() const { return Vec3(this->y, this->z, this->w); }
inline Vec3 Vec4::GAR() const { return Vec3(this->y, this->w, this->x); }
inline Vec3 Vec4::GAG() const { return Vec3(this->y, this->w, this->y); }
inline Vec3 Vec4::GAB() const { return Vec3(this->y, this->w, this->z); }
inline Vec3 Vec4::GAA() const { return Vec3(this->y, this->w, this->w); }
inline Vec3 Vec4::BRR() const { return Vec3(this->z, this->x, this->x); }
inline Vec3 Vec4::BRG() const { return Vec3(this->z, this->x, this->y); }
inline Vec3 Vec4::BRB() const { return Vec3(this->z, this->x, this->z); }
inline Vec3 Vec4::BRA() const { return Vec3(this->z, this->x, this->w); }
inline Vec3 Vec4::BGR() const { return Vec3(this->z, this->y, this->x); }
inline Vec3 Vec4::BGG() const { return Vec3(this->z, this->y, this->y); }
inline Vec3 Vec4::BGB() const { return Vec3(this->z, this->y, this->z); }
inline Vec3 Vec4::BGA() const { return Vec3(this->z, this->y, this->w); }
inline Vec3 Vec4::BBR() const { return Vec3(this->z, this->z, this->x); }
inline Vec3 Vec4::BBG() const { return Vec3(this->z, this->z, this->y); }
inline Vec3 Vec4::BBB() const { return Vec3(this->z, this->z, this->z); }
inline Vec3 Vec4::BBA() const { return Vec3(this->z, this->z, this->w); }
inline Vec3 Vec4::BAR() const { return Vec3(this->z, this->w, this->x); }
inline Vec3 Vec4::BAG() const { return Vec3(this->z, this->w, this->y); }
inline Vec3 Vec4::BAB() const { return Vec3(this->z, this->w, this->z); }
inline Vec3 Vec4::BAA() const { return Vec3(this->z, this->w, this->w); }
inline Vec3 Vec4::ARR() const { return Vec3(this->w, this->x, this->x); }
inline Vec3 Vec4::ARG() const { return Vec3(this->w, this->x, this->y); }
inline Vec3 Vec4::ARB() const { return Vec3(this->w, this->x, this->z); }
inline Vec3 Vec4::ARA() const { return Vec3(this->w, this->x, this->w); }
inline Vec3 Vec4::AGR() const { return Vec3(this->w, this->y, this->x); }
inline Vec3 Vec4::AGG() const { return Vec3(this->w, this->y, this->y); }
inline Vec3 Vec4::AGB() const { return Vec3(this->w, this->y, this->z); }
inline Vec3 Vec4::AGA() const { return Vec3(this->w, this->y, this->w); }
inline Vec3 Vec4::ABR() const { return Vec3(this->w, this->z, this->x); }
inline Vec3 Vec4::ABG() const { return Vec3(this->w, this->z, this->y); }
inline Vec3 Vec4::ABB() const { return Vec3(this->w, this->z, this->z); }
inline Vec3 Vec4::ABA() const { return Vec3(this->w, this->z, this->w); }
inline Vec3 Vec4::AAR() const { return Vec3(this->w, this->w, this->x); }
inline Vec3 Vec4::AAG() const { return Vec3(this->w, this->w, this->y); }
inline Vec3 Vec4::AAB() const { return Vec3(this->w, this->w, this->z); }
inline Vec3 Vec4::AAA() const { return Vec3(this->w, this->w, this->w); }

//Vec4 Swizzle


#pragma endregion
#pragma endregion

#pragma region DoublePrecisionVectors
#pragma region Vec2

#pragma endregion

#pragma region Vec3

#pragma endregion

#pragma region Vec4

#pragma endregion
#pragma endregion

#pragma region IntegerVectors
#pragma region Vec2

#pragma endregion

#pragma region Vec3

#pragma endregion

#pragma region Vec4

#pragma endregion
#pragma endregion

#pragma region LongVectors
#pragma region Vec2

#pragma endregion

#pragma region Vec3

#pragma endregion

#pragma region Vec4

#pragma endregion
#pragma endregion