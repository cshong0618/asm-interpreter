#ifndef BINARY_OPS_H
#define BINARY_OPS_H

namespace ASMI
{
	int* _and(int _lhs, int _rhs);
	int* _or (int _lhs, int _rhs);
	int* _xor(int _lhs, int _rhs);
	int* shift_left(int _lhs, int _rhs);
	int* shift_right(int _lhs, int _rhs);

}
#endif