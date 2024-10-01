#pragma once

#include <Arduino.h>
#include <M5Unified.h>
#include <SCServo.h>

#include "driver_avatar.hpp"

#define USE_SERVO

#ifdef USE_SERVO

#if defined(ARDUINO_M5STACK_Core2)
#define SERVO_PIN_RXD2 13 // SERIAL2 PORT
#define SERVO_PIN_TXD2 14
// #elif defined( ARDUINO_M5STACK_CORES3 )
//   #define SERVO_PIN_RXD2 18  //SERIAL2 PORT
//   #define SERVO_PIN_TXD2 17
#else
#define SERVO_PIN_RXD2 16 // SERIAL2 PORT
#define SERVO_PIN_TXD2 17
#endif

#define ID_X 1
#define ID_Y 2
#define START_DEGREE_VALUE_X 150
#define START_DEGREE_VALUE_Y 160
#endif // USE_SERVO

namespace SERVO_SC
{
    SCSCL sc;

    bool home = false;

    void move(int id, int pos)
    {
        //  sc.WritePos(id, map(pos, 0, 300, 0, 1023), 0, 300);
        sc.WritePos(id, map(pos, 0, 300, 0, 1023), 500, 70);
    }

    void servoTask(void *args)
    {
        float gazeX, gazeY;
        float mouth_ratio = 0.0;
        // DriveContext *ctx = (DriveContext *)args;
        // Avatar *avatar = ctx->getAvatar();
        for (;;) {
#ifdef USE_SERVO
            AVATAR::avatar.getGaze(&gazeY, &gazeX);
            //    mouth_ratio = AVATAR::avatar->getMouthOpenRatio();
            //    gazeX *= -1.0;
            gazeY *= -1.0;
            if (!home) {
                move(ID_X, START_DEGREE_VALUE_X - (int)(10.0 * gazeX));
                if (gazeY < 0) {
                    int tmp = (int)(7.0 * (gazeY * -1) + mouth_ratio * 10.0);
                    if (tmp > 10)
                        tmp = 10;
                    move(ID_Y, START_DEGREE_VALUE_Y - tmp);
                } else {
                    move(ID_Y, START_DEGREE_VALUE_Y + (int)(7.0 * gazeY) - mouth_ratio * 10.0);
                }
            } else {
                move(ID_X, START_DEGREE_VALUE_X);
                move(ID_Y, START_DEGREE_VALUE_Y);
            }
#endif
            delay(3000);
        }
    }

    void Servo_setup()
    {
#ifdef USE_SERVO
        //  Serial2.begin(1000000, SERIAL_8N1, 13, 14); //PORT C / M-BUS
        //  Serial2.begin(1000000, SERIAL_8N1, 33, 32); //PORT A
        //  Serial2.begin(1000000, SERIAL_8N1, 16, 17); //Serial2
        Serial2.begin(1000000, SERIAL_8N1, SERVO_PIN_RXD2, SERVO_PIN_TXD2); // Serial2
        sc.pSerial = &Serial2;
        move(ID_X, START_DEGREE_VALUE_X);
        move(ID_Y, START_DEGREE_VALUE_Y);
#endif
    }

    void init()
    {
        bool home = false;

        Servo_setup();
    }

    void update()
    {
        // update
    }
} // namespace SERVO
