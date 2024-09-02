/*
 * usr_fat_sd.h
 *
 *  Created on: 28 Ağu 2024
 *      Author: numan
 */

#ifndef USR_FAT_SD_H_
#define USR_FAT_SD_H_

#include "usr_fatSdGeneral.h"
#define bool _Bool
#define true 1
#define false 0
#define _io static
#define PUBLIC
#define UMARIM_CALISIR
// #define GNSS_SD_INTEGRATION_MODE

#include "stm32f0xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// #include "fatfs_sd.h"

#include "fatfs.h"
typedef struct _TEST_PAYLOAD1_TAG
{
    float a;
    float b;
    float c;
} _TEST_PAYLOAD1;
typedef struct _TEST_PAYLOAD2_TAG
{
    float lat;
    float lon;
    float speedKN;
    float timeDateBuf;
} _TEST_PAYLOAD2;

/*logger structures*/
typedef struct BME280_TAG
{
    float presure;
    float humidity;
    volatile float altitude;
    float velocity;
} _BME_280_T;
typedef struct BMI088_TAG
{
    float acc_x, acc_y, acc_z;
    double gyro_x, gyro_y, gyro_z;
} _BMI_088_T;
typedef struct BACKUP_SRAM_DATAS_TAG
{
    uint8_t r_status;
    float q[4];
    float max_altitude;
} _BACKUP_SRAM_DATA_T;
typedef struct GPS_DATA_TAG
{
    float lat;
    float lon;
    float timeBuf;
    int satInUse;
    float altitudeInMeter;
} _GPS_DATA_T;
typedef struct POWER_DATA_TAG
{
    float voltage;
    float current;
    float mWatt;
    float mWatt_s;
} _POWER_DATA_T;

/*EOF logger structures*/

void usr_fatfsInitial(void);
void sdInitials(void);
int sd_transmit(const char *str);
void usrFatTest(void);
void sdDataLogger(_BME_280_T *BME_Pack, _BMI_088_T *BMI_Pack, _BACKUP_SRAM_DATA_T *Backup_Pack, _GPS_DATA_T *GPS_Pack, _POWER_DATA_T *Power_Pack);

#endif /* USR_FAT_SD_H_ */
