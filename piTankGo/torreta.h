/*
 * torreta.h
 *
 *  Created on: 21 de enero de 2019
 *      Author: FFM
 */

#ifndef _TORRETA_H_
#define _TORRETA_H_

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#include "piTankGoLib.h"

typedef struct {
	int inicio; // Valor correspondiente a la posicion inicial del servo
	int incremento; // Cuantía en que se incrementa el valor de la posicion con cada movimiento del servo
	int minimo; // Valor mínimo correspondiente a la posicion del servo
	int maximo; // Valor maximo correspondiente a la posicion del servo
	int posicion; // Posicion Actual del servo
} TipoServo;



typedef struct {
	TipoServo servo_x;
	TipoServo servo_y;
	tmr_t* tmr_duracion_disparo;
	// A completar por el alumno (declaracion del temporizador para control duracion disparo)
	// ...
} TipoTorreta;

extern int flags_juego;

// Prototipos de procedimientos de inicializacion de los objetos especificos
void InicializaTorreta (TipoTorreta *p_torreta);

// Prototipos de funciones de entrada
int CompruebaComienzo (fsm_t* this);
int CompruebaButtonUp (fsm_t* this);
int CompruebaButtonDown (fsm_t* this);
int CompruebaButtonLeft (fsm_t* this);
int CompruebaButtonRight (fsm_t* this);
int CompruebaTimeoutDisparo (fsm_t* this);
int CompruebaImpacto (fsm_t* this);
int CompruebaTriggerButton (fsm_t* this);
int CompruebaFinalJuego (fsm_t* this);

// Prototipos de funciones de salida
void ComienzaSistema (fsm_t* this);
void MueveTorretaArriba (fsm_t* this);
void MueveTorretaAbajo (fsm_t* this);
void MueveTorretaIzquierda (fsm_t* this);
void MueveTorretaDerecha (fsm_t* this);
void DisparoIR (fsm_t* this);
void FinalDisparoIR (fsm_t* this);
void ImpactoDetectado (fsm_t* this);
void FinalizaJuego (fsm_t* this);

// Prototipos de procedimientos de atencion a las interrupciones
static void timer_duracion_disparo_isr (union sigval value);

#endif /* _TORRETA_H_ */
