<?hh

define('FRAMEWORK_NAME', 'nazosu');
define('FRAMEWORK_LIB_PATH', dirname(__FILE__));
define('DS', DIRECTORY_SEPARATOR);
define('FRAMEWORK_APP_PATH', FRAMEWORK_LIB_PATH . DS . '..' . DS . 'app');

require_once(FRAMEWORK_LIB_PATH . DS . 'Config.hh');
require_once(FRAMEWORK_LIB_PATH . DS . 'Autoload.hh');
require_once(FRAMEWORK_LIB_PATH . DS . 'Runner.hh');

\nazosu\Core\Runner::from(FRAMEWORK_RUNNER)->run();

