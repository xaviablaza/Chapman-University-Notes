<?php
// require the Faker autoloader
require_once 'vendor/fzaninotto/faker/src/autoload.php';

// use the factory to create a Faker\Generator instance
$faker = Faker\Factory::create();

// Declare fake data file to write out to
$my_file = 'fakedata.csv';
$handle = fopen($my_file, 'w') or die('Cannot open file:  '.$my_file);

// Randomly choose male or female
$gender = array('M','F');

// Generate 1000 records
for ($i=0; $i<1000; $i++) {
	// Name,Gender,Birthday,Address,Title,Email,BlockstackID
	fwrite($handle, $faker->name . ",");
	fwrite($handle, $faker->randomElement($gender) . ",");
	fwrite($handle, $faker->city . ",");
	fwrite($handle, $faker->jobTitle . ",");
	fwrite($handle, $faker->email . ",");
	fwrite($handle, $faker->uuid);
	fwrite($handle, PHP_EOL);
}

fclose($handle);
