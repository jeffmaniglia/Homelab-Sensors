# garden-instruments
Repository of 'wrapper' classes I have created for multiple common instruments. This code was compiled for and tested on an ESP-8266 NodeMCU in the Arduino IDE. These classes are optimized to make it easy for the user to report sensor values to an MQTT broker quickly and easily.
Dependent Libraries (so far):
Adafruit_ADS1105 
DHT11/22/21

Contributors to this project that wish to upload a wrapper - i'm still trying to make ground rules, but here's what I'm thinking currently:

Also - I'm writing these ground rules and notes for myself just as much for others, to keep some consistency in the classes

1. EXTREMELY beginner friendly - assume most likely case of use for some sensor/actuator and use that. Focus is home smart garden/smart home devices. Not university experiments or other projects
2. Assume use of MQTT broker. Each sensor should have a character array public variable called "msg" that is designated as the reporting variable for use in the "publish" method for the arduino pubsubclient.
3. When required to run any code in the main void setup(), the class shall have a void setup() method.
4. To take a sensor reading and update any public variables used for reporting, there shall be a void read() method
5. All variables from sensor readings should be in real units. Not digital representations of real numbers. If the sensor measures a voltage, don't report the digital value of that voltage, do some math to convert the digital value to a voltage and store it in a float. Make that float the public variable. Same goes for resistance readings, current readings, etc. Additionally, if applicable allow the user an input to the constructor to choose the type of units (english vs. metric)
6. Analog sensors should be built into the external Analog to Digital Converter ADS1015/1115 - just to make it centralized and plug and play with those units. Goal is to have the ability to have one ADS1115 in a sketch that has four separate analog sensors with their own classes, passing the same ADS1115 object to each sensor object and a different input port for each one. Simple and clean. This really helps smart garden/home users utilize ESP8266's as those MCUs only have one analog input to use. 
7. Don't rewrite classes already available for off the shelf components, even if it would be simple, unless absolutely required. I would like these to be wrapper classes as much as possible. The class should initialize and use an object of another class (like DHT for example) by use of pointers. This keeps the code modular, and if new sensors come around that use the same class, we don't have to change our code (maybe). Also, an idea would be integration with Adafruit Unified Sensor somehow - but I haven't played with that yet.

Future Sensors/Wrapper classes:
Ammeter - for kWh measurements
flow rate sensors
watering - turn on a valve/pump for a period of time
wrapper for espclient and wificlient. It's a lot of code that I think could be standardized and setup so that the end user doesn't have to think about it. But because the end user would probably want to change the callback() function, and I am unsure how a wrapper class would work, I haven't come up with a good plan yet. 
IR entry/exit
motion
glass break
water presence (flood warning)
carbon monoxide
fire alarm
???

