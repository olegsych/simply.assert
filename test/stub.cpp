#include "stub.h"

using namespace simply;
using namespace std;

wstring stub::output;

void stub::fail(const wstring& message)
{
    output = message;
}