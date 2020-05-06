// bluetft.h
//
// Separated from the main sketch to allow several display types.
// Includes for various ST7735 displays.  Size is 160 x 128.  Select INITR_BLACKTAB
// for this and set dsp_getwidth() to 160.
// Works also for the 128 x 128 version.  Select INITR_144GREENTAB for this and
// set dsp_getwidth() to 128.

#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip

// Color definitions for the TFT screen (if used)
// TFT has bits 6 bits (0..5) for RED, 6 bits (6..11) for GREEN and 4 bits (12..15) for BLUE.
#define WHITE   TFT_BLACK
#define BLUE    TFT_BLUE
#define RED     TFT_RED
#define GREEN   TFT_GREEN
#define CYAN    TFT_CYAN
#define MAGENTA TFT_MAGENTA
#define YELLOW  TFT_YELLOW
#define BLACK   TFT_WHITE

// Data to display.  There are TFTSECS sections
#define TFTSECS 4
scrseg_struct     tftdata[TFTSECS] =                        // Screen divided in 3 segments + 1 overlay
{                                                           // One text line is 8 pixels
  { false, BLACK,   4,  40, "" },                            // 1 top line size*5
  { false, CYAN,    64, 32, "" },                            // 4 lines in the middle
  { false, YELLOW,  100, 24, "" },                            // 3 lines at the bottom
  { false, GREEN,  100, 24, "" }                             // 3 lines at the bottom for rotary encoder
} ;


TFT_eSPI tft1 = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h
bool tft = true;
                                  
// Various macro's to mimic the ST7735 version of display functions
#define dsp_setRotation()       tft1.setRotation ( 1 )             // Use landscape format (3 for upside down)
#define dsp_print(a)            tft1.print ( a )                   // Print a string 
#define dsp_println(b)          tft1.println ( b )                 // Print a string followed by newline 
#define dsp_fillRect(a,b,c,d,e) tft1.fillRect ( a, b, c, d, e ) ;  // Fill a rectange
#define dsp_setTextSize(a)      tft1.setTextSize(a)                // Set the text size
#define dsp_setTextColor(a)     tft1.setTextColor(a)               // Set the text color
#define dsp_setCursor(a,b)      tft1.setCursor ( a, b )            // Position the cursor
#define dsp_erase()             tft1.fillScreen ( BLACK ) ;        // Clear the screen
#define dsp_getwidth()          160                                // Adjust to your display
#define dsp_getheight()         128                                // Get height of screen
#define dsp_update()                                               // Updates to the physical screen
#define dsp_usesSPI()           true                               // Does use SPI


bool dsp_begin()
{
  tft1.init();
  tft1.setRotation(1);
  tft1.fillScreen(TFT_BLACK);
}


//**************************************************************************************************
//                                      D I S P L A Y B A T T E R Y                                *
//**************************************************************************************************
// Show the current battery charge level on the screen.                                            *
// It will overwrite the top divider.                                                              *
// No action if bat0/bat100 not defined in the preferences.                                        *
//**************************************************************************************************
void displaybattery()
{
  if ( tft )
  {
    if ( ini_block.bat0 < ini_block.bat100 )              // Levels set in preferences?
    {
      static uint16_t oldpos = 0 ;                        // Previous charge level
      uint16_t        ypos ;                              // Position on screen
      uint16_t        v ;                                 // Constrainted ADC value
      uint16_t        newpos ;                            // Current setting

      v = constrain ( adcval, ini_block.bat0,             // Prevent out of scale
                      ini_block.bat100 ) ;
      newpos = map ( v, ini_block.bat0,                   // Compute length of green bar
                     ini_block.bat100,
                     0, dsp_getwidth() ) ;
      if ( newpos != oldpos )                             // Value changed?
      {
        oldpos = newpos ;                                 // Remember for next compare
        ypos = tftdata[1].y - 5 ;                         // Just before 1st divider
        dsp_fillRect ( 0, ypos, newpos, 2, GREEN ) ;      // Paint green part
        dsp_fillRect ( newpos, ypos,
                       dsp_getwidth() - newpos,
                       2, RED ) ;                          // Paint red part
      }
    }
  }
}


//**************************************************************************************************
//                                      D I S P L A Y V O L U M E                                  *
//**************************************************************************************************
// Show the current volume as an indicator on the screen.                                          *
// The indicator is 2 pixels heigh.                                                                *
//**************************************************************************************************
void displayvolume()
{
  if ( tft )
  {
    static uint8_t oldvol = 0 ;                         // Previous volume
    uint8_t        newvol ;                             // Current setting
    uint16_t       pos ;                                // Positon of volume indicator

    newvol = vs1053player->getVolume() ;                // Get current volume setting
    if ( newvol != oldvol )                             // Volume changed?
    {
      oldvol = newvol ;                                 // Remember for next compare
      pos = map ( newvol, 0, 100, 0, dsp_getwidth() ) ; // Compute position on TFT
      dsp_fillRect ( 0, dsp_getheight() - 4,
                     pos, 4, RED ) ;                    // Paint red part
      dsp_fillRect ( pos, dsp_getheight() - 4,
                     dsp_getwidth() - pos, 4, GREEN ) ; // Paint green part
    }
  }
}


//**************************************************************************************************
//                                      D I S P L A Y T I M E                                      *
//**************************************************************************************************
// Show the time on the LCD at a fixed position in a specified color                               *
// To prevent flickering, only the changed part of the timestring is displayed.                    *
// An empty string will force a refresh on next call.                                              *
// A character on the screen is 8*size pixels high and 6*size pixels wide.                                   *
//**************************************************************************************************
void displaytime ( const char* str, const char* alarmTime, bool alarmOn, uint16_t color )   //old:void displaytime ( const char* str, uint16_t color )
{
  static char oldstr[6] = "....." ;                // For compare
  static char oldAlarmTime[6] = "....." ;          // For compare
  static bool oldAlarmOn = false ;                 // For compare
  uint8_t     i ;                                  // Index in strings
  uint16_t    pos = 6 ;     // X-position of character, TIMEPOS is negative

  if ( str[0] == '\0' )                            // Empty string?
  {
    for ( i = 0 ; i < 5 ; i++ )                    // Set oldstr to dots
    {
      oldstr[i] = '.' ;
    }
    return ;                                       // No actual display yet
  }
  if ( alarmTime[0] == '\0' )                      // Empty string?  ~AC
  {
    for ( i = 0 ; i < 5 ; i++ )                    // Set oldstr to dots ~AC
    {
      oldAlarmTime[i] = '.' ;
    }
    return ;                                       // No actual display yet ~AC
  }
  if ( tft )                                       // TFT active?
  {
    dsp_setTextColor ( WHITE ) ;                   // Set the requested color //no: set WHITE
    dsp_setTextSize( 5 ) ;
    for ( i = 0 ; i < 5 ; i++ )                    // Compare old and new
    {
      if ( str[i] != oldstr[i] )                   // Difference?
      {
        dsp_fillRect ( pos, 2, 30, 42, BLACK ) ;     // Clear the space for new character
        dsp_setCursor ( pos, 2 ) ;                 // Prepare to show the info
        dsp_print ( str[i] ) ;                     // Show the character
        oldstr[i] = str[i] ;                       // Remember for next compare
      }
      pos += 30 ;                                   // Next position
    }
    pos = 100 ;
    dsp_setTextSize( 1 ) ;
    for ( i = 0 ; i < 5 ; i++ )                    // Compare old and new
    {
      if ( alarmTime[i] != oldAlarmTime[i] )         // Difference?
      {
        dsp_fillRect ( pos, 50, 6, 8, BLACK ) ;    // Clear the space for new character
        dsp_setCursor ( pos, 50 ) ;                 // Prepare to show the info
        dsp_print ( alarmTime[i] ) ;               // Show the character
        oldAlarmTime[i] = alarmTime[i] ;           // Remember for next compare
      }
      pos += 6 ;                                   // Next position
    }
    if ( alarmOn != oldAlarmOn )
    {
        dsp_fillRect ( pos, 50, 24, 8, BLACK ) ;    // Clear the space for new character
        dsp_setCursor ( pos, 50 ) ;                 // Prepare to show the info
        if ( alarmOn )
        {
          dsp_print ( " ON " ) ;               // Show the character
          //dbgprint (" ALARM ON") ;
        }
        else
        {
          dsp_print ( " OFF" ) ;               // Show the character
          //dbgprint ("ALARM OFF") ;
        }
        oldAlarmOn = alarmOn ;           // Remember for next compare
    }
  }
}
