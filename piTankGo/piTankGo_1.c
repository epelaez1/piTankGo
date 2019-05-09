
#include "piTankGo_1.h"
int frecuenciaDespacito[160] = {0,1175,1109,988,740,740,740,740,740,740,988,988,988,988,880,988,784,0,784,784,784,784,784,988,988,988,988,1109,1175,880,0,880,880,880,880,880,1175,1175,1175,1175,1318,1318,1109,0,1175,1109,988,740,740,740,740,740,740,988,988,988,988,880,988,784,0,784,784,784,784,784,988,988,988,988,1109,1175,880,0,880,880,880,880,880,1175,1175,1175,1175,1318,1318,1109,0,1480,1318,1480,1318,1480,1318,1480,1318,1480,1318,1480,1568,1568,1175,0,1175,1568,1568,1568,0,1568,1760,1568,1480,0,1480,1480,1480,1760,1568,1480,1318,659,659,659,659,659,659,659,659,554,587,1480,1318,1480,1318,1480,1318,1480,1318,1480,1318,1480,1568,1568,1175,0,1175,1568,1568,1568,1568,1760,1568,1480,0,1480,1480,1480,1760,1568,1480,1318};
int tiempoDespacito[160] = {1200,600,600,300,300,150,150,150,150,150,150,150,150,300,150,300,343,112,150,150,150,150,150,150,150,150,300,150,300,300,150,150,150,150,150,150,150,150,150,300,150,300,800,300,600,600,300,300,150,150,150,150,150,150,150,150,300,150,300,343,112,150,150,150,150,150,150,150,150,300,150,300,300,150,150,150,150,150,150,150,150,150,300,150,300,450,1800,150,150,150,150,300,150,300,150,150,150,300,150,300,450,450,300,150,150,225,75,150,150,300,450,800,150,150,300,150,150,300,450,150,150,150,150,150,150,150,150,300,300,150,150,150,150,150,150,450,150,150,150,300,150,300,450,450,300,150,150,150,300,150,300,450,800,150,150,300,150,150,300,450};
int frecuenciaGOT[518] = {1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,1175,0,1397,0,932,0,1244,0,1175,0,1397,0,932,0,1244,0,1175,0,1046,0,831,0,698,0,523,0,349,0,784,0,523,0,523,0,587,0,622,0,698,0,784,0,523,0,622,0,698,0,784,0,523,0,622,0,698,0,587,0,698,0,466,0,622,0,587,0,698,0,466,0,622,0,587,0,523,0,523,0,587,0,622,0,698,0,784,0,523,0,622,0,698,0,784,0,523,0,622,0,698,0,587,0,698,0,466,0,622,0,587,0,698,0,466,0,622,0,587,0,523,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1175,0,587,0,622,0,587,0,523,0,587,0,784,0,880,0,932,0,1046,0,1175,0,0,1397,0,0,932,0,0,1244,0,0,1175,0,0,1397,0,0,932,0,0,1244,0,0,1175,0,0,1046,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1175,0,880,0,784,0,932,0,1244,0,0,1397,0,0,932,0,0,1175,0,0,1244,0,0,1175,0,0,932,0,0,1046,0,0,2093,0,622,0,831,0,932,0,1046,0,622,0,831,0,1046,0,0,1865,0,622,0,784,0,831,0,932,0,622,0,784,0,932,0,0,1661,0,523,0,698,0,784,0,831,0,523,0,698,0,831,0,0,1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,0,0,1661,0,1046,0,1175,0,1244,0,831,0,1175,0,1244,0,0,0,0,2489,0,0,0,0,2794,0,0,0,0,3136,0,0,2093,0,622,0,831,0,932,0,1046,0,622,0,831,0,1046,0,0,1865,0,622,0,784,0,831,0,932,0,622,0,784,0,932,0,0,1661,0,523,0,698,0,784,0,831,0,523,0,698,0,831,0,0,1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,0,0,1661,0,1046,0,1175,0,1244,0,831,0,1175,0,1244,0,0,0,0,2489,0,1397,0,0,0,2350,0,0,0,2489,0,0,0,2350,0,0,0,0,2093,0,392,0,415,0,466,0,523,0,392,0,415,0,466,0,523,0,392,0,415,0,466,0,2093,0,1568,0,1661,0,1865,0,2093,0,1568,0,1661,0,1865,0,2093,0,1568,0,1661,0,1865};
int tiempoGOT[518] = {900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1400,1400,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,116,267,28,267,28,267,28,900,89,900,89,1400,89,69,7,69,7,69,7,69,7,900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1800,1800,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,2400,69,7,69,7,69,7,69,7,900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1800,1800,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,2400,3600,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,600,59,600,133,13,150,133,13,150,1200,400,69,7,69,7,69,7,69,7,267,28,400,45,133,13,267,28,267,28,267,28,300,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,900,89,900,133,13,150,133,13,150,1200,1800,3600,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,600,59,600,133,13,150,133,13,150,1200,400,267,28,1200,400,133,13,133,13,150,900,89,900,900,89,900,600,59,600,267,28,300,600,59,600,267,28,300,1200,2400,3600,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,133,13,267,28,267,28,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,150,600,59,133,13,133,13,267,28,267,28,133,13,133,13,150,150,150,900,89,900,900,900,900,89,900,900,900,1200,2400,3600,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,150,600,59,133,13,133,13,267,28,267,28,133,13,133,13,150,150,150,600,212,133,13,150,150,267,28,300,300,400,45,450,450,133,13,150,150,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,267,28,267,28,133,13,2400,116,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,267,28,267,28,133,13,2400};
int frecuenciaTetris[55] = {1319,988,1047,1175,1047,988,880,880,1047,1319,1175,1047,988,988,1047,1175,1319,1047,880,880,0,1175,1397,1760,1568,1397,1319,1047,1319,1175,1047,988,988,1047,1175,1319,1047,880,880,0,659,523,587,494,523,440,415,659,523,587,494,523,659,880,831};
int tiempoTetris[55] = {450,225,225,450,225,225,450,225,225,450,225,225,450,225,225,450,450,450,450,450,675,450,225,450,225,225,675,225,450,225,225,450,225,225,450,450,450,450,450,450,900,900,900,900,900,900,1800,900,900,900,900,450,450,900,1800};
int frecuenciaStarwars[59] = {523,0,523,0,523,0,698,0,1046,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,1760,0,0,784,0,523,0,0,523,0,0,523,0};
int tiempoStarwars[59] = {134,134,134,134,134,134,536,134,536,134,134,134,134,134,134,536,134,402,134,134,429,357,134,134,134,134,536,134,402,134,134,429,357,134,134,134,134,536,134,402,134,134,429,357,134,134,134,429,357,1071,268,67,67,268,67,67,67,67,67};

int frecuenciasDisparo[16] = {2500,2400,2300,2200,2100,2000,1900,1800,1700,1600,1500,1400,1300,1200,1100,1000};
int tiemposDisparo[16] = {75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75};
int frecuenciasImpacto[32] = {97,109,79,121,80,127,123,75,119,96,71,101,98,113,92,70,114,75,86,103,126,118,128,77,114,119,72};
int tiemposImpacto[32] = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};

int flags_juego = 0;
int debounceTimes[5] = {0,0,0,0,0};
int shotTime = 0;
int init_isr = 0;
// wait until next_activation (absolute time)
void delay_until (unsigned int next) {
	unsigned int now = millis();
	if (next > now) {
		delay (next - now);
	}
}

//------------------------------------------------------
// FUNCIONES DE CONFIGURACION/INICIALIZACION
//------------------------------------------------------

// int ConfiguracionSistema (TipoSistema *p_sistema): procedimiento de configuracion del sistema.
// Realizará, entra otras, todas las operaciones necesarias para:
// configurar el uso de posibles librerías (e.g. Wiring Pi),
// configurar las interrupciones externas asociadas a los pines GPIO,
// configurar las interrupciones periódicas y sus correspondientes temporizadores,
// crear, si fuese necesario, los threads adicionales que pueda requerir el sistema
int ConfiguraSistema (TipoSistema *p_sistema) {
	int result = 0;
	piLock(STD_IO_BUFFER_KEY);
	if (wiringPiSetupGpio() < 0){
		printf("Unable to setup wiringPi\n\n");
		piUnlock(STD_IO_BUFFER_KEY);
		return -1;
	}
	piUnlock(STD_IO_BUFFER_KEY);
	softToneCreate(PLAYER_PWM_PIN);
	softToneWrite(PLAYER_PWM_PIN, 0);
	
	pinMode (BUTTON_PIN_UP, INPUT);
	pullUpDnControl(BUTTON_PIN_UP, PUD_UP);
	wiringPiISR (BUTTON_PIN_UP, INT_EDGE_FALLING, button_up_isr);

	pinMode (BUTTON_PIN_DOWN, INPUT);
	pullUpDnControl(BUTTON_PIN_DOWN, PUD_UP);
	wiringPiISR (BUTTON_PIN_DOWN, INT_EDGE_FALLING, button_down_isr);

	pinMode (BUTTON_PIN_RIGHT, INPUT);
	pullUpDnControl(BUTTON_PIN_RIGHT, PUD_UP);
	wiringPiISR (BUTTON_PIN_RIGHT, INT_EDGE_FALLING, button_right_isr);

	pinMode (BUTTON_PIN_LEFT, INPUT);
	pullUpDnControl(BUTTON_PIN_LEFT, PUD_UP);
	wiringPiISR (BUTTON_PIN_LEFT, INT_EDGE_FALLING, button_left_isr);

	pinMode (BUTTON_PIN_CENTER, INPUT);
	pullUpDnControl(BUTTON_PIN_CENTER, PUD_UP);
	wiringPiISR (BUTTON_PIN_CENTER, INT_EDGE_FALLING, button_center_isr);

	pinMode (IR_RX_PIN, INPUT);
	digitalWrite(IR_RX_PIN, LOW);
	pullUpDnControl(IR_RX_PIN, PUD_DOWN);
	wiringPiISR (IR_RX_PIN, INT_EDGE_RISING, ir_led_rx_isr);
	return result;
}

// int InicializaSistema (TipoSistema *p_sistema): procedimiento de inicializacion del sistema.
// Realizará, entra otras, todas las operaciones necesarias para:
// la inicializacion de los diferentes elementos de los que consta nuestro sistema,
// la torreta, los efectos, etc.
// igualmente arrancará el thread de exploración del teclado del PC
int InicializaSistema (TipoSistema *p_sistema) {
	int result = 0;
	TipoPlayer player;
	p_sistema->player = player;
	TipoTorreta torreta;
	p_sistema->torreta = torreta;
	InicializaPlayer(&p_sistema->player);
	InicializaTorreta(&p_sistema->torreta);
	printf("Ahora el incremento es: %d \n", p_sistema->torreta.servo_x.incremento);

	if (result != 0) {
		printf ("Thread didn't start!!!\n\n");
		return -1;
	}

	return result;
}

void fsm_stup (fsm_t* this){
	piLock(SYSTEM_FLAGS_KEY);
	flags_juego = 0;
	piUnlock(SYSTEM_FLAGS_KEY);

	piLock(PLAYER_FLAGS_KEY);
	flags_player = 0;
	piUnlock(PLAYER_FLAGS_KEY);
	piLock(JUEGO_FLAGS_KEY);
	flags_juego = 0;
	piUnlock(JUEGO_FLAGS_KEY);

	FinalEfecto(this);

	piLock(STD_IO_BUFFER_KEY);
	printf("Pulsa a para disparar, pulsa b para simular impacto, pulsa c para terminar la nota\n\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	return;
}
//------------------------------------------------------
// SUBRUTINAS DE ATENCION A LAS INTERRUPCIONES
//------------------------------------------------------
static void button_up_isr (void) {
	piLock(STD_IO_BUFFER_KEY);
	printf("Boton arriba pulsado\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	// Pin event (key / button event) debouncing procedure
	if (millis () < debounceTimes[BUTTON_UP]) {
		debounceTimes[BUTTON_UP] = millis () + DEBOUNCE_TIME ;
		return;
	}

	piLock (JUEGO_FLAGS_KEY);
	flags_juego |= FLAG_BUTTON_UP;
	piUnlock (JUEGO_FLAGS_KEY);

	debounceTimes[BUTTON_UP] = millis () + DEBOUNCE_TIME ;
}
static void button_down_isr (void) {
	piLock(STD_IO_BUFFER_KEY);
	printf("Boton abajo pulsado\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	// Pin event (key / button event) debouncing procedure
	if (millis () < debounceTimes[BUTTON_DOWN]) {
		debounceTimes[BUTTON_DOWN] = millis () + DEBOUNCE_TIME ;
		return;
	}

	piLock (JUEGO_FLAGS_KEY);
	flags_juego |= FLAG_BUTTON_DOWN;
	piUnlock (JUEGO_FLAGS_KEY);

	debounceTimes[BUTTON_DOWN] = millis () + DEBOUNCE_TIME ;
}
static void button_left_isr (void) {
	piLock(STD_IO_BUFFER_KEY);
	printf("Boton izquierda pulsado\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	// Pin event (key / button event) debouncing procedure
	if (millis () < debounceTimes[BUTTON_LEFT]) {
		debounceTimes[BUTTON_LEFT] = millis () + DEBOUNCE_TIME ;
		return;
	}

	piLock (JUEGO_FLAGS_KEY);
	flags_juego |= FLAG_BUTTON_LEFT;
	piUnlock (JUEGO_FLAGS_KEY);

	debounceTimes[BUTTON_LEFT] = millis () + DEBOUNCE_TIME ;
}
static void button_right_isr (void) {
	piLock(STD_IO_BUFFER_KEY);
	printf("Boton derecha pulsado\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	// Pin event (key / button event) debouncing procedure
	if (millis () < debounceTimes[BUTTON_RIGHT]) {
		debounceTimes[BUTTON_RIGHT] = millis () + DEBOUNCE_TIME ;
		return;
	}

	piLock (JUEGO_FLAGS_KEY);
	flags_juego |= FLAG_BUTTON_RIGHT;
	piUnlock (JUEGO_FLAGS_KEY);

	debounceTimes[BUTTON_RIGHT] = millis () + DEBOUNCE_TIME ;
}
static void button_center_isr (void) {
	piLock(STD_IO_BUFFER_KEY);
	printf("Botton de disparo pulsado\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	// Pin event (key / button event) debouncing procedure
	if (millis () < debounceTimes[BUTTON_CENTER]) {
		debounceTimes[BUTTON_CENTER] = millis () + DEBOUNCE_TIME ;
		return;
	}

	piLock (JUEGO_FLAGS_KEY);
	flags_juego |= FLAG_BUTTON_CENTER;
	piUnlock (JUEGO_FLAGS_KEY);

	debounceTimes[BUTTON_CENTER] = millis () + DEBOUNCE_TIME ;
}
static void ir_led_rx_isr (void) {
	printf("Comparador dando señal activa\n");
	if (init_isr == 0){
		init_isr++;
		return;
	}
	piLock(STD_IO_BUFFER_KEY);
	printf("Comparador dando señal activa\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	// Pin event (key / button event) debouncing procedure
	if (millis () < shotTime + 520) {
		return;
	}

	piLock (JUEGO_FLAGS_KEY);
	flags_juego |= FLAG_TARGET_DONE;
	piUnlock (JUEGO_FLAGS_KEY);

	shotTime = millis();
}


int main ()
{
	TipoSistema sistema;
	unsigned int next;
	char* nombre_efecto_disparo = "Disparo";
	char* nombre_efecto_impacto = "Impacto";
	// Configuracion e inicializacion del sistema
	ConfiguraSistema (&sistema);
	InicializaSistema (&sistema);
	printf("Ahora el incremento es: %d \n", sistema.torreta.servo_x.incremento);
	//InicializaPlayer(&sistema.player);
	InicializaEfecto(&(sistema.player.efecto_disparo), nombre_efecto_disparo, &(frecuenciasDisparo), &(tiemposDisparo), 16);
	InicializaEfecto(&(sistema.player.efecto_impacto), &(nombre_efecto_impacto), &(frecuenciasImpacto), &(tiemposImpacto), 32);
	
	fsm_trans_t reproductor[] = {
		{ WAIT_START, CompruebaStartDisparo, WAIT_NEXT, InicializaPlayDisparo },
		{ WAIT_START, CompruebaStartImpacto, WAIT_NEXT, InicializaPlayImpacto },
		{ WAIT_NEXT, CompruebaStartImpacto, WAIT_NEXT, InicializaPlayImpacto },
		{ WAIT_NEXT, CompruebaNotaTimeout, WAIT_END, ActualizaPlayer },
		{ WAIT_END, CompruebaFinalEfecto, WAIT_START, FinalEfecto },
		{ WAIT_END, CompruebaNuevaNota, WAIT_NEXT, ComienzaNuevaNota},
		{-1, NULL, -1, NULL },
	};
	fsm_trans_t juego[] = {
		{ WAIT_START, CompruebaComienzo, WAIT_MOVE, ComienzaSistema },
		{ WAIT_MOVE, CompruebaButtonUp, WAIT_MOVE, MueveTorretaArriba },
		{ WAIT_MOVE, CompruebaButtonDown, WAIT_MOVE, MueveTorretaAbajo },
		{ WAIT_MOVE, CompruebaButtonLeft, WAIT_MOVE, MueveTorretaIzquierda },
		{ WAIT_MOVE, CompruebaButtonRight, WAIT_MOVE, MueveTorretaDerecha },
		{ WAIT_MOVE, CompruebaTimeoutDisparo, WAIT_MOVE, FinalDisparoIR },
		{ WAIT_MOVE, CompruebaImpacto, WAIT_MOVE, ImpactoDetectado },
		{ WAIT_MOVE, CompruebaTriggerButton, WAIT_MOVE, DisparoIR },
		{ WAIT_MOVE, CompruebaFinalJuego, WAIT_END, FinalizaJuego },
		{-1, NULL, -1, NULL },
	};

	fsm_t* player_fsm = fsm_new (WAIT_START, reproductor, &(sistema.player));
	fsm_t* juego_fsm = fsm_new (WAIT_START, juego, &(sistema.torreta));
	fsm_stup(player_fsm);

	// A completar por el alumno...
	// ...
	piLock (JUEGO_FLAGS_KEY);
	flags_juego |= FLAG_SYSTEM_START;
	piUnlock (JUEGO_FLAGS_KEY);
	next = millis();
	while (1) {
		fsm_fire (player_fsm);
		fsm_fire (juego_fsm);

		next += CLK_MS;
		delay_until (next);
	}

	return 0;
}
