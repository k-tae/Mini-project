#include "device_driver.h"

static void Sys_Init(void) {
  Clock_Init();
  Uart_Init(115200);
  Key_Poll_Init();
  Motor_Init();
  Adc_Cds_Init();
}

void Main(void) {
  Sys_Init();

  for (;;) 
  {
    Motor_run();
  }
}
