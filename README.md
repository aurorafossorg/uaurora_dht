# DHT Sensor Library
Arduino compatible library for DHT-based temperature and humidity sensors

## Usage
```cpp
#include <DHT11.h>

DHT11 dht11;

void setup()
{
	dht11.pin = 2;
}

void loop()
{
	delay(dht11.samplingPeriod());

	dht11.read();

	float humidity = dht11.getHumidity();
	float temperature = dht11.getTemperature();

	//...
}
```