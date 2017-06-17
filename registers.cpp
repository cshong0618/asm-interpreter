#include "registers.h"

ASMI::Registers::Registers()
{
	registers = new std::vector<Register>(reg_size);
}

int ASMI::Registers::allocate(int loc, int* val)
{
	if (loc > -1 && loc < registers->size())
	{
		registers->at(loc)._val = std::make_unique<int>(*val);
		registers->at(loc).used = true;
		return 1;
	}

	return -1;
}

int ASMI::Registers::memory_allocate(int loc, int * val)
{
	if (loc > -1 && loc < registers->size())
	{
		intptr_t p_int = reinterpret_cast<intptr_t>(val);
		int hold = (int)p_int;
		registers->at(loc)._val = std::make_unique<int>(hold);
		registers->at(loc).used = true;
	}

	return 0;
}

int ASMI::Registers::read_memory_loc(int loc) const
{
	if (loc > -1 && loc < registers->size())
	{
		if (registers->at(loc).used)
		{
			//intptr_t p = *registers->at(loc)._val;
            int p = *registers->at(loc)._val;
            //std::cout << std::hex << p << std::endl;
            int val = *reinterpret_cast<uint32_t*>(p);

			return val;
		}
	}

	return 0;
}

int ASMI::Registers::increment_memory(int loc, int val)
{
	if (loc > -1 && loc < registers->size())
	{
		if (registers->at(loc).used)
		{
			int* hold = registers->at(loc)._val.get();
			*hold += val;
			registers->at(loc)._val = std::make_unique<int>(*hold);
		}
	}
	return 0;
}


int ASMI::Registers::get_value(int loc) const
{
	if (loc > -1 && loc < registers->size())
	{
		if (registers->at(loc).used == true)
		{
			return *registers->at(loc)._val.get();
		}
		throw std::runtime_error("Register empty");
	}

	throw std::runtime_error("Out of range");
}

void ASMI::Registers::free_register(int loc)
{
	if (loc > -1 && loc < registers->size())
	{
		if (registers->at(loc).used == true)
		{
			registers->at(loc)._val.get_deleter();
			registers->at(loc).used = false;
		}
	}
	else
	{
		throw std::runtime_error("Register location not found");
	}
}

ASMI::Conditional_Registers::Conditional_Registers()
{
	for (int i = 0; i < 4; i++)
	{
		cond_regs[i].val = false;
	}
}

void ASMI::Conditional_Registers::trigger(flags f)
{
	cond_regs[f].val = true;
}

bool ASMI::Conditional_Registers::check_cond(flags f)
{
	return cond_regs[f].val;
}