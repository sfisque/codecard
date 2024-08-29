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

