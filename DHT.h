#ifndef DHT_H
#define DHT_H

#define SENSOR_DHT_OK 0
#define SENSOR_DHT_SAME 1
#define SENSOR_DHT_ERROR_CHECKSUM -1
#define SENSOR_DHT_ERROR_TIMEOUT -2

#include <stdint.h>

class DHT {
public:
	inline float getHumidity() { return this->humidity; }
	inline float getTemperature() { return this->temperature; }

	virtual int read(void);
	virtual int samplingPeriod(void);

	uint8_t pin;

protected:
	float humidity;
	float temperature;

	unsigned long lastTime;
};

#endif /* DHT_H */