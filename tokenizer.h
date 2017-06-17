#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

namespace ASMI
{
	class Tokenizer
	{
	public:
		Tokenizer()
		{

		}

		Tokenizer(std::string filename);
		std::vector<std::string> create_tokens();
		std::vector<std::string> create_tokens(std::string s);
		std::vector<std::string> get_lines();
	private:
		struct inst
		{
			std::string ops;
			std::string line;
			std::vector<std::string> tokens_excl_ops;
		};


		std::ifstream inf;
		std::vector<std::string> lines;
		std::vector<std::string> tokens;

		std::vector<inst> instructions;
	};
}


#endif