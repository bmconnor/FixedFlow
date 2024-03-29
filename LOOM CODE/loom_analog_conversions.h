// ================================================================ 
// ===                          NOTES                           === 
// ================================================================
// This file contains functions that are used ot convert analog
// readings from the raw values before they are stored into the 
// analog state struct

// Conversions are selected in the config based on the index of the 
// desired conversion

// All conversion functions should take int and return float

// Defines and constants should be placed immediately above their
// associated function, rather than all at the top

// Functions should be named analog_convert_X



// ================================================================ 
// ===                       DEFINITIONS                        === 
// ================================================================
typedef float (*convertRetFuncPtr)(int); 



// ================================================================ 
// ===                   FUNCTION PROTOTYPES                    === 
// ================================================================
float analog_convert_triple(int analog); // example
float analog_convert_voltage(int analog); // example
float analog_convert_thermistor(int analog);
float analog_convert_ph(int analog);


// ================================================================ 
// ===                     CONVERSION ARRAY                     === 
// ================================================================

static convertRetFuncPtr conversion_list[] = 
{
	analog_convert_triple,
	analog_convert_thermistor,
	analog_convert_ph
};



// ================================================================ 
// ===                         TRIPLE                           === 
// ================================================================

// mostly just an example
float analog_convert_triple(int analog)
{
	return 3*analog;
}


// ================================================================ 
// ===                        VOLTAGE                           === 
// ================================================================

float analog_convert_voltage(int analog)
{
	return analog*3.3/4096.0;
}



// ================================================================ 
// ===                ANALOG CONVERT THERMISTOR                 === 
// ================================================================

#define reverse_connect 1

#define THERMISTORNOMINAL 	10000   // resistance at 25 degrees C
#define TEMPERATURENOMINAL 	25   	// temp. for nominal resistance (almost always 25 C)
#define BCOEFFICIENT 		3950  	// The beta coefficient of the thermistor (usually 3000-4000)
//#define SERIESRESISTOR 10000    
#define SERIESRESISTOR 	29330  	// the value of the 'other' resistor
#define range_resol  		4095

float analog_convert_thermistor(int analog)
{
	float average = analog;

	#if reverse_connect == 0
		average = range_resol / average - 1;
		average = SERIESRESISTOR / average;
	#endif
	#if reverse_connect == 1
		average = range_resol / average - 1; 
		average = SERIESRESISTOR * average;
	#endif
	// Serial.print("Thermistor resistance "); 
	// Serial.println(average);
 
	float steinhart;
	steinhart = average / THERMISTORNOMINAL;     // (R/Ro)
	steinhart = log(steinhart);                  // ln(R/Ro)
	steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
	steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
	steinhart = 1.0 / steinhart;                 // Invert
	steinhart -= 273.15;                         // convert to C

	return steinhart;
}


// ================================================================ 
// ===                    ANALOG CONVERT PH                     === 
// ================================================================

#define PH_Offset 0.0

float analog_convert_ph(int analog)
{
	float voltage = analog*3.3/4096.0;
	float pHValue = 3.5*voltage + PH_Offset;

	return pHValue;
}





