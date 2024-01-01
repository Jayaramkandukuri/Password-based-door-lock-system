sbit motor_right_pin=P3^4;
sbit motor_left_pin=P3^5;
void motor_init();
void motor_rotate_right();
void motor_rotate_left();


void motor_init() {
    motor_right_pin = 0; // Make sure the motor is stopped initially
    motor_left_pin = 0;
}

void motor_rotate_right() {
    // Rotate the motor right by setting the appropriate pins
    motor_right_pin = 1;
    motor_left_pin = 0;
}

void motor_rotate_left() {
    // Rotate the motor left by setting the appropriate pins
    motor_right_pin = 0;
    motor_left_pin = 1;
}