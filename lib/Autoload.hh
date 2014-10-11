<?hh

namespace nazosu\Core;

class Autoload
{
    private static Map $extra_path = Map {};
    public static function register(string $class) : void {
        $params = explode('\\', $class);
        if (count($params) <= 3) {
            return;
        }
        if ($params[0] !== FRAMEWORK_NAME) {
            return;
        }
        $dir_name = $params[1];
        if ($dir_name === 'Core') {
            require_once(FRAMEWORK_LIB_PATH . DS . implode(DS, array_slice($params, 2)) . '.hh');
        } elseif ($dir_name === 'App') {
            require_once(FRAMEWORK_APP_PATH . DS . implode(DS, array_slice($params, 2)) . '.hh');
        } else {
            if (self::$extra_path->contains($dir_name)) {
                require_once(self::$extra_path[$dir_name] . DS . implode(DS, array_slice($params, 2)) . '.hh');
            } else {
                return;
            }
        }
    }

    public static function addExtraPath(string $name, string $dir) : void {
        self::$extra_path[$name] = $dir;
    }
}

spl_autoload_register(function($class) {
    Autoload::register($class, true, true);
});

