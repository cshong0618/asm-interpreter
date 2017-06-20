// STL includes
#include <iostream>
#include <string>
#include <cstdint>
#include <ctime>

// Project includes
#include "registers.h"
#include "variables.h"
#include "math_ops.h"
#include "binary_ops.h"
#include "tokenizer.h"
#include "type.h"

enum RUN_STATES
{
	NORMAL = 1,
	INTERPRETER = 1 << 1,
	COMPILE = 1 << 2
	
};

int parseCommand(char* argv);

void space(void);

int main(int argc, char* argv[])
{
    ASMI::Variables* vars = new ASMI::Variables();
	ASMI::Registers* regs = new ASMI::Registers();
	std::clock_t t1;
	t1 = clock();
	// int literal declaration into variables
	vars->allocate("hello", 100);

	// int literal allocation into register
	regs->allocate(1, vars->get_address("hello"));
    std::cout << "hello: " << std::dec << regs->get_value(1) << "\n";

    // double lieteral declaration into variables
    vars->allocate("float_test", 2.45);
    regs->allocate(10, vars->get_address("float_test"));
    std::cout << "float_test in register: " << std::dec << regs->get_value(10) << "\n";

	// math operations
	regs->memory_allocate(0, ASMI::add(regs->get_value(1), regs->get_value(1)));
	std::cout << regs->read_memory_loc(0) << std::endl;

	space();

	// Pointer into variable
	vars->memory_allocate("a", ASMI::add(0, 100));
	regs->memory_allocate(7, vars->get_address("a"));
	std::cout << "Value at address pointed by R7: " << regs->read_memory_loc(7) << std::endl;
	
	// Array as variable
	int arr[] = { 1, 2, 3 ,4, 5, 6, 7, 8, 9, 10, 11, 12};
	vars->memory_allocate("array", arr);
	regs->memory_allocate(6, vars->get_address("array"));
	std::cout << "Address of arr: " << &arr << std::endl;
	std::cout << "Address of R6: 0x" << std::hex << regs->get_value(6) << std::endl;
	std::cout << "Value at address pointed by R6[0]: " << std::dec << regs->read_memory_loc(6) << std::endl;
	space();

	for (int i = 1; i < 12; i++)
	{
		// Increment by four byte (32 bits)
		regs->increment_memory(6, sizeof(int));
		std::cout << "Address of arr: 0x" << arr + i << std::endl;
		std::cout << "Value of R6: 0x" << std::hex << regs->get_value(6) << std::endl;
		std::cout << "Value at address pointed by R6[" << std::dec << i << "]: " << std::dec<< regs->read_memory_loc(6) << std::endl;
		space();
	}

	// Array as register
	regs->memory_allocate(5, arr);
	std::cout << "Address of arr: 0x" << arr << std::endl;
	std::cout << "Address of R5: 0x" << std::hex << regs->get_value(5) << std::endl;
	std::cout << "Value at address pointed by R5[0]: " << std::dec << regs->read_memory_loc(5)<< std::endl;
	space();
	
	for (int i = 1; i < 12; i++)
	{
		// Increment by one byte (4 bits)
		regs->increment_memory(5, sizeof(int));
		std::cout << "Address of arr: 0x" << arr + i << std::endl;
		std::cout << "Value of R5: 0x" << std::hex<< regs->get_value(5) << std::endl;
		std::cout << "Value at address pointed by R5[" <<std::dec << i <<"]: " << std::dec << regs->read_memory_loc(5) << std::endl;
		space();
	}

	try
	{
		std::cout<<std::dec;
		std::cout << vars->get_value("hello") << std::endl;
		std::cout << "Value of R1: " << regs->get_value(1) << std::endl;
		vars->allocate("hello", 200);

		// The value in the register should not change
		// Even after the value in the memory had changed
		std::cout << vars->get_value("hello") << std::endl;

		std::cout << "Value of R1: " << regs->get_value(1) << std::endl;

		std::cout << vars->get_value("world") << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	ASMI::Tokenizer tkn("../test.asm");
	space();
	std::cout << "Before tokenizing:" << std::endl;

	for (auto str : tkn.get_lines())
	{
		std::cout << str << std::endl;
	}

	std::vector<std::string> s = tkn.create_tokens();
	std::cout << std::endl << "After tokenizing:" << std::endl;
	for (auto str : s)
	{
		std::cout << str << ' ';
	}
	space();
		
	std::cout << (float)(clock() - t1) / CLOCKS_PER_SEC << " seconds"<< std::endl;
	return 0;
}

int parseCommand(char *argv)
{
	if (argv[0] == '-' || argv[0] == '\\' || argv[0] == '/')
	{
		switch (toupper(argv[1]))
		{
			case 'C':
				return COMPILE;

			case 'I':
				return INTERPRETER;
		}
	}

	return -1;
}

inline void space(void)
{
	std::cout << std::endl;
}
