#include "DHT11.h"

DHT11 dht11;

void setup()
{
	Serial.begin(9600);

	dht11.pin = 2;
}

void loop()
{
	delay(dht11.samplingPeriod());

	dht11.read();

	float humidity = dht11.getHumidity();
	float temperature = dht11.getTemperature();

	//...

	Serial.print(humidity);
	Serial.print("\t");
	Serial.println(temperature);
}