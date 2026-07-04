# UART-Driver-Simulation

## Overview

This project simulates a UART (Universal Asynchronous Receiver/Transmitter) driver in C without requiring hardware. It follows a modular embedded software architecture using separate source and header files. A circular (ring) buffer is used to manage transmit (TX) and receive (RX) data efficiently.

## Project Structure

- `main.c` – Application layer for testing the UART driver.
- `uart.c` / `uart.h` – UART driver implementation and API declarations.
- `ring_buffer.c` / `ring_buffer.h` – Circular buffer implementation.

## Working

1. Initializes the UART driver and TX/RX ring buffers.
2. Sends characters using the UART transmit API.
3. Receives characters through the UART receive API.
4. Stores incoming data in the receive ring buffer.
5. Reads data from the receive buffer until it becomes empty.
6. Detects and reports:
   - TX Buffer Full
   - RX Buffer Full
   - RX Buffer Empty

## Features

- UART Driver Simulation
- Circular (Ring) Buffer
- Modular Embedded Software Design
- Transmit and Receive APIs
- Buffer Overflow Detection
- Buffer Underflow Detection

## Test Results

- Normal UART Transmission
- Buffer Overflow Handling
- Buffer Underflow Handling
