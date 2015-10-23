#ifndef H_SCANNER
#define H_SCANNER

#include <iostream>
#include <vector>

#include "lexeme.hpp"

enum class character_type {
	UPPER_ALPHA,
	LOWER_ALPHA,
	DIGIT,
	SINGLE_SYMBOL,
	MAYBE_MULTIPLE_SYMBOL,
	WHITESPACE,
	OTHER,
};

enum class state_type {
	START,
	WORD,
	DIGIT,
	MAYBE_MULTIPLE_SYMBOL,
	WHITESPACE,
};

struct scanner_state {
private:
	std::istream *input;

public:
	int line = 1;
	int pos = -1;
	state_type current_state = state_type::START;

	scanner_state(std::istream *i)
	: input(i)
	{
	}

	bool get_character(char &c);
};

class scanner_error : std::exception {
	int line;
	int pos;
	char c;
	std::string msg;

public:
	scanner_error(int line, int pos, char c)
	: line(line)
	, pos(pos)
	, c(c)
	, msg("Invalid character '" + std::string(1, c) + "' at line " + std::to_string(line) + " on position " + std::to_string(pos))
	{
	}

	virtual char const *
	what() const noexcept
	{
		return msg.c_str();
	}
};

std::vector<lexeme> scan(std::istream &input);

#endif	// H_SCANNER
