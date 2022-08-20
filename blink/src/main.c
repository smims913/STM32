#include "stm32f4xx_hal.h"//STM32F4头文件库

#define LED1_Pin GPIO_PIN_9//将LED引脚设置为9号引脚
#define LED2_Pin GPIO_PIN_10//将LED引脚设置为10号引脚
#define LED_GPIO_Port GPIOF//将LED组设置为GPIOF组

void LED_Init(void)//LED引脚初始化函数
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};//声明一个GPIO的结构体，用于后续定义引脚

  __HAL_RCC_GPIOF_CLK_ENABLE();//引脚时钟使能函数

  HAL_GPIO_WritePin(LED_GPIO_Port, LED1_Pin|LED2_Pin, GPIO_PIN_RESET);//初始化引脚状态

  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin;//声明引脚编号
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;//声明引脚的模式
  GPIO_InitStruct.Pull = GPIO_PULLUP;//确定上拉状态
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;//确定引脚的输出速度
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);//将结构体状态传递给LED组

}

int main(void)
{
    HAL_Init();//系统初始化函数
    LED_Init();//引脚初始化函数

    while(1)//循环运行体
    {
        HAL_GPIO_TogglePin(LED_GPIO_Port, LED1_Pin);//将LED引脚状态取反
        HAL_Delay(500-1);//延时函数
        HAL_GPIO_TogglePin(LED_GPIO_Port, LED2_Pin);//将LED引脚状态取反
        HAL_Delay(500-1);//延时函数
    }
}

void SysTick_Handler(void)//系统始终中断函数
{
  HAL_IncTick();
}