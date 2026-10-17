#pragma once

class IJudge {
public:
    virtual void update() = 0;
    virtual bool judge() const = 0;
    virtual void reset() = 0;
};
