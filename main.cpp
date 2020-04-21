 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   - you should be left with only your UDTs.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */


/*
1)speaker
5 properties:
    1)crossover frequency
    2)woofer material
    3)tweeter material
    4)ported design
    5)active design with rated power
3 things it can do:
    1)active design can amplify a line level signal
    2)can split the signal in 2 bands at crossover frequency
    3)port can boost the low frequencies
 */
struct Speaker
{
    //1)crossover frequency
    float fc = 2000;
    //2)woofer material
    char wooferMaterial ='p';
    //3)tweeter material
    char tweeterMaterial = 'r';
    //4)ported design
    float portResonantFrequency = 48; 
    //5)active design with rated power
    float ratedAmpPower = 100;
    
    struct Signal
    {
        float level;
        float fMin;
        float fMax; 

        void limitInputLevel( float maxIncomingPeakLevel = 10);
        void bandPass( float minFreqAllowed = 20, float maxFreqAllowed = 20000 );
    };

    //1)active design can amplify a line level signal
    Signal amplifySignal( Signal signalToModify );
    //2)can split the signal in 2 bands at crossover frequency
    Signal splitSignal( Signal signalToModify );
    //3)port can boost the low frequencies
    Signal boostLowFreq( Signal signalToModify );

    Signal signal;
    
};
/*
2)jumpstarter
5 properties:
    1)current rating in amperes
    2)battery technology
    3)weight
    4)short circuit protection
    5)charge display leds
3 things it can do:
    1)jumpstart a car 
    2)power devices trough USB
    3)display the battery charge level
 */
struct JumpStarter
{
    //1)current rating in amperes
    int maxCurrent = 300;
    //2)battery technology
    char batteryType = 'a';
    //3)weight
    float weight = 55;
    //4)short circuit protection
    float peakCurentTriggerProtection = 400;
    //5)charge display leds
    int ledAmount = 3;
    int currentChargeLevel = 80; // added this to use in function

    struct DeviceToBeCharged
    {
        bool isItACar = true;
        bool isItUSB = false;
        float currentDraw;

        bool startEngine( int timesToAttemp = 3 );
        float consumePower( float currentDraw = 250 );
    };

    //1)jumpstart a car 
    float jumpStartCar( DeviceToBeCharged car );
    //2)power devices trough USB
    float chargePhone( DeviceToBeCharged phone );
    //3)display the battery charge level
    int displayChargeLevel();

    DeviceToBeCharged car;
};
/*
3)midi controller
5 properties:
    1)amount of keys
    2)amount of knobs
    3)display size
    4)performance controls
    5)weight 
3 things it can do:
    1)send midi data when keys pressed
    2)display current patch
    3)transpose octave
 */
struct MidiController
{
    //1)amount of keys
    int amountOfKeys = 49;
    //2)amount of knobs
    int amountOfKnobs = 5;
    //3)display size
    int displayCharacters = 10;
    //4)performance controls
    int performanceControls = 2;
    //5)weight 
    float weight = 25;

    //1)send midi data when keys pressed
    int sendMidi( int keyPressed );
    //2)display current patch
    int displayPatch( int patchNumber );
    //3)transpose octave
    int transposeOctave( int semitones );

};
/*
4)air contitioning unit
5 properties:
    1)portable
    2)cooling power in BTU
    3)noise level
    4)heather option
    5)directional fan
3 things it can do:
    1)remove environment heat to control room temperature
    2)heat a room
    3)select the fan speed
 */
struct AirConditioningUnit
{
    //1)portable
    int numberOfCasters = 4;
    //2)cooling power in BTU
    float coolingBtu = 2000;
    //3)noise level
    float noiseLevel = 55;
    //4)heather option
    float heatherPower = 2000;
    //5)directional fan
    char fantype ='d';

    //1)remove environment heat to control room temperature
    float removeHeat( float roomHeatAmount = 8000 );
    //2)heat a room
    float heatRoom( float initialTemperature = 55 );
    //3)select the fan speed
    int selectFanSpeed( int selectedSpeed );
};
/*
5)USB interface
5 properties:
    1)speed in Mb per second
    2)standard (1.0 or 2.0 for USB ) 
    3)cable length 
    4)connector type
    5)current it can receive for powering the board
3 things it can do:
    1)get the program to be stored in memory
    2)report errors
    3)transmit serial data back to computer
 */
struct UsbInterface
{
    //1)speed in Mb per second
    int speed = 40;
    //2)standard (1.0 or 2.0 for USB ) 
    int standard = 1;
    //3)cable length
    float length = 5; 
    //4)connector type
    char connectorType = 'A';
    //5)current it can receive for powering the board
    float currentDrawForPower = 50;

    //1)get the program to be stored in memory
    int openLinkToGetData();
    //2)report errors
    char sendErrorToComputer( int errorCode = 0 );
    //3)transmit serial data back to computer
    int sendDataStreamToComputer ( int streamLength = 10 );
};
/*
6)DA converters
5 properties:
    1)amount of channels
    2)bit depth
    3)clocking speed
    4)max output current
    5)output impedance
3 things it can do:
    1)provide a constant voltaje for controlling a device
    2)drive a transistor
    3)read a constant sensor voltage 
 */
struct Converter
{
    //1)amount of channels
    int channels = 5;
    //2)bit depth
    int bitDepth =16;
    //3)clocking speed
    int clockSpeed = 1;
    //4)max output current
    float maxCurrent = 10;
    //5)output impedance
    char adOrDa = 'a';

    //1)provide a constant voltaje for controlling a device
    void setVoltage( int vLevel = 25, int channel = 1 );
    //2)drive a transistor
    void setBoolOut( bool status, int channel = 2 );
     //3)read a constant sensor voltage
    int readConstantValue( int channel = 3 );


};
/*
7)serial port
5 properties:
    1)amount of channels 
    2)speed
    3)mode
    4)data word length
    5)error correction
3 things it can do:
    1)transmit data
    2)receive data
    3)set speed
 */
struct SerialPort
{
    //1)amount of channels
    int channels = 2; 
    //2)speed
    int speed = 128;
    //3)mode
    char mode ='a';
    //4)data word length
    int wordLength = 8;
    //5)error correction
    char errorCorrection = 'n';

    //1)transmit data
    void transmitData( int channel = 1, char data = '0' );
    //2)receive data
    char receiveData( int channel = 2 );
    //3)set speed
    void setSpeed( int speed = 128 );
};
/*
8)memory
5 properties:
    1)size
    2)type of memory (ram , eprom, rom, flash)
    3)clock speed
    4)slot for flash card
    5)power consumption
3 things it can do:
    1)store script
    2)store data read from sensors
    3)store status 
 */
struct Memory
{
    //1)size
    int Size = 1000;
    //2)type of memory (ram , eprom, rom, flash)
    char Type = 'r';
    //3)clock speed
    int Speed = 1000;
    //4)slot for flash card
    char Flash = 'y';
    //5)power consumption
    int powerComsumption = 200;

    //1)store script
    int writeScript( int scriptSize = 500 );
    //2)store data read from sensors
    int writeData( int location = 800, int dataSize = 1 );
    //3)store status
    int writeStatus( int statusCode = 0 );
};
/*
9)reset button
5 properties:
    1)size
    2)location on the board
    3)color
    4)material
    5)number of clicks before failure
3 things it can do:
    1)reset the script
    2)produce a click sound
    3)trigger a led
 */
struct ResetButton
{
    //1)size
    float height = 0.05f;
    //2)location on the board
    char location = 't';
    //3)color
    char color = 'r';
    //4)material
    char material = 'p';
    //5)number of clicks before failure
    int clicksBeforeFailure = 10000;

    //1)reset the script
    int triggerResetSginal( float clickTime = 0 );
    //2)produce a click sound
    void clickSound( float clickTime = 0 );
    //3)trigger a led
    void triggerLed( float clickTime = 0 );
};
/*
10)microcontroller
5 properties:
    1)USB interface
    2)converters
    3)serial port
    4)memory
    5)reset button
3 things it can do:
    1)store instructions received from computer trough USB
    2)get a data character from serial interface
    3)read analog value from AD converter 
 */
struct Microcontroller
{
    //1)USB interface
    UsbInterface usb0;
    //2) converter
    Converter ad;
    Converter da;
    //3)
    SerialPort serialPort;
    //4)memory
    Memory memory;
    //5)reset button
    ResetButton resetButton;

    struct Script      //this was not requested but can be used later
    {
        int scriptLength; 
    };

    //1)store instructions received from computer trough USB
    int storeScript( Script script );
    //2)get a data character from serial interface
    char getCharacter( SerialPort serialPort, int channel = 1 ); 
    //3)read analog value from AD converter 
    char readValue( Converter ad, int channel = 0 ); 
};
#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
