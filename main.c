//
// Created by lawrence on 1/13/25.
//
#include "FreeRTOS.h"
#include "task.h"
#include "pico/stdlib.h"
#include "stdio.h"

void led_task(void *pvParameters){
  while(1){
    gpio_put(15,1);
    vTaskDelay(100);
    gpio_put(15,0);
    vTaskDelay(100);
  }
}

int main() {
   gpio_init(15);
   gpio_set_dir(15, GPIO_OUT);
   xTaskCreate(led_task, "led_task",256, NULL, 5, NULL);
   vTaskStartScheduler();

   while(true) {
    //do nothing
   }
}