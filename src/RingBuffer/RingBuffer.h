/*Ring buffer implementation*/
#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFERLENGTH 64
#define BUFFERQUANTITY 8

struct ringbuffer{
	uint8_t data[BUFFERLENGTH];
	uint8_t length;
};

class RingBuffer{
	public:
		RingBuffer();
		
		~RingBuffer();
		
		uint8_t Put(uint8_t *data, uint8_t length);
		
		uint8_t Get(uint8_t *data);
		
		uint8_t Clear();
		
	private:
		ringbuffer buffer[BUFFERQUANTITY];
		
		uint8_t lastwrite;
		
		uint8_t lastread;
		
		uint8_t quantity;


};

#endif
