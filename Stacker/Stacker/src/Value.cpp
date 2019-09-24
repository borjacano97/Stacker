#include "Value.hpp"
#include <exception>
std::ostream& operator<<(std::ostream& os, const Value& value)
{
	switch (value.type)
	{
	case Value::Type::INT:		return os << std::get<int64_t>(value.value);
	case Value::Type::REAL:		return os << std::get<double>(value.value);
	case Value::Type::STRING:	return os << std::get<std::string>(value.value);
	}
	return os;
};

Value& Value::operator+=(const Value& rhs)
{
	switch (type)
	{
		case Type::INT:
			switch (rhs.type)
			{
				case Type::INT:
					std::get<int64_t>(value) += std::get<int64_t>(rhs.value);
				break;
				case Type::REAL:
					std::get<int64_t>(value) += std::get<double>(rhs.value);
				break;
				case Type::STRING:
					throw std::exception("ERROR: invalid operation. You're trying to add a variable of type STRING to a variable of type INT");
				break;
			}
		break;
	case Type::REAL:
		switch (rhs.type)
		{
			case Type::INT:
			
			break;
			case Type::REAL: break;
			case Type::STRING: break;
		}
		break;
	case Type::STRING:
		switch (rhs.type)
		{
			case Type::INT: break;
			case Type::REAL: break;
			case Type::STRING: break;
		}
		break;
	}

	return *this;
}

Value& Value::operator-=(const Value& rhs)
{
	return *this;
}

Value& Value::operator*=(const Value& rhs)
{
	return *this;
}

Value& Value::operator/=(const Value& rhs)
{
	return *this;
}

Value& Value::operator%=(const Value& rhs)
{
	return *this;
}

Value& Value::pow(const Value& rhs)
{
	return *this;
}

Value& Value::log(const Value& rhs)
{
	return *this;
}
