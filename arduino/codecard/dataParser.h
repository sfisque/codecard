#include "GxEPD2.h"
/*
  dataParser.h
  
*/

/*
*/
void parseJson(String jsonString) 
{  
    const size_t capacity = jsonString.length();
    DynamicJsonBuffer jsonBuffer(capacity);
    //StaticJsonBuffer<400> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(jsonString);

    String jsonStr;
    root.printTo(jsonStr);
    Serial.println(F("Response: "));
    Serial.println("  " + jsonStr);
    Serial.println(F(">>>"));

    if (!root.success()) 
    {
        Serial.println(F("JSON parsing failed!"));
        Serial.println(F(">>>"));
        cardScreen( "Invalid response", "Please verify JSON",  jsonString );
        //saveToMemory(getKeyIndex("showdefaultscreen"), "true");
        return;
    }

    //saveToMemory(getKeyIndex("lastpayload"), jsonStr);
    
    String templateName = root["template"].as<String>();
    String title = root["title"].as<String>();
    String subtitle = root["subtitle"].as<String>();
    String body = root["bodytext"].as<String>();
    String icon = root["icon"].as<String>();
    String backgroundImage = root["backgroundImage"].as<String>();
    String backgroundColor = root["backgroundColor"].as<String>();
    String badge = root["badge"].as<String>();
    String fingerprint = root["fingerprint"].as<String>();
    String barcode = root["barcode"].as<String>();  

    jsonBuffer.clear();
    
  // Serial.println("Free HEAP: " + String(ESP.getFreeHeap()));
  
    saveToMemory( getKeyIndex( "showdefaultscreen" ), "false" );
    
    if (templateName == "template1") {
        templateList[ 0 ]->render( title, subtitle, body, icon, badge, fingerprint );
        // template1( title, subtitle, body, icon, badge, backgroundColor, fingerprint );
    } else if (templateName == "template2") {
        // template2(title, subtitle, body, icon, badge, backgroundColor, fingerprint);
        templateList[ 1 ]->render( title, subtitle, body, icon, badge, fingerprint );
    } else if (templateName == "template3") {
        // template3(title, subtitle, body, icon, badge, backgroundColor, fingerprint);
        templateList[ 2 ]->render( title, subtitle, body, icon, badge, fingerprint );
    } else if (templateName == "template4") {
        // template4(title, subtitle, body, icon, badge, backgroundColor, fingerprint);
        templateList[ 3 ]->render( title, subtitle, body, icon, badge, fingerprint );
    } /* else if (templateName == "template5") {
        template5(title, subtitle, body, backgroundColor);
    } else if (templateName == "template6") {
        template6(title, subtitle, body, backgroundColor);    
    } else if (templateName == "template7") {
        template7(title, subtitle, backgroundColor, backgroundImage, fingerprint);    
    } else if (templateName == "template8") {
        template8(backgroundColor, backgroundImage, fingerprint); 
    } else if (templateName == "template9") {
        template9(title, subtitle, backgroundColor);
    } else if (templateName == "template10") {
        template10(title, subtitle, body, backgroundColor, barcode);    
    } else if (templateName == "template11") {
        template11(title, subtitle, icon, badge, backgroundColor, fingerprint);                 
    } else {
        template1("Invalid response", "Please verify JSON",  jsonString ,"fail","","", "");
        saveToMemory(getKeyIndex("showdefaultscreen"), "true");
    }
    */
}
/**/

/*

void parseJsonObject(JsonObject& root) {
  String jsonStr;
  root.printTo(jsonStr);
  parseJson(jsonStr);
}
*/

uint8_t *image_buffer;

/*
*/
void displayImageFromUrl(WiFiClient& client, int16_t x, int16_t y, bool connection_ok, bool with_color, int rotation ) 
{
    // bool valid = false; // valid format to be handled
    // bool flip = true; // bitmap is stored bottom-to-top
    // uint32_t startTime = millis();

    // display.setRotation(0);
  
  // Parse BMP header
    uint16_t header = read16(client);
    char buffer[3];
    itoa( header, buffer, 16 ); 
    Serial.print( "   Header : " );
    Serial.println( buffer );

    if( header == 0x4d42 ) // BMP signature
    {
        // continuation of file header
        uint32_t fileSize = read32(client);  // 0x02 / 4
        /* uint32_t creatorBytes = */ read32(client); // 0x06 / 4 : discarded - discarded
        uint32_t imageOffset = read32(client); // 0x0a / 4 : Start of image data

        // beginning BITMAPINFOHEADER
        /* uint32_t headerSize = */ read32(client); // 0x0e / 4 : always 0x28 for supported files - discarded
        uint32_t width  = read32(client); // 0x12 / 4
        uint32_t height = read32(client); // 0x16 / 4
        uint16_t planes = read16(client); // 0x1a / 2 : always 1
        uint16_t depth = read16(client); // 0x1c / 2 : we only support 1 bpm
        uint32_t format = read32(client); // 0x1e / 4 : we only support 0 - no compression
        uint32_t bytes_read = 34;

        image_buffer = (uint8_t*) malloc( fileSize - imageOffset );

Serial.print("  Planes : "); Serial.println( planes );
Serial.print("  Format : "); Serial.println( format );
    
        if( ( planes == 1) && ( format == 0 ) ) //|| (format == 3))) // uncompressed is handled, 565 also
        {
            // Serial.print("  File size: "); Serial.println(fileSize);
            // Serial.print("  Image Offset: "); Serial.println(imageOffset);
            // Serial.print("  Header size: "); Serial.println(headerSize);
            // Serial.print("  Bit Depth: "); Serial.println(depth);
            // Serial.print("  Image size: ");
            // Serial.print(width);
            // Serial.print('x');
            // Serial.println(height);
      // BMP rows are padded (if needed) to 4-byte boundary

            // uint32_t rowSize = (width * depth / 8 + 3) & ~3;

            uint16_t w = width;
            // uint16_t h = height;
            if ((x + w - 1) >= display.width())  w = display.width()  - x;
            // if ((y + h - 1) >= display.height()) h = display.height() - y;

        // works for small icons
            y = (display.height() - height) + y;

            Serial.print("x: "); Serial.println(x);
            Serial.print("y: "); Serial.println(y);
            Serial.print("display.width(): "); Serial.println(display.width());
            Serial.print("display.height(): "); Serial.println(display.height());

            read32( client ); // raw image size - discarded
            read32( client ); // horizontal resolution - discarded
            read32( client ); // vertical resolution - discarded
            read32( client ); // number of colors in palette - discarded
            read32( client ); // number of IMPORTANT colors - discarded

            bytes_read += 20;

            if( w < max_row_width ) // handle with direct drawing
            {
                // if (depth == 1) with_color = false;
                if (depth == 1 ) // we don't support higher density bitmaps
                {
                    read32( client ); // 0 palette entry - discarded
                    read32( client ); // 1 palette entry - discarded
            
                    uint left = client.available();

Serial.print( "bytes available :: " ); Serial.println( left );
                    bytes_read += client.readBytes( image_buffer, left );

                    switch( rotation )
                    {
                        case 1:
                        {
                            break;
                        }
                        case 2:
                        {
                            break;
                        }
                        case 3:
                        {
                            break;
                        }
                        default:
                            // no op
                            break;
                    }

                }

                display.drawBitmap( x, y, image_buffer, width, height, GxEPD_BLACK );
                display.refresh(true);
                display.display();
                // } // end line
                Serial.print("  downloaded in "); Serial.print(millis() - startTime); Serial.println(" ms");
                Serial.print("  bytes read "); Serial.println( bytes_read );

                free( image_buffer );
            }

        }
    }
    else
    {
        Serial.println("bitmap format not handled.");
    }
}


void displayImageFromUrl(WiFiClient& client, int16_t x, int16_t y, bool connection_ok, bool with_color)
{
    displayImageFromUrl( client, x, y, connection_ok, with_color, 0 );
}


uint8_t* fetchImageFromClient( WiFiClient& client, int16_t x, int16_t y, bool connection_ok, bool with_color, int rotation ) 
{
    // Parse BMP header
    uint16_t header = read16(client);
    char buffer[3];
    itoa( header, buffer, 16 ); 
    Serial.print( "   Header : " );
    Serial.println( buffer );

    if( header == 0x4d42 ) // BMP signature
    {
        // continuation of file header
        uint32_t fileSize = read32(client);  // 0x02 / 4
        /* uint32_t creatorBytes = */ read32(client); // 0x06 / 4 : discarded
        uint32_t imageOffset = read32(client); // 0x0a / 4 : Start of image data

        // beginning BITMAPINFOHEADER
        /* uint32_t headerSize = */ read32(client); // 0x0e / 4 : always 0x28 for supported files - discarded
        uint32_t width  = read32(client); // 0x12 / 4
        uint32_t height = read32(client); // 0x16 / 4
        uint16_t planes = read16(client); // 0x1a / 2 : always 1
        uint16_t depth = read16(client); // 0x1c / 2 : we only support 1 bpm
        uint32_t format = read32(client); // 0x1e / 4 : we only support 0 - no compression
        uint32_t bytes_read = 34;

        image_buffer = (uint8_t*) malloc( fileSize - imageOffset );

Serial.print("  Planes : "); Serial.println( planes );
Serial.print("  Format : "); Serial.println( format );
    
        if( ( planes == 1) && ( format == 0 ) ) //|| (format == 3))) // uncompressed is handled, 565 also
        {
            Serial.print("x: "); Serial.println(x);
            Serial.print("y: "); Serial.println(y);
            Serial.print("display.width(): "); Serial.println(display.width());
            Serial.print("display.height(): "); Serial.println(display.height());

            read32( client ); // raw image size - discarded
            read32( client ); // horizontal resolution - discarded
            read32( client ); // vertical resolution - discarded
            read32( client ); // number of colors in palette - discarded
            read32( client ); // number of IMPORTANT colors - discarded

            bytes_read += 20;

            if( width < (uint) display.width() ) // handle with direct drawing
            {
                // if (depth == 1) with_color = false;
                if (depth == 1 ) // we don't support higher density bitmaps
                {
                    read32( client ); // 0 palette entry - discarded
                    read32( client ); // 1 palette entry - discarded
            
                    uint left = client.available();

Serial.print( "bytes available :: " ); Serial.println( left );
                    bytes_read += client.readBytes( image_buffer, left );

                    // BMP files are encoded flipped vertically
                    uint length = (uint) ( 0.9 + width / 8 );
                    uint8_t temp = 0;

                    uint median = (int) height / 2;
                    for( uint i = 0; i < median; i ++ )
                    {
                        for( uint j = 0; j < length; j ++ )
                        {
                            temp = image_buffer[ i * length + j ];
                            image_buffer[ i * length + j ] = image_buffer[ (height - i - 1 ) * length + j ];
                            image_buffer[ (height - i - 1 ) * length + j ] = temp;
                        }
                    }


                    // display.drawBitmap( x, y, image_buffer, width, height, GxEPD_BLACK );
                    // display.refresh(true);
                    // display.display();
                    // } // end line
                    Serial.print("  downloaded in "); Serial.print(millis() - startTime); Serial.println(" ms");
                    Serial.print("  bytes read "); Serial.println( bytes_read );
                }
                // free( image_buffer );
            }

        }
    }
    else
    {
        Serial.println("bitmap format not handled.");
    }

    return image_buffer;
}

/*
*/