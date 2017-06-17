#include "tokenizer.h"

ASMI::Tokenizer::Tokenizer(std::string filename)
{
	this->inf = std::ifstream(filename);
	if (inf.good())
	{
		std::string line;
		
		while (std::getline(inf, line))
		{
			lines.push_back(line);
		}
	}
}

std::vector<std::string> ASMI::Tokenizer::create_tokens()
{
	std::for_each(lines.begin(), lines.end(), [&] (const std::string s)
	{
		int offset = 0;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (s[i] == ';')
			{
				offset = i + 1;
				break;
			}

			switch (s[i])
			{
				case ' ':
				case ',':
				case '\0':
				case '\t':
				{
					std::string temp = s.substr(offset, i - offset);
					if (temp.length() > 0)
						tokens.push_back(s.substr(offset, i - offset));
					offset = i + 1;
				}
			}
		}
		tokens.push_back(s.substr(offset, s.length() - offset));
	});

	return tokens;
}

std::vector<std::string> ASMI::Tokenizer::create_tokens(std::string s)
{
	std::vector<std::string> tokens;
	int offset = 0;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == ';')
		{
			offset = i + 1;
			break;
		}

		switch (s[i])
		{
			case ' ':
			case ',':
			case '\0':
			case '\t':
			{
				std::string temp = s.substr(offset, i - offset);
				if (temp.length() > 0)
					tokens.push_back(s.substr(offset, i - offset));
				offset = i + 1;
			}
		}
	}

	return tokens;
}

std::vector<std::string> ASMI::Tokenizer::get_lines()
{
	return lines;
}
