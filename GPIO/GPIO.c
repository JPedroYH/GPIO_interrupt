/*
 * GPIO.c
 *
 *
 *  PP3 LED
 *  PD3 INTERRUPCIÓN PUSH
 *
 */
#include "lib/include.h"

extern void GPIO_D_CONF(void)
{
        // CONFIGURACIÓN PUERTO D
        SYSCTL->RCGCGPIO |= (1<<3);
        while((SYSCTL->PRGPIO&0x00000008) == 0){;} // Espera para encender Puerto
        //  PIN PD3
        GPIOD_AHB->DIR |= (0<<3);//Se configura como entrada
        GPIOD_AHB->AFSEL |= 0x00;//Funciones alternativas
        GPIOD_AHB->PCTL |= 0x00;//Control del puerto
        GPIOD_AHB->PUR |=(1<<3);//Se configura el boton el modo Pull-up
        GPIOD_AHB->DEN |= (1<<3);//Se configura como digital
}

extern void GPIO_P_CONF(void)
{
        // CONFIGURACIÓN PUERTO P
        SYSCTL->RCGCGPIO |= 0x0002000;
        while((SYSCTL->PRGPIO&0x0002000) == 0){;} // Espera para encender Puerto

        GPIOP->DIR |= (1<<3); //Se configura como Salida
        GPIOP->AFSEL |= 0x00;//Funciones alternativas
        GPIOP->PCTL |= 0x00;//Control del Puerto
        GPIOP->DEN |= (1<<3);//Se configura como digital
}

extern void INT_CONF(void)
{
        // CONFIGURACIÓN DE LA INTERRUPCIÓN DLE PUERTO D (BOTÓN)
        // La prioridad es 3/4=0; n=0; interrupción #3; Vector 4n+3
        GPIOD_AHB->IM |=(0<<3);//Se deshabilita la mascara
        GPIOD_AHB->IS |=(0<<3);//Se detectan los bordes
        GPIOD_AHB->IBE |=(0<<3);//Se configura un unico borde
        GPIOD_AHB->IEV |=(1<<3);//Se configura como subida o bajada el envento de la interrupción
        GPIOD_AHB->RIS |=(0<<3);//Se limpia la interrupción
        GPIOD_AHB->IM |=(1<<3);//Se habilita la máscara
        NVIC->IP[0] = (NVIC->IP[0] & 0x00FFFFFF)|0x05000000;//Se configura la prioridad 0
        NVIC->ISER[0] = 0x8; // Se habilita el registro de la interrupción
}

extern void blink(void)
{
    uint32_t a;//Se declara la variable de conteo
    a=0;

    GPIOP->DATA = (1<<3);//Se enciende el LED (Pin 3 puerto P)
    for(a=0;a<1000000;a++){}//Se espera por 1 segundo
    a=0;//Se reinicia la variable de conteo
    GPIOP->DATA = (0<<3);//Se apaga el LED

    if (GPIOD_AHB->RIS==(1<<3))//Cuando el estado de la interrupción este en 1, se limpiará todos los pines del puerto
    {
        GPIOD_AHB->ICR|=(1<<7)|(1<<6)|(1<<5)|(1<<4)|(1<<3)|(1<<2)|(1<<1)|(1<<0);
    }
}
