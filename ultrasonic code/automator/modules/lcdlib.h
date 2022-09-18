#ifndef LCDLIB_H_		/* Define library H file if not defined */
#define LCDLIB_H_

#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 8000000L
#endif

#include <util/delay.h>

#define LCD_DATA_DDR DDRB		/* Define LCD data port direction */
#define LCD_DATA_PORT PORTB		/* Define LCD data port */
#define LCD_CONTROL_DDR DDRA	/* Define LCD command port direction register */
#define LCD_CONTROL_PORT PORTA	/* Define LCD command port */

#define ENABLE_SIGNAL PA5	
#define REGISTER_SELECT PA6	/* Define Register Select (data reg./command reg.) signal pin */
#define READ_WRITE PA1	/* Define Read/Write signal pin */
 
/*	
	register select = 0; command register REGISTER_SELECT_LOW()
	register select = 1; data register	REGISTER_SELECT_HIGH()
*/

#define REGISTER_SELECT_LOW() LCD_CONTROL_PORT &= ~(1 << REGISTER_SELECT)
#define REGISTER_SELECT_HIGH() LCD_CONTROL_PORT |= (1 << REGISTER_SELECT)

#define ENABLE_LOW() LCD_CONTROL_PORT &= ~(1 << ENABLE_SIGNAL)
#define ENABLE_HIGH() LCD_CONTROL_PORT |= (1 << ENABLE_SIGNAL)

void LCD_init();
void LCD_cmd(unsigned char cmd);
void setPosition(unsigned char pos_x, unsigned char pos_y);
void LCD_out(char ch);
void LCD_write_char(char ch, unsigned char pos_x, unsigned char pos_y);
void LCD_write_string(char *st, unsigned char pos_x, unsigned char pos_y);
unsigned char LCD_write_number(unsigned char number, unsigned char pos_x, unsigned char pos_y, char zfill);
void LCD_clear();


#endif /* LCDLIB_H_ */