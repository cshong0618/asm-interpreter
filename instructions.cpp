#include "instructions.h"

// TODO: Build a proper structure of instructions

std::map<std::string, ASMI::name_instruction_pair> _m_nip;

void ASMI::import_nip(std::string filename)
{
	std::vector<ASMI::name_instruction_pair> v_nip;
	build_map(_m_nip, v_nip);
}

void ASMI::build_map(std::map<std::string, ASMI::name_instruction_pair> m_nip, std::vector<ASMI::name_instruction_pair> v_nip)
{
	return;
}
