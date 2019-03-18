

# Installation of Arduino 
  * Download and install the Arduino program. 
  * Add the Adafruit boards index. 
  * Install Adafruit SAMD Boards using the boards manager.
  * Windows 7 users need to install drivers.
  
# Installation of the Libraries 
  
## Mac/Linux ##

Find the 'Dependencies' folder in the FixedFlow folder
Select all of the zip folders
Right-click and 'Open With' an installed zip extracting application (like Unarchiver)
Once all of the zip files have been extracted as folders, drag them all to the folder: Documents/Arduino/libraries

## Windows ##

Find the 'Dependencies' folder in the Fixed Flow folder
Select all of the zip folders
Right-click and use 7zip or equivalent to extract the folders (use "extract here")
Once all of the zip files have been extracted as folders, drag them all to the folder: Documents/Arduino/libraries
Other Libraries

Install other libraries with the Arduino IDE, as described here

Note: This installation guide was borrowed from Oregeon State University's OPEnSLab and abbreviated to make the most sense in the context of this project.

## Using the Code ##

The code has been debugged and modified to make the most sense for this project. Credits to Brian Connor for debugging and fixing the code to work for this project. Once the dependencies are installed and the Loom Code is opened in arduino, multiple windows should open with each loom code file being a sketch. Make sure the Feather MO board is selected and the Port should have "feather MO" in the name. Once the board is connected, verify and upload the program.

## Verifying the Code if Working ##

Make sure the board is plugged in and that there is a micro-sd card in the adalogger featherwing board. 

To make sure the code is working, open the serial monitor by the top right magnifying glass icon or through the menu bar. 

The serial monitor should give all of the expected data, as well as say the data is saving to the file. I.e. "Saving bundle to sd file: filename.csv"

Make sure the sd card initilizes. Look for "Initializing SD card...done"

Below is an example of what the data for one reading should say: 

Bundle Size: 9

Message: 0
 
Address: /LOOM1/Sapflow1/vbat

Value (0) (f) 4.29

Message: 1
 
Address: /LOOM1/Sapflow1/button
 
Value (0) (i) 1

Message: 2
 
Address: /LOOM1/Sapflow1/temp0

Value (0) (f) 19.99

Message: 3
 
Address: /LOOM1/Sapflow1/temp1
 
Value (0) (f) 13.29
 
Message: 4
 
Address: /LOOM1/Sapflow1/temp_diff
 
Value (0) (f) 6.70
 
Message: 5
 
Address: /LOOM1/Sapflow1/SHT31D_0x44_temp
 
Value (0) (f) 22.85
 
Message: 6
 
Address: /LOOM1/Sapflow1/SHT31D_0x44_humid
 
Value (0) (f) 15.34

Message: 7

Address: /LOOM1/Sapflow1/SHT31D_0x44_temp
 
Value (0) (f) 22.85
 
Message: 8
 
Address: /LOOM1/Sapflow1/SHT31D_0x44_humid
 
Value (0) (f) 15.34


Saving bundle to SD file: SP190318.csv

