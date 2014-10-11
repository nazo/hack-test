<?hh

namespace nazosu\Core;

class Config
{
    private static Map $data = Map {};
    public static function set(string $name, mixed $value): void
    {
        self::$data[$name] = $value;
    }

    public static function get(string $name) : mixed
    {
        return self::$data->contains($name) ? self::$data[$name] : null;
    }

    public static function has(string $name) : bool
    {
        return self::$data->contains($name);
    }
}
