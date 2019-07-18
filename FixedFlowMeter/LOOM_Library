// ================================================================
// ===              INCLUDE CONFIGURATION FILE                  ===
// ===    INCLUDE DECLARATIONS, STRUCTS, AND FUNCTIONS FROM     ===
// ===            OTHER FILES AS SET IN CONFIG.H                ===
// ================================================================

// Config has to be first has it hold all user specified options
#include "config.h"



// Preamble includes any relevant subroutine files based 
// on options specified in the above config
#include "loom_preamble.h"


// ================================================================ 
// ===                           SETUP                          ===
// ================================================================ 
void setup() 
{


	// LOOM_begin calls any relevant (based on config) LOOM device setup functions
	Loom_begin();	

	// NOTE Tweak added for the Featherwing to enable to SD card - not clear why it works
  digitalWrite(8, HIGH); 
}

// ================================================================ 
// ===                        MAIN LOOP                         ===
// ================================================================ 
void loop() 
{
	OSCBundle bndl;

   // NOTE In order to get the RTC working properly, we needed to comment out the following
   //      line in loom_rtc.h - this removes another RTC's specific functions
   //      // #include <RTClibExtended.h>
   //   
   //      See https://github.com/OPEnSLab-OSU/InternetOfAg#real-time-clock-support 
   
   // Create the log filename in as SP190317.csv
   char filename[15] = "SPYYMMDD.csv";
  
   DateTime time_check = rtc_inst.now();
   int y = time_check.year() - (time_check.year() / 1000) * 1000;
   int m = time_check.month();
   int d = time_check.day();
 
   sprintf(filename, "SP%02d%02d%02d.csv", y, m, d);
  
	 measure_sensors();				// Read sensors, store data in sensor state struct
	 package_data(&bndl);			// Copy sensor data from state to provided bundle

   // Log the sensor data to the screen (does *not* include the data and time that is logged in the file)
	 print_bundle(&bndl);

   // Log the sensor data to the SD card
   log_bundle(&bndl, SDCARD, filename);

	 delay(1000);

   // NOTE Uncomment this line to see the file contents 
   // sd_dump_file (filename);
	 additional_loop_checks();		// Miscellaneous checks


   // NOTE ANYTHING BELOW THIS LINE IS JUST EXAMPLES!!!
	// --- End Example ---



	// // --- OLED Example ---

	// measure_sensors();			// Read sensors, store data in sensor state struct
	// package_data(&bndl);			// Copy sensor data from state to provided bundle
	
	// print_bundle(&bndl);
	// log_bundle(&bndl, OLED);

	// delay(1000);

	// additional_loop_checks();	// Miscellaneous checks

	// // --- End Example ---



	// // --- LoRa Hub Example ---

	// receive_bundle(&bndl, LORA);		// Read sensors, store data in sensor state struct
	// print_bundle(&bndl);
	// log_bundle(&bndl, PUSHINGBOX);

	// additional_loop_checks();		// Miscellaneous checks
	// // --- End Example ---



	// // --- LoRa Node Example ---

	// measure_sensors();			// Read sensors, store data in sensor state struct
	// package_data(&bndl);			// Copy sensor data from state to provided bundle
	
	// print_bundle(&bndl);

	// log_bundle(&bndl, SDCARD, "savefile.csv");
	// send_bundle(&bndl, LORA);

	// delay(1000);

	// additional_loop_checks();	// Miscellaneous checks
	// // --- End Example ---



	// // --- LoRa Evaporometer Example ---

	// measure_sensors();			// Read sensors, store data in sensor state struct
	// package_data(&bndl);			// Copy sensor data from state to provided bundle
	
	// print_bundle(&bndl);

	// log_bundle(&bndl, SDCARD, "savefile.csv");
	// send_bundle(&bndl, LORA);

	// sleep_for(5, MINUTES, STANDBY);

	// additional_loop_checks();	// Miscellaneous checks
	// // --- End Example ---



	// // --- Common Example ---

	// receive_bundle(&bndl, WIFI);	// Receive messages
	// if (bndl.size()) {
	// 	print_bundle(&bndl);		// Print bundle if LOOM_DEBUG enabled
	// }
	// process_bundle(&bndl);			// Dispatch message to correct handling functions

	// measure_sensors();				// Read sensors, store data in sensor state struct
	// package_data(&bndl);			// Copy sensor data from state to provided bundle

	// // print_bundle(&bndl);			// Print bundle if LOOM_DEBUG enabled

	// send_bundle(&bndl, WIFI);		// Send bundle of packaged data
	// // log_bundle(&bndl, PUSHINGBOX);	// Send bundle to Google Sheet
	// // log_bundle(&bndl, SDCARD, "Ishield.csv");	// Send bundle to Google Sheet

	// additional_loop_checks();			// Miscellaneous checks
	// // --- End Example ---




}


// ================================================================ 
// ===                 High-Level API Functions                 === 
// ================================================================ 

// void receive_bundle(OSCBundle *bndl, CommPlatform platform);
// void process_bundle(OSCBundle *bndl);
// void measure_sensors();
// void package_data(OSCBundle *bndl);
// void send_bundle(OSCBundle *bndl, CommPlatform platform, int port);
// void send_bundle(OSCBundle *bndl, CommPlatform platform);
// void log_bundle(OSCBundle *bndl, LogPlatform platform, char* file); // filename required for SD files
// void log_bundle(OSCBundle *bndl, LogPlatform platform);
// bool bundle_empty(OSCBundle *bndl);
// void additional_loop_checks();
// void sleep_for(int amount, TimeUnits units, SleepMode mode);
// void sleep_until_time(SleepMode mode, int hour, int min, int sec);
// void append_to_bundle_key_value(OSCBundle *bndl, char* key, T elem);

// CommPlatforms: WIFI, LORA, NRF
// LogPlatforms:  PUSHINGBOX, SDCARD, OLED
// TimeUnits: MINUTES, SECONDS
// SleepMode: STANDBY, SLEEPYDOG

// Print Macro
// LOOM_DEBUG_Println
