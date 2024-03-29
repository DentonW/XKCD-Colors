# XKCD Colors
 
Converts color names from the [XKCD color survey](https://xkcd.com/color/rgb/)
into their equivalent RGB values. The results of this survey are at
https://xkcd.com/color/rgb/, and a description of the survey and results is at
https://blog.xkcd.com/2010/05/03/color-survey-results/.

# Usage
There are only three functions to be used in this package. All three take a string
with the color name as an input, and they return different representations of the
color data. These functions return their values wrapped in a std::optional, since a
color requested may not exist. The easier alternative would have been to return a
default value in that case, but then there is no way to tell whether that color
actually existed in the table or not.

```c++
#include "XkcdColors.h"

auto hexColor = xkcdColors::GetColorHexString("midnight blue");
auto intColor = xkcdColors::GetColorInt("baby puke green");
auto rgbColor = xkcdColors::GetColorRgb("eggshell");
```

As with any usage of `std::optional`, it should be checked to see whether it contains
a value. These functions return an empty `std::optional` if the color does not exist.

```c++
if (hexColor)
    std::cout << hexColor << "\n";
else
    std::cout << "Requested color does not exist\n";
```