#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>
#include "DC_Motor.h"

// Definición de pines de motor y encoder
// Nomenclatura---> DC_Motor nombremotor(numeropin forward,numeropin backward,numeropin CanalAEncoder,numeropin CanalBEncoder);
DC_Motor eje1(0,2,25,26); 
DC_Motor eje2(3,5,27,28);
DC_Motor eje3(7,9,37,38);
DC_Motor eje4(11,14,31,32);
DC_Motor eje5(15,18,33,34);

const float pulso_millis=500;

int t;
float output=0;

void setup() {
  //CUIDADO CON LOS BAUDIOS
  Serial.begin(614400); // 614400 BAUDIOS MAXIMOS
}

void loop() {
  t = millis();
  if (t>=1)
  {
   // Sincronización de eventos del encoder
   eje1.Enlazar();
   eje2.Enlazar();
   eje3.Enlazar();
   eje4.Enlazar();
   eje5.Enlazar();
  }
   // Movimiento de cada articulación del brazo robótico
   // Nomenclatura---> nombremotor.Mover(numero sentido,numero pulsosmaximos, numero salidaanalogica);
   
   /* El valor del sentido será 0,1,2 :
            0 -> Sin movimiento en el eje.
            1 -> Movimiento horario (Forward) del eje del motor.
            2 -> Movimiento antihorario (Backward) del eje del motor.
   */
   /*
      El valor de pulsos máximos dependerá del eje a mover puesto que
       queda directamente relacionado con el desplazamiento de dicho eje.
   */
   /*
      El valor de salida analógica controla directamente la velocidad del motor,
       dicho valor no debe exceder el valor de 255, ni ser menor que 0, 
       aunque se ha realizado un algoritmo de seguridad que evita dichos casos.
   */
  eje1.Mover(0,190000,210);
  eje2.Mover(0,25000,210);
  eje3.Mover(0,120,210);
  eje4.Mover(0,200,210);
  eje5.Mover(0,50,210);
}
