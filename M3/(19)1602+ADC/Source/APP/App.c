/**
  ******************************************************************************
  * @file    APP.c
  * @author  phone
  * @version V1.0
  * @date    2014-12-14
  * @brief   LCD1602��ʾ
  ******************************************************************************
  * @attention
  *
  * @{ʵ��ƽ̨:
  * @{�ŵ��ȳ�������	
	* @{ USE_STM3210B_EVAL
  ******************************************************************************
  */ 
	
/* Includes ------------------------------------------------------------------*/
#include <stm32f10x.h>
#include "BSP.h"
#include "LCD_1602.h"
#include "bsp_adc.h"

unsigned int ADC_ConvertedValueLocal;    
unsigned char dis1[] = {"Power voltage:"};
unsigned char dis2[8];


void Delay(__IO u32 nCount); 

#if 1
/**---------------------------------------------------------------------------------
  * @brief       ������.
  * @param    		��
  *	@arg         NULL
  * @retval     null
  ---------------------------------------------------------------------------------*/
int main(void)
{
	/*�����ǵ���ϵͳʱ�ӣ���3.0�汾�Ŀ��У�
	��main������������ã���3.5�汾�У�
	ϵͳʱ�ӷ����������ļ�����
	�������е�ʱ�����ȴ������ຯ��ִ�е�
	�����ļ� 151��    ��
	LDR     R0, =SystemInit			  ;����ϵͳʱ��
	SetSysClock();	
	*/
	/*�������ߵ���*/
	#ifdef DEBUG
		debug();
	#endif
	/*����Ӳ����ʼ��*/
	ALL_Config();
	
	LCD_1602_CONFIG();
	ADC1_Init();
	
	LCD1602_WRITE(1,0,dis1);
	
/**----------------------------------------------------------------------
* @brief ����3��ʹ�üĴ�������IO
-----------------------------------------------------------------------*/
	#if 1
	while(1)
	{
			ADC_ConvertedValueLocal =ADC_ConvertedValue*3300/4096; // ��ȡת����ADֵ
			//ADC_ConvertedValueLocal = (*(__IO u16 *)ADC1_DR_Address)*3300/4096;// ��ȡת����ADֵ
			dis2[0] = ADC_ConvertedValueLocal%10000/1000 + 0x30;
			dis2[1] = '.';
			dis2[2] = ADC_ConvertedValueLocal%1000/100 + 0x30;
			dis2[3] = ADC_ConvertedValueLocal%100/10 + 0x30;
			dis2[4] = ADC_ConvertedValueLocal%10 + 0x30;
//			
			//dis2[0] = 9 + 0x30;
			LCD1602_WRITE(2,0,dis2);
			Delay(0x2fffee);  
	}
	#endif	
}
#endif




/**---------------------------------------------------------------------------------
  * @brief       CPU��ʱ����
  * @param    		��
  ---------------------------------------------------------------------------------*/
void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}

/**---------------------------------------------------------------------------------
  * @brief       ��⴫�ݸ������Ĳ����Ƿ�����Ч�Ĳ���
  * @param    		��
	* @example		 ĳ��������ȡֵ��Χֻ����С��3������������������Ĳ�������3��
	* @example	   �����assert_param()���������г�����õ��������ʱ����			
  ---------------------------------------------------------------------------------*/
#ifdef DEBUG
void assert_failed(uint8_t* file, uint32_t line){
while (1);}
#endif
/*********************************************END OF FILE**********************/



