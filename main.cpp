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
struct Person	
{	
	int age;
	int height;
	float hairLength;
	float GPA;
	unsigned int SATScore;

    struct Foot				
	{			
        float distanceFromGround = 0 ;
        float momentum = 0;

    	int stepForward( float momentum, float distanceFromGround );		
		float stepSize();		
	};			

    Foot leftFoot;
    Foot rightFoot;

    void run( int howFast, bool startWithLeftFoot );
};


int Person::Foot::stepForward( float momentumT0, float distanceFromGroundT0 )				
{			
    if ( momentumT0*distanceFromGroundT0 > 0 )
    
    return 1;			
    
    else return 0 ;
}			

float Person::Foot::stepSize()				
{			
	int legLength = 2;			
	float sineOfStepAngle = .25;	
    int stepDirection = Person::Foot::stepForward( momentum, distanceFromGround );

	return  sineOfStepAngle * legLength * stepDirection;			
}			
 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

struct Speaker
{
    float fc = 2000;
    char wooferMaterial ='p';
    char tweeterMaterial = 'r';
    float portResonantFrequency = 48; 
    float ratedAmpPower = 100;
    
    struct Signal
    {
        float level;
        float fMin;
        float fMax; 

        void limitInputLevel( float maxIncomingPeakLevel = 10 );
        void bandPass( float minFreqAllowed = 20, float maxFreqAllowed = 20000 );
    };

    Signal amplifySignal( Signal signalToModify );
    Signal splitSignal( Signal signalToModify );
    Signal boostLowFreq( Signal signalToModify );

    Signal signal;
};

Speaker::Signal Speaker::amplifySignal( Signal signalToModify )
{
    signalToModify.level += 3;
    return signalToModify;
}

Speaker::Signal Speaker::splitSignal( Signal signalToModify )
{
    signalToModify.fMax = fc;       //will just return the woofer signal range, can't return 2 signals yet
    return signalToModify;
}

Speaker::Signal Speaker::boostLowFreq( Signal signalToModify )
{
    signalToModify = splitSignal( signalToModify );
    signalToModify.level += 1;
    return signalToModify;
}

void Speaker::Signal::limitInputLevel( float maxIncomingPeakLevel )
{
    if( level > maxIncomingPeakLevel )
    {
        level = maxIncomingPeakLevel;
    };
}

void Speaker::Signal::bandPass( float minFreqAllowed, float maxFreqAllowed )
{
    if( fMin < minFreqAllowed )
    {
        fMin = minFreqAllowed;
    };
    if ( fMax > maxFreqAllowed )
    {
        fMax = maxFreqAllowed;
    }
}
///////////////////////////////////////////////////////////////////////
struct JumpStarter
{
    int maxCurrent = 300;
    char batteryType = 'a';
    float weight = 55;
    float peakCurentTriggerProtection = 400;
    int ledAmount = 3;
    int currentChargeLevel = 80;

    struct DeviceToBeCharged
    {
        bool isItACar = true;
        bool isItUSB = false;
        float currentDraw;

        bool startEngine( int timesToAttemp = 3 );
        float consumePower( float currentDraw = 250 );
    };

    float jumpStartCar( DeviceToBeCharged car );
    float chargePhone( DeviceToBeCharged phone );
    int displayChargeLevel();

    DeviceToBeCharged car;
};

float JumpStarter::jumpStartCar( DeviceToBeCharged device )
{
    return currentChargeLevel - device.currentDraw*12/100;  //probably not correct formula
}

bool JumpStarter::DeviceToBeCharged::startEngine( int timesToAttempt )
{
    if( isItACar )
    {
        if( timesToAttempt <= 3 )   //will not allow more than 3 attempts
        return true;
        else return false;
    }
    else return false;    
}

float JumpStarter::DeviceToBeCharged::consumePower( float current )
{
    return current*12;    
}

int JumpStarter::displayChargeLevel()
{
    return currentChargeLevel*3/100;
}
///////////////////////////////////////////////////////////////////////
struct MidiController
{
    int amountOfKeys = 49;
    int amountOfKnobs = 5;
    int displayCharacters = 10;
    int performanceControls = 2; 
    float weight = 25;

    int sendMidi( int keyPressed );
    int displayPatch( int patchNumber );
    int transposeOctave( int semitones );
};

int MidiController::sendMidi( int keyPressed )
{
    return keyPressed + 36;     // first C key is C1 36
}

int MidiController::displayPatch( int patchNumber)
{
    int bankNumber = patchNumber/8;
    return bankNumber + ( patchNumber - bankNumber*8 );    
}

int MidiController::transposeOctave( int semitones )
{
    if ( semitones > 12 )
    return semitones - 12;
    else return semitones;
}
///////////////////////////////////////////////////////////////////////
struct AirConditioningUnit
{
    int numberOfCasters = 4;
    int coolingBtu = 2000;
    float noiseLevel = 55;
    int heatherPower = 2000;
    char fantype ='d';

    double removeHeat( int roomHeatAmount = 8000 );      //changed float to doble to avoid warnings
    double heatRoom( int initialTemperature = 55 );
    int selectFanSpeed( int selectedSpeed );
};

double AirConditioningUnit::removeHeat( int roomHeatAmount ) 
{
    return roomHeatAmount - coolingBtu*.75;
}

double AirConditioningUnit::heatRoom ( int initialTemperature )
{
    return initialTemperature + heatherPower*0.0005;
}


///////////////////////////////////////////////////////////////////////
struct UsbInterface
{
    int speed = 40;
    int standard = 1;
    float length = 5; 
    char connectorType = 'A';
    float currentDrawForPower = 50;

    int openLinkToGetData();
    char sendErrorToComputer( int errorCode = 0 );
    int sendDataStreamToComputer( int streamLength = 10 );
};

int UsbInterface::openLinkToGetData()
{
    return 1;
}

char sendErrorToComputer( int errorCode )
{
    if( errorCode == 0 )
    {
    return '0';
    }
    else return 'f';
}

int sendDataStreamToComputer( int streamLength )
{
    return streamLength;
}
///////////////////////////////////////////////////////////////////////
struct Converter
{
    int channels = 5;
    int bitDepth =16;
    int clockSpeed = 1;
    float maxCurrent = 10;
    char adOrDa = 'a';

    void setVoltage( int vLevel = 25, int channel = 1 );
    void setBoolOut( bool status, int channel = 2 );
    int readConstantValue( int channel = 3 );
};

void Converter::setVoltage( int vLevel, int channel )
{
    int dummy = 0;
    
    if ( adOrDa == 'd' )
    {
        dummy = vLevel ;
        channel += 1;
    }
}

void Converter::setBoolOut( bool status, int channel )
{
    if( status )
    {
        status = false;
        channel += 1;
    }
}

int Converter::readConstantValue( int channel ) 
{
    int dummy = 256;

    if ( adOrDa == 'a' )
    {
        channel += 1;
        return dummy;
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////
struct SerialPort
{
    int channels = 2; 
    int speed = 128;
    char mode ='a';
    int wordLength = 8;
    char errorCorrection = 'n';

    void transmitData( int channel = 1, char data = '0' );
    char receiveData( int channel = 2 );
    void setSpeed( int speed );
};

void SerialPort::transmitData( int channel, char data )
{
    char dummy;

    if( mode =='a' )
    {
        dummy = data;
        channel += 1;
    }
}

char SerialPort::receiveData( int channel )
{
    char dummy = '0';

    if( channel < 2  )
    {
        channel += 1;
        return dummy;
    }
    else return 'f';
}

void SerialPort::setSpeed( int chSpeed )
{
    int dummy;

    if( chSpeed <= 256 )
    {
        dummy = chSpeed;
    }
}
///////////////////////////////////////////////////////////////////////
struct Memory
{
    int size = 1000;
    char type = 'r';
    int speed = 1000;
    char flash = 'y';
    int powerComsumption = 200;

    int writeScript( int scriptSize = 500 );
    int writeData( int location = 800, int dataSize = 1 );
    int writeStatus( int statusCode = 0 );
};

int Memory::writeScript( int scriptSize )
{
    if( scriptSize < size/2 )
    return size - scriptSize;
    else return size;
}

int Memory::writeData( int location , int dataSize )
{
    if( location < size - dataSize )
    return location + dataSize;
    else return 0;
}

int Memory::writeStatus( int statusCode )
{
    if( statusCode > 100 )
    return 100;
    else return statusCode;
}
///////////////////////////////////////////////////////////////////////
struct ResetButton
{
    float height = 0.05f;
    char location = 't';
    char color = 'r';
    char material = 'p';
    int clicksBeforeFailure = 10000;

    int triggerResetSginal( float clickTime = 0 );
    void clickSound( float clickTime = 0 );
    void triggerLed( float clickTime = 0 );
};

int ResetButton::triggerResetSginal( float clickTime )
{
    int dummy;

    if( clickTime > 0 )
    {
        dummy = 1;
        return 1;
    }
    return 0;
}

void ResetButton::clickSound( float clickTime )
{
    int x;
    int dummy = 0;

    if( clickTime > 0 )
    {
        for( x = 0; x < 100; x++ )
        { dummy++;} 
    }

}
void ResetButton::triggerLed( float clickTime )
{
    int dummy = 0;

    if( clickTime > 0 )
    {
        dummy = 1;
    }
}

///////////////////////////////////////////////////////////////////////
struct Microcontroller
{
    UsbInterface usb0;
    Converter ad;
    Converter da;
    SerialPort serialPort;
    Memory memory;
    ResetButton resetButton;

    struct Script      
    {
        int scriptLength; 
    };

    int storeScript( Script script );
    char getCharacter( SerialPort serialPort, int channel = 1 ); 
    int readValue( Converter ad, int channel = 0 ); 
};

int Microcontroller::storeScript( Script script )
{
    int dummy = 0;
    int x = 0;

    for( x = 0; x < script.scriptLength + 1; x++ )
    {
        dummy = x;
    }
    return dummy;
}

char Microcontroller::getCharacter( SerialPort serialPort0, int channel )
{
    char dummy = 'f';
    int pointer = 0; 

    if( channel == 0 ) 
    {
        dummy = serialPort0.receiveData( 0 );
        pointer = pointer + serialPort0.wordLength ;
    }
    return dummy;
}

int Microcontroller::readValue( Converter ad0, int channel0 )
{
    int dummy = 0;

    if( ad0.adOrDa == 'a' )
    {   
        dummy = ad0.readConstantValue( channel0 );
    }
    return dummy;

}


#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
