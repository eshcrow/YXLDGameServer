#pragma once
#include "Util/ustring.h"
#include "FmUtil.h"

USING_NS_FM;

struct stLegionContributeData
{
    public:
    stLegionContributeData();
    virtual ~stLegionContributeData();
    void Decode(Freeman::MemStream& stream);

    int m_ID;
    int m_silver;
    int m_gold;
    int m_contribution;
};

