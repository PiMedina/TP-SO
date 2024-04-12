#include <stdio.h>
#include <stdlib.h>
#include <commons/log.h>

#include "kernel_config.h"
#include <logging/logging.h>
#include <conexiones/conexiones.h>
#include "generales.h"
#include <serializacion/serializacion.h>
#include <enum/enum.h>
#include "procesar_conexion.h"

int main(int argc, char* argv[]) {

    t_log* logger = iniciar_logger("kernel.log", "KERNEL");
    log_info(logger, "Iniciando Modulo Kernel");
   
    t_kernel_config* config = init_kernel_config("kernel.config");

    int conexion_cpu_dispatch = crear_conexion(config->ip_cpu, config->puerto_cpu_dispatch, "CPU_DISPATCH" , logger);
    //enviar_handshake(conexion_cpu_dispatch, HANDSHAKE, "KERNEL", "CPU_DISPATCH", logger);

    int conexion_cpu_interrupt = crear_conexion(config->ip_cpu, config->puerto_cpu_interrupt, "CPU_INTERRUPT", logger);
    //enviar_handshake(conexion_cpu_dispatch, HANDSHAKE, "KERNEL", "CPU_INTERRUPT", logger);

    int conexion_memoria = crear_conexion(config->ip_memoria, config->puerto_memoria, "MEMORIA", logger);
    //enviar_handshake(conexion_cpu_dispatch, HANDSHAKE, "KERNEL", "MEMORIA", logger);

    int server_fd = iniciar_servidor("KERNEL", config->ip_kernel, config->puerto_kernel, logger);

    log_info(logger, "KERNEL Escuchando Conexiones");
    while(server_listen(logger, "KERNEL", server_fd, (void*)procesar_conexion_io));

    log_destroy(logger);
    liberar_kernel_config(config);
    liberar_conexion(conexion_cpu_dispatch);
    liberar_conexion(conexion_cpu_interrupt);
    liberar_conexion(conexion_memoria);
    
    return 0;
}
