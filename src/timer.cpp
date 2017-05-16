
#include "agl/timer.h"

// Construtor da classe
AGL::Timer::Timer()
{
	milliseconds = 0;
}
		
// Inicia a contagem de tempo
void AGL::Timer::start()
{
	milliseconds = SDL_GetTicks();
}

// Finaliza a contagem de tempo, retornando o tempo gasto (em s)
float AGL::Timer::stop()
{
	int nSpan = SDL_GetTicks() - milliseconds;
	return nSpan/1000.0;
}

// Finaliza a contagem de tempo, retornando o tempo gasto (em ms)
int AGL::Timer::stopMs()
{
	return SDL_GetTicks() - milliseconds;
}
		
// Inicia a contagem de tempo
void AGL::Timer::startMachineTimer()
{
	t1 = clock();
}

// Finaliza a contagem de tempo, retornando o tempo gasto (em s)
float AGL::Timer::stopMachineTimer()
{
	clock_t t2 = clock();
	return ((float)(t2 - t1))/CLOCKS_PER_SEC;
}

