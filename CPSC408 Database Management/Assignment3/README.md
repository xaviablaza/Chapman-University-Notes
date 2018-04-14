Xavier Luis (Xavi) Ablaza
#2258883
Assignment3
CPSC408 Database Management Spring 2018

References Used:
PHP Faker Library: https://github.com/fzaninotto/Faker
File Handling in PHP: https://davidwalsh.name/basic-php-file-handling-create-open-read-write-append-close-delete
I asked Tommy Madden for some help in using PHP and Faker.

Instructions to start:

1. Install Docker, PHP and Composer
2. Run this:  docker run --name some-mysql -e MYSQL_DATABASE=my_db -e MYSQL_ROOT_PASSWORD=root -p 3306:3306 -d mysql:5.7.18
3. Go into /fakedatagen and run: composer install
4. Generate the fake data file using: php generate_csv.php
5. Place the data file in /DataImporter and run Main.java
