# Raspberry Pi C Servo

Another little C program. This time to have a go at software pulse width modulation with a Servo. So my C GPIO library using the 'sysfs interface' is slowly moving along! Refer to the wiki page <https://github.com/mse240966/raspberry-pi-c-servo/wiki> for more information.

The code important to this little project is GPIO/pwm.c, GPIO/pwm.h and main.c.  This is where all the software pulse width modulation happens to move the servo arm.

## Example

```bash
$ sudo ./servo
Which Direction [L]eft, [N]eutral, [R]ight or [X] to exit ?
L
Which Direction [L]eft, [N]eutral, [R]ight or [X] to exit ?
Which Direction [L]eft, [N]eutral, [R]ight or [X] to exit ?
R
Which Direction [L]eft, [N]eutral, [R]ight or [X] to exit ?
Which Direction [L]eft, [N]eutral, [R]ight or [X] to exit ?
N
Which Direction [L]eft, [N]eutral, [R]ight or [X] to exit ?
Which Direction [L]eft, [N]eutral, [R]ight or [X] to exit ?
X
