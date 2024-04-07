#include <stdio.h>
#include <stdlib.h>

#include <utils/hello.h>

#include "kernel_config.h"

int main(int argc, char* argv[]) {

    say_hello("Hola desde la libreria estatica");

    t_kernel_config* config = init_kernel_config("kernel.config");

    int keys = config_keys_amount(config->config);
    printf("cantidad de keys = %d \n", keys);

    liberar_kernel_config(config);
    
    return 0;
}
