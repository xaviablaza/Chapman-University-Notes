# Web APIs

## API

- Application Programming Interface
- Set of protocols or tools for building software

## Web API

- Requests typically via HyperText Transfer Protocol (HTTP)
- Responses in either XML (Extensible Markup Language) or JSON (JavaScript Object Notation)
- JSON is exclusive to web responses

Search APIs on ProgrammableWeb

Open APIs

## HTTP Requests

- GET request
  - Requests data from a specified resource
  - Query parameters go in the URL
- POST request
  - Submits data to a specified resource
  - Query parameters go in message body

###  GET Request Example

https://api.en.wikipedia.org/v2**?search=dad**
BaseURL + **Query String**

## Response Formats: JSON

- Easy for humans to read and write
- {string:value,string:value}

## Building an API Wrapper

- By using libraries

### Making a class that can recognize JSON

1. API call returns a bytestream
2. Need to read the bytestream into a String
3. Making a WebRequest class
4. HttpURLConnection
5. WebRequest constructor with urlString
6. URL url = new URL(urlString);
7. connection = (HttpURLConnection) url.getConnection();
8. Methods to do a GET and POST
9. get(): setRequestMethod("GET");

### JUnit Testing
1. Add library dependency JUnit to the test artifact
2. Test compile
3. Built Variants = Unit Tests
4. CtrlShiftT to add function to the test

### Parsing JSON

Project Structure -> Dependencies

GSON Library is used to make Java objects based on JSON.

1. Make a class to parse the JSON.
2. Look for a String field called name, look for an object field called main, etc.
3. Make wrapper return an instance of the WeatherResultModel.
