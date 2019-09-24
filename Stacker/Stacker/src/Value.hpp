#ifndef STACKER_VALUE_H
#define STACKER_VALUE_H
#include <iostream>
#include <string>
#include <variant>
struct Value
{
	// ReSharper disable once CppNonExplicitConvertingConstructor
	Value(int64_t i) : type(Type::INT), value(i) {};
	// ReSharper disable once CppNonExplicitConvertingConstructor
	Value(double d) : type(Type::REAL), value(d) {};
	// ReSharper disable once CppNonExplicitConvertingConstructor
	Value(const std::string& str) : type(Type::STRING), value(str) {};

	enum class Type
	{
		//BOOL,
		INT,
		REAL,
		STRING
	} type;

	std::variant<int64_t, double, std::string> value;

	Value& operator+=(const Value& rhs);
	Value& operator-=(const Value& rhs);
	Value& operator*=(const Value& rhs);
	Value& operator/=(const Value& rhs);
	Value& operator%=(const Value& rhs);
	Value& pow(const Value& rhs);
	Value& log(const Value& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Value& value);
};


#endif // STACKER_VALUE_H
