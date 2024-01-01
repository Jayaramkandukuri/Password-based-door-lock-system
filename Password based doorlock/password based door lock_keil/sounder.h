sbit sounder = P1^7;
void sounder_init();
void sounder_on();
void sounder_off();
void sounder_init() {
    sounder = 0; // Make sure the sounder is off initially
}

void sounder_on() {
    // Turn on the sounder by setting the appropriate pin
    sounder = 1;
}

void sounder_off() {
    // Turn off the sounder by clearing the pin
    sounder = 0;
}