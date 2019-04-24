
#include "player.h"

int flags_player = 0;
//------------------------------------------------------
// PROCEDIMIENTOS DE INICIALIZACION DE LOS OBJETOS ESPECIFICOS
//------------------------------------------------------

//------------------------------------------------------
// void InicializaEfecto (TipoEfecto *p_efecto)
//
// Descripcion: inicializa los parametros del objeto efecto.
// Ejemplo de uso:
//
// ...
//
// TipoEfecto efecto_demo;
//
// if ( InicializaEfecto (&efecto_demo, "DISPARO", frecuenciasDisparo, tiemposDisparo, 16) < 0 ) {
// 		printf("\n[ERROR!!!][InicializaEfecto]\n");
// 		fflush(stdout);
// 		}
//
// ...
//
//------------------------------------------------------

int InicializaEfecto (TipoEfecto *p_efecto, char *nombre, int *array_frecuencias, int *array_duraciones, int num_notas) {
	strcpy(p_efecto->nombre, nombre);
	for(int i = 0; i< num_notas; i++){
		p_efecto->frecuencias[i] = *(array_frecuencias);
		p_efecto->duraciones[i] = *(array_duraciones);
		array_duraciones++;
		array_frecuencias++;
	}

	p_efecto->num_notas = num_notas;

	return p_efecto->num_notas;
}

// Procedimiento de inicializacion del objeto especifico
// Nota: parte inicialización común a InicializaPlayDisparo y InicializaPlayImpacto

void InicializaPlayer (TipoPlayer *p_player) {

	TipoEfecto efecto_disparo;
	TipoEfecto efecto_impacto;

	p_player->posicion_nota_actual = -1;
	p_player->frecuencia_nota_actual= -1;
	p_player->duracion_nota_actual=-1;
	p_player->tmr_duracion_notas = tmr_new(timer_player_duracion_nota_actual_isr);
	p_player->efecto_disparo = efecto_disparo;
	p_player->efecto_impacto = efecto_impacto;

}

//------------------------------------------------------
// FUNCIONES DE ENTRADA O DE TRANSICION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------

int CompruebaStartDisparo (fsm_t* this) {
	int result = 0;
	piLock(PLAYER_FLAGS_KEY);
	result = (flags_player & FLAG_START_DISPARO);
	piUnlock(PLAYER_FLAGS_KEY);

	return result;
}

int CompruebaStartImpacto (fsm_t* this) {
	int result = 0;
	piLock(PLAYER_FLAGS_KEY);
	result = (flags_player & FLAG_START_IMPACTO);
	piUnlock(PLAYER_FLAGS_KEY);

	return result;
}

int CompruebaNuevaNota (fsm_t* this){
	int result = 0;
	piLock(PLAYER_FLAGS_KEY);
	result = ~(flags_player & FLAG_PLAYER_END);
	piUnlock(PLAYER_FLAGS_KEY);
	// A completar por el alumno
	// ...

	return result;
}

int CompruebaNotaTimeout (fsm_t* this) {
	int result = 0;
	piLock(PLAYER_FLAGS_KEY);
	result = (flags_player & FLAG_NOTA_TIMEOUT);
	piUnlock(PLAYER_FLAGS_KEY);
	// A completar por el alumno
	// ...

	return result;
}

int CompruebaFinalEfecto (fsm_t* this) {
	int result = 0;
	piLock(PLAYER_FLAGS_KEY);
	result = (flags_player & FLAG_PLAYER_END);
	piUnlock(PLAYER_FLAGS_KEY);

	return result;
}

//------------------------------------------------------
// FUNCIONES DE SALIDA O DE ACCION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------

void InicializaPlayDisparo (fsm_t* this) {

	printf("\nInicializando disparo\n");
	fflush(stdout);
	char *nombre_efecto = "Disparo";
	TipoPlayer *p_player;
	p_player = (TipoPlayer*)(this->user_data);
	p_player->p_efecto = &(p_player->efecto_disparo);


	//p_efecto = (TipoEfecto*) p_player->p_efecto;
	//p_efecto->nombre = nombre;

	// strcpy(p_efecto->nombre , "disparo");
	// memcpy(&(frecuenciasDisparo), &(p_efecto->frecuencias), 16);
	// memcpy(&(tiemposDisparo), &(p_efecto->duraciones), 16);


	piLock(PLAYER_FLAGS_KEY);
	flags_player = 0;
	piUnlock(PLAYER_FLAGS_KEY);
	ActualizaPlayer(&(this));
	ComienzaNuevaNota(&(this));
	tmr_startms(p_player->tmr_duracion_notas,p_player->duracion_nota_actual);
	// A completar por el alumno
	// ...
}


void InicializaPlayImpacto (fsm_t* this) {
//	char *nombre_efecto = "Impacto";
//	TipoPlayer *p_player;
//	p_player = (TipoPlayer*)(this->user_data);
//
//	p_player->posicion_nota_actual = -1;
//	p_player->frecuencia_nota_actual = -1;
//	p_player->duracion_nota_actual = -1;
//	p_player->tmr_duracion_notas = tmr_new(timer_player_duracion_nota_actual_isr);
//
//	TipoEfecto *p_efecto;
//	p_efecto = (TipoEfecto*)malloc(sizeof(TipoEfecto));
//
//	*p_efecto->nombre = nombre_efecto;
//	*p_efecto->frecuencias = &(frecuenciasImpacto);
//	*p_efecto->duraciones = &(tiemposImpacto);
//	p_efecto->num_notas = 32;
//	p_player->p_efecto = p_efecto;
//
//	//strcpy(p_efecto->nombre , "imppacto");
//	//memcpy(&(frecuenciasImpacto), &(p_efecto->frecuencias), 32);
//	//memcpy(&(tiemposImpacto), &(p_efecto->duraciones), 32);
//
//
//	piLock(PLAYER_FLAGS_KEY);
//	flags_player &= (~FLAG_START_IMPACTO);
//	piUnlock(PLAYER_FLAGS_KEY);
//	ActualizaPlayer(&(this));
//	ComienzaNuevaNota(&(this));
//	tmr_startms(p_player->tmr_duracion_notas,p_player->duracion_nota_actual);
	// A completar por el alumno
	// ...
}

void ComienzaNuevaNota (fsm_t* this) {
	TipoPlayer *p_player;
	p_player =  this->user_data;
	printf("\nComienza a sonar la nota %i con frecuencia: %i\n",p_player->posicion_nota_actual, p_player->frecuencia_nota_actual);
	fflush(stdout);
	softToneWrite(PLAYER_PWM_PIN, p_player->frecuencia_nota_actual);
	tmr_startms(p_player->tmr_duracion_notas,p_player->duracion_nota_actual);



}

void ActualizaPlayer (fsm_t* this) {

	TipoPlayer *p_player;
	p_player = this->user_data;

	TipoEfecto *p_efecto;
	p_efecto = (TipoEfecto*) p_player->p_efecto;

	p_player->posicion_nota_actual += 1;
	if (p_player->posicion_nota_actual  == p_efecto->num_notas){
		piLock(PLAYER_FLAGS_KEY);
		flags_player |= FLAG_PLAYER_END;
		piUnlock(PLAYER_FLAGS_KEY);
		return;
	} else {
		flags_player = 0;
	};

	p_player->frecuencia_nota_actual = p_efecto->frecuencias[p_player->posicion_nota_actual];
	p_player->duracion_nota_actual = p_efecto->duraciones[p_player->posicion_nota_actual];
	// if (p_player->posicion_nota_actual > 0){
    	  // tmr_stop(p_player->tmr_duracion_notas);
	// }
}

void FinalEfecto (fsm_t* this) {

	TipoPlayer *p_player;
	p_player = this->user_data;

	TipoEfecto *p_efecto;
	p_efecto = (TipoEfecto*) p_player->p_efecto;

	p_player->posicion_nota_actual = -1;
	p_player->frecuencia_nota_actual = -1;
	p_player->duracion_nota_actual = -1;
	flags_player = 0;
	softToneWrite(PLAYER_PWM_PIN, 0);
}

//------------------------------------------------------
// PROCEDIMIENTOS DE ATENCION A LAS INTERRUPCIONES
//------------------------------------------------------

static void timer_player_duracion_nota_actual_isr (union sigval value) {
	piLock(PLAYER_FLAGS_KEY);
	flags_player |= FLAG_NOTA_TIMEOUT;
	piUnlock(PLAYER_FLAGS_KEY);
}
