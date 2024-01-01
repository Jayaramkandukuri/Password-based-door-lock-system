#include <regx51.h>
#include "lcd.h"
#include "keypad.h"
#include "Led.h"
#include "dc_motor.h"
#include "sounder.h"

unsigned char dum[5], pass[5] = "1234";
unsigned char option = '0';
int a = 0, b;
char s;

void function() {
    while (1) {
        sounder_init();
        led_init();
        lcd_init();

        lcd_cmd(0x01);
        lcd_cmd(0x80);
        lcd_string("Enter code:");

        while (key_interrupt());
        b = 0xc0;
        lcd_cmd(b);

        while (a < 4) {
            s = get_key();
            dum[a] = s;
            lcd_data('*');
            a++;
        }

        dum[a] = '\0';
        a = 0;

        if ((dum[0] == pass[0]) && (dum[1] == pass[1]) && (dum[2] == pass[2]) && (dum[3] == pass[3])) {
            lcd_cmd(0x01);
            lcd_cmd(0x80);
            led_on1();
            lcd_string("valid code");
            delay(250);
            lcd_cmd(0x01);
            lcd_cmd(0x80);
            lcd_string("1 Open  2 Close");
            lcd_cmd(0xc0);
            lcd_string("3 Change code");
            led_off1();

            lcd_cmd(0xd4);
                option = get_key(); // Wait for user input
            if (option == '1') {
                // Code to open and close the door
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("Door is opening");
                motor_rotate_right();
                delay(1000);
                motor_init();
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("Door is opened");
                delay(1000);
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("Door is Closing");
                motor_rotate_left();
                delay(1000);
                motor_init();
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("Door is Closed");
                delay(1000);
            } else if (option == '2') {
                // Code to close the door
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("Door is Closing");
                motor_rotate_left();
                delay(1000);
                motor_init();
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("Door is Closed");
                delay(1000);
            } else if (option == '3') {
                // Code to change the code
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("Enter old code:");
                while (key_interrupt());
                b = 0xc0;
                lcd_cmd(b);

                while (a < 4) {
                    s = get_key();
                    dum[a] = s;
                    lcd_data('*');
                    a++;
                }

                dum[a] = '\0';
                a = 0;

                if ((dum[0] == pass[0]) && (dum[1] == pass[1]) && (dum[2] == pass[2]) && (dum[3] == pass[3])) {
                    lcd_cmd(0x01);
                    lcd_cmd(0x80);
                    lcd_string("Enter new code:");
                    while (key_interrupt());
                    b = 0xc0;
                    lcd_cmd(b);

                    while (a < 4) {
                        s = get_key();
                        pass[a] = s;
                        lcd_data('*');
                        a++;
                    }

                    pass[a] = '\0';
                    a = 0;

                    lcd_cmd(0x01);
                    lcd_cmd(0x80);
                    lcd_string("Code changed");
                    delay(1000);
                } else {
                    lcd_cmd(0x01);
                    lcd_cmd(0x80);
                    lcd_string("Invalid old code");
                    delay(1000);
                }
            } else {
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("Wrong selection");
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("Try Again");
                delay(500);
            }
        } else {
            lcd_cmd(0x01);
            lcd_cmd(0x80);
            led_on2();
            sounder_on();
            lcd_string("Invalid code");
            lcd_cmd(0xc0);
            lcd_string("Access Denied");
            delay(1000);
            sounder_off();
            led_off2();
        }
        option = '0'; // Reset the option value for the next iteration
    }
}
void main(){
	while(1){
		function();
	}
}