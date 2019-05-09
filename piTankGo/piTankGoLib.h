
#ifndef _PITANKGOLIB_H_
#define _PITANKGOLIB_H_

#include <stdio.h>

#include "fsm.h"
#include "tmr.h"

#define CLK_MS 10

// INTERVALO DE GUARDA ANTI-REBOTES
#define	DEBOUNCE_TIME	10
// DURACION DISPARO IR
#define SHOOTING_PERIOD 500

// CLAVES PARA MUTEX
#define	SYSTEM_FLAGS_KEY		1
#define	PLAYER_FLAGS_KEY		2
#define	STD_IO_BUFFER_KEY		3
#define JUEGO_FLAGS_KEY  		4
#define BUTTON_FLAGS_KEY  		5

// Distribucion de pines GPIO empleada para los pulsadores
#define BUTTON_PIN_UP			17
#define BUTTON_PIN_DOWN			27
#define BUTTON_PIN_LEFT			22
#define BUTTON_PIN_RIGHT		10
#define BUTTON_PIN_CENTER		 9

// Distribucion de pines GPIO empleada para el enlace IR
#define	IR_TX_PIN		20
#define	IR_RX_PIN		26

// Distribucion de pines GPIO empleada para la reproducción de efectos
#define PLAYER_PWM_PIN 	18

// Distribucion de pines GPIO empleada para el control de los servos
#define	SERVO_VERTICAL_PIN		19
#define	SERVO_HORIZONTAL_PIN	16
#define SERVO_3V3_PIN           26
// PWM SW: el SO provoca que cuanto más alta sea la frecuencia de la señal PWM de control menos estable resulta esta (i.e. cimbreo del servo)
// Interesa una frecuencia para la señal de control relativamente baja para minimizar el cimbreo
// El problema es que tampoco puede ser demasiado baja o de lo contrario el control del servo se resiente y su respuesta es peor
// (más lenta ante variaciones rápidas del ciclo de trabajo de la señal de control)
#define SERVO_PWM_RANGE		400 // 100 * 400 = 40,000 µS = 40 ms // 25 Hz

#define SERVO_INCREMENTO	1
#define SERVO_MINIMO		9
#define SERVO_MAXIMO		22


// FLAGS FSM CONTROL DE JUEGO Y TORRETA
#define FLAG_SYSTEM_START 		0x00000001
#define FLAG_BUTTON_UP 			0x00000002
#define FLAG_BUTTON_DOWN 		0x00000004
#define FLAG_BUTTON_LEFT		0x00000008
#define FLAG_BUTTON_RIGHT		0x00000010
#define FLAG_BUTTON_CENTER		0x00000020
#define FLAG_SHOOT_TIMEOUT		0x00000040
#define FLAG_TARGET_DONE		0x00000080
#define FLAG_SYSTEM_END			0x00000100

// FLAGS FSM REPRODUCCION DE EFECTOS DE SONIDO
#define FLAG_START_DISPARO 		0x01
#define FLAG_START_IMPACTO 		0x02
#define FLAG_PLAYER_STOP 		0x04
#define FLAG_PLAYER_END			0x08
#define FLAG_NOTA_TIMEOUT		0x10

enum interruption_sources {
	TARGET_ISR,
	BUTTON_UP_ISR,
	BUTTON_DOWN_ISR,
	BUTTON_LEFT_ISR,
	BUTTON_RIGHT_ISR,
	BUTTON_CENTER_ISR
};

extern int flags_system;
extern int flags_player;
extern int flags_button;
extern int flags_juego;

extern int frecuenciaDespacito[];
extern int tiempoDespacito[];
extern int frecuenciaGOT[];
extern int tiempoGOT[];
extern int frecuenciaTetris[];
extern int tiempoTetris[];
extern int frecuenciaStarwars[];
extern int tiempoStarwars[];

extern int frecuenciasDisparo[];
extern int tiemposDisparo[];
extern int frecuenciasImpacto[];
extern int tiemposImpacto[];

#endif /* _PITANKGOLIB_H_ */
