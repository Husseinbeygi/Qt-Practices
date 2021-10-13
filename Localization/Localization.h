#ifndef LOCALIZATION_H
#define LOCALIZATION_H


#include <array>
#include <cinttypes>
#include <string>
#include <unordered_map>
#include <QString>

namespace  Localization{
using StringID = int32_t;
enum class Languages{
    EN_US,
    EN_GB,
    Number
};
constexpr StringID STRING_COLOR {0};

class Manager
{
public:
    Manager();

    void SetLanguages(Languages languages);
    std::string GetString(StringID stringid) const;
private:
    using Strings = std::unordered_map<StringID,std::string>;
    using StringPacks = std::array<Strings,static_cast<size_t>(Languages::Number)>;



    StringPacks m_Stringpacks;
    Strings* m_CurrentStringPacks {nullptr};
    uint32_t m_LanguageIndex;
};
}
#endif // LOCALIZATION_H
