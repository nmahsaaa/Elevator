/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 6/28/2018
Author  : 
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>
#include <delay.h>
//outside keys
#define o1 PINB.0
#define o2 PINB.1
#define o3 PINB.2


// Declare your global variables here
int cf; // variable for storing current floor  
//int i=0 ;
//int opcl = 0 ;
unsigned char cathode_seg[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


void seven_seg(int number){
PORTA = cathode_seg[number];
}

void door (int opcl)
{
 if (opcl == 0)
 {         
   PORTC = 0x06; //door closes
 }        
 else if (opcl == 1)
 {
  PORTC = 0x09; //door opens
 }
}

void motor ( int direction , int time) 
{
 door(0); //closes door 
  delay_ms(100);
if ( direction == 0 ) //going down

   {
      PORTD = 0x08;  //meghdar dehi vurudi haye motor
      delay_ms(100);
      PORTD = 0x04; 
      delay_ms(100);
      PORTD = 0x02; 
      delay_ms(100);
      PORTD = 0x01;
      cf--;          //update cf
      seven_seg(cf);
      delay_ms(100); 
      
      if (time == 2)  //do tabaghe jabejayi (masalan az 3 be 1)
      {
      PORTD = 0x08;   //tekrare marahele ghabl
      delay_ms(100);
      PORTD = 0x04; 
      delay_ms(100);
      PORTD = 0x02; 
      delay_ms(100);
      PORTD = 0x01;
      cf--;          //update cf
      seven_seg(cf);  //show the current floor in seven segment
      delay_ms(100);
      }          
      
    door(1);//opens door
    return ;
    
   }
else if (direction == 1){ //we are going up
      PORTD = 0x01;     //meghdar dehie vurudie motor khalafe jahate marhale ye ghabl
      delay_ms(100);
      PORTD = 0x02; 
      delay_ms(100);
      PORTD = 0x04;
      delay_ms(100);
      PORTD = 0x08;  
      cf++;
      seven_seg(cf);       
      delay_ms(100);
      
  // PORTD = 0x00;
   if(time == 2)
   {
      PORTD = 0x01;
      delay_ms(100);
      PORTD = 0x02;
      delay_ms(100);
      PORTD = 0x04;
      delay_ms(100);
      PORTD = 0x08;  
      cf++;
      seven_seg(cf);       
      delay_ms(100);
   }
    //PORTD = 0x00;
    door(1);//opens door 
    return ;
    
   }
}   

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(1<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (1<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=0xFF;
// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=0xFF;
// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=0xFF;
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=0x00;

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=0xFF;
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=0x00;
// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);

// USART initialization
// USART disabled
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);
cf = 1;
seven_seg(cf);

while (1)
      {
      if(cf == 1){
        if(o1 == 0){ door(1) ; // opens door 
        }
        else if (o2 == 0) 
        {               
        motor(1,1);
        }
        else if (o3 == 0)
        {   
        motor(1,2);
        }   
      }
      else if(cf == 2){
        if(o2 == 0){ door(1); //opens door
      }
        else if (o1 == 0){ 
        motor(0,1);
        }
        else if (o3 == 0) {
        motor(1,1);}
      }
      else if (cf==3) {
      if(o3 == 0){door(1); //opens door
      }
        else if (o2 == 0){
        motor(0,1);}
        else if (o1 == 0) {
        motor(0,2);}
      }

      }
}
