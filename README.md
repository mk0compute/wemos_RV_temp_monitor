# wemos_RV_temp_monitor
A simple arduino based project that uses a Wemos d1 mini, a LCD and 4 sensors to show various temperatures on a small LCD for display in an RV

It collects data from 4 different sensors and shows the values on a LCD for quick viewing while maintaining extremely low power consumption, ideal for a system a small RV which has limited battery 

This project uses the follow components

-Wemos D1 mini  
-DHT11(used only for humidity sensor)  
-3 DS18B20 waterproof one wire temperature sensors  
-SSD1306 OLED LCD monitor for display  


Future goals
-Send data via serial to a raspberry PI onboard the RV and publish it to a MQTT broker to integrate with a IoT platform(home assistant)
