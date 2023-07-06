# Xen-OS
Il sistema operativo della console Xenos.

## Caratteristiche base

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
|---------------------|------------------|
|Economico: true|Economico: false|
|Prestazioni: false|Prestazioni: true|