#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#define LDR "LDR"
#define STR "STR"
#define BAL "BAL"
#define ADD "ADD"
#define MUL "MUL"
#define SUB "SUB"

#define LSL "LSL"
#define LSR "LSR"

#include <string>
#include <vector>
#include <fstream>
#include <map>

namespace ASMI
{
	struct name_instruction_pair
	{
		std::string name;
		int opcode;
	};

	enum Instructions
	{
		I_LDR,
		I_STR,
		I_BAL,
		I_ADD,
		I_MUL,
		I_SUB,
		I_LSL,
		I_LSR
	};

	void import_nip(std::string filename);
	void build_map(std::map<std::string, ASMI::name_instruction_pair> m_nip, std::vector<ASMI::name_instruction_pair> v_nip);
}

#endif