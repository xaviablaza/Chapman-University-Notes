# Creating a Database

Have an object `Entry` which has particular `attributes` and a `table name`.

| Entry |
| ----- |
| -attributes |
| -tableName |
| -------------------- |
| +makeModel() |
| +makeContentValues() |

### Pushing to Database

Model -> Entry -> Database

### Pulling from Databse

Database -> Entry -> Model

Database is handled by a Web API. Anything that is stored on the phone is usually also stored on the cloud.

After searching, we need to save the result as a "recently searched" object in a database.

String zip and occurence count

```java
RecentLocationEntry implements BaseColumns
```

```java
public static final String COLUMN_ID = "id"
public static final String COLUMN_ZIP = "zip
```

Updating occurence count by 1