#include "interpreter.h"
#include "instructions.h"
ASMI::Interpreter::Interpreter(std::string filename)
{
	tokenizer = Tokenizer(filename);
	lines = tokenizer.get_lines();
}

void ASMI::Interpreter::init()
{
	// This function tags all lines according to what they do

	// Maybe this function should just initialize the jump points and data area...

	// TODO: Create branch points.
	// TODO: Create data initialization area.
	for (int i = 0; i < lines.size(); i++)
	{
		if (lines[i].length() > 0)
		{
			int line_num = i;
			std::string line = lines[i];
			std::vector<std::string> temp = tokenizer.create_tokens(lines[i]);
			INSTRUCTION_FLAGS ifs = get_type(temp);

			insts.push_back({ line_num, line, ifs });
		}
		
	}
}

ASMI::Interpreter::INSTRUCTION_FLAGS ASMI::Interpreter::get_type(std::vector<std::string> tokens)
{
	if (tokens[0] == "LDR" || tokens[0] == "STR")
	{
		return LDR_STR_INSTRUCTION;
	}
	
	return INSTRUCTION_FLAGS();
}
