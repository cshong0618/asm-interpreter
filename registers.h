#ifndef REGISTERS_H
#define REGISTERS_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdint>

#include "type.h"

namespace ASMI
{
	struct Register
	{
		std::unique_ptr<int> _val;
		bool used;
        Type type;
	};

	class Registers
	{
	public:
		Registers();
		int allocate(int loc, int* val);
		int get_value(int loc) const;
		
		int memory_allocate(int loc, int* val);
		int read_memory_loc(int loc) const;
		int increment_memory(int loc, int val);
	private:
		std::vector<Register>* registers;
		const unsigned int reg_size = 16;
		void free_register(int loc);
	};

	class Conditional_Registers
	{
	public:
		enum flags
		{
			C,
			P,
			S,
			R,
		};

		Conditional_Registers();

		void trigger(flags f);
		bool check_cond(flags f);
	private:
		struct conditional_register
		{
			bool val;
		} cond_regs[4];
	};
}

#endif