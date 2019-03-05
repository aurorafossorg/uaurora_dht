#include "DHT11.h"

#if ARDUINO < 100
	#include <WProgram.h>
#else
	#include <Arduino.h>
#endif

int DHT11::read(void)
{
	unsigned long startTime = millis();
	if((unsigned long)(startTime - this->lastTime) < 999L)
		return SENSOR_DHT_SAME;
	
	this->lastTime = startTime;

	digitalWrite(this->pin, LOW);
	pinMode(this->pin, OUTPUT);
	
	delay(18);

	pinMode(this->pin, INPUT);
	digitalWrite(this->pin, HIGH);

	uint16_t humidity;
	uint16_t temperature;
	uint16_t data = 0;

	for(int8_t i = -3; i < 2 * 40; i++)
	{
		byte age;
		startTime = micros();

		do {
			age = (unsigned long)(micros() - startTime);
			if(age > 90 )
				return SENSOR_DHT_ERROR_TIMEOUT;
		}
		while (digitalRead(this->pin) == (i & 1) ? HIGH : LOW);

		if(i>=0 && (i & 1))
		{
			data <<= 1;

			if(age > 30)
				data |= 1;
		}
		
		switch(i) {
			case 31:
				humidity = data;
				break;
			case 63:
				temperature = data;
				data = 0;
				break;
		}
	}

	if( (byte)(((byte)humidity) + (humidity >> 8) + ((byte)temperature) + (temperature >> 8)) != data)
		return SENSOR_DHT_ERROR_CHECKSUM;

	this->humidity = humidity >> 8;
	this->temperature = temperature >> 8;

	return SENSOR_DHT_OK;
}