# PHP Basics

I used *PHP 5 Power Programming* as my study document.

## Variables

When declaring variables, you do not need to state its type. All variable names begin with a dollar sign (```$```). Here are some example variable declarations:

```php
$name = 'John';
$my_integer = 5;
```

### Indirect References

By adding more dollar signs (```$```) to the beginning of a variable name, you effectively create new variable names based on the value of another variable. For example:

```php
$name = 'John';
$$name = 'Smith';
print $John; // returns "Smith"
```

This is useful because one can create and access variables at runtime instead of at compile-time.

## isset() and empty() checks

```php 
isset()
// returns true if value is not NULL
// returns false if value is NULL
```
 
```php
empty()
// returns true if "" (empty string), 0, null, or empty array
// false otherwise
```

## Single/Double Quotes and Escape Sequences

Strings can be delimited using single quotes (' ') or double quotes (" "). Escape sequences are used to define symbols that would normally destroy the syntax of the code (i.e. putting a double quote in a double quote delimited string). Below are some escape sequences:

```php
\n // newline
\" double quote
\' single quote
```

Single quotes can also delimit Strings, but lack many escape sequences compared to double quotes.

## Arrays

Below are several examples of how we can create an array in PHP:

```php
$array1 = array(1, 2, 3);
$array2 = array("name" => "John", "age" => 28);
$array3 = array();
$array4 = array(array(), array());
```

```$array2``` is an example of an *associative array*, where we can access a value in the array with its index (or key). For example:

```php
$array = array(6, 1, 9);
// $array{index or key} = value;
echo $array{0} // will return 6.
```

### Nested Arrays

```php
$array = array("John"=>array("age"=>18));
echo $array{"John"}{"age"} // will return 18
```

### Traversing Arrays

You can traverse an array using a foreach loop.

```php
// <> represents optional args
foreach($people as <&>$person) {
   doSomething($person); 
}
```

```&``` signifies if we want to make a duplicate of the array, and iterate over the duplicated elements in the foreach loop. 

Include ```&``` if we want to modify actual array values.

## Functions to check array & object values

Use the functions ```print_r($variable)``` or ```var_dump($variable)``` to check arrays, and object values.