#include <stdio.h>
#include <stdlib.h>
#include <commons/log.h>

#include "cpu_config.h"
#include <logging/logging.h>
#include "generales.h"
#include "init.h"

t_log* logger = NULL;
t_cpu_config* config = NULL;

int main(int argc, char* argv[]) {

    init_cpu();
    
    logger = iniciar_logger("cpu.log", "CPU");
    log_info(logger, "Iniciando Modulo CPU \n");
    
    config = init_cpu_config("cpu.config");

    iniciar_servidores();
    
    liberar_cpu();

    return 0;
}



