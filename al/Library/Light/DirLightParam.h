#pragma once

#include <basis/seadTypes.h>

#include "Project/Base/ParamRequestInterp.h"

namespace al {
class DirectionParam;
class ParameterC4f;
class ParameterObj;

class DirLightParam : public IUseRequestParam {
public:
    DirLightParam();

    const char* getParamName() const override;
    ParameterObj* getParamObj() override;
    const ParameterObj* getParamObj() const override;
    bool isEqual(const IUseRequestParam& other) const override;
    void copy(const IUseRequestParam& other) override;
    void copyInterp(const IUseRequestParam& start, const IUseRequestParam& end,
                    f32 rate) override;

    ParameterC4f* getColor() const { return mColor; }

    DirectionParam* getDirectionParam() const { return mDirectionParam; }

private:
    ParameterObj* mParameterObj;
    ParameterC4f* mColor;
    DirectionParam* mDirectionParam;
};

static_assert(sizeof(DirLightParam) == 0x20);

}  // namespace al
