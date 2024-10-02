#pragma once

#include <M5Unified.h>
#include <AudioOutput.h>
#include <AudioFileSourceBuffer.h>
#include <AudioGeneratorMP3.h>
#include "AudioFileSourceHTTPSStream.h"
#include "AudioOutputM5Speaker.h"
#include "WebVoiceVoxTTS.h"
#include "driver_apikey.hpp"


namespace TTS
{
    extern String TTS_SPEAKER_NO;
    extern String TTS_SPEAKER;
    extern String TTS_PARMS;

    /// set M5Speaker virtual channel (0-7)
    static constexpr uint8_t m5spk_virtual_channel = 0;

    extern AudioOutputM5Speaker audio_out;
    extern AudioGeneratorMP3 *mp3;
    extern AudioFileSourceBuffer *audio_buff;
    //int preallocateBufferSize = 30*1024;
    extern uint8_t *preallocateBuffer;
    extern AudioFileSourceHTTPSStream *audio_file;

    void playMP3(AudioFileSourceBuffer *buff);
} // namespace TTS