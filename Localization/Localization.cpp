#include "Localization.h"

using namespace std;
Localization::Manager::Manager()
{
    static const uint32_t INDEX_EN_US {static_cast<uint32_t>(Languages::EN_US)};
    m_Stringpacks[INDEX_EN_US][STRING_COLOR] = "COLOR";

    static const uint32_t INDEX_EN_GB {static_cast<uint32_t>(Languages::EN_GB)};
    m_Stringpacks[INDEX_EN_GB][STRING_COLOR] = "COLOUR";

    SetLanguages(Languages::EN_US);
}

void Localization::Manager::SetLanguages(Languages languages)
{
    m_CurrentStringPacks = &m_Stringpacks[static_cast<uint32_t>(languages)];
}

std::string Localization::Manager::GetString(StringID stringid) const
{
    string result  = QString("!!!{0}!!!").arg(stringid).toStdString();
    auto iter = m_CurrentStringPacks->find(stringid);
    if(iter != m_CurrentStringPacks->end()){
        result = iter->second;
    }

    return result;
}
