<?hh

namespace nazosu\Core;

abstract class Controller implements ArrayAccess
{
    private Service $service_finder;

    public function setServiceFinder(ServiceFinder $service_finder) : void
    {
        $this->service_finder = $service_finder;
    }

    public function _service(string $name) : Service
    {
        return $this->service_finder->getSerivce($name);
    }

    public function offsetSet($offset, $value) {
    }

    public function offsetExists($offset) : bool {
        return $this->service_finder->hasService($offset);
    }

    public function offsetUnset($offset) {
    }

    public function offsetGet($offset) : Service {
        return $this->service_finder->getSerivce($name);
    }
}

}

