/*
 * Cwiczenia.c
 *
 * Created: 28.11.2017 17:21:23
 * Author : Michal-PC
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define SPI_DIR DDRB
#define SPI_MOSI PB3
#define SPI_SCK PB5
#define SPI_SS PB2


#define LCD_DIR DDRD
#define LCD_PORT PORTD
#define LCD_DC PD2
#define LCD_RST PD3
#define LCD_SCE PD4
#define LCD_LED PD5
#define LCD_LENGTH 504

/*
uint8_t lcd_buffer[LCD_LENGTH]={
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11000000,
	0b11111111, 0b11111111, 0b11111111, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11000000,
	0b11000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000
};
*/

void SPI_init();
uint8_t Spi_Master_Write(uint8_t data);

void LCD_Nokia_init();
void LCD_Clear();
void LCD_Set_Instruction(uint8_t set);
void LCD_Set_Horizontal(uint8_t horizontal);
void LCD_Set_LCD_Vop(uint8_t vop6, uint8_t vop5, uint8_t vop4, uint8_t vop3, uint8_t vop2, uint8_t vop1, uint8_t vop0);
void LCD_Set_PD(uint8_t mode);
void LCD_Set_Bias(uint8_t bs0, uint8_t bs1, uint8_t bs2);
void LCD_Set_TempC(uint8_t tc1, uint8_t tc0);
void LCD_Write_C(uint8_t data_C);
void LCD_Write(uint8_t data);
void LCD_Disp_Blank();
void LCD_Disp_Normal();
void LCD_Set_X(uint8_t x_pos);
void LCD_Set_Y(uint8_t y_pos);
void LCD_Limit_Check();
void LCD_Set_XY(uint8_t x_poz, uint8_t y_poz);
void LCD_Write_NOP();
void LCD_Render();

//Impulsator
void impulsator_Init();

void turn_Right();
void turn_Left();


uint8_t lcd_y;
uint8_t last_A=0;
uint8_t last_B=0;

struct lcd_str
{
	struct 
	{
		uint8_t position;
		uint8_t flag;
	} menu;

	struct  
	{
		uint8_t x;
		uint8_t y;
	}position ;

	uint8_t buffer[LCD_LENGTH];
};



uint8_t znak_M [6]={
	0b01111111,
	0b00000010,
	0b00000100,
	0b00000010,
	0b01111111,
	0b00000000
};

uint8_t znak_I[6]={
	0b00000000,
	0b00000000,
	0b01111111,
	0b00000000,
	0b00000000,
	0b00000000
	};

uint8_t znak_C[6]={
	0b00011100,
	0b00100010,
	0b01000001,
	0b01000001,
	0b01000001,
	0b00000000
	};

uint8_t znak_H[6]={
	0b01111111,
	0b00001000,
	0b00001000,
	0b00001000,
	0b01111111,
	0b00000000,
	};

uint8_t znak_A[6]={
	0b01111100,
	0b00010010,
	0b00010001,
	0b00010010,
	0b01111100,
	0b00000000
};

uint8_t znak_LP[6]={
	0b00010000,
	0b01111111,
	0b01001000,
	0b01000100,
	0b01000000,
	0b00000000
};

 struct lcd_str lcd;

 


int main(void)
{
	turn_Right();
	cli();
	lcd.position.x=0;
	

	lcd.menu.position = 0;
	

	LCD_Nokia_init();
	impulsator_Init();

	
	LCD_Render();
	_delay_ms(1000);
	for (uint8_t p=0; p<6;p++)
	{
		lcd.buffer[lcd.position.x]=znak_M[p];
		lcd.position.x++;
	}
	LCD_Render();
	
	_delay_ms(1000);
	LCD_Clear();
	//_delay_ms(1000);
	lcd.position.x=10;
	for(uint8_t i=0; i<6;i++)
	{
			lcd.buffer[lcd.position.x]=znak_M[i];
			lcd.position.x++;
			LCD_Render();
			_delay_ms(500);
	
	}
	
	last_A=1;
	
    while (1) 
    {
		
		if (last_A)
		{
			if (PIND &(1<<PD6))
				{
					lcd.menu.flag = 1;
					turn_Right();
					last_A=0;
					last_B=1;
				}
		}
		
		if(last_B)
		{
			if (PIND & (1<<PD7))
				{
					lcd.menu.flag = 1;
					turn_Left();
					last_A=1;
					last_B=0;
				}
		}
		if(lcd.menu.flag)
			{	
				LCD_Render();
				lcd.menu.flag = 0;
				_delay_ms(500);
			}

    }
}





void LCD_Limit_Check()
{
	if(lcd.position.x > 83)
	{
		if(lcd_y >= 5)
		{
			LCD_Set_XY(0,0);
			lcd.position.x = 0;
			lcd_y = 0;
		}
		else
		{
			lcd.position.x=0;
			lcd_y++;
		}
	}	
	else
		lcd.position.x++;
}

//Inicjalizacja SPI
void SPI_init()
{

	//MISO i SCK jako OUTPUT, MOSI, SS jako INPUT
	SPI_DIR |= (1<<SPI_MOSI) | (1<<SPI_SCK) | (1<<SPI_SS);

	//Ustawienie SPI Enable, SPI Master, SCK/4 (4 MHz)
	SPCR |= (1<<SPE) | (1<<MSTR);
	
}


//Wysy³anie danych przez SPI
uint8_t Spi_Master_Write(uint8_t data)
{
	//Zapis do buforu SPI
	SPDR = data;

	asm volatile("nop");
	//Czekanie na koniec transmisji
	while(!(SPSR & (1<<SPIF)));
	
	return SPDR;
}

//Inicjalizacja LCD Nokia
void LCD_Nokia_init()
{
	LCD_PORT |= (1<<LCD_RST) | (1<<LCD_SCE);
	//Kierunek portów steruj¹ych
	LCD_DIR |= (1<<LCD_DC) | (1<<LCD_RST) | (1<<LCD_SCE) /*| (1<<LCD_LED)*/;

	
	_delay_ms(10);
	LCD_PORT &= ~(1<<LCD_SCE);
	//Resetowanie rejestru i RAMu
	LCD_PORT &= ~(1<<LCD_RST);
	_delay_ms(35);
	LCD_PORT |= (1<<LCD_RST);
	LCD_PORT |= (1<<LCD_SCE);

	//SPI_init(); 
	SPI_init();
	LCD_Set_Instruction(1);
	LCD_Set_LCD_Vop(0,1,1,1,1,0,0);
	LCD_Set_TempC(0,0); //Temperature control
	LCD_Set_Bias(0,1,1); // Mux Rate 1:48
	LCD_Set_Instruction(0);
	LCD_Disp_Normal();
	
	LCD_Render();
	LCD_Disp_Blank();
	LCD_Disp_Normal();
	
}

void LCD_Set_Bias(uint8_t bs2, uint8_t bs1, uint8_t bs0)
{
	uint8_t bias;

	bias = 0b00010000;
	bias |=  (bs0<<0) | (bs1<<1) | (bs2<<2);

	LCD_PORT &= ~((1<<LCD_SCE) | (1<<LCD_DC));
	Spi_Master_Write(bias);
	LCD_PORT |= (1<<LCD_SCE);

}

void LCD_Write(uint8_t data)
{
	//LCD_Limit_Check();
	LCD_PORT &= ~(1<<LCD_SCE);
	LCD_PORT |= (1<<LCD_DC);
	Spi_Master_Write(data);
	LCD_PORT |= (1<<LCD_SCE);
	
}

void LCD_Disp_Blank()
{
	uint8_t blank;
	blank = 0b00001000;
	LCD_PORT &= ~((1<<LCD_SCE) | (1<<LCD_DC));
	Spi_Master_Write(blank);
	LCD_PORT |= (1<<LCD_SCE);
}

void LCD_Disp_Normal()
{
	uint8_t normal;
	normal = 0b00001100;
	LCD_PORT &= ~((1<<LCD_SCE) | (1<<LCD_DC));
	Spi_Master_Write(normal);
	LCD_PORT |= (1<<LCD_SCE);
}

void LCD_Set_X(uint8_t x_pos)
{
	uint8_t x_com;
	x_com = 0b10000000;
	x_com |= x_pos;
	LCD_PORT &= ~((1<<LCD_SCE) | (1<<LCD_DC));
	Spi_Master_Write(x_com);
	LCD_PORT |= (1<<LCD_SCE);
}

void LCD_Set_Y(uint8_t y_pos)
{
	uint8_t y_com;
	y_com = 0b01000000;
	y_com |= y_pos;
	LCD_PORT &= ~((1<<LCD_SCE) | (1<<LCD_DC));
	Spi_Master_Write(y_com);
	LCD_PORT |= (1<<LCD_SCE);
}

void LCD_Set_PD(uint8_t mode)
{
	uint8_t pd_mode;
	pd_mode = 0b00100000;
	pd_mode |= (1<<mode);
	LCD_PORT &= ~((1<<LCD_SCE) | (1<<LCD_DC));
	Spi_Master_Write(pd_mode);
	LCD_PORT |= (1<<LCD_SCE);

}

void LCD_Clear()
{
	lcd.position.x=0;
	for (uint16_t i=0;i<LCD_LENGTH;i++)
	{
		lcd.buffer[lcd.position.x]=0x00;
		lcd.position.x++;
	}
	LCD_Render();
	lcd.position.x=0;
}

void LCD_Set_Horizontal(uint8_t horizontal)
{
	uint8_t horizontal_com;
	horizontal_com = 0b00100000;
	horizontal_com |= (horizontal<<1);
	LCD_PORT &= ~((1<<LCD_SCE) | (1<<LCD_DC));
	Spi_Master_Write(horizontal_com);
	LCD_PORT |= (1<<LCD_SCE);
}

void LCD_Set_Instruction(uint8_t set)
{
	uint8_t set_com;
	set_com = 0b00100000;
	set_com |= (set<<0);
	LCD_PORT &= ~((1<<LCD_SCE) | (1<<LCD_DC));
	Spi_Master_Write(set_com);
	LCD_PORT |= (1<<LCD_SCE);
}

void LCD_Set_LCD_Vop(uint8_t vop6, uint8_t vop5, uint8_t vop4, uint8_t vop3, uint8_t vop2, uint8_t vop1, uint8_t vop0)
{
	uint8_t vop_com;
	vop_com = 0b10000000;
	vop_com |= (vop6<<6) | (vop5<<5) | (vop4<<4) | (vop3<<3) | (vop2<<2) | (vop1<<1) | (vop0<<0);
	LCD_PORT &= ~((1<<LCD_SCE) | (1<<LCD_DC));
	Spi_Master_Write(vop_com);
	LCD_PORT |= (1<<LCD_SCE);
}

void LCD_Set_TempC(uint8_t tc1, uint8_t tc0)
{
	uint8_t tempC_com;
	tempC_com = 0b00000100;
	tempC_com |= (tc1<<1) | (tc0<<0);
	LCD_PORT &= ~((1<<LCD_SCE) | (1<<LCD_DC));
	Spi_Master_Write(tempC_com);
	LCD_PORT |= (1<<LCD_SCE);

}

void LCD_Write_C(uint8_t data_C)
{
	
	LCD_PORT &= ~(1<<LCD_SCE);
	LCD_PORT |= (1<<LCD_DC);
	Spi_Master_Write(data_C);
	LCD_PORT |= (1<<LCD_SCE);
}

void LCD_Set_XY(uint8_t x_poz, uint8_t y_poz)
{	
	uint8_t x_poz_com, y_poz_com;
	x_poz_com = 0b10000000;
	y_poz_com = 0b01000000;
	if (x_poz < 83)
		x_poz_com |= x_poz;
	if (y_poz < 5)
		y_poz_com |= y_poz;
	
	LCD_PORT &= ~((1<<LCD_SCE) | (1<<LCD_DC));
	Spi_Master_Write(x_poz);
	Spi_Master_Write(y_poz);
	LCD_PORT |= (1<<LCD_SCE);
}

void LCD_Write_NOP()
{
	LCD_PORT &= ~((1<<LCD_SCE) | (1<<LCD_DC));
	Spi_Master_Write(0x00);
	LCD_PORT |= (1<<LCD_SCE);
}

void LCD_Render()
{
	uint8_t col = 0;
	uint8_t row = 0;
	for (row=0 ; row < 6;row++)
	{
		LCD_Set_Y(row);
		//LCD_Set_X(col);

		LCD_PORT |= (1<<LCD_DC);
		LCD_PORT &= ~(1<<LCD_SCE);
		for (col=0; col<84;col++)
		{
			Spi_Master_Write(lcd.buffer[(84*row)+col]);
		}
		LCD_PORT |= (1<<LCD_SCE);


	}
	LCD_Set_Y(0);

}

void impulsator_Init()
{
	//Ustawienie portów jako wejœcia
	DDRD &= ~((1<<PD6) | (1<<PD7)); // Kanal A i B
	DDRB &= ~((1<<PB1)); // Switch
	
	//Ustawienie przerwan od pinow 6(PD6) i 7(PD7)
	PCMSK2 |= (1<<PCINT23) | (1<<PCINT22); // Pin 6 and 7 cause interupt Enable
	PCICR |= (1<< PCIE2); // Interrupt Enable
}


void turn_Right()
{
	uint8_t temp;
	//lcd.position.x = 83;
	//lcd.position.y = 5;
	
	for (int8_t i =5; i>=0; i--)
		{
			for (int8_t j=83; j>=0; j--)
			{
				temp = lcd.buffer[(84*i)+j-1];
				lcd.buffer[(84*i)+j] = temp;
			}
		}
	
}

void turn_Left()
{
	uint8_t temp;
	
	for (lcd.position.y=0; lcd.position.y<=5; lcd.position.y++)
		{
			for( lcd.position.x=0 ; lcd.position.x <= 83; lcd.position.x++)
			{
				temp = lcd.buffer[(84*lcd.position.y)+lcd.position.x +1];
				lcd.buffer[(84*lcd.position.y)+lcd.position.x] = temp;
			} 
		}
}