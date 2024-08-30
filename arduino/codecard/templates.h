#include "gfxfont.h"
#include <cstdlib>
#include "GxEPD2_EPD.h"

// builds with 1.1.10
// builds with 1.2.16
// builds with 1.3.9
// builds with 1.4.9
// builds with 1.5.8

/*
  template.h
  
*/
// function prototypes

void initNavigation();
void nextMenu();
void selectMenu();
void chooseScreen();
void menuScreen();
void cardScreen( String title, String subTitle, String body );
void configScreen();
void aboutScreen( int which );
void defaultScreen();




// prototypes

// void imageFromUrl( String url, int16_t x, int16_t y, String fingerprint = "", bool with_color = true );


// definitions

/*
*/
void drawBarcode39(int x, int y, int width, int height, int pitch, String barcode)
{
  int c = 0;
  display.fillRect(x, y, width, height, GxEPD_WHITE);
  c = (pitch * 10);

  for( uint i = 0; i < barcode.length(); i++ )
  {
     String binCode = getBinCode(barcode.charAt(i));
     bool bk = true;
     for(int j = 0; j < 9; j++){
      int color;
      if(bk){
        color = GxEPD_BLACK; 
      }else{
        color = GxEPD_WHITE;
      }
      bk = !bk;
      int bw;
      if(binCode.charAt(j) == '0'){
        bw = pitch;
      }else{
        bw = pitch * 2;
      }
      display.fillRect( c, y, bw, height, color);
      c = c + bw;
     }
     //Gap
     display.fillRect( c, y, pitch, height, GxEPD_WHITE);
     c = c + pitch;
  }
  
}
/*
*/

/*
*/
// void drawIcon64(int x, int y, String icon, long color){
  
//   if (icon == "01d" || icon == "01n") { display.drawInvertedBitmap(x, y, weather01, 64, 64, color); return; }
//   if (icon == "02d" || icon == "02n") { display.drawInvertedBitmap(x, y, weather02, 64, 64, color); return; }
//   if (icon == "03d" || icon == "03n") { display.drawInvertedBitmap(x, y, weather03, 64, 64, color); return; }
//   if (icon == "04d" || icon == "04n") { display.drawInvertedBitmap(x, y, weather04, 64, 64, color); return; }
//   if (icon == "09d" || icon == "09n") { display.drawInvertedBitmap(x, y, weather09, 64, 64, color); return; }
//   if (icon == "10d" || icon == "10n") { display.drawInvertedBitmap(x, y, weather10, 64, 64, color); return; }
//   if (icon == "11d" || icon == "11n") { display.drawInvertedBitmap(x, y, weather11, 64, 64, color); return; }
//   if (icon == "13d" || icon == "13n") { display.drawInvertedBitmap(x, y, weather13, 64, 64, color); return; }
//   if (icon == "50d" || icon == "50n") { display.drawInvertedBitmap(x, y, weather50, 64, 64, color); return; }
//   if (icon == "twitter") { display.drawInvertedBitmap(x, y, twitter64, 64, 64, color); return; }
//   if (icon == "mail") { display.drawInvertedBitmap(x, y, mail64, 64, 64, color); return; } 
//   if (icon == "fail") { display.drawInvertedBitmap(x, y, fail64, 64, 64, color); return; }   
//   if (icon == "ace") { display.drawInvertedBitmap(x, y, ace64, 64, 64, color); return; } 
//   if (icon == "duke") { display.drawInvertedBitmap(x, y, duke64, 64, 64, color); return; }  
//   if (icon == "oracle") { display.drawInvertedBitmap(x, y, oracle64, 64, 64, color); return; } 
//   if (icon == "champion") { display.drawInvertedBitmap(x, y, champion64, 64, 64, color); return; } 
//   if (icon == "jduchess") { display.drawInvertedBitmap(x, y, jduchess64, 64, 64, color); return; } 

//   if (icon == "db") { display.drawInvertedBitmap(x, y, db64, 64, 64, color); return; }
//   if (icon == "java") { display.drawInvertedBitmap(x, y, java64, 64, 64, color); return; } 
//   if (icon == "containers") { display.drawInvertedBitmap(x, y, containers64, 64, 64, color); return; }   
//   if (icon == "microservices") { display.drawInvertedBitmap(x, y, microservices64, 64, 64, color); return; } 
//   if (icon == "opensource") { display.drawInvertedBitmap(x, y, opensource64, 64, 64, color); return; }  
//   if (icon == "chatbots") { display.drawInvertedBitmap(x, y, chatbots64, 64, 64, color); return; } 
//   if (icon == "blockchain") { display.drawInvertedBitmap(x, y, blockchain64, 64, 64, color); return; }   
//   if (icon == "javascript") { display.drawInvertedBitmap(x, y, javascript64, 64, 64, color); return; }  
//   if (icon == "nighthacker") { display.drawInvertedBitmap(x, y, nighthacker64, 64, 64, color); return; }   
//   if (icon == "wifi") { display.drawInvertedBitmap(x, y, wifi64, 64, 64, color); return; } 
// }
/*
*/

/*
*/
// void drawIcon128(int x, int y, String icon, long color){
//   if (icon == "oracle") { display.drawInvertedBitmap(x, y, oracle128, 128, 128, color); return; }
//   if (icon == "champion") { display.drawInvertedBitmap(x, y, champion128, 128, 128, color); return; }  
//   if (icon == "jduchess") { display.drawInvertedBitmap(x, y, jduchess128, 128, 128, color); return; }  

//   if (icon == "db") { display.drawInvertedBitmap(x, y, db128, 128, 128, color); return; }
//   if (icon == "java") { display.drawInvertedBitmap(x, y, java128, 128, 128, color); return; } 
//   if (icon == "containers") { display.drawInvertedBitmap(x, y, containers128, 128, 128, color); return; }   
//   if (icon == "microservices") { display.drawInvertedBitmap(x, y, microservices128, 128, 128, color); return; } 
//   if (icon == "opensource") { display.drawInvertedBitmap(x, y, opensource128, 128, 128, color); return; }  
//   if (icon == "chatbots") { display.drawInvertedBitmap(x, y, chatbots128, 128, 128, color); return; } 
//   if (icon == "blockchain") { display.drawInvertedBitmap(x, y, blockchain128, 128, 128, color); return; }   
//   if (icon == "javascript") { display.drawInvertedBitmap(x, y, javascript128, 128, 128, color); return; } 
//   if (icon == "nighthacker") { display.drawInvertedBitmap(x, y, nighthacker128, 128, 128, color); return; } 
//   if (icon == "wifi") { display.drawInvertedBitmap(x, y, wifi128, 128, 128, color); return; } 
// }
/*
*/

/*
*/
// void drawBackground(int x, int y, String backgroundImage, long color){ 
//   if (backgroundImage == "codeone") { display.drawInvertedBitmap(x, y, codeone264, display.width(), display.height(), color); return; } 
//   if (backgroundImage == "oracle") { display.drawInvertedBitmap(x, y, oracle264, display.width(), display.height(), color); return; } 
// }
/*
*/

/*
*/
// void drawBadge( int x, int y, int radius, String badge, long color ) 
// {
//     int circleColor = GxEPD_BLACK;
//     int badgeText = GxEPD_WHITE;

//     if (color == GxEPD_BLACK) {
//       circleColor = GxEPD_WHITE;
//       badgeText = GxEPD_BLACK;
//     }
  
//     //int radius = 32;
//     bool isDegree = false;
//     if (badge.indexOf("u00B0") > -1 ){
//       badge.replace("u00B0", "");
//       isDegree = true;
//     }
//     display.fillCircle(x + radius, y + radius, radius - 2, circleColor);
//     display.setTextColor(badgeText);
//     if (badge.length() > 1 && badge.length() < 3) {
//       // Two characters
//       display.setFont(&FreeMonoBold18pt7b);
//       display.setCursor(x  + 11, y + 42); 
//     } else if (badge.length() == 1 ) {
//       // One character
//       display.setFont(&FreeMonoBold18pt7b);  
//       display.setCursor(x + 21, y + 44);
//     } else if (badge.length() > 2 ) {
//       // Three characters
//       display.setFont(&FreeMonoBold12pt7b);  
//       display.setCursor(x + 11, y + 40);
//     }
//     display.print(badge);

//     if (isDegree == true) {
//       display.setFont(&TomThumb);
//       display.setTextSize(2);
//       //display.setCursor(x + radius + radius / 2 + 5, y + radius - radius / 3 + 5);
//       display.setCursor(x + radius + radius / 2, y + radius - radius / 3);
//       display.print("o");
//     }

//     display.setTextSize(1);
//     display.setTextColor(circleColor);
// }
/*
*/

typedef struct Point
{
    int x, y;
} Point;


class Template 
{
    int backgroundColor = GxEPD_WHITE;
    int textColor = GxEPD_BLACK;

    Point titleLoc = { 72, 25 };
    const GFXfont * titleFont;

    Point subTitleLoc = { 73, 45 };
    const GFXfont *subTitleFont;

    Point bodyLoc = { 0, 80 };
    const GFXfont *bodyFont;

    Point iconLoc = { 0, 0 };

    public:

    Template();
    Template( Point tLoc, GFXfont *tFont, Point stLoc, GFXfont *stFont, Point bLoc, GFXfont *bFont );
    Template( int bgColor, int tColor, Point tLoc, const GFXfont *tFont, Point stLoc, const GFXfont *stFont
            , Point bLoc, const GFXfont *bFont, Point iLoc );

    void render( String title, String subtitle, String body, String icon, String badge, String fingerprint );
};


Template::Template()
{
    this->titleFont = &FreeSansBold12pt7b;

    this->subTitleFont = &FreeSans9pt7b;

    this->bodyFont = &FreeSans9pt7b;
}


Template::Template( Point tLoc, GFXfont *tFont, Point stLoc, GFXfont *stFont, Point bLoc, GFXfont *bFont )
{
    this->titleLoc = tLoc;
    this->titleFont = tFont;
    
    this->subTitleLoc = stLoc;
    this->subTitleFont = stFont;

    this->bodyLoc = bLoc;
    this->bodyFont = bFont;
}


Template::Template( int bgColor, int tColor, Point tLoc, const GFXfont *tFont, Point stLoc, const GFXfont *stFont
        , Point bLoc, const GFXfont *bFont, Point iLoc )
{
    this->backgroundColor = bgColor;
    this->textColor = tColor;
    
    this->titleLoc = tLoc;
    this->titleFont = tFont;
    
    this->subTitleLoc = stLoc;
    this->subTitleFont = stFont;

    this->bodyLoc = bLoc;
    this->bodyFont = bFont;

    this->iconLoc = iLoc;
}


void Template::render( String title, String subtitle, String body, String icon, String badge, String fingerprint )
{
    uint8_t* iconBuffer = NULL;

    display.setFullWindow();
    display.firstPage();
    
    if( icon != "" && icon.indexOf( "http") >= 0 ) 
    {
        // this->drawIcon64( 0, 0, icon, this->textColor );
Serial.println( "Template::render :: call to imageFromUrl()" );
        delay( 10 );
        iconBuffer = fetchImageFromUrl( icon, 0, 0, fingerprint , false, 3 );
    }
    
    do 
    {
        display.fillScreen( this->backgroundColor );
        display.setTextColor( this->textColor );
        
        // title
        display.setFont( this->titleFont );
        display.setCursor( titleLoc.x, titleLoc.y );
        display.println( title );
    
        // subtitle 
        display.setFont( this->subTitleFont );
        display.setCursor( this->subTitleLoc.x, this->subTitleLoc.y );
        display.println( subtitle );
    
        // body
        display.setFont( this->bodyFont );
        display.setCursor( this->bodyLoc.x, this->bodyLoc.y );
        display.println( body );
     
        if( iconBuffer != NULL )
        {
            display.drawBitmap( iconLoc.x, iconLoc.y, iconBuffer, 64, 64, this->textColor );
        }
    }
    while( display.nextPage() );

    free( iconBuffer );
}

/*
    Template lookup table
*/
Template *templateList[ 10 ];

void initTemplates()
{
    templateList[ 0 ] = new Template( GxEPD_WHITE, GxEPD_BLACK
        , { 72, 25 }, &FreeSansBold12pt7b, { 73, 45 }, &FreeSansBold9pt7b
        , { 0, 90 }, &FreeSansBold9pt7b, { 0, 0 } );
    
    templateList[ 1 ] = new Template( GxEPD_WHITE, GxEPD_BLACK
        , { 0, 20 }, &FreeSansBold12pt7b, { 0, 38 }, &FreeSans9pt7b
        , { 0, 125 }, &FreeSans9pt7b, { 102, 56 } );
    
    templateList[ 2 ] = new Template( GxEPD_WHITE, GxEPD_BLACK
        , { 0, 25 }, &FreeSansBold12pt7b, { 1, 50 }, &FreeSans9pt7b
        , { 0, 80 }, &FreeSans9pt7b, { 198, 102 } );
        
    templateList[ 3 ] = new Template( GxEPD_WHITE, GxEPD_BLACK
        , { 25, 100 }, &FreeSansBold12pt7b, { 25, 150 }, &FreeSans9pt7b
        , { 0, 170 }, &FreeSans9pt7b, { 2, 2 } );
}

// 264, 176

/*

    */


/*
    deprecated
*/

/*
void template5(String title, String subtitle, String body, String backgroundColor) {
  long bgColor = GxEPD_WHITE;
  long txtColor = GxEPD_BLACK;
  
  display.setFullWindow();
  display.firstPage();

  if (backgroundColor == "black"){
    bgColor = GxEPD_BLACK;
    txtColor = GxEPD_WHITE;
  } 
  
  do {
    display.fillScreen(bgColor);
    display.setTextColor(txtColor);  
    
    // title
    display.setFont(&FreeSansBold18pt7b);
    if (subtitle.length() > 15) { subtitle = subtitle.substring(0, 15); }  
    int xTitle = display.width() / 2 - title.length() / 2 * 18;
    display.setCursor(xTitle - 10, 25);
    display.println(title);  
  
      // subtitle 
    display.setFont(&FreeSansBold9pt7b);
    if (subtitle.length() > 25) { subtitle = subtitle.substring(0, 25); }  
    int xSubtitle = display.width() / 2 - subtitle.length() / 2 * 9;    
    display.setCursor(xSubtitle - 12 , 45);
    display.println(subtitle);
  
    // body
    display.setFont(&FreeSans9pt7b);
    display.setCursor(0, 72);
    display.println(body.substring(0, 170));
    
  }
  while (display.nextPage());
    
}
*/

/*
void template6(String title, String subtitle, String body, String backgroundColor) {
  long bgColor = GxEPD_WHITE;
  long txtColor = GxEPD_BLACK;
  
  display.setFullWindow();
  display.firstPage();

  if (backgroundColor == "black"){
    bgColor = GxEPD_BLACK;
    txtColor = GxEPD_WHITE;
  } 
  
  do {
    display.fillScreen(bgColor);
    display.setTextColor(txtColor);  
    
    // title
    display.setFont(&FreeSansBold18pt7b);
    if (subtitle.length() > 15) { subtitle = subtitle.substring(0, 15); }  
    int xTitle = display.width() / 2 - title.length() / 2 * 18;
    display.setCursor(xTitle - 10, 80);
    display.println(title);  
  
      // subtitle 
    display.setFont(&FreeSansBold9pt7b);
    if (subtitle.length() > 25) { subtitle = subtitle.substring(0, 25); }  
    int xSubtitle = display.width() / 2 - subtitle.length() / 2 * 9;    
    display.setCursor(xSubtitle - 12 , 100);
    display.println(subtitle);
  
    // body
    display.setFont(&FreeSans9pt7b);
    display.setCursor(1, 146);
    display.println(body.substring(0, 80));
    
  }
  while (display.nextPage());
    
}
*/

/*
// Minimalist - No Icon
void template7(String title, String subtitle, String backgroundColor, String backgroundImage, String fingerprint){

  long bgColor = GxEPD_BLACK;
  long txtColor = GxEPD_WHITE;

  if (backgroundColor == "white"){
    bgColor = GxEPD_WHITE;
    txtColor = GxEPD_BLACK;
  } 

  if (backgroundImage == "") { backgroundImage = "oracle";} 

  display.setFullWindow();
  display.firstPage();
  
  do {

    if (backgroundImage.indexOf("http") == -1){
      display.fillScreen(txtColor);
      drawBackground(0, 0, backgroundImage, bgColor);
    }else {
      display.fillScreen(bgColor);
    }
  
    display.setTextColor(txtColor);
    
    // title
    display.setFont(&FreeSansBold12pt7b);  
    display.setCursor(0, 20);
    display.println(title.substring(0, 22));  
    
    // subtitle 
    display.setFont(&FreeSans9pt7b);
    if (subtitle.length() > 105) { subtitle = subtitle.substring(0, 105); }
    int x = display.width() / 2 - subtitle.length() / 2 * 9;
    display.setCursor(x, display.height() - 15);
    display.println(subtitle); 

    
  }
  while (display.nextPage());

}
*/

/*
// Minimalist - No Icon
void template8(String backgroundColor, String backgroundImage, String fingerprint){

  long bgColor = GxEPD_BLACK;
  long txtColor = GxEPD_WHITE;

  if (backgroundColor == "white"){
    bgColor = GxEPD_WHITE;
    txtColor = GxEPD_BLACK;
  } 

  if (backgroundColor == "white"){ bgColor = GxEPD_WHITE; } 
  if (backgroundImage == "") { backgroundImage = "oracle";}  

  display.setFullWindow();
  display.firstPage();
  do {
    if (backgroundImage.indexOf("http") == -1){
      display.fillScreen(txtColor);
      drawBackground(0, 0, backgroundImage, bgColor);
    }
  }
  while (display.nextPage());
  
  if (backgroundImage.indexOf("http") > -1){
    imageFromUrl(backgroundImage, 0, 0, fingerprint , false);
  }
  
}

// status
void template9(String title, String subtitle, String backgroundColor){
  long bgColor = GxEPD_BLACK;
  long txtColor = GxEPD_WHITE;

  if (backgroundColor == "white"){
    bgColor = GxEPD_WHITE;
    txtColor = GxEPD_BLACK;
  } 
  
  display.setFullWindow();
  //display.setPartialWindow(0, 0, display.width(), display.height());
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);

    display.setFont(&FreeSansBold9pt7b);
    display.setCursor(25, 80);
    display.println(title.substring(0,50));
    
    display.setFont(&FreeMono9pt7b);
    display.setCursor(25, 100);
    display.println(subtitle.substring(0,50));
  }
  while (display.nextPage());
}
*/

/*

// barcode template 43 max chars
void template10(String title, String subtitle, String body, String backgroundColor, String barcode){
  long bgColor = GxEPD_BLACK;
  long txtColor = GxEPD_WHITE;

  if (backgroundColor == "white"){
    bgColor = GxEPD_WHITE;
    txtColor = GxEPD_BLACK;
  } 

  display.setFullWindow();
  display.firstPage();

  do {
    display.fillScreen(bgColor);
    display.setTextColor(txtColor);
  
    display.setFont(&FreeSansBold18pt7b);
    display.setCursor(0, 30);
    display.println(title.substring(0,15));
    
    display.setFont(&FreeSansBold9pt7b);
    display.setCursor(1, 50);
    display.println(subtitle.substring(0,26));

    display.setFont(&FreeSans9pt7b);
    display.setCursor(0, 77);
    display.println(body.substring(0,65));
  
    String formattedBarcode = String("@" + barcode + "#");
    drawBarcode39(50, 110, display.width(), 50, 1.9, formattedBarcode);

    display.setFont(&FreeMono9pt7b);
    int barcodeX = display.width() / 2 - barcode.length() / 2 * 5;
    display.setCursor(12, 172);
    display.println(barcode);
  

  }
  while (display.nextPage());

}
*/

/*
void template11(String title, String subtitle, String icon, String badge, String backgroundColor, String fingerprint) {
  long bgColor = GxEPD_WHITE;
  long txtColor = GxEPD_BLACK;
  int iconSize = 128;
  
  display.setFullWindow();
  display.firstPage();

  if (backgroundColor == "black"){
    bgColor = GxEPD_BLACK;
    txtColor = GxEPD_WHITE;
  } 

  int middle = display.width() / 2 - 68;
  
  do {
    display.fillScreen(bgColor);
    display.setTextColor(txtColor);  
  
    if (badge != "") {
      // badge
      drawBadge(middle, 2, 64, badge, bgColor); 
    } else if (icon != "" && icon.indexOf("http") == -1 && badge == "") {
      // icon
      drawIcon128(middle, 2, icon, txtColor);   
    }
    
    // title
    display.setFont(&FreeSansBold12pt7b); 
    int titleX = 126 - (title.length() / 2 * 12);
    display.setCursor(titleX, 150);
    display.println(title.substring(0, 22));  
  
    // subtitle 
    display.setFont(&FreeSans9pt7b);
    int subtitleX = 126 - (subtitle.length() / 2 * 9);
    display.setCursor(subtitleX, 170);
    display.println(subtitle.substring(0, 26));
  }
  while (display.nextPage());

  if (icon != "" && icon.indexOf("http") > -1 && badge == ""){
    int iconX = display.height() / 2 - 64;
    int iconY = display.width() / 2 - 68;
    imageFromUrl(icon, 2, -iconY, fingerprint , false);
    
  }
    
}
*/

/*
void custom(){
  
}
*/


/*
    Menu Stuff
*/

#define MENU_SIZE 10
#define MENU_8_EM "MMMMMMMM"

// menu
#define SCREEN_1 1
// card one
#define SCREEN_2 2
// card two
#define SCREEN_3 3
// card three
#define SCREEN_4 4
// card four
#define SCREEN_5 5
// about one
#define SCREEN_6 6
// about two
#define SCREEN_7 7


class Navigation
{
    public:

    String label;
    char code;
    char next;
    char screen;

    Navigation();
    Navigation( String l, char c, char n, char s );
};


Navigation::Navigation( String l, char c, char n, char s )
{
    this->label = l;
    this->code = c;
    this->next = n;
    this->screen = s;
}

Navigation::Navigation()
{}

Navigation *navigation[ 11 ];

void initNavigation()
{
    navigation[ 0 ] = new Navigation( "Card One", 105, 1, SCREEN_1 );
    navigation[ 1 ] = new Navigation( "Card Two", 106, 2, SCREEN_1 );
    navigation[ 2 ] = new Navigation( "Card Three", 107, 3, SCREEN_1 );
    navigation[ 3 ] = new Navigation( "Card Four", 108, 4, SCREEN_1 );
    navigation[ 4 ] = new Navigation( "About", 109, 0, SCREEN_1 );

    navigation[ 5 ] = new Navigation( "Back", 100, 5, SCREEN_2 );
    navigation[ 6 ] = new Navigation( "Back", 101, 6, SCREEN_3 );
    navigation[ 7 ] = new Navigation( "Back", 102, 7, SCREEN_4 );
    navigation[ 8 ] = new Navigation( "Back", 103, 8, SCREEN_5 );
    
    // navigation[ 5 ] = new Navigation( "Back", 100, 6, SCREEN_3 );
    // navigation[ 6 ] = new Navigation( "Fetch One", 1, 7, SCREEN_3 );
    // navigation[ 7 ] = new Navigation( "Fetch Two", 2, 8, SCREEN_3 );
    // navigation[ 8 ] = new Navigation( "Fetch Three", 3, 9, SCREEN_3 );
    // navigation[ 9 ] = new Navigation( "Fetch Four", 4, 5, SCREEN_3 );
    navigation[ 9 ] = new Navigation( "Next About", 104, 10, SCREEN_6 );
    navigation[ 10 ] = new Navigation( "Close About", 104, 9, SCREEN_7 );

    // navigation[ 10 ] = new Navigation( "Back", 100, 11, SCREEN_4 );
    // navigation[ 11 ] = new Navigation( "Start Term", 5, 12, SCREEN_4 );
    // navigation[ 12 ] = new Navigation( "Stop Term", 6, 13, SCREEN_4 );
    // navigation[ 13 ] = new Navigation( "Native", 7, 10, SCREEN_4 );
    // navigation[ 14 ] = new Navigation( "9600 bps", 8, 10, SCREEN_4 );

    // navigation[ 15 ] = new Navigation( "Close About", 100, 15, SCREEN_5 );
}


// String menu[ MENU_SIZE ] = {
//     "Card 1", "Card 2", "Card 3", "About"
// };


int current = 0;
int screen = SCREEN_1;


void nextMenu()
{
    // current = ( current + 1 ) % MENU_SIZE;
    current = navigation[ current ]->next;
    Serial.print( "\tnavigation :: " );
    Serial.println( current );
}


void selectMenu()
{
    char code = navigation[ current ]->code;

    Serial.print( "selectMenu :: " );
    Serial.println( navigation[ current ]->label );

    if( code >= 100 )
    {
        current = code - 100;
        screen = navigation[ current ]->screen;
        chooseScreen();
        return;
    }

    // switch( navigation[ current ]->code )
    // {
    //     case 1:
    //     case 2:
    //     case 3: 
    //     case 4:
    //     case 5:
    //     case 6:
    //     case 7:
    //     // case 8:
    //     {
    //         break;
    //     }
    //     default:
    //         // no op
    //         break;
    // }

    Serial.print( screen );
    Serial.print( " :: " );
    Serial.println( navigation[ current ]->label );
}


void chooseScreen()
{
    switch( navigation[ current ]->screen )
    {
        case SCREEN_1:
        {
            menuScreen();
            break;
        }
        case SCREEN_2:
        {
            cardScreen( "Card One", "Requesting Card One", "please stand by..." );

            pushButton( "a", 1 );
//            cardScreen();
            break;
        }
        case SCREEN_3:
        {
            cardScreen( "Card Two", "Requesting Card Two", "please stand by..." );

            pushButton( "a", 2 );
            break;
        }
        case SCREEN_4:
        {
            cardScreen( "Card Three", "Requesting Card Three", "please stand by..." );

            pushButton( "b", 1 );
            break;
        }
        case SCREEN_5:
        {
            cardScreen( "Card Four", "Requesting Card Four", "please stand by..." );

            pushButton( "b", 2 );
            break;
        }
        case SCREEN_6:
        {
            aboutScreen( 1 );
            break;
        }
        case SCREEN_7:
        {
            aboutScreen( 2 );
            break;
        }
    }
}


void menuScreen()
{
    int16_t tbx, tby; 
    uint16_t tbw, tbh;

    display.setTextColor( GxEPD_BLACK, GxEPD_WHITE );    
    display.setFont( &FreeSansBold18pt7b );
    display.getTextBounds( MENU_8_EM, 0, 0, &tbx, &tby, &tbw, &tbh );

    display.setPartialWindow( 0, 0, display.width(), display.height() );

    display.firstPage();

    do 
    {
        int i = 0;
        for( int index = 0; index < MENU_SIZE; index ++ )
        {
            if( navigation[ index ]->screen == screen )
            {
                display.setCursor( 4, ( i + 1 ) * ( tbh + 8 ) );

                if( index == current )
                {
                    display.fillRect( 0, i * ( tbh + 8 ) + 4, tbw + 8, tbh + 8, GxEPD_BLACK );
                    display.setTextColor( GxEPD_WHITE, GxEPD_BLACK );    
                }
                else
                {
                    display.setTextColor( GxEPD_BLACK, GxEPD_WHITE );    
                }

                display.println( navigation[ index ]->label );
                i ++;
                yield();
            }
        }
    }
    while ( display.nextPage() );    // flashing
}


void cardScreen( String title, String subTitle, String body )
{
    int16_t tbx, tby; 
    uint16_t tbw, tbh;

    display.setTextColor( GxEPD_BLACK, GxEPD_WHITE );    
    display.setFont( &FreeSansBold18pt7b );
    display.getTextBounds( "MMMMMMM", 0, 0, &tbx, &tby, &tbw, &tbh );

    display.setPartialWindow( 0, 0, display.width(), display.height() );

    display.firstPage();

    do 
    {
        display.setCursor( 2, tbh +2);
        display.println( title );

        display.setCursor( 2, 2 * tbh + 4 );
        display.setFont( &FreeSans12pt7b );
        display.println( subTitle );

        display.setCursor( 2, 2 * 3 * tbh + 6 );
        display.setFont( &FreeSans9pt7b );
        display.println( body );
    }
    while ( display.nextPage() );    // flashing
}


void aboutScreen( int which )
{
    int16_t tbx, tby; 
    uint16_t tbw, tbh;
    String body = "Lattice Card is the evolution of Code Card from the 2019"
            " Code One Groundbreakers tech garden.  This new version features"
            " various upgrades:\n"
            "<More>        <Back>";

    switch( which )
    {
        case 1 : break;
        case 2 :
        {
            body = "* a menuing system\n"
                "* better http handling\n"
                "* updated libraries\n"
                "* streamlined design\n"
                "\nEnjoy!";
            break;
        }
        default: break;
    }

    display.setTextColor( GxEPD_BLACK, GxEPD_WHITE );    
    display.setFont( &FreeSansBold12pt7b );
    display.getTextBounds( "M", 0, 0, &tbx, &tby, &tbw, &tbh );

    display.setPartialWindow( 0, 0, display.width(), display.height() );

    display.firstPage();

    do 
    {
        display.setCursor( 4, tbh + 8 );
        display.println( "About Lattice Card" );

        display.setFont( NULL );
        display.setTextSize( 2 );
        display.println( body );
        display.setTextSize( 1 );
    }
    while ( display.nextPage() );    // flashing
}


void defaultScreen()
{  
    display.setFullWindow();

    display.firstPage();
    do 
    {
        display.fillScreen(GxEPD_WHITE);
    }
    while (display.nextPage());    
}

