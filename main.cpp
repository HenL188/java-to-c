#include <iostream>
#include "Lexer.h"
#include <cstdio>

int main()
{
    Lexer lexer;
    FILE *file = fopen("main.java", "r");
    if (file == nullptr)
    {
        std::cerr << "Failed to open file" << std::endl;
    }
    int tok;
    while ((tok = lexer.GetToken(file)) != lexer.tok_eof)
    {
        if (tok == lexer.tok_left_paren) {
            while ((tok = lexer.GetToken(file)) != lexer.tok_right_paren) {
                lexer.func_args.push_back(lexer.id_str);
                lexer.func_args.push_back(std::to_string(tok));
            }
        }
        if (tok == lexer.tok_number)
        {
           printf("Number: %f\n", lexer.num_val);
        }
        else if (tok == lexer.tok_identifier)
        {
            std::cout << "ID: " << lexer.id_str << std::endl;
        }
        else
        {
            std::cout << "Token: " << tok << std::endl;
        }
    }
    return 0;
}