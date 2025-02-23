#include <stdio.h>
#include <stdint.h>
#include "vsd_board.h"  // Include the appropriate board-specific header file

#define TRIG_PIN PA0  // Trigger pin for ultrasonic sensor
#define ECHO_PIN PA1  // Echo pin for ultrasonic sensor
#define LED_PIN  PB0  // LED pin

void delay_ms(uint32_t ms) {
    volatile uint32_t count;
    while (ms--) {
        for (count = 0; count < 5000; count++); // Simple delay loop
    }
}

void send_trigger_pulse() {
    digitalWrite(TRIG_PIN, LOW);
    delay_ms(2);
    digitalWrite(TRIG_PIN, HIGH);
    delay_ms(10);
    digitalWrite(TRIG_PIN, LOW);
}

uint32_t measure_echo_time() {
    while (digitalRead(ECHO_PIN) == 0); // Wait for HIGH
    uint32_t start_time = get_micros(); // Get start time

    while (digitalRead(ECHO_PIN) == 1); // Wait for LOW
    uint32_t end_time = get_micros();   // Get end time

    return end_time - start_time;  // Return pulse duration in microseconds
}

float calculate_distance(uint32_t time_us) {
    return (time_us * 0.0343) / 2.0; // Convert to cm
}

int main() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    while (1) {
        send_trigger_pulse();  // Send trigger pulse
        uint32_t echo_time = measure_echo_time();  // Measure the time of the echo pulse
        float distance = calculate_distance(echo_time);  // Convert time to distance

        if (distance < 10.0) {  // If an object is within 10 cm
            digitalWrite(LED_PIN, HIGH);  // Turn LED ON
            delay_ms(500);  // Keep LED ON for 500ms
            digitalWrite(LED_PIN, LOW);  // Turn LED OFF
            delay_ms(500);
        } else {
            digitalWrite(LED_PIN, LOW);  // Keep LED OFF if no object is nearby
        }
    }

    return 0;
}
