// Simple program showing how to use XkcdColors.h package

#include <iomanip>
#include <iostream>
#include "XkcdColors.h"

namespace xkcd = xkcdColors;


int main()
{
    auto intColor = xkcd::GetColorInt("baby puke green");
    if (intColor)
    {
        std::cout << "baby puke green: #" << std::hex << *intColor << "\n";
    }

    auto rgbColor = xkcd::GetColorRgb("eggshell");
    if (rgbColor)
    {
        xkcd::RGBs& rgb = *rgbColor;
        std::cout << "eggshell" << "\n";
        // These need to be casted, otherwise C++ will output the characters, not the numeric values.
        std::cout << " red: "   << static_cast<int>(rgb.r) << "\n";
        std::cout << " green: " << static_cast<int>(rgb.g) << "\n";
        std::cout << " blue: "  << static_cast<int>(rgb.b) << "\n";
    }

    auto hexColor = xkcd::GetColorHexString("midnight blue");
    if (hexColor)
        std::cout << "midnight blue: " << *hexColor << "\n";

    auto fuschiaString = xkcd::GetColorHexString("fuschia");  // Common fuchsia misspelling
    if (!fuschiaString)
        std::cout << "Could not find fuschia\n";
    else
        std::cout << *fuschiaString << "\n";

    return 0;
}
