#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define SERVO 4
#define INFRARED 11
#define LED 12

static void Angle(int angle) {
	softPwmWrite(SERVO, 15 - angle/10);
	delay(1000);
}

int main(void) {

	if (wiringPiSetup() == -1) { return 1; }
	// wiringPi 비활성화시 종료

	pinMode(INFRARED, INPUT);
	//적외선 센서는 감지 여부를 전송해주므로 INPUT이다.
	pinMode(LED, OUTPUT);
	softPwmCreate(SERVO, 0, 100);

	for (;;) {
		//무한루프

		if (digitalRead(INFRARED) == HIGH) {
			//적외선 센서가 감지했을 때
			digitalWrite(LED, HIGH);
			Angle(0);
		}
		else {
			//적외선 센서에 아무것도 감지되지 않을때
			digitalWrite(LED, LOW);
			Angle(90);
		}

	}
}