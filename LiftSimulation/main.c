/**
 * @file LiftSimulation.c
 * @brief Hauptprogramm und entry point der Liftsteuerung
 *
 * @date 20.11.2019 Erstellen des Templates
 * @author
 */ 

#include "LiftLibrary.h"
#include "LiftSimulationCommon.h"

void TestFunction(uint8_t* data, uint8_t nrOfBytes);
uint8_t FindBit(uint8_t value);


int main(void)
{
    /* Replace with your application code */
   InitializePorts();
   Usart_Init();
   RegisterTestHandler(TestFunction);
   InitializeStart();
}

void TestFunction(uint8_t* data, uint8_t nrOfBytes)
{
	if(data[0] == 1)
	{
		char *ch = "Hello-World\n";
		
		while( *ch != 0)
		{
			Usart_PutChar(*ch++);	
			SetDisplay(Floor2);		
		}
	}
	if(data[0] != 1)
	{
		uint8_t res = FindBit(data[0]);
		Usart_PutChar((char)(res + 48));
		Usart_PutChar('\n');
	}
}

uint8_t FindBit(uint8_t value)
{
	uint8_t maxsize = sizeof(value) * 8;
	uint8_t i = 0;

	if (value == 0) {
		return 0;
	}

	while ((value & 0x1) != 0x1 && i < maxsize) {
		i++;
		value = value >> 1;
	};

	return i;
}

