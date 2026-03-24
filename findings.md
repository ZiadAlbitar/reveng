# Viktor och Ziad, mars 24
Första 6 packets är handshakes (3 fram och tillbaka). 
Headern i acks är 28 (0x1C) words (två siffror är en word). 
headern ser ut så här:

[Header length (2) | IRP ID (8) | USB status (4) | USB function (2) | Direction (1) | bus id (2) | device adress (2) | endpoint (1) | URB transfer type (1) | packet data length (4) | Control transfer stage setup (1)]

Control transfer stage finns bara i handshake header, alltså har andra headers längd 27 (0x1B)

Verkar finnas olika ips för sources: 1.29.0, 1.29.3, 1.29.4, 1.29.5 och 1.29.6 där 29 är device adress.
1.29.0 är för handshaken
1.29.3 har alla längd 91 words om det skickas till oss och 27 som vi skickar baka (gissar en ack)
1.29.4 samma som 3 fast tvärtom. Så antagligen en port för att skicka och en för att ta emot.
1.29.5 har två större paket på längd 300-400, och vi skickar tillbaka en ack (antagligen alltså)
1.29.6 har bara ett paket skickat med 106 words och 27 tillbaka, antagligen en ack. På samma sätt verkar vi skicka acks när vi får in stora paket på .5. 

De mesta av informationen är att vi skickar en paket på 91 till .4, får tillbaka en på 27 från .4 och sen skickar en på 27 till .3 och sen får en på 91 från .3. Detta repeteras massa gånger.

Värt att kolla upp:
Hur skiljer sig paketen som går igenom portarna 3->6. Framförallt headern för att det är lättast att se skillnad. På något sätt borde det förklara vad man ska göra med informationen gissningsvis.