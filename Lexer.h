#pragma once
#include <string>
#include <vector>
#include <cstdio>

class Lexer {
public:
    enum Token {
        tok_eof = -1,
        tok_identifier = -2,
        tok_number = -3,
        // Conditionals
        tok_if = -4,
        tok_elseif = -5,
        tok_else = -6,
        tok_while = -7,
        tok_for = -8,
        // Types
        tok_int = -9,
        tok_float = -10,
        tok_char = -11,
        tok_string = -12,
        tok_bool = -13,
        tok_return = -14,
        tok_null = -15,
        tok_true = -16,
        tok_false = -17,
        // Syntax
        tok_left_paren = -18,
        tok_right_paren = -19,
        tok_left_bracket = -20,
        tok_right_bracket = -21,
        tok_left_brace = -22,
        tok_right_brace = -23,
        tok_function = -24,
        tok_single_quote = -25,
        tok_double_quote = -26,
        tok_semi_colon = -41,
        //Signs
        tok_plus = -27,
        tok_minus = -28,
        tok_star = -29,
        tok_slash = -30,
        tok_mod = -31,
        tok_equal = -32,
        tok_greater = -33,
        tok_less = -34,
        tok_greater_equal = -35,
        tok_less_equal = -36,
        tok_double_equal = -37,
        tok_and = -38,
        tok_or = -39,
        tok_not = -40,
    };
    int last_char = ' ';
    std::string id_str;
    double num_val;
    std::vector<std::string> func_name, func_type, func_args;
    int GetToken(FILE* f);
};

