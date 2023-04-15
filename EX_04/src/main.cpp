#include <Arduino.h>

/*Bibliotecas FreeRTOS */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/*mapeamento de pinos*/ 
#define LED1 2
#define LED2 14

/* Variáveis para armazenamento do handle das tasks*/
TaskHandle_t task1Handle = NULL;
TaskHandle_t task2Handle = NULL;

/*protítipos das Tasks*/
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

void setup() {

  Serial.begin(9600);
    
  xTaskCreate(vTask1,"TASK1",configMINIMAL_STACK_SIZE,(void*)LED1,1,&task1Handle);
  xTaskCreate(vTask2,"TASK2",configMINIMAL_STACK_SIZE+1024,NULL,2,&task2Handle);
  xTaskCreate(vTask1,"TASK1",configMINIMAL_STACK_SIZE,(void*)LED1,1,&task1Handle);
  
}

void loop() {
  vTaskDelay(3000);
}


void vTask1(void *pvParameters)
{

    int pin = (int)pvParameters;

    pinMode(pin,OUTPUT);

    while (1)
    {
      digitalWrite(pin,!digitalRead(pin));
      vTaskDelay(pdMS_TO_TICKS(200));
    }
}


void vTask2(void *pvParameters)
{
  int cont = 0;

  while (1)
  {
    Serial.println("Task 2: " + String(cont++));

    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}