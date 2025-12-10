import anonymous;
import std;

int main ( )
{
    throw anonymous::runtime_error("hello, world {} {} {}!", "yya", 2, 3);
}