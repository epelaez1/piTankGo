
#include "torreta.h"

//------------------------------------------------------
// PROCEDIMIENTOS DE INICIALIZACION DE LOS OBJETOS ESPECIFICOS
//------------------------------------------------------
int total_impactos = 0;
int shooting = 0;
int InicializaServo (TipoServo *p_servo) {
	piLock(STD_IO_BUFFER_KEY);
	printf("Inicializando Servo\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	int result = 0;

	p_servo->incremento = SERVO_INCREMENTO;
	p_servo->minimo 	= SERVO_MINIMO;
	p_servo->maximo 	= SERVO_MAXIMO;
	p_servo->inicio 	= SERVO_MINIMO + (SERVO_MAXIMO - SERVO_MINIMO)/2;
	p_servo->posicion	= p_servo->inicio;

	if(p_servo->posicion > p_servo->maximo)
		p_servo->posicion = p_servo->maximo;

	if(p_servo->posicion < p_servo->minimo)
		p_servo->posicion = p_servo->minimo;

	return result;
}
void InicializaTorreta (TipoTorreta *p_torreta) {
	piLock(STD_IO_BUFFER_KEY);
	printf("Inicializando Torreta\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	TipoServo servo_x;
	TipoServo servo_y;
	InicializaServo(&(servo_x));
	InicializaServo(&(servo_y));

	p_torreta->servo_x = servo_x;
	p_torreta->servo_y = servo_y;


	p_torreta->tmr_duracion_disparo = tmr_new(timer_duracion_disparo_isr);


}


//------------------------------------------------------
// FUNCIONES DE ENTRADA O DE TRANSICION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------

int CompruebaComienzo (fsm_t* this) {
	int result = 0;
	
	piLock(JUEGO_FLAGS_KEY);
	result = (flags_juego & FLAG_SYSTEM_START);
	piUnlock(JUEGO_FLAGS_KEY);
	
	return result;
}

int CompruebaButtonUp (fsm_t* this) {
	int result = 0;
	
	piLock(JUEGO_FLAGS_KEY);
	result = (flags_juego & FLAG_BUTTON_UP);
	piUnlock(JUEGO_FLAGS_KEY);

	return result;
}
int CompruebaButtonDown (fsm_t* this) {
	int result = 0;
	
	piLock(JUEGO_FLAGS_KEY);
	result = (flags_juego & FLAG_BUTTON_DOWN);
	piUnlock(JUEGO_FLAGS_KEY);

	return result;
}
int CompruebaButtonLeft (fsm_t* this) {
	int result = 0;
	
	piLock(JUEGO_FLAGS_KEY);
	result = (flags_juego & FLAG_BUTTON_LEFT);
	piUnlock(JUEGO_FLAGS_KEY);

	return result;
}
int CompruebaButtonRight (fsm_t* this) {
	int result = 0;
	
	piLock(JUEGO_FLAGS_KEY);
	result = (flags_juego & FLAG_BUTTON_RIGHT);
	piUnlock(JUEGO_FLAGS_KEY);

	return result;
}

int CompruebaTimeoutDisparo (fsm_t* this) {
	int result = 0;
	
	piLock(JUEGO_FLAGS_KEY);
	result = (flags_juego & FLAG_SHOOT_TIMEOUT);
	piUnlock(JUEGO_FLAGS_KEY);

	return result;

}

int CompruebaImpacto (fsm_t* this) {
	int result = 0;
	
	piLock(JUEGO_FLAGS_KEY);
	result = (flags_juego & FLAG_TARGET_DONE);
	piUnlock(JUEGO_FLAGS_KEY);

	return result;
}

int CompruebaTriggerButton (fsm_t* this) {
	int result = 0;
	
	piLock(JUEGO_FLAGS_KEY);
	result = (flags_juego & FLAG_BUTTON_CENTER);
	piUnlock(JUEGO_FLAGS_KEY);

	return result;
}

int CompruebaFinalJuego (fsm_t* this) {
	int result = 0;
	
	piLock(JUEGO_FLAGS_KEY);
	result = (flags_juego & FLAG_SYSTEM_END);
	piUnlock(JUEGO_FLAGS_KEY);

	return result;
}

//------------------------------------------------------
// FUNCIONES DE SALIDA O DE ACCION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------

void ComienzaSistema (fsm_t* this) {
	piLock(STD_IO_BUFFER_KEY);
	printf("Comienza Sistema\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	TipoTorreta *p_torreta;
	p_torreta = (TipoTorreta*)(this->user_data);
	wiringPiSetupGpio();
	pinMode(IR_TX_PIN, OUTPUT);
	digitalWrite(IR_TX_PIN, LOW);

	softPwmCreate (SERVO_HORIZONTAL_PIN, p_torreta->servo_x.inicio, SERVO_PWM_RANGE); // Internamente ya hace: piHiPri (90) ;
	softPwmWrite(SERVO_HORIZONTAL_PIN, p_torreta->servo_x.posicion);
	softPwmCreate (SERVO_VERTICAL_PIN, p_torreta->servo_y.inicio, SERVO_PWM_RANGE); // Internamente ya hace: piHiPri (90) ;
	softPwmWrite(SERVO_VERTICAL_PIN, p_torreta->servo_y.posicion);
}

void MueveTorretaArriba (fsm_t* this) {
	piLock(STD_IO_BUFFER_KEY);
	printf("Moviendo Arriba\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	TipoTorreta *p_torreta;
	p_torreta = (TipoTorreta*)(this->user_data);
	

	
	piLock(JUEGO_FLAGS_KEY);
	flags_juego &= (~FLAG_BUTTON_UP);
	piUnlock(JUEGO_FLAGS_KEY);

	if(p_torreta->servo_y.posicion + p_torreta->servo_y.incremento <= p_torreta->servo_y.maximo) {
		p_torreta->servo_y.posicion = p_torreta->servo_y.posicion + p_torreta->servo_y.incremento;

		softPwmWrite(SERVO_VERTICAL_PIN, p_torreta->servo_y.posicion);
		printf("[SERVO][POSICION]=[%d]\n", p_torreta->servo_y.posicion);
		fflush(stdout);
	}
}

void MueveTorretaAbajo (fsm_t* this) {
	piLock(STD_IO_BUFFER_KEY);
	printf("Moviendo Abajo\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	TipoTorreta *p_torreta;
	p_torreta = (TipoTorreta*)(this->user_data);


	piLock(JUEGO_FLAGS_KEY);
	flags_juego &= (~FLAG_BUTTON_DOWN);
	piUnlock(JUEGO_FLAGS_KEY);

	if(p_torreta->servo_y.posicion - p_torreta->servo_y.incremento >= p_torreta->servo_y.minimo) {
		printf("La  posicion anterior era = %d \n", p_torreta->servo_y.posicion);
		printf("El incremento es = %d \n", p_torreta->servo_y.incremento);

		p_torreta->servo_y.posicion = p_torreta->servo_y.posicion - p_torreta->servo_y.incremento;
		printf("La nueva posicion es = %d \n", p_torreta->servo_y.posicion);

		softPwmWrite(SERVO_VERTICAL_PIN, p_torreta->servo_y.posicion);

		printf("[SERVO][POSICION]=[%d]\n", p_torreta->servo_y.posicion);
		fflush(stdout);
	}
}

void MueveTorretaIzquierda (fsm_t* this) {
	piLock(STD_IO_BUFFER_KEY);
	printf("Moviendo Izquierda\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	TipoTorreta *p_torreta;
	p_torreta = (TipoTorreta*)(this->user_data);
	
	
	piLock(JUEGO_FLAGS_KEY);
	flags_juego &= (~FLAG_BUTTON_LEFT);
	piUnlock(JUEGO_FLAGS_KEY);

	if(p_torreta->servo_x.posicion - p_torreta->servo_x.incremento >= p_torreta->servo_x.minimo) {
		p_torreta->servo_x.posicion = p_torreta->servo_x.posicion - p_torreta->servo_x.incremento;

		softPwmWrite(SERVO_HORIZONTAL_PIN, p_torreta->servo_x.posicion);

		printf("[SERVO][POSICION]=[%d]\n", p_torreta->servo_x.posicion);
		fflush(stdout);
	}
}

void MueveTorretaDerecha (fsm_t* this) {
	piLock(STD_IO_BUFFER_KEY);
	printf("Moviendo Derecha\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	TipoTorreta *p_torreta;
	p_torreta = (TipoTorreta*)(this->user_data);

	
	piLock(JUEGO_FLAGS_KEY);
	flags_juego &= (~FLAG_BUTTON_RIGHT);
	piUnlock(JUEGO_FLAGS_KEY);

	if(p_torreta->servo_x.posicion + p_torreta->servo_x.incremento <= p_torreta->servo_x.maximo) {
		p_torreta->servo_x.posicion = p_torreta->servo_x.posicion + p_torreta->servo_x.incremento;

		softPwmWrite(SERVO_HORIZONTAL_PIN, p_torreta->servo_x.posicion);

		printf("[SERVO][POSICION]=[%d]\n", p_torreta->servo_x.posicion);
		fflush(stdout);
	}
}

void DisparoIR (fsm_t* this) {
	shooting = 1;
	piLock(STD_IO_BUFFER_KEY);
	printf("Disparando\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	TipoTorreta *p_torreta;
	p_torreta = this->user_data;
	
	piLock(JUEGO_FLAGS_KEY);
	flags_juego &= (~FLAG_BUTTON_CENTER);
	piUnlock(JUEGO_FLAGS_KEY);
	
	piLock(STD_IO_BUFFER_KEY);
	printf("Cambiando Flags\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	
	piLock(PLAYER_FLAGS_KEY);
	flags_player |= FLAG_START_DISPARO;
	piUnlock(PLAYER_FLAGS_KEY);
	piLock(STD_IO_BUFFER_KEY);
	printf("Encendiendo led\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	digitalWrite(IR_TX_PIN, HIGH);
	//tmr_startms(p_torreta->tmr_duracion_disparo, (int) (SHOOTING_PERIOD));
}

void FinalDisparoIR (fsm_t* this) {
	shooting = 0;
	piLock(STD_IO_BUFFER_KEY);
	printf("Final disparo: Se apaga el led\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	
	piLock(JUEGO_FLAGS_KEY);
	flags_juego &= (~FLAG_SHOOT_TIMEOUT);
	piUnlock(JUEGO_FLAGS_KEY);

	digitalWrite(IR_TX_PIN, LOW);
}

void ImpactoDetectado (fsm_t* this) {
	if (!shooting) {
		printf("Se ha detectado un impacto pero no se estaba disparando\n");
		piLock (JUEGO_FLAGS_KEY);
		flags_juego &= (~FLAG_TARGET_DONE);
		piUnlock (JUEGO_FLAGS_KEY);

		return;
	}
	piLock(STD_IO_BUFFER_KEY);
	printf("Se ha detectado el impacto\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	// Poner una variable de tiempo de el ultimo impacto detectado;
	piLock(PLAYER_FLAGS_KEY);
	flags_player |= FLAG_START_IMPACTO;
	piUnlock(PLAYER_FLAGS_KEY);
	piLock (JUEGO_FLAGS_KEY);
	flags_juego &= (~FLAG_TARGET_DONE);
	piUnlock (JUEGO_FLAGS_KEY);

	total_impactos++;
	printf("El numero de impactos es %d \n", total_impactos);
	if (total_impactos == 5) {
		piLock(PLAYER_FLAGS_KEY);
		flags_juego |= FLAG_SYSTEM_END;
		piUnlock(PLAYER_FLAGS_KEY);
	}

}

void FinalizaJuego (fsm_t* this) {
	piLock(STD_IO_BUFFER_KEY);
	printf("Fin del juego. Has acertado 5 veces al objetivo\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	exit(0);
}
static void timer_duracion_disparo_isr (union sigval value) {
	piLock(STD_IO_BUFFER_KEY);
	printf("Timeout del disparo led\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);

	piLock(JUEGO_FLAGS_KEY);
	flags_juego |= FLAG_SHOOT_TIMEOUT;
	piUnlock(JUEGO_FLAGS_KEY);

}
