/*
  httpClient.h
  
*/

/*
    root CA
*/
#ifdef HAS_SECURE
const char TARGETED_CERT [] PROGMEM = R"CERT(
    ### paste your cert here ###
)CERT";

X509List cert( TARGETED_CERT );
#endif


String request( String host, int port, String url, String btnLabel, int btnFunction, bool secure ) 
{
    String methodKey =  "method" + btnLabel + String(btnFunction);
    String httpMethod = getFromMemory(methodKey);
    String shaKey = "fingerprint" + btnLabel + String(btnFunction);
    String fingerprint = getFromMemory(shaKey);
    
    Serial.println(F("Request:"));
    Serial.print(F("  host: "));
    Serial.println(host);
    Serial.print(F("  port: "));
    Serial.println(port);  
    Serial.print(F("  url: /"));
    Serial.println(url);
    Serial.print(F("  fingerprint: "));
    Serial.println(fingerprint);  
    Serial.print(F("  method: "));
    Serial.println(httpMethod);

    // WiFiClientSecure client;
    // BearSSL::WiFiClientSecure secureClient;
    // std::unique_ptr<BearSSL::WiFiClientSecure> secureClient( new BearSSL::WiFiClientSecure );
    WiFiClient *client;

    if( secure )
    {
        client = new BearSSL::WiFiClientSecure();

        #ifdef HAS_INSECURE
Serial.println( "insecure set" );
            ((WiFiClientSecure*) client)->setInsecure();
        #endif

        #ifdef HAS_FINGERPRINT
            if( fingerprint == "" ) 
            {
                Serial.println(F(""));
                Serial.println(F("  This SSL url needs to have a corresponding SHA fingerprint."));
                Serial.println(F("  Add one by typing 'fingerprint[btn][fn]=XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX'."));
                Serial.println("  To learn how to retrieve an SSL SHA fingerprint go to " + String(projectSite));
                Serial.println(F(">>>"));
                return "";
            }
Serial.println( "fingerprint set" );
            client->setFingerprint( (const uint8_t*) fingerprint.c_str() );
        #endif

        #ifdef HAS_SECURE
Serial.println( "trust anchor set" );
            client->setTrustAnchors( &cert );
        #endif

    }
    else
    {
        client = new WiFiClient();
    }

    String payload;
    HTTPClient http;
    http.setFollowRedirects( HTTPC_FORCE_FOLLOW_REDIRECTS );
    
    if( http.begin( *client, host, port, "/" + url, secure ) )
    {
        int httpResult = http.GET();

        if( httpResult > 0 )
        {
            Serial.printf("[http] GET... code: %d\n", httpResult );

            if( httpResult == HTTP_CODE_OK || httpResult == HTTP_CODE_MOVED_PERMANENTLY ) 
            {
                payload = http.getString();
                Serial.println(payload);
            }
        }
        else
        {
            Serial.printf( "[http] GET... failed, error: %d : %s\n", httpResult, http.errorToString( httpResult ).c_str() );
        }

        http.end();
    }
    else
    {
        Serial.printf( "[http] Unable to connect\n" );
    }
    delete client;

    return payload;
}


uint8_t* fetchHttpImage( String host, int port, String url, int16_t x, int16_t y, bool with_color, int rotation, String fingerprint ) 
{ 
Serial.println( "httpImage" );

    WiFiClient *client;
    
    if( port == 443 )
    {
        client = new BearSSL::WiFiClientSecure();

        #ifdef HAS_INSECURE
Serial.println( "insecure set" );
            ((WiFiClientSecure*) client)->setInsecure();
        #endif

        #ifdef HAS_FINGERPRINT
            if (fingerprint == "") {
                Serial.println(F(""));
                Serial.println(F("  This SSL url needs to have a corresponding SHA fingerprint."));
                Serial.println(F("  Add one by typing 'fingerprint[btn][fn]=XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX'."));
                Serial.println("  To learn how to retrieve an SSL SHA fingerprint go to " + String(projectSite));
                Serial.println(F(">>>"));
                return "";
            }
Serial.println( "fingerprint set" );
            client->setFingerprint( (const uint8_t*) fingerprint.c_str() );
        #endif

        #ifdef HAS_SECURE
Serial.println( "trust anchor set" );
            client->setTrustAnchors( &cert );
        #endif

    }
    else
    {
        client = new WiFiClient();
    }
    bool connection_ok = false;
  
    if (( x >= display.width() ) || ( y >= display.height() ) ) return NULL;

    Serial.println(F("Request:"));
    Serial.print(F("  host: "));
    Serial.println(host);
    Serial.print(F("  port: "));
    Serial.println(port);  
    Serial.print(F("  url: "));
    Serial.println(url); 
    Serial.println(F("  method: GET"));

    uint8_t* imageBuffer = NULL;
    HTTPClient http;
    http.setFollowRedirects( HTTPC_FORCE_FOLLOW_REDIRECTS );
    
    if( http.begin( *client, host, port, url, (port == 443) ) )
    {
        int httpResult = http.GET();

        if( httpResult > 0 )
        {
            Serial.printf("[http] GET... code: %d\n", httpResult );

            if( httpResult == HTTP_CODE_OK || httpResult == HTTP_CODE_MOVED_PERMANENTLY ) 
            {
                // payload = http.getString();
                // Serial.println(payload);
                imageBuffer = fetchImageFromClient( *client, x, y, connection_ok, with_color, rotation );
            }
        }
        else
        {
            Serial.printf( "[http] GET... failed, error: %d : %s\n", httpResult, http.errorToString( httpResult ).c_str() );
        }

        http.end();
    }
    else
    {
        Serial.printf( "[http] Unable to connect\n" );
    }

    delete client;
    // if (!connection_ok) return;
    // return fetchImageFromClient( *client, x, y, connection_ok, with_color, rotation );
    return imageBuffer;
}


uint8_t* fetchImageFromUrl( String url, int16_t x, int16_t y, String fingerprint, bool with_color, int rotation )
{
Serial.println( "imageFromUrl :: " + url );
    String protocol = parseValue( url, '/', 0 );

    String uri = url.substring( url.indexOf( '/', 10 ) );

    String host = parseValue( url, '/', 2 );
    String portString = parseValue( host, ':', 1 ) ;
    host = parseValue( host, ':', 0 );
    
    if (protocol == "https:") {
        int port = ( portString.length() != 0 ) ? portString.toInt() : 443;
        return fetchHttpImage( host, port, uri, x, y, with_color, rotation, fingerprint );
    }
    else 
    {
        int port = ( portString.length() != 0 ) ? portString.toInt() : 80;
        return fetchHttpImage( host, port, uri, x, y, with_color, rotation, "" );
    }
}


uint8_t *image_buffer;


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

