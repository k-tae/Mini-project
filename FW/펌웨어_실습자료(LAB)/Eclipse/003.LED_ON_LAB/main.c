#include <device_driver.h>

// ���⿡ ����� ������ define�� �ۼ��Ͻÿ�

#define GPIOB_CRH
#define GPIOB_ODR

void Main(void)
{
	  // �� �κ��� ���Ƿ� �ٲ��� ���ÿ�
	  RCC_APB2ENR |= (1<<3);

	  // GPB[9:8]�� ��� ���� �����Ͻÿ�

	  GPIOB_CRH =

	  // GPB[9:8]�� LED0�� OFF, LED1�� ON ��Ű���� �����Ͻÿ�

	  GPIOB_ODR =
}
