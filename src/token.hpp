#pragma once

#include <string>
#include <vector>
#include <map>

#include "lexeme.hpp"

// Tokens that have a single lexeme_type with the same name and discard the character contents
#define KOMPILATOR_IDENTICAL_EMPTY_TOKEN_TYPES(def)	\
	def(SEMICOLON)	\
	def(COLON)	\
	def(COMMA)	\
	def(PLUS)	\
	def(MINUS)	\
	def(MULTIPLY)	\
	def(DIVIDE)	\
	def(MODULO)	\
	def(EQUALS)	\
	def(NOT_EQUALS)	\
	def(LESS_THAN)	\
	def(LESS_THAN_EQUALS)	\
	def(GREATER_THAN)	\
	def(GREATER_THAN_EQUALS)	\
	def(ROUND_BRACKET_OPEN)	\
	def(ROUND_BRACKET_CLOSE)	\
	def(CURLY_BRACKET_OPEN)	\
	def(CURLY_BRACKET_CLOSE)	\
	def(SQUARE_BRACKET_OPEN)	\
	def(SQUARE_BRACKET_CLOSE)	\
	def(AND)	\
	def(OR)	\
	def(IS)	\
	def(NOT)	\
	def(EMPTY_LIST)

#define KOMPILATOR_OTHER_TOKEN_TYPES(def)	\
	def(TYPE_INT)	\
	def(TYPE_BOOL)	\
	def(TYPE_VOID)	\
	def(IF)	\
	def(ELSE)	\
	def(WHILE)	\
	def(RETURN)	\
	def(TRUE)	\
	def(FALSE)	\
	def(IDENTIFIER)	\
	def(INTEGER)	\
	def(WHITESPACE)	\
	def(COMMENT)

#define KOMPILATOR_TOKEN_TYPES(def)	\
	KOMPILATOR_IDENTICAL_EMPTY_TOKEN_TYPES(def)	\
	KOMPILATOR_OTHER_TOKEN_TYPES(def)

enum class token_type {
	#define DEFINE_ENUM_TYPE(v) v,
	KOMPILATOR_TOKEN_TYPES(DEFINE_ENUM_TYPE)
	#undef DEFINE_ENUM_TYPE
};

const std::map<std::string, token_type> token_types_by_name = {
	#define DEFINE_CONVERSION(v) { #v, token_type::v },
	KOMPILATOR_TOKEN_TYPES(DEFINE_CONVERSION)
	#undef DEFINE_CONVERSION
};
token_type get_token_type_by_name(const std::string &name);

std::string get_token_type_name(token_type type);

class token
{
public:
	token_type type;
	const lexeme *lme;

	token(token_type type, const lexeme *lme);

	std::string get_type_name() const;
	bool has_contents() const;
	std::string get_contents() const;
};
