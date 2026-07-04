#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>

#define BUFFER_SIZE 16

typedef struct
{
    uint8_t buffer[BUFFER_SIZE];
    int head;
    int tail;
    int count;
} RingBuffer;

void RingBuffer_Init(RingBuffer *rb);
int RingBuffer_IsEmpty(RingBuffer *rb);
int RingBuffer_IsFull(RingBuffer *rb);
int RingBuffer_Push(RingBuffer *rb, uint8_t data);
int RingBuffer_Pop(RingBuffer *rb, uint8_t *data);

#endif
