
#include "bsp.h"
#include <clock.h>  
#include <sys/process.h>  
#include <sys/procinit.h>  
#include <etimer.h>  
#include <sys/autostart.h>  
#include "contiki.h"


int main(void)
{
	unsigned char i;
	LED_Init();
	uart_init();
	Systick_Init();
	//lcd ��ʼ
	lcd_init();
	printf("\r\nlcd init suc");
	//lcd���óɺ�ɫ
	Lcd_regread();	
//	lcd_clear();
	printf("\r\nLcd is clear");
	
	display_NET(0x55,4);
	
//	//����.bmp �� .txt�ļ�
//	Find_FileName();
//	
//	//��ʾ.bmp�ļ�
//	for(i=0;i<BMP_NUM;i++){
//		lcd_display_string_line(0,i*16,0xf800,0,(unsigned char *)BMP_Files[i]);	
//	}
//	//��ʾ.txt�ļ�
//	for(i=0;i<TXT_NUM;i++){
//		lcd_display_string_line(120,i*16,0xf800,0,(unsigned char *)TXT_Files[i]);	
//	}
	while(1)
	{
		LED_Tog(LED0);
		Delay(500);
		LED_Tog(LED1);
		Delay(500);
		LED_Tog(LED2);
		Delay(500);
		LED_Tog(LED3);
		Delay(500);
	}
}
