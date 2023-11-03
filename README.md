# DIY-Smart-Garage-Door-Opener

## Descripción:

Este proyecto ofrece una solución eficiente y sencilla para controlar mediante un teléfono móvil o computadora un portón eléctrico utilizando una placa ESP8266, ESP32 o cualquier otra placa con conectividad WiFi.

## Contenido del Repositorio:

- **Código ESP8266 NodeMCU:** Contiene el código fuente necesario para programar la placa ESP8266 NodeMCU, establecer la comunicación mediante web server y asi desencadenar la lógica necesaria para controlar el portón eléctrico. Sería necesario adaptar el código si la placa a utilizar fuera una ESP32 en lugar de la ESP8266 que se usa en este proyecto.

- **Diagramas de Conexión:** Las conexiones a realizar son sumamente sencillas. Igualmente, dejo esquemas detallados y diagramas de conexión para facilitar la reproducción y modificación del proyecto.

- **Imágenes:** Agregué algunas imágenes del proyecto como referencia para futuras replicas del proyecto 🌎. También grabé un video de mi madre utilizando el dispositivo desde su teléfono. Ver el proyecto funcionando acá --> www.youtube.com/shorts/uxmjgB_-3TI 

## Componentes necesarios 🛒:

- Placa ESP8266 NodeMCU con capacidad WiFi. 🛜
- Módulo relé controlado con 5v.
- Módulo 220v AC a 5v DC para alimentar el proyecto. ⚡️
- Una placa de cobre perforada (opcional).
- Algunos cables. 
- Un contenedor para resguardar el proyecto de las inclemencias del tiempo. 🌦️
- Portón eléctrico. (Hace falta investigar un poco para endender donde conectar el relé a la placa del portón)

## Funcionamiento 📡

La placa ESP8266 cuenta con capacidad de conexión a una red WiFi, lo que habilita a los usuarios para establecer comunicación con la dirección de este dispositivo. Cuando el dispositivo recibe una instrucción por parte del usuario, se procede a poner el pin D8 en un estado lógico alto por un período determinado. Este estado excitado del pin D8 tiene como finalidad activar un relé o saturar un transistor (consideraciones de diseño a gusto de los usuarios). Esto posibilita que el pin asignado por el fabricante de la placa de control del portón eléctrico se conecte a tierra, lo cual es interpretado como una señal para abrir o cerrar el portón.

## Limitaciones 😔:

Lamentablemente el sistema solo funciona si el teléfono celular y el ESP8266 estan conectados a la misma red WiFi. Una posible solución a este problema seria abrir un puerto de la red local y así acceder al dispositivo a través de este puerto(habría que tener consideraciones en términos de seguridad). Sin embargo, esto sería una solución temporal, ya que generalmente nuestro proveedor de internet cambia nuestra IP pública regularmente. (Mis conocimientos en redes son básicos, sepan disculpar tecnicismos)

¡Espero que este proyecto anime a otras personas a desarrollar sus proyectos y seguir aprendiendo📚!
