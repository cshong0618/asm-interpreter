#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "tokenizer.h"

namespace ASMI
{
	class Interpreter
	{
	public:
		Interpreter(std::string filename);

		void init();
	private:
		enum INSTRUCTION_FLAGS
		{
			DECLARATION = 1,
			LDR_STR_INSTRUCTION = 1 << 1,
			OPS_INSTRUCTION = 1 << 2,
			SFT_INSTRUCTION = 1 << 3,
			JMP_INSTRUCTION = 1 << 4,
			CMP_INSTRUCTION = 1 << 5,
			ENTRY_POINT = 1 << 6,
			AREA_PROGRAM = 1 << 7,
			AREA_DATA = 1 << 8,
			JMP_LABEL = 1 << 9
		};

		struct instuctions
		{
			int line_num;
			std::string line;
			INSTRUCTION_FLAGS ifs;
		};

		struct program_information
		{
			// The current instruction
			int program_counter;

			// Total number of instructions
			int max_count;

			// Where to resume counter
			int resume_counter;
		} pi;

		struct labels
		{
			std::string label_name;
			int label_line;
		} jmp_label;

		ASMI::Tokenizer tokenizer;
		std::vector<std::string> lines;
		std::vector<instuctions> insts;
		INSTRUCTION_FLAGS get_type(std::vector<std::string> tokens);
	};
}

#endif