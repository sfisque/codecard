
//******************************************
// defined in dataParser.h
//******************************************

void parseJson( String jsonString );

uint8_t* fetchImageFromClient( WiFiClient& client, int16_t x, int16_t y, bool connection_ok, bool with_color, int rotation );

//******************************************
// defined in httpClient.h
//******************************************

uint8_t* fetchImageFromUrl( String url, int16_t x, int16_t y, String fingerprint, bool with_color, int rotation );

//******************************************
// defined in buttonEvents.h
//******************************************

void pushButton( String btnLabel, int btnFunction );

//******************************************
// defined in buttonEvents.h
//******************************************

void initTemplates();
