# Inviare bit video con VGA
#### Fonte: Bing AI

> 08/07/2023 

Certo! Per inviare un segnale video in una TV usando Arduino e una porta VGA, puoi utilizzare la libreria VGA per Arduino Due. Questa libreria ti consente di connettere un Arduino Due a un monitor con un'ingresso VGA. Le risoluzioni disponibili sono fino a 800x600 in monocromatico e 320x240 a colori. L'API è abbastanza semplice e diretta - basta VGA.begin(x,y); e sei pronto! [La libreria ha alcune funzioni di disegno comuni per pixel, linee, triangoli, rettangoli, cerchi, ellissi e testo. Deriva anche dalla libreria Print, quindi supporta le funzioni Arduino VGA.print (...) e VGA.println (...).](https://forum.arduino.cc/t/arduino-to-vga-or-hdmi-output-is-it-possible-and-how/1047733)

Ecco il codice che puoi utilizzare per inviare un segnale video in una TV usando Arduino e una porta VGA:

```c++
#include <VGA.h>

void setup() {
  VGA.begin(320,240,VGA_COLOUR);
}

void loop() {
  // your code here
}
```
