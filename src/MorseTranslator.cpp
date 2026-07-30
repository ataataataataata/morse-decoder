#include "MorseTranslator.h"

std::optional<char> MorseTranslator::DecodeLetter(const std::string& morseLetter){
    auto it = m_MorseToChar.find(morseLetter);
    if(it != m_MorseToChar.end()){
        return it->second;
    }
    
    return std::nullopt;
    
}