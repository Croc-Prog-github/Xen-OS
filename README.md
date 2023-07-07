# Xen-OS
Il sistema operativo della console Xenos.

## Caratteristiche principali

| **INTERNET** |**CONTROLLER**|**HARD DISK**       |**AUDIO**            |**ALIMENTAZIONE**|**SCHERMO**  |
|--------------|--------------|--------------------|---------------------|-----------------|-------------|
|Arduino Ethernet| MAX: 2       |Lettore-scrittore SD|Integrato: X         |Batteria: X      |Integrato: X |
|              |Comand: Wirles|Size os: 8GB        |Connettore:          |Alimentatore: OK |HDMI: X      |
|              |              |User space: 4GB     |Jack: X              |                 |Pres.Scart: X|
|              |              |                    |USB: X               |                 |RCA: X       |
|              |              |                    |Jack G: OK           |                 |VGA: OK      |
|              |              |                    |Port.Ser.25PIN: X    |                 |             |
|              |              |                    |Buffer Altern.Audi: X|                 |             |

## Config. delle schede
|**Tutto in Arduino Mega**|**Separati in schede**|
|-------------------------|------------------|
|Economico: true|Economico: false|
|Prestazioni: false|Prestazioni: true|
|Problemi stimati: 30%|Problemi stimati: 45%|
|Flessibilità di prog.: false|Flessibilità di prog.: true|
|Stima Tempo 1°modello: 15h|Stima Tempo 1°modello: 34h|