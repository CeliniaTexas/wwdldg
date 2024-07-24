#include <fstream>
#include <iostream>
#include "./IR/genIR.h"
#include "./AST/ast.h"
#include "./AST/define.h"
#include "./IR/type.h"
extern unique_ptr<CompUnitAST> root;
extern int yyparse();
extern FILE *yyin;
int main(int argc, char **argv) {
    assert(argc >= 2);
    char *filename;
    bool print_ir = false;
    
    for (int i = 1; i < argc; i++) {
        if (argv[i] == std::string("-ir")) {
            print_ir = true;
        } else {
            filename = argv[i];
        }
    }
    yyin = fopen(filename, "r");
    if (yyin == nullptr) {
        std::cout << "yyin open" << filename << "failed" << std::endl;
        return -1;
    }
    yyparse();
    GenIR genIR;
    root -> accept(genIR);
    std::unique_ptr<Module> m = genIR.getModule();
    std::string IR = m -> print();
    if (print_ir){
        std::cout << IR << std::endl;
    }
    return 0;
}
