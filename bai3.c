#include <stdio.h>

struct OldDevice {
    int id;
    float voltage;
    int status;
    float current;
    float power;
    int time;
};

struct SmartDevice {
    float voltage;
    float current;
    float power;
    int time;
    int id;
    int status;
};

int main() {
    struct OldDevice old;
    struct SmartDevice device;
    float pcalc, kWh, diff;

    printf("Nhap ID: ");
    scanf("%d", &device.id);
    printf("Nhap dien ap (V): ");
    scanf("%f", &device.voltage);
    printf("Nhap dong dien (A): ");
    scanf("%f", &device.current);
    printf("Nhap cong suat (W): ");
    scanf("%f", &device.power);
    printf("Nhap trang thai (0-Tat, 1-Bat): ");
    scanf("%d", &device.status);
    printf("Nhap thoi gian hoat dong (phut): ");
    scanf("%d", &device.time);

    printf("\nStruct cu: %zu bytes\n", sizeof(old));
    printf("Struct toi uu: %zu bytes\n", sizeof(device));

    if (device.voltage <= 0 || device.current < 0 ||
        device.time < 0 || (device.status != 0 && device.status != 1)) {
        printf("Loi: Du lieu khong hop le!\n");
        return 0;
    }

    pcalc = device.voltage * device.current;
    diff = device.power - pcalc;
    if (diff < 0)
        diff = -diff;

    if (pcalc > 0 && diff / pcalc > 0.05)
        printf("Canh bao: Cam bien cong suat bao sai lech!\n");

    if (device.current > 30.0f || device.power > 6600.0f)
        printf("Canh bao: QUA TAI NGUY HIEM!\n");

    if (device.status == 0 && device.current > 0.05f)
        printf("Canh bao: RO RI DIEN HOAC TAI AN!\n");

    kWh = device.power * (device.time / 60.0f) / 1000.0f;

    printf("Cong suat tinh toan: %.2f W\n", pcalc);
    printf("Dien nang tieu thu: %.2f kWh\n", kWh);

    return 0;
}