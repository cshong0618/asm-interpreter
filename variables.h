#ifndef VARIABLES_H
#define VARIABLES_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace ASMI
{
	struct Variable
	{
		std::string name;
		int* val;
		bool used;
	};


	class Variables
	{
	public:
		Variables()
		{
			variables = new std::map<std::string, Variable>();
		}

		void allocate(std::string name, int val);
		void memory_allocate(std::string name, int vals[]);

		int* get_address(std::string name) const;
		int get_value(std::string name) const;
	
	private:
		std::map<std::string, Variable>* variables;

		bool has_variable(std::string name) const ;
	};
}

#endif