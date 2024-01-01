sbit LED1 = P3^2;
sbit LED2 = P3^3;
void led_init();
void led_on1();
void led_off1();
void led_on2();
void led_off2();
void led_init() {
    LED1 = 0; // Turn off the LED initially
	  LED2 = 0;
	  
}
void led_on1() {
    LED1 = 1; // Turn on green LED
}
void led_on2() {
    LED2 = 1; // Turn on red LED
}
void led_off1(){
	LED1 = 0;  // Turn off green LED
}
void led_off2(){
	LED2 = 0; // Turn off red LED
}

