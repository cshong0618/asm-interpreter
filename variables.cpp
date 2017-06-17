#include "variables.h"

void ASMI::Variables::allocate(std::string name, int val)
{
	if (!has_variable(name))
	{
		(*variables)[name].name = name;
		(*variables)[name].val = new int;
		(*variables)[name].used = true;
	}

	*variables->at(name).val = val;

}

void ASMI::Variables::memory_allocate(std::string name, int vals[])
{
	if (!has_variable(name))
	{
		(*variables)[name].name = name;
		(*variables)[name].val = vals;
		(*variables)[name].used = true;
	}
}

int* ASMI::Variables::get_address(std::string name) const
{
	if (has_variable(name))
	{
		return variables->at(name).val;
	}

	std::string error_msg = "Variable name \"" + name + "\" not found.";
	//throw std::exception(error_msg.c_str());
}

int ASMI::Variables::get_value(std::string name) const
{
	if (has_variable(name))
	{
		return *variables->at(name).val;
	}

	std::string error_msg = "Variable name \"" + name + "\" not found.";
	//throw std::exception(error_msg.c_str());
}

bool ASMI::Variables::has_variable(std::string name) const
{
	return variables->find(name) != variables->end();
}