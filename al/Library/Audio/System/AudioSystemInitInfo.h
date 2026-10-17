#pragma once

namespace al {

/**
 * A struct holding information used to initialize the audio system
 * The full size of this struct is still unknown
 */
struct AudioSystemInitInfo {
    const char* seDataFileName;
    const char* bgmDataFileName;
};

}
