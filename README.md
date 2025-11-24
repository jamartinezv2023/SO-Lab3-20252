# Informe Laboratorio -- Análisis de Rendimiento Paralelo

## 1. Introducción

Este documento presenta el análisis completo del rendimiento obtenido al
ejecutar un programa en diferentes cantidades de hilos. Se evalúan
métricas fundamentales como el *speedup* y la *eficiencia*, comparando
los tiempos paralelos con el tiempo serial.

## 2. Objetivos

1.  Medir el tiempo de ejecución para distintos números de hilos.
2.  Calcular el *speedup* alcanzado.
3.  Evaluar la eficiencia del programa paralelo.
4.  Analizar los resultados obtenidos.
5.  Identificar comportamientos anómalos o esperados en el escalamiento.

## 3. Descripción de la experimentación

Se tomó como referencia el tiempo serial (ejecución con un solo hilo) y
luego se realizaron ejecuciones con diferentes cantidades de hilos: 1,
2, 4, 8, 16, 32 y 48.\
Los tiempos capturados permitieron calcular las métricas estándar de
paralelización.

## 4. Tiempo Serial

El tiempo serial medido fue:

**Ts = 8.902823 segundos**

## 5. Tabla de Resultados

A continuación se presentan los valores calculados de tiempo paralelo
(Tp), speedup y eficiencia:

     N        Tp     Speedup   Eficiencia
  ---- --------- ----------- ------------
     1   144.947   0.0614211    0.0614211
     2   81.2769    0.109537    0.0547685
     4   38.5047    0.231214    0.0578035
     8   43.3886    0.205188    0.0256485
    16   44.4757    0.200173    0.0125108
    32   49.4865    0.179904     0.005622
    48   37.8504    0.235211   0.00490023

## 6. Cálculo del Speedup

El *speedup* se calcula como:

\[ S(N) = `\frac{T_s}{T_p(N)}`{=tex} \]

donde ( T_s ) es el tiempo serial y ( T_p(N) ) el tiempo paralelo usando
( N ) hilos.

## 7. Cálculo de la Eficiencia

La eficiencia se define como:

\[ E(N) = `\frac{S(N)}{N}`{=tex} \]

Esta métrica indica qué tan bien se aprovechan los recursos
computacionales.

## 8. Análisis de Resultados

-   El speedup no escala de manera lineal.
-   Existen puntos donde el incremento de hilos no mejora el
    rendimiento.
-   Para 48 hilos se observa una caída fuerte, posiblemente por
    sobrecarga de administración de hilos o saturación del hardware.
-   El mejor tiempo paralelo pertenece a N=48, pero no implica el mejor
    speedup ni la mejor eficiencia.

## 9. Conclusiones

-   El programa presenta mejoría significativa al pasar de 1 a 4 hilos.
-   A partir de 8 hilos el rendimiento oscila, indicando limitaciones
    arquitectónicas o del propio algoritmo.
-   Es necesario evaluar técnicas de optimización adicionales y
    considerar afinidad de hilos, balanceo de carga y partición del
    trabajo.

## 10. Referencias

-   Grama, Gupta, Karypis & Kumar -- *Introduction to Parallel
    Computing*.
-   Amdahl, G. M. (1967). *Validity of the Single Processor Approach to
    Achieving Large-Scale Computing Capabilities*.
-   Foster, I. -- *Designing and Building Parallel Programs*.
