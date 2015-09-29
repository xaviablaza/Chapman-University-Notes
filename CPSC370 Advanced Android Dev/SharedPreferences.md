# SharedPreferences

### Parse Core (back-end databases and APIs)

Make a database table on the front-end and objects on the client-side

## Data Persistence

- Android API for simple key-value data storage
- Points to an XML file on your device
- Simple methods for reading and writing simple values

`<username>gg321</username>`

`getPreferences()` can only be used within the activity it was created in (specific activity)

`getSharedPreferences()` (general data storage)

If a `SharedPreferences` object is requested and doesn't exist, it will be created.

### Writing to SharedPreferences

1. Obtain a `SharedPreferences.Editor` object by calling `edit()` on a `SharedPreferences` instance

```java 
SharedPreferences prefs = getReferences();
Editor editor = prefs.edit();
editor.commit();
editor.putString("username", user);
prefs.getString("key", value);
```

SharedPreferencesHelper that has getUsername() etc.

Let the activity be created before setting the SharedPreferences. Use `onCreateView()` 

`prefs = getActivity().getPreferences(Context.MODE_PRIVATE);`

Refactor Change Signature on the Method Name

SettingsActivity extends PreferencesActivity
isValidFragment() override to return true;

PreferenceScreen, ListPreference

SharedPreferences defaultPrefs = ...

Use settings to convert dollars into peso