<?hh

namespace nazosu\Core;

abstract class Runner
{
    public static function from(string $boot_parameter): Runner
    {
        switch($boot_parameter) {
        case 'web':
            return new Runner\Web();
            break;
        case 'console':
            return new Runner\Console();
            break;
        case 'test':
            return new Runner\Test();
            break;
        default:
            return new Runner\None();
            break;
        }
    }

    protected function createController($controller_name) : Controller
    {
        $controller_name = '\\' . FRAMEWORK_NAME . '\\App\\Controller\\' . $controller_name;

        $controller_class = new $controller_name();
        $controller_class->setServiceFinder($this->service_finder);
        return $controller_class;
    }

    abstract public function run() : void;
}

