sbit c1=P1^0;
sbit c2=P1^1;
sbit c3=P1^2;
sbit r1=P1^3;
sbit r2=P1^4;
sbit r3=P1^5;
sbit r4=P1^6;
char keypad[4][3]={{'1','2','3'},
									 {'4','5','6'},
									 {'7','8','9'},
									 {'*','0','#'}};
unsigned int key_interrupt(void);
unsigned char get_key(void);
unsigned int key_interrupt(void){
	r1=r2=r3=r4=0;c1=c2=c3=1;
	if((c1==0) || (c2==0) || (c3==0))
		return 1;
	else
		return 0;
}
unsigned char get_key(void){
	unsigned int x,y;
	while(1){
		c1=c2=c3=1;
		r1=0;r2=r3=r4=1;
		x=0;
		if(c1==0){
			y=0;
			break;
		}
		else if(c2==0){
			y=1;
			break;
		}
		else if(c3==0){
			y=2;
			break;
		}
		r2=0;r1=r3=r4=1;
		x=1;
				if(c1==0){
			y=0;
			break;
		}
		else if(c2==0){
			y=1;
			break;
		}
		else if(c3==0){
			y=2;
			break;
		}
		r3=0;r1=r2=r4=1;
		x=2;
				if(c1==0){
			y=0;
			break;
		}
		else if(c2==0){
			y=1;
			break;
		}
		else if(c3==0){
			y=2;
			break;
		}
		r4=0;r1=r2=r3=1;
		x=3;
				if(c1==0){
			y=0;
			break;
		}
		else if(c2==0){
			y=1;
			break;
		}
		else if(c3==0){
			y=2;
			break;
		}
	}
	while((c1==0)||(c2==0)||(c3==0));
	return keypad[x][y];
}