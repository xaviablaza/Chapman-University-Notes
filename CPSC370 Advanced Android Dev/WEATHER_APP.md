# Creating a Weather App

Control or Cmd + B links to strings.xml

Double Shift brings up a Search

onSectionAttached uses a switch statemtnt where you need to set the Fragment's title

ID Naming Conventions:
et\_zip, tv\_area, btn\_submit etc.

Set an onClickListener to the Button

Shift+F10 Button

## ASyncTasks

- Network tasks are done on the background thread
- Wrappers around Thread and Handler classes for ease of use
- For executing background tasks and updating UI based on certain events

### 3 Generic Types

  1. Params: type of parameters that can be sent to execute() method - String zip of weather
  2. Progress: type of progress units published during execution - progress bar for downloading a file
  3. Result: type of the result of background execution; type sent on onPostExecute() method: WeatherResultModel

### 3 Main Steps

  1. onPreExecute(): invoked on the UI thread before the task is executed (animating a progress wheel)
  2. doInBackground(Params...): invoked in the background thread; the background work. (submitting the params into the WeatherModel)
  3. onPostExecute(Result): invoked on the UI thread after the background task finishes (hide the progress wheel)

### Executing ASyncTasks

  1. executeOnExecutor(Executor, Object[])
    Types of Executors: SERIAL_EXECUTOR, THREAD_POOL_EXECUTOR
  2. execute(Object[])
    Uses SERIAL_EXECUTOR by default
    
Objects in the SERIAL_EXECUTOR will not process until another object is finished executing.

Ctrl+O: Select Methods to Override/Implement

## Progress Bar UI Methods

loadingStarted() onPreExecute

loadingFinished(WaetherResultModel) onPostExecute

All written in the fragment class.

WeatherFragment.this

execute("39834", "19284"), execute(new String[]{"92866"})

## Gson Parsing

WeatherResultModel[].class