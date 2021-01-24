# CGuard


CGuard is an inexpensive, portable anti-theft device that detects suspicious activity when the driver is not in the car. Our long-term goal is to reduce car theft in the Worcester community by cheaply mass-producing this device and distributing it widely. In this hackathon, we aim to show a proof of concept of this device where we show that an Arduino board, acoustic sensor, accelerometer, GPS, and GSM module is all that’s needed for a comprehensive and inexpensive anti-theft tool.


We have an Arduino as the central processing unit; when we mass produce this product, we can opt for a cheaper microcontroller for under less than a dollar. The Arduino has acoustic sensors to detect glass breaking. Our algorithm and future next steps will ensure that the sensors can only detect glass breaking and not other types of sounds to eliminate false alarms. We have researched and developed various approaches to create this algorithm based on timing, amplitudes, and frequencies of glass-breaking. If we detect glass breaking, our GSM module will send a text message to ping the user of the theft immediately.

If the thieves decide to run away with the car, our accelerometer will pick up the motion and activate our GPS module that will track the current location of the car. Again, our GSM module will communicate this information with the user, where the user can query the location via SMS.
