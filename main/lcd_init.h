#ifndef __LCD_INIT_H
#define __LCD_INIT_H

#include <string.h>
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"


#define USE_HORIZONTAL 2  //���ú�������������ʾ 0��1Ϊ���� 2��3Ϊ����


#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 135
#define LCD_H 240

#else
#define LCD_W 240
#define LCD_H 135
#endif

#define ST7789_PIN_NUM_CLK		18
#define ST7789_PIN_NUM_MOSI		19
#define ST7789_PIN_NUM_RESET	23
#define ST7789_PIN_NUM_DC		16
#define ST7789_PIN_NUM_BLK		4
#define ST7789_PIN_NUM_CS		5

//-----------------LCD�˿ڶ���---------------- 

#define LCD_SCLK_Clr() WRITE_PERI_REG(GPIO_OUT_W1TC_REG, (0x1 << ST7789_PIN_NUM_CLK))//SCL=SCLK
#define LCD_SCLK_Set() WRITE_PERI_REG(GPIO_OUT_W1TS_REG, (0x1 << ST7789_PIN_NUM_CLK))

#define LCD_MOSI_Clr() WRITE_PERI_REG(GPIO_OUT_W1TC_REG, (0x1 << ST7789_PIN_NUM_MOSI))//SDA=MOSI
#define LCD_MOSI_Set() WRITE_PERI_REG(GPIO_OUT_W1TS_REG, (0x1 << ST7789_PIN_NUM_MOSI))

#define LCD_RES_Clr()  WRITE_PERI_REG(GPIO_OUT_W1TC_REG, (0x1 << ST7789_PIN_NUM_RESET))//RES
#define LCD_RES_Set()  WRITE_PERI_REG(GPIO_OUT_W1TS_REG, (0x1 << ST7789_PIN_NUM_RESET))

#define LCD_DC_Clr()   WRITE_PERI_REG(GPIO_OUT_W1TC_REG, (0x1 << ST7789_PIN_NUM_DC))//DC
#define LCD_DC_Set()   WRITE_PERI_REG(GPIO_OUT_W1TS_REG, (0x1 << ST7789_PIN_NUM_DC))
 		     
#define LCD_CS_Clr()   WRITE_PERI_REG(GPIO_OUT_W1TC_REG, (0x1 << ST7789_PIN_NUM_CS))//CS
#define LCD_CS_Set()   WRITE_PERI_REG(GPIO_OUT_W1TS_REG, (0x1 << ST7789_PIN_NUM_CS))

#define LCD_BLK_Clr()  WRITE_PERI_REG(GPIO_OUT_W1TC_REG, (0x1 << ST7789_PIN_NUM_BLK))//BLK
#define LCD_BLK_Set()  WRITE_PERI_REG(GPIO_OUT_W1TS_REG, (0x1 << ST7789_PIN_NUM_BLK))




void LCD_GPIO_Init(void);//��ʼ��GPIO
void LCD_Writ_Bus(uint8_t dat);//ģ��SPIʱ��
void LCD_WR_DATA8(uint8_t dat);//д��һ���ֽ�
void LCD_WR_DATA(uint16_t dat);//д�������ֽ�
void LCD_WR_REG(uint8_t dat);//д��һ��ָ��
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);//�������꺯��
void LCD_Init(void);//LCD��ʼ��



#endif




