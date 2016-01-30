#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include "gpio/pwm.h"
#include "gpio/gpio.h"

#define GPIO_PIN_SERVO          GPIO_PIN_14

// 20 milli seconds = 20,000 micro seconds. 1,000,000 (1 second) / 20,000 = 50 cycles per second
#define SERVO_CYCLES_PER_SECOND 50

// 0.5 milli seconds = 500 micro seconds. 2.5% of 20,000 milli seconds
#define DUTY_CYCLE_LEFT         2.5

// 1.5 milli seconds = 1500 micro seconds. 7.5% of 20,000 milli seconds
#define DUTY_CYCLE_NEUTRAL      7.5

// 2.5 milli seconds = 2500 micro seconds. 12.5% of 20,000 milli seconds
#define DUTY_CYCLE_RIGHT        12.5

#define PULSE_LENGTH            20

static int returnStatus;

/*
 * Program main entry point
 */
int main()
{
    returnStatus = EXIT_SUCCESS;

    // Initialise gpio servo pin
    returnStatus = gpioExportAndDirection(GPIO_PIN_SERVO, GPIO_OUTPUT);
    assert(returnStatus == EXIT_SUCCESS);

    // Create parameters for servo thread
    GPIO_PWM_PARAMETERS servoPwmParameters =
    {
        .gpioPin            = GPIO_PIN_SERVO,
        .cyclesPerSecond    = SERVO_CYCLES_PER_SECOND,
        .lengthOfPulse      = PULSE_LENGTH
    };

    int direction = 0;

    while (direction != 'X' && direction != 'x')
    {
        // Prompt for direction until X entered
        printf("Which Direction [L]eft, [N]eutral, [R]ight or [X] to exit ?\n");
        direction = getchar();

        // Neutral
        if (direction == 'N' || direction == 'n')
        {
            servoPwmParameters.dutyCycle = DUTY_CYCLE_NEUTRAL;
            gpioPwmPulsePin(&servoPwmParameters);
        }

        // Left
        if (direction == 'L' || direction == 'l')
        {
            servoPwmParameters.dutyCycle = DUTY_CYCLE_LEFT;
            gpioPwmPulsePin(&servoPwmParameters);
        }

        // Right
        if (direction == 'R' || direction == 'r')
        {
            servoPwmParameters.dutyCycle = DUTY_CYCLE_RIGHT;
            gpioPwmPulsePin(&servoPwmParameters);
        }
    }

    // Tidy up
    returnStatus = gpioUnexport(GPIO_PIN_SERVO);
    assert(returnStatus == EXIT_SUCCESS);

    return returnStatus;
}
