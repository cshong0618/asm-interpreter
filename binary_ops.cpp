#include "binary_ops.h"

int* ASMI::_and(int _lhs, int _rhs)
{
	int res = _lhs & _rhs;
	int* ret = new int();
	*ret = res;
	return ret;
}

int* ASMI::_or(int _lhs, int _rhs)
{
	int res = _lhs | _rhs;
	int* ret = new int();
	*ret = res;
	return ret;
}


int* ASMI::_xor (int _lhs, int _rhs)
{
	int res = _lhs ^ _rhs;
	int* ret = new int();
	*ret = res;
	return ret;
}

int* ASMI::shift_left (int _lhs, int _rhs)
{
	int res = _lhs << _rhs;
	int* ret = new int();
	*ret = res;
	return ret;
}

int* ASMI::shift_right(int _lhs, int _rhs)
{
	int res = _lhs >> _rhs;
	int* ret = new int();
	*ret = res;
	return ret;
}
