/* libc/sys/hermit/sleep.c - sleep function */

/* Written 2018 by Stefan Lankes */

void sys_msleep(unsigned int ms);

unsigned int sleep(unsigned int seconds)
{
  sys_msleep(1000*seconds);
}
