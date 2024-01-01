sfr datalines=0xA0;
sbit rs=P3^0;
sbit en=P3^1;

void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_string(unsigned char []);
void lcd_num(unsigned int); // int a; 0 to 65535
void lcd_init(void);
void delay(unsigned int);

void lcd_cmd(unsigned char ch){
	rs=0;
	datalines = ch;
	en=1;
	delay(10);
	en=0;
}
void lcd_data(unsigned char ch){
	rs=1;
	datalines=ch;
	en=1;
	delay(10);
	en=0;
}
void lcd_string(unsigned char ch[]){
	int a;
	for(a=0;ch[a]!='\0';a++)
	lcd_data(ch[a]);
}
void lcd_num(unsigned int ch){
	int a=0,b[16];
	while(ch>0){
		b[a]=ch%10;
		ch=ch/10;
		a++;
	}
	while(a>0){
		a--;
		lcd_data(b[a]+48);
	}
}
void lcd_init(void){
	lcd_cmd(0x38);
	lcd_cmd(0x06);
	lcd_cmd(0x02);
	lcd_cmd(0x0c);
}
void delay(unsigned int ch){
	int a,b;
	for(a=0;a<ch;a++)
	for(b=0;b<1000;b++);
}
	
	