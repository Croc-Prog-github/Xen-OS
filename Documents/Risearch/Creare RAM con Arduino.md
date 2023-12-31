# Creare RAM con Arduino
**Ordine**: Data di creazione, Decrescente.

>  26/07/2023

### Memory chip: IS42S16400F-7TL

**Fonte: [www.mouser.it](https://www.mouser.it/ProductDetail/ISSI/IS42S16400F-7TL?qs=v9o34zvNDAZm8HO2EnJw4g%3D%3D)**<br>

[Datashell IS42S16400F-7TL](https://www.mouser.it/datasheet/2/198/42-45S16400F-258310.pdf)<br>

Tipo: DRAM✔️<br>
Sottotipo: SDRAM<br>
Larghezza bus dati:	16 bit<br>
Organizzazione:	4 M x 16<br>
Dimensioni memoria:	64 Mbit<br>
Frequenza di clock massima:	143 MHz<br>
Tensione di alimentazione Max: 3.6 V<br>
Tensione di alimentazione Min: 3 V<br>
Corrente di alimentazione Max: 100 mA<br>


> 25/07/2023

**Fonte: [www.mouser.it](https://www.mouser.it/ProductDetail/ISSI/IS42S81600F-7TL?qs=9hm%252BDT1Jr7ydJlC0KQMDXA%3D%3D)**

**~~Memory chip: IS42S81600F-7TL~~**<br>
Tipo: DRAM✔️<br>
Sottotipo: SDRAM<br>
Larghezza bus dati:	8 bit<br>
Organizzazione:	16 M x 8<br>
Dimensioni memoria:	128 Mbit<br>
Frequenza di clock massima:	143 MHz<br>
Tensione di alimentazione Max: 3.6 V<br>
Tensione di alimentazione Min: 3 V<br>


> 15/07/2023
## Pro e contro SRAM e DRAM
|**DRAM**|**SRAM**|
|--------|--------|
|Capacità:✔️|Capacità:?|
|Costo:✔️|Costo:✖️|
|Energia:✔️|Energia:?|
|Scalabilità:✔️|Latenza:✔️|
|Velocità:✖️|Velocità:✔️|
|Refresh:✖️|Refresh:?|
|Affidabilità:✖️|Affidabilità:✔️|

**DRAM win**

> 14/07/2023
## Come programmare la RAM

**Fonte: Chat GPT**<br>
Passaggi per programmare un microcontrollore esterno con Arduino
1. Collega e seleziona l'Arduino
2. Vai su: "Strumenti" > "Programmatore" e seleziona "Arduino as ISP".
3. Vai su "Strumenti" > "Scrivi il bootloader". (Da qui sei dentro al microcontollore esterno)
4. Scrivi il tuo codice nell'IDE di Arduino come faresti normalmente. Assicurati di selezionare la scheda Arduino attuale dal menu "Strumenti" > "Scheda" in modo che il codice venga compilato per l'ATmega168-20PU.

**Fonte: Chat GPT**<br>
Un altro esempio è quello di generare un codice Writing presumendo che:<br>
- memory chip DRAM collegati tramite bus
- gestiti da un ATmega168-20PU<br>
**WARNIG: Questo codice non è verificato**
```c++
  #include <avr/io.h>

  // Dichiarazioni dei pin per il bus di dati e indirizzi
  #define DATA_BUS_PORT PORTA
  #define DATA_BUS_DDR DDRA
  #define ADDR_BUS_PORT PORTB
  #define ADDR_BUS_DDR DDRB
  #define CONTROL_BUS_PORT PORTC
  #define CONTROL_BUS_DDR DDRC
  #define CHIP_ENABLE_PIN PC0

  // Funzione per scrivere un byte nella RAM
  void writeByte(unsigned int address, unsigned char data) {
    ADDR_BUS_PORT = (address >> 8); // Inserisci l'indirizzo MSB nel bus di indirizzi
    DATA_BUS_PORT = data; // Inserisci il dato nel bus di dati

    // Controlli di scrittura
    CONTROL_BUS_PORT |= (1 << CHIP_ENABLE_PIN); // Abilita il chip di memoria
    CONTROL_BUS_PORT &= ~(1 << PC1); // Imposta il segnale WRITE a basso per avviare la scrittura
    delayMicroseconds(10); // Breve ritardo per garantire che i segnali siano stabili
    CONTROL_BUS_PORT |= (1 << PC1); // Imposta il segnale WRITE ad alto per terminare la scrittura
    CONTROL_BUS_PORT &= ~(1 << CHIP_ENABLE_PIN); // Disabilita il chip di memoria
  }

  // Funzione per leggere un byte dalla RAM
  unsigned char readByte(unsigned int address) {
    ADDR_BUS_PORT = (address >> 8); // Inserisci l'indirizzo MSB nel bus di indirizzi

    // Controlli di lettura
    CONTROL_BUS_PORT |= (1 << CHIP_ENABLE_PIN); // Abilita il chip di memoria
    CONTROL_BUS_PORT |= (1 << PC2); // Imposta il segnale READ ad alto per avviare la lettura
    delayMicroseconds(10); // Breve ritardo per garantire che i segnali siano stabili
    unsigned char data = DATA_BUS_PORT; // Leggi il dato dal bus di dati
    CONTROL_BUS_PORT &= ~(1 << PC2); // Imposta il segnale READ a basso per terminare la lettura
    CONTROL_BUS_PORT &= ~(1 << CHIP_ENABLE_PIN); // Disabilita il chip di memoria

    return data;
  }

  void setup() {
    // Configurazione dei pin
    DATA_BUS_DDR = 0xFF; // Configura il bus di dati come uscita
    ADDR_BUS_DDR = 0xFF; // Configura il bus di indirizzi come uscita
    CONTROL_BUS_DDR |= (1 << CHIP_ENABLE_PIN) | (1 << PC1) | (1 << PC2); // Configura i pin di controllo come uscita
  }

  void loop() {
    // Esempio di utilizzo: scrittura e lettura di un byte dalla RAM
    unsigned int address = 0x1234; // Indirizzo di memoria
    unsigned char dataToWrite = 0xAB; // Dato da scrivere
    writeByte(address, dataToWrite); // Scrivi il dato nella RAM

    unsigned char dataRead = readByte(address); // Leggi il dato dalla RAM
    // Utilizza il dato letto come desiderato...

    delay(1000); // Ritardo tra le operazioni di scrittura e lettura
  }
```

**Fonte: https://forum.arduino.cc/t/accedere-ad-una-sram-parallela/51187**<br>
Per gestire in lettura/scrittura una SRAM⚠️ esterna di tipo parallelo, non una seriale a cui si può accedere tramite I2C o SPI ma una classica memoria con un bus indirizzi ed un bus dati indipendenti.<br>

Realizzato con 1 chip di SRAM (ovviamente), tre 74595 ed un 74165, interfacciati ad un Arduino. La SRAM è una Cypress 7C185 da 64 Kbit (8Kx8) ma può essere usato qualunque chip, (con le dovute modifiche).<br>

Il codice usato per leggere/scrivere sulla RAM è il seguente:

**WARNIG: Questo codice non è verificato**
```c++
  /* TEST DI CONNESSIONE AD UN CHIP SRAM DA 8Kx8 UTILIZZANDO 2 REGISTRI 
  DI TURNO 74595 PER GESTIRE L'INDIRIZZO, 1 74595 PER GESTIRE I DATI DA 
  LEGGERE/SCRIVERE NELLA RAM E 1 74165 P/S TURNO REG. PER LEGGERE I DATI DALLA RAM
  */
  #include <EEPROM.h>

  // Connessione ai pin
  //1st and 2nd 595
  #define data1pin 2 //pin DS
  #define latch1pin 3 //pin ST_CP
  #define clock1pin 4 //pin SH_CP 

  //3rd chip 595
  #define data2pin 7 //pin DS
  #define latch2pin 8 //pin ST_CP
  #define clock2pin 9 //pin SH_CP

  //SRAM Chip
  #define ram_we 5 //pin WE/ + 3rd 595 OE/
  #define ram_oe 6 //pin OE/

  //chip 165
  #define load_data 11 //pin CP
  #define set_load 12 //pin PL/
  #define clock_pin 10 //pin Q7

  void setup() {
    //configurazione iniziale dei pin
 
    //pin dei registri a scorrimento 1, 2 e 3: OUTPUT
    pinMode(latch1pin, OUTPUT);
    pinMode(clock1pin, OUTPUT);
    pinMode(data1pin, OUTPUT);
    pinMode(data2pin, OUTPUT);
    pinMode(clock2pin, OUTPUT);
    pinMode(latch2pin, OUTPUT);
    
    //RAM pins: OUTPUT
    pinMode(ram_we, OUTPUT);
    pinMode(ram_oe, OUTPUT);
    
    //S/r 165
    pinMode(clock_pin, OUTPUT);
    pinMode(set_load, OUTPUT);
    pinMode(load_data, INPUT);  
    
    //inizializza la ram
    digitalWrite(ram_oe, HIGH);
    digitalWrite(ram_we, HIGH);
    
    //impostare D13 per i lampeggi del LED
    pinMode(13, OUTPUT);
    
    for (unsigned int mem_address = 0; mem_address <20; mem_address++) {
      write_ram(mem_address, 0);
    }
  }

  void loop() {
    unsigned int mem_address; //l'indirizzo da utilizzare
    byte value = 3; //il valore da utilizzare

    // cancellare 10 posizioni nella SRAM e quindi scrivere una sequenza di numeri
    for (mem_address = 0; mem_address < 20; mem_address++) {
      write_ram(mem_address, value);
      value += 3;
    }
    delay(500);
    
    value = 255;
    //leggere i primi 10 byte e poi scriverli nella uC EEPROM
    for (mem_address = 0; mem_address < 20; mem_address++) {
      value = read_ram(mem_address);
      EEPROM.write(mem_address, value);
      delay(10);
    }
    digitalWrite(13, HIGH);
    delay(3000);
    digitalWrite(13, LOW);
  }

  void write_ram(unsigned int mem_address, byte value) {
    byte hbyte, lbyte;
    
    digitalWrite(set_load, HIGH); //metti i 165 pin in H.I. per evitare cortocircuiti sul bus dati
    //scrivere l'indirizzo nei registri a scorrimento 1 e 2
    digitalWrite(latch1pin, LOW);
    digitalWrite(latch2pin, LOW);
    digitalWrite(clock1pin, LOW);
    digitalWrite(clock2pin, LOW);
    hbyte = highByte(mem_address);
    lbyte = lowByte(mem_address);
    shiftOut(data1pin, clock1pin, MSBFIRST, hbyte);
    shiftOut(data1pin, clock1pin, MSBFIRST, lbyte);
    //scrivi il valore nella 3a s/r
    shiftOut(data2pin, clock2pin, MSBFIRST, value);
    //impostare l'indirizzo ei dati "visibili" sui bus
    digitalWrite(latch1pin, HIGH);
    digitalWrite(latch2pin, HIGH);
    //scrivi nella RAM
    digitalWrite(ram_we, LOW);
    digitalWrite(ram_we, HIGH);
    
    //disabilitare tutti i chip
    digitalWrite(latch1pin, LOW);
    digitalWrite(latch2pin, LOW);
  }

  byte read_ram(unsigned int mem_address) {
    byte value, hbyte, lbyte;
    
    //leggere il contenuto del byte "indirizzo"
    //scrivi l'indirizzo
    digitalWrite(latch1pin, LOW);
    digitalWrite(latch2pin, LOW);
    digitalWrite(ram_we, HIGH); //disabilitare il 3° 595 e dire alla RAM di non scrivere in se stessa
    hbyte = highByte(mem_address);
    lbyte = lowByte(mem_address);
    shiftOut(data1pin, clock1pin, MSBFIRST, hbyte);
    shiftOut(data1pin, clock1pin, MSBFIRST, lbyte);
    
    //impostare l'indirizzo "visibile" sul bus
    digitalWrite(latch1pin, HIGH);
    digitalWrite(latch2pin, HIGH);
    //preparare il 165
    digitalWrite(clock_pin, HIGH);
    digitalWrite(set_load, LOW);
    //leggi dalla RAM
    digitalWrite(ram_oe, LOW);
    //caricare i dati dal 165
    digitalWrite(set_load, HIGH);
    digitalWrite(ram_oe, HIGH);
    value = shiftIn(load_data, clock_pin, MSBFIRST);
    digitalWrite(latch1pin, LOW);
    digitalWrite(latch2pin, LOW);
    return value;   
  }
```


> 13/07/2023
## Memory chip:

**Memory chip: 23LCV1024**<br>
Fonte: Fritzing<br>
Famiglia: Memory<br>
Tipo: SRAM⚠️<br>
Pakage: DIP (Dual line)[THT]<br>
Pins: 8<br>

**Memory chip: 23K640-I/P (non verificata compatibilità)**<br>
Fonte: https://www.microchip.com/en-us/product/23K640<br>
Memory: 64 Kbit <br>
Tipo: SRAM⚠️<br>
Max clock: 16 MHz <br>
Organizzazione: 8192 x 8 bit <br>
Modalità operative flessibili: Lettura e scrittura byte<br>

Fonte: https://www.mouser.it/ProductDetail/Microchip-Technology/23K640-I-P?qs=WqWCsLCZBkrTQsioMaN7VA%3D%3D&mgh=1&vip=1<br>
Dimensioni memoria:	64 kbit <br>
Organizzazione:	8 k x 8 <br>
Frequenza di clock massima:	20 MHz<br>
Tipo di interfaccia: SPI<br>
Tensione di alimentazione Max: 3.6V<br>
Tensione di alimentazione Min: 2.7 V<br>

**Altro...**<br>
[Molti altri Memory chip SRAM](https://www.mouser.it/c/semiconductors/memory-ics/sram/?instock=y)⚠️<br>
[Ricerca Google: Memory chip SRAM](https://www.google.com/search?q=memory+chip+DRAM&sa=X&rlz=1C1CHBD_itIT1059IT1059&biw=1536&bih=714&tbm=shop&sxsrf=AB5stBhj9DN2i1dEs3f4ilTd8TVJ5u_9jg%3A1689242226612&ei=csqvZO37I_eL9u8P_M2IOA&ved=0ahUKEwjt_OvWtYuAAxX3hf0HHfwmAgcQ4dUDCAg&uact=5&oq=memory+chip+DRAM&gs_lcp=Cgtwcm9kdWN0cy1jYxADMggIABAWEB4QGDoHCCMQsAMQJzoKCAAQGBCABBCwAzoJCAAQBxAeELADOgcIABAeELADOgsIrgEQygMQsAMQJzoECCMQJzoHCAAQExCABDoICAAQFhAeEBM6BggAEBYQHjoKCAAQFhAeEBgQDzoNCAAQFhAeEBgQ8QQQCjoPCAAQFhAeEBgQDxDxBBAKOgwIABAWEB4QGBAPEApQ-idYnOcMYO3wDGgCcAB4AIABoAGIAZUHkgEDMi42mAEAoAEBwAEByAEL&sclient=products-cc)⚠️<br>
[Ricerca Google: Infineon FM24V01A-G F-RAM](https://www.google.com/search?q=Infineon+FM24V01A-G+F-RAM&rlz=1C1CHBD_itIT1059IT1059&tbm=isch&sxsrf=AB5stBgZ62H16k9kNxOz404Gjuok79f1rQ:1689242766939&source=lnms&sa=X&ved=0ahUKEwipqr_Yt4uAAxWOcvEDHaTFBOIQ0pQJCHs&biw=1536&bih=714&dpr=1.25)<br>
[Ricerca Google: ISSI IS42S81600F-7TL DRAM](https://www.google.com/search?q=ISSI+IS42S81600F-7TL+DRAM&sa=X&rlz=1C1CHBD_itIT1059IT1059&biw=1536&bih=714&tbm=shop&sxsrf=AB5stBjrxlveZ3N9KOoZ01yxMamp08mtyw%3A1689242454393&ei=VsuvZL-IF73l7_UPxZK70AU&ved=0ahUKEwi_i7vDtouAAxW98rsIHUXJDloQ4dUDCAg&uact=5&oq=ISSI+IS42S81600F-7TL+DRAM&gs_lcp=Cgtwcm9kdWN0cy1jYxADOgsIABAIEB4QGBCwAzoLCK4BEMoDELADECdQngZYngZg4BBoAHAAeACAAagBiAGNApIBAzAuMpgBAKABAqABAcABAcgBAg&sclient=products-cc)(Scrivi i dettagli)<br>


> 12/07/2023

### Microcontrollore: ATmega168-20PU
[Aquista ATmega168-20PU](https://www.amazon.it/s?k=ATmega168-20pu&__mk_it_IT=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=116O85AZQNVDO&sprefix=atmega168-20pu%2Caps%2C210&ref=nb_sb_noss)<br>
Per gestire il microcontrollore della RAM ho trovato lo schema della pedinatura; infatti usa le corrispondenze dei pin Arduino, questo rende più semplice la connessione diretta tra Scheda arduino e microcontrollore.
<br>
**Possiamo quindi collegarlo direttamente ad Arduino e programmarlo dai pin**
<br>
![Schema pedinatura ATmega168](/Risearch/png/Pedinatura_ATmega168.png)
<br>
**Se programmazione diretta con Arduino fallisce:** usa una [scheda programmatore](https://it.aliexpress.com/item/1005002024535402.html?pdp_npi=2%40dis%21EUR%212%2C28%E2%82%AC%211%2C78%E2%82%AC%21%21%21%21%21%40211b446416891975608484484e7e18%2112000018450454697%21btf&_t=pvid%3A6b026697-c6a6-4801-b510-cff78210e0f5&afTraceInfo=1005002024535402__pc__pcBridgePPC__xxxxxx__1689197561&spm=a2g0o.ppclist.product.mainProduct&gatewayAdapt=glo2ita)


> 09/07/2023

## Domanda di partenza: <br> Possibile trasformare un microcontrollore (normale) in un Memory chip?

Presumendo di creare un codice che possa usare il 100% della memoria interna del microcont. il codice potrebbe essere così:
```c++
  #include <string.h>

  int main() {
    string m = [100%];
  }
```

## Come usare un Memory Chip per creare una RAM?
#### Fonte: Chat GPT

Per creare una RAM utilizzando un memory chip esterno, come ad esempio una memoria SRAM o una memoria DRAM, dovrai seguire i seguenti passaggi generali:

1. **Seleziona il chip di memoria**: Scegli un memory chip   esterno adatto alle tue esigenze, considerando i requisiti di capacità, velocità e interfaccia.
2. **Collega il chip di memoria al microcontrollore**: Collega il chip di memoria al microcontrollore utilizzando l'interfaccia appropriata, come ad esempio un bus di dati e un bus di indirizzi. È importante consultare il datasheet del chip di memoria e del microcontrollore per comprendere i dettagli dell'interfacciamento e dei segnali necessari.
3. **Configura il chip di memoria**: Inizializza il chip di memoria seguendo le specifiche del suo datasheet. Ciò può includere l'impostazione di parametri come la modalità di funzionamento (ad esempio, asincrona o sincrona), il timing dei segnali, le opzioni di gestione dell'alimentazione e altre configurazioni specifiche del chip.
4. **Scrivi e leggi dati dalla memoria**: Utilizzando le istruzioni e i comandi appropriati forniti dal datasheet del chip di memoria, puoi scrivere e leggere dati nella memoria esterna. Questo coinvolge l'invio dei segnali di controllo e dati attraverso l'interfaccia tra il microcontrollore e il chip di memoria.
5. **Gestisci l'indirizzamento della memoria**: Poiché stai utilizzando un chip di memoria esterno, dovrai gestire l'indirizzamento dei dati. Assicurati di avere un meccanismo per tenere traccia degli indirizzi di memoria utilizzati per scrivere e leggere i dati correttamente.
6. **Considera la gestione della sincronizzazione**: Se stai utilizzando una memoria DRAM, potrebbe essere necessario gestire i segnali di refresh periodici per mantenere i dati. Questi segnali di refresh sono specifici delle DRAM e richiedono una gestione adeguata per garantire il corretto funzionamento della RAM.

## Caratteristiche selezionate per RAM
|Metodo lett-scritt.|Tipo di RAM| Colonna |
|-------------------|-----------|-----------|
|Asincrono| DRAM  | Valore |


### Skech di come verrebbe:
Infine: si pensa che bisogna mettere dei Memory Chip collegati e contollati da un Microcontrollore.
![Skech fritzing](/Risearch/png/Skech_frizzing.png)

## Info e definizioni
#### Fonte: [Wikipedia](https://it.wikipedia.org/wiki/RAM); [Seample RAM Wikipedia](https://simple.wikipedia.org/wiki/Random-access_memory)

**Asincrone**: ovvero l'accesso in scrittura ed in lettura è comandato direttamente dai segnali in ingresso. 
<br>
**Sincrone**: il passaggio da uno stato all'altro è sincronizzato ad un segnale di clock.

**DRAM**:La DRAM: Ram Dinamica, è costituita da un transistor che separa un condensatore,(che quale mantiene l'informazione, dai fili di dati). A livello pratico non viene usato un vero condensatore ma si sfruttano le proprietà elettrico/capacitive dei semiconduttori. È così possibile usare un solo componente per ogni cella di memoria, con costi molto ridotti e la possibilità di aumentare notevolmente la densità di memoria.

A causa del non perfetto isolamento, il condensatore si scarica, quindi dopo un breve lasso di tempo il suo contenuto diventa completamente inaffidabile. Si rende necessario perciò ricaricarlo, l'operazione è detta di "refreshing", provvedendo ad eseguire un'operazione di lettura fittizia e riscrittura entro il tempo massimo in cui il contenuto può essere considerato ancora valido. Queste operazioni sono eseguite da un circuito interno alle memorie stesse. Oltre a comportare un certo dispendio di energia rendono più lenta la memoria in quanto, mentre si sta eseguendo il refreshing, non è possibile accedervi. Le memorie DRAM si possono considerare abbastanza affidabili anche perché molto spesso ad ogni riga della memoria è associato un bit di parità, che consente di individuare eventuali errori singoli all'interno della riga, oppure una serie di bit (login), che opportunamente impostati nel momento di ogni scrittura, generano il codice di Hamming corrispondente, che consente di individuare e correggere errori singoli e individuare errori doppi.

È importante sottolineare come l'operazione di lettura sia distruttiva, in quanto nel momento in cui un dato viene letto viene anche perso; risulta quindi necessaria la sua riscrittura immediata e questa porta a uno spreco di tempo.


> 08/07/2023
#### Fonte: Bing AI

Per creare uno slot RAM compatibile con Arduino Mega 2560 è necessario utilizzare una memoria esterna. La memoria esterna può essere collegata alla scheda Arduino tramite un bus di dati e un bus di indirizzi. 

[Per quanto riguarda la programmazione, è possibile utilizzare la libreria "External RAM" che permette di utilizzare la memoria esterna come se fosse una memoria interna.](https://github.com/elechouse/External_RAM) 

[Inoltre, esistono anche moduli di memoria RAM esterna già pronti per l'utilizzo con Arduino Mega 2560 come ad esempio il modulo "RAMPS 1.4" che permette di controllare fino a 5 motori passo-passo.](https://reprap.org/wiki/RAMPS_1.4)