#include "Localization.h"


Localization::Manager::Manager()
{
    static const uint32_t INDEX_EN_US {static_cast<uint32_t>(Languages::EN_US)};
    m_Stringpacks[INDEX_EN_US][STRING_COLOR] = "COLOR"s;
}

void Localization::Manager::SetLanguages(Languages languages)
{

}

std::string Localization::Manager::GetString(StringID stringid) const
{

}
