#pragma once

class myMotor
{
private:
    const int motorPWMR = 12;     // Connect to the PWM pin of the BTS7960
    const int motorPWML = 13;
    const int motorDIRR = 27;    // Connect to the input 1 of the BTS7960
    const int motorDIRL = 14;    // Connect to the input 2 of the BTS7960
    int pwmR = 200;

    const int motor2PWMR = 25;
    const int motor2PWML = 26;
    const int motor2DIRR = 19;
    const int motor2DIRL = 18;

    // const int motorPWMR = 25;     // Connect to the PWM pin of the BTS7960
    // const int motorPWML = 26;
    // const int motorDIRR = 19;    // Connect to the input 1 of the BTS7960
    // const int motorDIRL = 18;    // Connect to the input 2 of the BTS7960
    // int pwmR = 200;

    // const int motor2PWMR = 12;
    // const int motor2PWML = 13;
    // const int motor2DIRR = 27;
    // const int motor2DIRL = 14;

public:
    void init();
    void kanan(int pwm);
    void kiri(int pwm);
    void stop();
    void motor2kanan(int pwm);
    void motor2kiri(int pwm);
    void motor2stop();
};

