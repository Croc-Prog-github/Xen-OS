# Creare RAM con Arduino
**Ordine**: Data di creazione, Decrescente.

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
![Skech fritzing](/Risearch/png/Skech_fritzing.png)

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