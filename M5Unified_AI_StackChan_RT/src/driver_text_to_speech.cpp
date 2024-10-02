#include "driver_text_to_speech.hpp"

namespace TTS
{
    String TTS_SPEAKER_NO = "3";
    String TTS_SPEAKER = "&speaker=";
    String TTS_PARMS = TTS_SPEAKER + TTS_SPEAKER_NO;

    AudioOutputM5Speaker audio_out(&M5.Speaker, TTS::m5spk_virtual_channel);
    AudioGeneratorMP3 *mp3;
    AudioFileSourceBuffer *audio_buff = nullptr;
    //int preallocateBufferSize = 30*1024;
    uint8_t *preallocateBuffer;
    AudioFileSourceHTTPSStream *audio_file = nullptr;

    void playMP3(AudioFileSourceBuffer *buff)
    {
        mp3->begin(buff, &audio_out);
    }

} // namespace TTS