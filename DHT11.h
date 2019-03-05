#ifndef DHT11_H
#define DHT11_H

#include "DHT.h"

class DHT11 : public DHT {
public:
	int read(void);
	inline int samplingPeriod(void) { return 1000; }
};

#endif /* DHT11_H */