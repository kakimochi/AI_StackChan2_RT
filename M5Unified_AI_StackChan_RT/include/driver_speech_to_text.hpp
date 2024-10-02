#pragma once

#include <M5Unified.h>
#include "driver_avatar.hpp"

#include "AudioWhisper.h"
#include "Whisper.h"
#include "Audio.h"
#include "CloudSpeechClient.h"
#include "rootCACertificate.h"
#include "rootCAgoogle.h"

#include "driver_apikey.hpp"

namespace STT
{
    String SpeechToText(bool isGoogle)
    {
        Serial.println("\r\nRecord start!\r\n");

        String ret = "";
        if (isGoogle) {
            Audio *audio = new Audio();
            audio->Record();
            Serial.println("Record end\r\n");
            Serial.println("音声認識開始");
            AVATAR::avatar.setSpeechText("わかりました");
            CloudSpeechClient *cloudSpeechClient = new CloudSpeechClient(root_ca_google, APIKEY::STT_API_KEY.c_str());
            ret = cloudSpeechClient->Transcribe(audio);
            delete cloudSpeechClient;
            delete audio;
        } else {
            AudioWhisper *audio = new AudioWhisper();
            audio->Record();
            Serial.println("Record end\r\n");
            Serial.println("音声認識開始");
            AVATAR::avatar.setSpeechText("わかりました");
            Whisper *cloudSpeechClient = new Whisper(root_ca_openai, APIKEY::OPENAI_API_KEY.c_str());
            ret = cloudSpeechClient->Transcribe(audio);
            delete cloudSpeechClient;
            delete audio;
        }
        return ret;
    }

    void init()
    {
        // begin
    }

    void update()
    {
        // update
    }
} // namespace STT