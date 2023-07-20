# wemos_RV_temp_monitor
A simple arduino based project that uses a Wemos d1 mini, a LCD and 4 sensors to show various temperatures on a small LCD for display in an RV

It collects data from 4 different sensors and shows the values on a LCD for quick viewing while maintaining extremely low power consumption, ideal for a system a small RV which has limited battery

It is proceeds to transmit the sensors values over serial to an external machine running linux, for remote monitoring. The device is designed to be fully operational with the external machine powered off in case of low power situations where running the linux machine is not desireable

This project uses the follow components

-Wemos D1 mini  
-DHT11(used only for humidity sensor)  
-3 DS18B20 waterproof one wire temperature sensors  
-SSD1306 OLED LCD monitor for display  


Future goals
-Send data via serial to a raspberry PI onboard the RV and publish it to a MQTT broker to integrate with a IoT platform(home assistant)
