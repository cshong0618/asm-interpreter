#include "math_ops.h"

int* ASMI::add(int _lhs, int _rhs)
{
	int res = _lhs + _rhs;
	int* ret = new int();
	*ret = res;
	return ret;
}

int* ASMI::sub(int _lhs, int _rhs)
{
	int res = _lhs - _rhs;
	int* ret = new int();
	*ret = res;
	return ret;
}

int* ASMI::mul(int _lhs, int _rhs)
{
	int res = _lhs * _rhs;
	int* ret = new int();
	*ret = res;
	return ret;
}

int ASMI::n_add(int _lhs, int _rhs)
{
	return _lhs + _rhs;
}
