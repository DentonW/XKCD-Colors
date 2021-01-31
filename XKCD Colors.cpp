#include <iostream>
#include "XkcdColors.h"

using namespace xkcdColors;


int main()
{
    uint32_t i = *GetColorInt("purple1");
    RGBs color = internal::HexToRGB(i);
    std::cout << "red: " << (int)color.r << "\n";
    std::cout << "green: " << (int)color.g << "\n";
    std::cout << "blue: " << (int)color.b << "\n";

    //std::string s = *GetColorHexString("midnight blue");
    std::cout << *GetColorHexString("midnight blue") << "\n";

    auto fuschiaString = GetColorHexString("fuschia");  // Common fuchsia misspelling
    if (!fuschiaString)
        std::cout << "Could not find fuschia\n";
    else
        std::cout << *fuschiaString << "\n";

    return 0;
}
