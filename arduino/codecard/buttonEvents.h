/*
  buttonEvents.h
  
*/

void pushButton( String btnLabel, int btnFunction )
{  
    String button = "button" + btnLabel + String(btnFunction);
    String typeOfPress = (btnFunction == 1) ? " - short pressed" : " - long pressed";
    String upperCaseBtnLabel = btnLabel;

    upperCaseBtnLabel.toUpperCase();
    
    //   template9(upperCaseBtnLabel + typeOfPress , "please wait...", "white");
    Serial.println("Button " + btnLabel + typeOfPress);
    Serial.println(F(">>>"));

    if( wifiConnect() == false ) 
    {
        // template3("No Internet", "", "Connect your card to the Code Card Terminal to configure your wifi settings.", "wifi", "", "white", "");
        return;
    }
    
    String url = getFromMemory( button );
    String protocol = parseValue(url, '/', 0);
    String host = parseValue( url, '/', 2 );

    String uri = parseValue( url, '/', 3, 1 );

    String portString = parseValue( host, ':', 1 ) ;
    host = parseValue(host, ':', 0);

    if (protocol == "https:") 
    {
        int port = (portString.length() != 0) ? portString.toInt() : 443;
        // String response = secureRequest( host, port, uri, btnLabel, btnFunction );
        String response = request( host, port, uri, btnLabel, btnFunction, 1 );
        if (response != "") { parseJson(response); }
    } 
    else 
    {
        int port = (portString.length() != 0) ? portString.toInt() : 80;
        String response = request( host, port, uri, btnLabel, btnFunction, 0 );
        if (response != "") { parseJson(response); }
    }

}
