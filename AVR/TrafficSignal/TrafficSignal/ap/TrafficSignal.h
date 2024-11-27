
#ifndef TRAFFICSIGNAL_H_
#define TRAFFICSIGNAL_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../driver/Button/Button.h"
#include "../driver/Led/Led.h"

enum {B_Auto, B_Manual, B_Switching};
enum {Auto, Manual};
enum {RG, RY, GR, YR};


void redGreen();
void redYellow();
void greenRed();
void yellowRed();
void autoMode();
void manualMode();
void TrafficSignal_init();
void TrafficSignal_execute();

#endif /* TRAFFICSIGNAL_H_ */