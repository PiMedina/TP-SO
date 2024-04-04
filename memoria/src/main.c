#include <stdio.h>
#include <stdlib.h>
#include <commons/txt.h>

#include <utils/hello.h>

int main(int argc, char* argv[]) {
    txt_write_in_stdout("Hola, Operativos!!\n");

    say_hello("Hola desde la libreria estatica");

    return 0;
}
