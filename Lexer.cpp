#include "Lexer.h"

int Lexer::GetToken(FILE* f) {
    static int last_char = ' ';
    while (isspace(last_char))
        last_char = fgetc(f);
    if (last_char == '/') {
        last_char = fgetc(f);
        if (last_char == '/') {
            do
                last_char = fgetc(f);
            while (last_char != EOF && last_char != '\n' && last_char != '\r');
            if (last_char != EOF)
                return GetToken(f);
        }
    }
    if (isalpha(last_char) || last_char == '_' || last_char == '.') {
        id_str = last_char; // Store the first character
        while (isalnum(last_char = fgetc(f)) || last_char == '.')
            id_str += last_char;
        if (id_str == "void") {
            while (isalnum(last_char = fgetc(f)))
                id_str += last_char;
            func_name.push_back(id_str);
            func_type.emplace_back("void");
            last_char = fgetc(f);
            return tok_function;
        }
        if (id_str == "String") {
            last_char = fgetc(f);
            return tok_string;
        }
        return tok_identifier;
    }
    if (isdigit(last_char) || last_char == '.') {
        std::string NumStr; // Buffer for the number string
        do {
            NumStr += last_char;
            last_char = fgetc(f);
        } while (isdigit(last_char) || last_char == '.');

        num_val = strtod(NumStr.c_str(), nullptr);
        return tok_number;
    }
    switch (last_char) {
        case 40:
            last_char = fgetc(f);
            return tok_left_paren;
        case 41:
            last_char = fgetc(f);
            return tok_right_paren;
        case 123:
            last_char = fgetc(f);
            return tok_left_bracket;
        case 125:
            last_char = fgetc(f);
            return tok_right_bracket;
        case 91:
            last_char = fgetc(f);
            return tok_left_brace;
        case 93:
            last_char = fgetc(f);
            return tok_right_brace;
        case 34:
            last_char = fgetc(f);
            return tok_double_quote;
        case 39:
            last_char = fgetc(f);
            return tok_single_quote;
        case 59:
            last_char = fgetc(f);
            return tok_semi_colon;
        default:
            break;
    }

    if (last_char == EOF)
        return tok_eof;

    // Otherwise, return the character as its ASCII value
    int ThisChar = last_char;
    last_char = fgetc(f);
    return ThisChar;
}
