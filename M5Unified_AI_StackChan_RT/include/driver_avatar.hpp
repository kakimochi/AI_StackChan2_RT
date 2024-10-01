#pragma once

#include <M5Unified.h>
#include <Avatar.h>

using namespace m5avatar;

namespace AVATAR
{
    Avatar avatar;

    const Expression expressions_table[] = {
    Expression::Neutral,
    Expression::Happy,
    Expression::Sleepy,
    Expression::Doubt,
    Expression::Sad,
    Expression::Angry
    };

    void init()
    {
        // begin
    }

    void update()
    {
        // update
    }
} // namespace AVATAR
