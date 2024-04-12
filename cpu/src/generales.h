#ifndef GENERALES_H_
#define GENERALES_H_

#include "cpu_config.h"
#include <commons/log.h>
#include <stdbool.h>
#include <semaphore.h>

// declarado en main.c
extern t_cpu_config* config;
extern t_log* logger;

// declarado en init.c
extern int server_cpu_dispatch_fd; 
extern int server_cpu_interrupt_fd;

extern bool procesar_conexion_en_ejecucion;

extern sem_t sem_test;



#endif 