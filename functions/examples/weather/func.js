const fdk=require('@fnproject/fdk');
const axios = require('axios');

fdk.handle(function(input, ctx) {
  let url = 'http://api.openweathermap.org/data/2.5/weather?appid=[APP_ID]&q=San%20Francisco'
  var codeCardData = getWeather(url)
  return codeCardData
})

const getWeather = async url => {
  try {
    const response = await axios.get(url)
    let jsonData = response.data
    var codeCardJson = {
      template: 'template1',
      title: jsonData.name + ' Weather',
      subtitle: jsonData.main.temp + ' - ' +  jsonData.weather[0].description,
      bodytext: 'More weather info...',
      icon: jsonData.weather[0].icon,
      backgroundColor: 'white'
    }
    return codeCardJson
  } catch (error) {
    console.log('ERROR:',error)
    return null
  }
};
