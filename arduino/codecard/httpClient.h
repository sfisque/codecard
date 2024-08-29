/*
  httpClient.h
  
*/

/*
    Latticeware.com root CA
*/
#ifdef HAS_SECURE
const char LATTICEWARE_CERT [] PROGMEM = R"CERT(
-----BEGIN CERTIFICATE-----
MIIF3jCCA8agAwIBAgIQAf1tMPyjylGoG7xkDjUDLTANBgkqhkiG9w0BAQwFADCB
iDELMAkGA1UEBhMCVVMxEzARBgNVBAgTCk5ldyBKZXJzZXkxFDASBgNVBAcTC0pl
cnNleSBDaXR5MR4wHAYDVQQKExVUaGUgVVNFUlRSVVNUIE5ldHdvcmsxLjAsBgNV
BAMTJVVTRVJUcnVzdCBSU0EgQ2VydGlmaWNhdGlvbiBBdXRob3JpdHkwHhcNMTAw
MjAxMDAwMDAwWhcNMzgwMTE4MjM1OTU5WjCBiDELMAkGA1UEBhMCVVMxEzARBgNV
BAgTCk5ldyBKZXJzZXkxFDASBgNVBAcTC0plcnNleSBDaXR5MR4wHAYDVQQKExVU
aGUgVVNFUlRSVVNUIE5ldHdvcmsxLjAsBgNVBAMTJVVTRVJUcnVzdCBSU0EgQ2Vy
dGlmaWNhdGlvbiBBdXRob3JpdHkwggIiMA0GCSqGSIb3DQEBAQUAA4ICDwAwggIK
AoICAQCAEmUXNg7D2wiz0KxXDXbtzSfTTK1Qg2HiqiBNCS1kCdzOiZ/MPans9s/B
3PHTsdZ7NygRK0faOca8Ohm0X6a9fZ2jY0K2dvKpOyuR+OJv0OwWIJAJPuLodMkY
tJHUYmTbf6MG8YgYapAiPLz+E/CHFHv25B+O1ORRxhFnRghRy4YUVD+8M/5+bJz/
Fp0YvVGONaanZshyZ9shZrHUm3gDwFA66Mzw3LyeTP6vBZY1H1dat//O+T23LLb2
VN3I5xI6Ta5MirdcmrS3ID3KfyI0rn47aGYBROcBTkZTmzNg95S+UzeQc0PzMsNT
79uq/nROacdrjGCT3sTHDN/hMq7MkztReJVni+49Vv4M0GkPGw/zJSZrM233bkf6
c0Plfg6lZrEpfDKEY1WJxA3Bk1QwGROs0303p+tdOmw1XNtB1xLaqUkL39iAigmT
Yo61Zs8liM2EuLE/pDkP2QKe6xJMlXzzawWpXhaDzLhn4ugTncxbgtNMs+1b/97l
c6wjOy0AvzVVdAlJ2ElYGn+SNuZRkg7zJn0cTRe8yexDJtC/QV9AqURE9JnnV4ee
UB9XVKg+/XRjL7FQZQnmWEIuQxpMtPAlR1n6BB6T1CZGSlCBst6+eLf8ZxXhyVeE
Hg9j1uliutZfVS7qXMYoCAQlObgOK6nyTJccBz8NUvXt7y+CDwIDAQABo0IwQDAd
BgNVHQ4EFgQUU3m/WqorSs9UgOHYm8Cd8rIDZsswDgYDVR0PAQH/BAQDAgEGMA8G
A1UdEwEB/wQFMAMBAf8wDQYJKoZIhvcNAQEMBQADggIBAFzUfA3P9wF9QZllDHPF
Up/L+M+ZBn8b2kMVn54CVVeWFPFSPCeHlCjtHzoBN6J2/FNQwISbxmtOuowhT6KO
VWKR82kV2LyI48SqC/3vqOlLVSoGIG1VeCkZ7l8wXEskEVX/JJpuXior7gtNn3/3
ATiUFJVDBwn7YKnuHKsSjKCaXqeYalltiz8I+8jRRa8YFWSQEg9zKC7F4iRO/Fjs
8PRF/iKz6y+O0tlFYQXBl2+odnKPi4w2r78NBc5xjeambx9spnFixdjQg3IM8WcR
iQycE0xyNN+81XHfqnHd4blsjDwSXWXavVcStkNr/+XeTWYRUc+ZruwXtuhxkYze
Sf7dNXGiFSeUHM9h4ya7b6NnJSFd5t0dCy5oGzuCr+yDZ4XUmFF0sbmZgIn/f3gZ
XHlKYC6SQK5MNyosycdiyA5d9zZbyuAlJQG03RoHnHcAP9Dc1ew91Pq7P8yF1m9/
qS3fuQL39ZeatTXaw2ewh0qpKJ4jjv9cJ2vhsE/zB+4ALtRZh8tSQZXq9EfX7mRB
VXyNWQKV3WKdwrnuWih0hKWbt5DHDAff9Yk2dDLWKMGwsAvgnEzDHNb842m1R0aB
L6KCq9NjRHDEjf8tM7qtj3u1cIiuPhnPQCjY/MiQu12ZIvVS5ljFH4gxQ+6IHdfG
jjxDah2nGN59PRbxYvnKkKj9
-----END CERTIFICATE-----
)CERT";

X509List cert( LATTICEWARE_CERT );
#endif

// String httpRequest( WiFiClient& client, String httpMethod, String url, String host, String btnLabel, int btnFunction )
// {
  
//     String mac = WiFi.macAddress();
//     mac.replace(":", "");

//     String contentType;
//     String responseString;
//     String headers;

//     client.print( httpMethod + " " + url + " HTTP/1.0\r\n" +
//                 "Host: " + host + "\r\n" + 
//                 "X-CODECARD-ID: " + mac + "\r\n" +
//                 "X-CODECARD-BUTTON-LABEL: " + btnLabel + "\r\n" + 
//                 "X-CODECARD-BUTTON-FUNCTION: " + String(btnFunction) + "\r\n" +               
//                 "Accept: */*\r\n" +
//                 "Connection: close\r\n\r\n" );

//     unsigned long timeout = millis();
//     uint pending = 0;

// Serial.println( "<sending>" );

//     while( ( pending = client.available() ) == 0) 
//     {
//         if( millis() - timeout > 5000 ) 
//         {
//             Serial.println(F("  Request timeout!"));
//             Serial.println(F(">>>"));
//             return "";
//         }
//     }       
// Serial.print( "<pending>" ); Serial.println( pending );
                                
//     int result = client.println();

//     if (client.println() != 0) {
//         Serial.println(F("  Failed to send request"));
//         Serial.println( result );
//         Serial.println(F(">>>"));   
//         return "";
//     }

//     delay( 10 );

//     String body = client.readString();
// Serial.print( "<body>" ); Serial.println( body );
  
//     yield();
    
//     int index = body.indexOf( "\r\n\r\n" );
//     headers = body.substring( 0, index );
//     Serial.print( " headers " );
//     Serial.println( headers );

//     body = body.substring( index + 4 );
//     Serial.print( " body " );
//     Serial.println( body );

//     Serial.println(F("> >"));
//     if ( headers.indexOf("json") > -1) {
//         responseString = body.substring( body.indexOf( '{' ) );
//     }
//     else {
//         responseString = body;
//     }
    
//     client.stop();

//     return responseString;
// }


String secureRequest( String host, int port, String url, String btnLabel, int btnFunction ) 
{
    // WiFiClientSecure client;
    // BearSSL::WiFiClientSecure secureClient;
    std::unique_ptr<BearSSL::WiFiClientSecure> secureClient( new BearSSL::WiFiClientSecure );

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

#ifdef HAS_INSECURE
Serial.println( "insecure set" );
    secureClient->setInsecure();
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
    secureClient->setFingerprint( (const uint8_t*) fingerprint.c_str() );
#endif

#ifdef HAS_SECURE
Serial.println( "trust anchor set" );
    secureClient->setTrustAnchors( &cert );
#endif

    String payload;
    HTTPClient http;
    
    if( http.begin( *secureClient, host, port, "/" + url, 1 ) )
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
    return payload;

}


String request( String host, int port, String url, String btnLabel, int btnFunction, int secure )
{
    WiFiClient client;
    
    String methodKey =  "method" + btnLabel + String(btnFunction);
    String httpMethod = getFromMemory(methodKey);
    
    Serial.println(F("Request:"));
    Serial.print(F("  host: "));
    Serial.println(host);
    Serial.print(F("  port: "));
    Serial.println(port);  
    Serial.print(F("  url: "));
    Serial.println(url); 
    Serial.print(F("  method: "));
    Serial.println(httpMethod);

    String payload;
    HTTPClient http;
    
    if( http.begin( client, host, port, "/" + url, 0 ) )
    {
        int httpResult = http.GET();

        if( httpResult > 0 )
        {
            Serial.printf("[HTTP] GET... code: %d\n", httpResult );

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
    return payload;
}


// void httpImage(String host, int port, String url, int16_t x, int16_t y, String fingerprint, bool with_color) 
// {
//     // WiFiClientSecure secureClient;
//     BearSSL::WiFiClientSecure secureClient;
//     // axTLS::WiFiClientSecure secureClient;
    
//     bool connection_ok = false;
//     //   uint32_t startTime = millis();
    
//     if ((x >= display.width()) || (y >= display.height())) return;
    
//     Serial.println(F("Request:"));
//     Serial.print(F("  host: "));
//     Serial.println(host);
//     Serial.print(F("  port: "));
//     Serial.println(port);  
//     Serial.print(F("  url: "));
//     Serial.println(url); 
//     Serial.print(F("  fingerprint: "));
//     Serial.println(fingerprint);  
//     Serial.println(F("  method: GET"));

//     //const char* fingerprintChar = fingerprint.c_str();
//     //secureClient.setFingerprint(fingerprintChar);
//     //secureClient.setInsecure();
//     //const uint8_t fp[20] = {0x6F, 0x9C, 0xC2, 0xBF, 0x5B, 0xBD, 0xF0, 0x50, 0xEA, 0x6E, 0x70, 0x10, 0x19, 0xDF, 0x32, 0xCD, 0x79, 0x01, 0x4C, 0x67};

//     secureClient.setInsecure();
// //    secureClient.setFingerprint( (const uint8_t*) fingerprint.c_str() );
    
//     secureClient.setTimeout(10000);
//     if ( ! secureClient.connect(host, port ) ) 
//     {
//         Serial.println("  SSL connection failed");
//         Serial.println(">>>");
//         return;
//     }
    
//     // if (!secureClient.verify(fingerprint.c_str(), host.c_str())) {
//     //     Serial.println(F("  Connection insecure! Halting execution."));
//     //     Serial.println(F(">>>"));
//     //     return;
//     // }
    
//     secureClient.print(String("GET ") + url + " HTTP/1.1\r\n" +
//                 "Host: " + host + "\r\n" +
//                 "User-Agent: CodeCard\r\n" +
//                 "Connection: close\r\n\r\n");
//     while (secureClient.connected())
//     {
//         String line = secureClient.readStringUntil('\n');
//         if (!connection_ok)
//         {
//         connection_ok = line.startsWith("HTTP/1.1 200 OK"); // || line.startsWith("HTTP/1.1 30");
//         if (connection_ok) {
//             Serial.println(F("Response:"));
//             Serial.print(F("  "));
//             Serial.println(line);
//         }
//         //if (!connection_ok) Serial.println(line);
//         }
//         if (!connection_ok) Serial.println(line);
//         //Serial.println(line);
//         if (line == "\r")
//         {
//         //Serial.println("headers received");
//         break;
//         }
//     }
//     if (!connection_ok) return;
//     displayImageFromUrl( secureClient, x, y, connection_ok, with_color );
// }


// void httpImage( String host, int port, String url, int16_t x, int16_t y, bool with_color, int rotation ) 
// { 
// Serial.println( "httpImage" );

//     WiFiClient client;
//     bool connection_ok = false;
  
//     if (( x >= display.width() ) || ( y >= display.height() ) ) return;

//     Serial.println(F("Request:"));
//     Serial.print(F("  host: "));
//     Serial.println(host);
//     Serial.print(F("  port: "));
//     Serial.println(port);  
//     Serial.print(F("  url: "));
//     Serial.println(url); 
//     Serial.println(F("  method: GET"));

//     if( ! client.connect( host, port ) )
//     {
//             Serial.println("  Connection failed");
//             return;
//     }

//     client.print( String("GET ") + url + " HTTP/1.1\r\n" +
//                "Host: " + host + "\r\n" +
//                "User-Agent: CodeCard\r\n" +
//                "Connection: close\r\n\r\n");

// Serial.println("request sent");

//     unsigned long timeout = millis();

//     while (client.available() == 0) 
//     {
//         if (millis() - timeout > 5000) 
//         {
//             Serial.println(F("  Request timeout!"));
//             Serial.println(F(">>>"));
//             return;
//         }
//     }       
                                
//     int result = client.println();

//     if (client.println() != 0) 
//     {
//         Serial.println(F("  Failed to send request"));
//         Serial.println( result );
//         Serial.println(F(">>>"));   
//         return;
//     }


//     while ( client.available() )
//     {
//         String header = client.readStringUntil( '\n' );

//     Serial.println( "header :: " + header );

//         // if( ! connection_ok )
//         // {
//             // connection_ok = line.startsWith("HTTP/1.1 200 OK"); // || line.startsWith("HTTP/1.1 30");
//             // if (connection_ok) Serial.println(line);
//         //if (!connection_ok) Serial.println(line);
//         // }

//         // if (!connection_ok) Serial.println(line);
//     // Serial.println( headers );
//         if( header == "\r" )
//         {
//             Serial.println("headers received");
//             break;
//         }
//     }
//     // if (!connection_ok) return;
//     displayImageFromUrl( client, x, y, connection_ok, with_color, rotation );
// }


// void httpImage( String host, int port, String url, int16_t x, int16_t y, bool with_color ) 
// {
//     httpImage( host, port, url, x, y, with_color, 0 );
// }


uint8_t* fetchHttpImage( String host, int port, String url, int16_t x, int16_t y, bool with_color, int rotation ) 
{ 
Serial.println( "httpImage" );

    WiFiClient client;
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

    if( ! client.connect( host, port ) )
    {
            Serial.println("  Connection failed");
            return NULL;
    }

    client.print( String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: CodeCard\r\n" +
               "Connection: close\r\n\r\n");

Serial.println("request sent");

    unsigned long timeout = millis();

    while (client.available() == 0) 
    {
        if (millis() - timeout > 5000) 
        {
            Serial.println(F("  Request timeout!"));
            Serial.println(F(">>>"));
            return NULL;
        }
    }       
                                
    int result = client.println();

    if (client.println() != 0) 
    {
        Serial.println(F("  Failed to send request"));
        Serial.println( result );
        Serial.println(F(">>>"));   
        return NULL;
    }


    while ( client.available() )
    {
        String header = client.readStringUntil( '\n' );

    Serial.println( "header :: " + header );

        if( header == "\r" )
        {
            Serial.println("headers received");
            break;
        }
    }
    // if (!connection_ok) return;
    return fetchImageFromClient( client, x, y, connection_ok, with_color, rotation );
}


// void imageFromUrl( String url, int16_t x, int16_t y, String fingerprint, bool with_color, int rotation )
// {
// Serial.println( "imageFromUrl :: " + url );
//     String protocol = parseValue( url, '/', 0 );
//     String host = parseValue( url, '/', 2 );
//     String portString = parseValue( host, ':', 1 ) ;
//     host = parseValue( host, ':', 0 );
    
//     if (protocol == "http:") {
//         int port = ( portString.length() != 0 ) ? portString.toInt() : 443;
//         httpImage(host, port, url, x, y, fingerprint, with_color);
//     } else {
//         int port = ( portString.length() != 0 ) ? portString.toInt() : 80;
//         httpImage( host, port, url, x, y, with_color, rotation );
//     }
// }


uint8_t* fetchImageFromUrl( String url, int16_t x, int16_t y, String fingerprint, bool with_color, int rotation )
{
Serial.println( "imageFromUrl :: " + url );
    String protocol = parseValue( url, '/', 0 );
    String host = parseValue( url, '/', 2 );
    String portString = parseValue( host, ':', 1 ) ;
    host = parseValue( host, ':', 0 );
    
    // if (protocol == "http:") {
    //     int port = ( portString.length() != 0 ) ? portString.toInt() : 443;
    //     httpImage(host, port, url, x, y, fingerprint, with_color);
    // } else {
        int port = ( portString.length() != 0 ) ? portString.toInt() : 80;
        return fetchHttpImage( host, port, url, x, y, with_color, rotation );
    // }
}


// void imageFromUrl( String url, int16_t x, int16_t y, String fingerprint, bool with_color )
// {
//     imageFromUrl( url, x, y, fingerprint, with_color, 0 );
// }



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

