# Android Services

For executing tasks unrelated to the UI

They run separately from the application

Must be subclassed implementing the Service class

Work on the main thread of the application.

`<service android:name=".ExampleService"`

IntenseService
RegularService

## Service States

- Started
  - by calling startService()
  - RUns indefinitely until stopped
  - Does not return a result to the caller
  - Handling code exists in `Service.onStartCommand()` callback
- Bound
  - by calling `bindService()`
  - Application component is bound to service
  - Offers a client-server like interface and allows application to send requests and get results from service
  - Handling code exists in `Service.onBind()` callback
- A service can be started and simultaneously allow binding

Bind to this service and pass these files to it

### IntentService

Automatically handles all intents to onStartCommand(), sending work to onHandleIntent(), which needs to be implemented

Automatically stops the service when all requests have been handled

PendingIntent = runnable, activity or service to start

```java
AlarmManager am = (AlarmManager) ctw.getSystemService(Context.ALARM_SERVICE);
am.setInexactRepeating(AlarmManager.ELAPSED_REALTIME, SystemClock.elapsedRealtime(), 60000, 
```

RainCheckService, ForecastResultModel

1. RainCheckService does API Calls to see for the weather for the next 7 days
2. Need to parse JSON, so we create a ForecastResultModel
3. Understand the ForecastResultModel

Jodatime