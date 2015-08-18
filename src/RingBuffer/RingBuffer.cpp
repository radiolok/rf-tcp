/*Ring buffer implementation*/

#include "RingBuffer.h"

RingBuffer::RingBuffer(){
	lastread = 0;
	lastwrite = 0;
	quantity = BUFFERQUANTITY;
}

RingBuffer::~RingBuffer(){

}

uint8_t RingBuffer::Put(uint8_t *data, uint8_t length){
	uint8_t status = 0;
	lastwrite++;
	if (lastwrite == quantity){
		lastwrite = 0;
	}
	if (lastwrite == lastread){
		status = 1;//overflow
	}
	if (BUFFERLENGTH > length){
		length = BUFFERLENGTH;
	}
	//copy:
	memcpy(buffer[lastwrite].data, data, length);


	return status;
}

uint8_t RingBuffer::Get(uint8_t *data){
	lastread++;
	if (lastread == quantity){
		lastread = 0;
	}
	uint8_t length = buffer[lastread].length;
	memcpy(data, buffer[lastread].data, length);
	return length;
}


uint8_t RingBuffer::Clear(){
	lastread = lastwrite;

	return 0;
}

