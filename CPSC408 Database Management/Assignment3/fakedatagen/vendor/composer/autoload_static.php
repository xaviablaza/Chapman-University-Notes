<?php

// autoload_static.php @generated by Composer

namespace Composer\Autoload;

class ComposerStaticInitd15e30555facabbad08a5a8978be960a
{
    public static $prefixLengthsPsr4 = array (
        'F' => 
        array (
            'Faker\\' => 6,
        ),
    );

    public static $prefixDirsPsr4 = array (
        'Faker\\' => 
        array (
            0 => __DIR__ . '/..' . '/fzaninotto/faker/src/Faker',
        ),
    );

    public static function getInitializer(ClassLoader $loader)
    {
        return \Closure::bind(function () use ($loader) {
            $loader->prefixLengthsPsr4 = ComposerStaticInitd15e30555facabbad08a5a8978be960a::$prefixLengthsPsr4;
            $loader->prefixDirsPsr4 = ComposerStaticInitd15e30555facabbad08a5a8978be960a::$prefixDirsPsr4;

        }, null, ClassLoader::class);
    }
}
