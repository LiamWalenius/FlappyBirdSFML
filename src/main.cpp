#include "program.hpp"

int main(){
    if(!Program::initialize()){
        return EXIT_FAILURE;
    }

    Program::startMainLoop();
}