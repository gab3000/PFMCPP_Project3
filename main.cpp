/*
Project 3 - Part 1 / 5
Video:  Chapter 2 Part 5
User-Defined Types

Create a branch named Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to reinforce the syntax habits that C++ requires.  What you create in this project will be used as the basis of Project 5 in the course.   

1) write 10 user-defined types in plain english
   - This step will involve several checkpoints before it is complete.

Checkpoint 1:
    Fill in #1 - 4 with a random UDT in plain english
    These 4 UDTs do not need to be related.
    For each plain-english UDT, write out 3 things it can do, and 5 traits or properties.

************************
    Commit after you complete this step so i can review before you proceed
    Ping me in Slack to review this step.
    Wait for me to review before proceeding to the next Checkpoint
************************

Checkpoint 2:
    For the 10th UDT, come up with an object that is made of 5 smaller parts.
    Here is an example:
    Cell Phone

    A Cell Phone is made up of the following 5 properties:
        Display
        Memory
        CPU
        Radio
        Applications

    A Cell Phone has 3 things it can do:
        make a call
        send a text
        run an application.

************************
    Commit after you complete this step so i can review before you proceed
    Ping me in Slack to review this step.
    Wait for me to review before proceeding to the next Checkpoint
************************

Checkpoint 3: 

    Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, until the smallest object is made of up only C++ primitives. 

    These 5 things can be broken down into their own sub-objects and properties. 

    For example: Display
    A Display has the following 5 traits or properties:
        pixels
        amount of power consumed.
        brightness.
        width
        height

    the Display's brightness can be represented with a Primitive, such as a double. 
    The amount of power consumed can also be represented with a Primitive.
    The 'pixels' must be represented with an array of Pixel instances.  Arrays have not been discussed and can't be used in this project.
    Instead, we can use an Integer primitive to describe the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed
        Brightness

    Notice that I did not write "has a display" or "Has memory" or "has a cpu"  
    Writing 'has a ___" checks whether or not your object *has the ability to do something*.
    Instead, I wrote "Display" or "CPU".  These are specific objects or amounts. 
    In C++ terms, this means to I want you to avoid bool (has a) as a member variable type.
    Instead, prefer the other primitive types when you get to step 2)

************************
    Commit after you complete this step so i can review before you proceed
    Ping me in Slack to review this step.
    Wait for me to review before proceeding with step 2.
************************
  
 2) define your struct for each of your 10 types. 
    - Copy your 3 actions & 5 traits into your struct body.
    - comment them out.
    - I recommend compiling after finishing each one and making sure it compiles without errors or warnings before moving on to writing the next UDT.
 
 3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
 
 4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions in part2 for these functions
    - you'll call each of these functions in part3
 
 5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs at least 2 member functions.
    - these nested classes are not considered one of your 10 UDTs.
 
 6) your 10th UDTs should only use 5 of your other UDTs for its member variable types.   
    - No primitives allowed!
 
 7) After you finish defining each type, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

/*
 example:  

//1) write out, in plain-english, 5 traits and 3 things it can do.
Car Wash   
5 properties:
    1) vacuum cleaners
    2) eco-friendly cleaning supplies
    3) stores the amount of water used per week.
    4) stores amount of profit made per week
    5) number of cars serviced per day

3 things it can do:
    1) wash and wax car
    2) charge customer
    3) detail the car interior
 */
struct CarWash //2)        
{
    //2) has vacuum cleaners
    int numVacuumCleaners = 3; //3) member variables with relevant data types.
    //2) has eco-friendly cleaning supplies
    int numEcoFriendlyCleaningSupplies = 20; //3) member variables with relevant data types.
    //2) stores the amount of water used per week.
    float waterUsedPerWeek = 200.f; //3) member variables with relevant data types.
    //2) stores amount of profit made per week
    float profitPerWeek = 495.95f; //3) member variables with relevant data types.
    //2) number of cars serviced per day
    int numberOfCarsServiced = 10; //3) member variables with relevant data types.
    
    //5) make 2 of the 10 user-defined types have a nested class. 
    struct Car   
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);   
    };

    /* 
    member functions with a user-defined type as the parameter.
    The user-defined type parameter happens to be the nested class.
    */

    //2) wash and wax car
    void washAndWaxCar( Car car );
    //2) charge customer
    float chargeCustomer();
    //2) detail the car interior
    void detailInterior( Car car );
    
               
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};


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
2)car jumpstarter
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
struct CarJumpstarter
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
    float jumpstartCar( DeviceToBeCharged car);
    //2)power devices trough USB
    float chargePhone( DeviceToBeCharged phone);
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
    int usbSpeed = 40;
    //2)standard (1.0 or 2.0 for USB ) 
    int usbStandard = 1;
    //3)cable length
    float cableLength = 5; 
    //4)connector type
    char usbConnectorType = 'A';
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
    1)play audio
    2)provide a constant voltaje for controlling a device
    3)drive a transistor 
 */
struct DaConverter
{
    //1)amount of channels
    int daChannels = 5;
    //2)bit depth
    int daBitDepth =16;
    //3)clocking speed
    int daClockSpeed = 1;
    //4)max output current
    float daMaxCurrent = 10;
    //5)output impedance
    float daOutImpedance = 50;

    //1)play audio
    void playAudio( int audioLevel = 50, int channel = 0 );
    //2)provide a constant voltaje for controlling a device
    void setVoltage( int vLevel = 25, int channel = 1);
    //3)drive a transistor
    void setBoolOut( bool status, int channel = 2);
};
/*
7)AD converters
5 properties:
    1)amount of channels
    2)bit depth
    3)sampling speed
    4)input impedance
    5)overcurrent protection
3 things it can do:
    1)read a constant sensor voltage
    2)read an audio signal
    3)read a TTL binary signal
 */
struct AdConverter
{
    //1)amount of channels
    int adChannels = 2;
    //2)bit depth
    int adBitDepth = 12;
    //3)sampling speed
    int adSamplingSpeed = 1;
    //4)input impedance
    int adImpedance = 600;
    //5)overcurrent protection
    float adMaxCurrent = 10;

    //1)read a constant sensor voltage
    int readConstantValue( int channel = 0 );
    //2)read an audio signal
    int readAudioSignal( int SamplingSpeed = 1, int channel = 1 );
    //3)read a TTL binary signal
    int readBool( int channel = 3 );
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
    int memorySize = 1000;
    //2)type of memory (ram , eprom, rom, flash)
    char memoryType = 'r';
    //3)clock speed
    int memorySpeed = 1000;
    //4)slot for flash card
    char memoryFlash = 'y';
    //5)power consumption
    int powerComsumption = 200;

    //1)store script
    int writeScript( int scriptSize = 500 );
    //2)store data read from sensors
    int writeData( int memoryLocation = 800, int dataSize = 1 );
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
    float buttonHeight = 0.05f;
    //2)location on the board
    char buttonLocation = 't';
    //3)color
    char buttonColor = 'r';
    //4)material
    char buttonMaterial = 'p';
    //5)number of clicks before failure
    int buttonClicksBeforeFailure = 10000;

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
    2)DA converters
    3)AD converters
    4)memory
    5)reset button
3 things it can do:
    1)store instructions received from computer trough USB
    2)read data from AD converter 
    3)control devices trough DA converter. 
 */
struct Microcontroller
{
    //1)USB interface
    UsbInterface usb0;
    //2)DA converters
    DaConverter da0;
    //3)AD converters
    AdConverter ad0;
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
    //2)read data from AD converter
    char readData( AdConverter ad0, int channel = 0 ); 
    //3)control devices trough DA converter.
    int setValue( DaConverter da0, int value = 0, int channel = 0 );
};
#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
